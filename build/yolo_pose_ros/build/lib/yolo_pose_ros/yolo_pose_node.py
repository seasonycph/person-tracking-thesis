#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node

import torch
from torchvision import transforms
import math
import cv2
import numpy as np

from sensor_msgs.msg import Image
from custom_interfaces.msg import PersonPose
from geometry_msgs.msg import Point
from cv_bridge import CvBridge, CvBridgeError

from yolo_pose_ros.utils.datasets import letterbox
from yolo_pose_ros.utils.general import non_max_suppression_kpt
from yolo_pose_ros.utils.plots import output_to_keypoint, plot_skeleton_kpts
from yolo_pose_ros.models.yolo import Model


class YoloPoseNode(Node):
    def __init__(self):
        super().__init__("yolo_pose_node")
        
        # Get parameter to show the video
        self.declare_parameter('show_video', True)

        # Initialize the node
        self.get_logger().info("YOLOPose node initialized.")

        # Read the parameters for the model
        self.read_parameters()

        # Initialize the subscriber and the publishers
        self.init_communication()

    def read_parameters(self):
        # Chack availability of GPU
        if torch.cuda.is_available():
            self.get_logger().info(
                f"GPU available: {torch.cuda.device.__name__}")
            self.device_ = "cuda:0"
        else:
            self.get_logger().warn("GPU not available, using CPU instead.")
            self.device_ = "cpu"

        # Location of the weight file
        self.weight_file_ = "weights/yolo-pose/yolov7-w6-pose.pt"

        # Confidence threshold
        self.conf_thres_ = 0.4

        # Load the model
        self.get_logger().info("Loading model...")
        self.model_ = load_model(self.weight_file_, self.device_)
        self.get_logger().info("YOLO-Pose loaded successfully.")

        # Create bridge to convert Image msg into jpg image
        self.bridge_ = CvBridge()

    def init_communication(self):
        """
        Initialize ROS connection
        """

        # Publisher
        self.dets_pub_ = self.create_publisher(
            msg_type=PersonPose, topic="/yolo_pose/detections", qos_profile=10)

        # Subscriber
        topic = "/lewis_b1/camera_front/rgb/image_raw"
        self.image_sub_ = self.create_subscription(
            Image, topic, self.callback_camera_front, qos_profile=10)

    def callback_camera_front(self, msg):

        # Try converting the msg into a image
        try:
            # Convert the raw image into a OpenCV2
            self.cv2_image_ = self.bridge_.imgmsg_to_cv2(msg, 'bgr8')
        except CvBridgeError as e:
            self.get_logger().error(e)

        t = time.time()
        
        # Run inference on the converted image
        output, self.cv2_image_ = run_inference(
            self.model_, self.cv2_image_, self.device_)

        # Draw keypoints and skeleton on the image
        nimg, kpts = draw_keypoints(self.model_, output, self.cv2_image_)
        #print(kpts)
        

        # Convert the detections into PersonPose message
        dets_msg = kpts_to_person_pose(kpts)
        dets_msg.header = msg.header
        self.dets_pub_.publish(dets_msg)

        self.get_logger().info(f"FPS: {1 / (time.time() - t)}")

        # Show the inference
        #if self.get_parameter('show_video') == True:
        display_inference(nimg)


def load_model(weight_file, device):
    """
    Load the pre-trained YOLOv7 pose estimation model
    """

    # Load model to GPU from the weight file
    model = torch.load(weight_file, map_location=device)['model']

    # Put model in inference mode
    model.float().eval()

    if torch.cuda.is_available():
        # half() turns predicitons into float16 tensors,
        # which lowers inference time
        model.half().to(device)

    return model


def run_inference(model, image, device):
    """
    Function to run the image through the model
    """
    # Resize and pad the image
    image = letterbox(image, 960, stride=64, auto=True)[0]
    # Apply transforms
    image = transforms.ToTensor()(image)  # torch.Size([3, 567, 960])
    # If GPU is available, run the image there
    if torch.cuda.is_available():
        image = image.half().to(device)
    # Turn image into batch
    image = image.unsqueeze(0)  # torch.Size([1, 3, 567, 960])
    with torch.no_grad():
        output, _ = model(image)

    return output, image


def draw_keypoints(model, output, image):
    # Apply non-maximum suppression
    output = non_max_suppression_kpt(output,
                                     0.4,  # Confidence threshold
                                     0.65,  # IoU threshold
                                     # Number of classes (only 1)
                                     nc=model.yaml['nc'],
                                     # Number of Keypoints (17)
                                     nkpt=model.yaml['nkpt'],
                                     kpt_label=True)

    # Disable gradient propagation
    with torch.no_grad():
        output = output_to_keypoint(output)

    # Drop the first 7 elements so then we have 51 elements per person
    if len(output) != 0:
        output = output[:, 7:]

    # Fit the frame to the needed representation
    nimg = image[0].permute(1, 2, 0) * 255
    nimg = nimg.cpu().numpy().astype(np.uint8)
    nimg = cv2.cvtColor(nimg, cv2.COLOR_RGB2BGR)
    kpts = []
    for idx in range(output.shape[0]):
        # steps will always have to be 3
        # since for each keypoint we have 3 elements {x, y, conf.}
        plot_skeleton_kpts(nimg, output[idx].T, 3)
        kpts.append(output[idx])
        

    return nimg, kpts


def kpts_to_person_pose(output):
    person_pose = PersonPose()

    # Select the keypoints
    for kpts in output: # Range through the 17 keypoints
        i = 0
        for _ in range(17):
            # Define the position of each keypoint
            kpt_pose = Point()
            kpt_pose.x = kpts[i]
            kpt_pose.y = kpts[i+1]
            kpt_pose.z = 0.0

            # Append the positions of the keypoints and the confidence
            person_pose.kpt_conf.append(kpts[i+2])
            person_pose.keypoints.append(kpt_pose)

            # Increase i to the next set of kpt values {x, y, conf.}
            i += 3
    
    return person_pose
            

def display_inference(image):
    # Create a window that sizes itself
    cv2.namedWindow("Front Camera", cv2.WINDOW_AUTOSIZE)
    # Show the image
    cv2.imshow("Front Camera", cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    # Wait 1ms before closing the window
    cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = YoloPoseNode()
    rclpy.spin(node)
    rclpy.shutdown()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
