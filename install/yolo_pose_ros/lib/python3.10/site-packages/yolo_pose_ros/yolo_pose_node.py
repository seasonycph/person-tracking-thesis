#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node

import torch
from torchvision import transforms
import math
import cv2
import numpy as np
from deep_sort_realtime.deepsort_tracker import DeepSort
from collections import OrderedDict

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

        # Initialize the node
        self.get_logger().info("YOLOPose node initialized.")

        # Read the parameters for the model
        self.read_parameters()

        # Initialize the subscriber and the publishers
        self.init_communication()

        # Initialize the tracker
        self.tracker_ = DeepSort(max_age=5, n_init=2, embedder_gpu=True)

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

        # Initialize the frame count
        self.frame_count_ = 1
        self.fps_ = []

    def init_communication(self):
        """
        Initialize ROS connection
        """

        # Publisher
        topic = "/yolo_pose/detections"
        self.dets_pub_ = self.create_publisher(
            PersonPose, topic, qos_profile=10)

        topic = "/yolo_pose/pose_image"
        self.image_pub_ = self.create_publisher(
            Image, topic, qos_profile=10)

        # Subscriber
        topic = "/lewis_b1/camera_front/rgb/image_raw"
        self.image_sub_ = self.create_subscription(
            Image, topic, self.callback_camera_front, qos_profile=10)

    def callback_camera_front(self, msg):
        # Increase frame count
        self.frame_count_ += 1

        # Calculate the average every 10 fps
        t = time.time()

        # Try converting the msg into a image
        try:
            # Convert the raw image into a OpenCV2
            self.cv2_image_ = self.bridge_.imgmsg_to_cv2(msg, 'bgr8')
        except CvBridgeError as e:
            self.get_logger().error(e)

        # Run inference every 3 frames
        if self.frame_count_ % 2 == 0:
            # Run inference on the converted image
            output, self.cv2_image_ = run_inference(
                self.model_, self.cv2_image_, self.device_)

            # Save previous inference output and image
            self.inf_output = output
            self.inf_image = self.cv2_image_

            # Draw keypoints and skeleton on the image
            nimg, kpts, boxes, confs = draw_keypoints(
                self.model_, output, self.cv2_image_)
        else:
            self.cv2_image_ = image_processing(self.cv2_image_, self.device_)
            nimg, kpts, boxes, confs = draw_keypoints(
                self.model_, self.inf_output, self.cv2_image_)

        
        # Compute the bounding boxes around the person
        boxes = compute_bbox(kpts)

        #print(boxes)

        # Compute detections
        detections = compute_detections(boxes, confs)

        # # Tracker
        tracks = self.tracker_.update_tracks(detections, frame=nimg)
        track_dict = OrderedDict()
        for track in tracks:
            if not track.is_confirmed():
                continue
            track_dict[track.track_id] = track.to_ltrb()

        # Convert the detections into PersonPose message
        dets_msg, prsn_pose = kpts_to_person_pose(kpts)
        dets_msg.header = msg.header
        self.dets_pub_.publish(dets_msg)

        # Draw the center of the detected person (temporal feature)
        # for pose in prsn_pose:
        #     nimg = cv2.circle(nimg, pose, 5, (255, 0, 0), -1)

        # Draw a circle in the center of the tracked bounding box
        # for box in track_dict.values():
        #     nimg = cv2.circle(
        #         nimg, (int(box[0]), int(box[1])), 5, (0, 255, 0), -1)
        #nimg = draw_bbox(track_dict.values(), nimg, (255,0,0))

        # Send the resulting image through the topic
        try:
            image_msg = self.bridge_.cv2_to_imgmsg(
                nimg, encoding=msg.encoding, header=msg.header)
        except CvBridgeError as e:
            self.get_logger().error(e)
        self.image_pub_.publish(image_msg)

        #nimg = draw_bbox(boxes, nimg, (0,255,0))

        # Show the inference
        display_inference(nimg)

        self.fps_.append(1 / (time.time() - t))
        if len(self.fps_) > 10:
            self.fps_ = self.fps_[-10:]
        self.get_logger().info(f"FPS: {np.mean(self.fps_)}")


def load_model(weight_file, device):
    """
    Load the pre-trained YOLOv7 pose estimation model
    """

    # Load model to GPU from the weight file
    model = torch.load(weight_file, map_location=device)['model']

    # Put model in inference mode
    model.float().eval()

    if device == "cuda:0":
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
    if device == "cuda:0":
        image = image.half().to(device)
    # Turn image into batch
    image = image.unsqueeze(0)  # torch.Size([1, 3, 567, 960])
    with torch.no_grad():
        output, _ = model(image)

    return output, image


def image_processing(image, device):
    # Resize and pad the image
    image = letterbox(image, 960, stride=64, auto=True)[0]
    # Apply transforms
    image = transforms.ToTensor()(image)  # torch.Size([3, 567, 960])
    # If GPU is available, run the image there
    if device == "cuda:0":
        image = image.half().to(device)
    # Turn image into batch
    image = image.unsqueeze(0)

    return image


def draw_keypoints(model, output, image):
    # Apply non-maximum suppression
    output = non_max_suppression_kpt(output,
                                     0.5,  # Confidence threshold
                                     0.65,  # IoU threshold
                                     # Number of classes (only 1)
                                     nc=model.yaml['nc'],
                                     # Number of Keypoints (17)
                                     nkpt=model.yaml['nkpt'],
                                     kpt_label=True)

    # Disable gradient propagation
    with torch.no_grad():
        output, boxes, confs = output_to_keypoint(output)

    # Drop the first 7 elements so then we have 51 elements per person
    if len(output) != 0:
        output = output[:, 7:]

    # Fit the frame to the needed representation
    nimg = image[0].permute(1, 2, 0) * 255
    nimg = nimg.cpu().numpy().astype(np.uint8)
    nimg = cv2.cvtColor(nimg, cv2.COLOR_RGB2BGR)

    # Draw the bounding box around the detection
    #nimg = draw_bbox(boxes, nimg)

    kpts = []
    for idx in range(output.shape[0]):
        # steps will always have to be 3
        # since for each keypoint we have 3 elements {x, y, conf.}
        plot_skeleton_kpts(nimg, output[idx].T, 3)
        kpts.append(output[idx])

    return nimg, kpts, boxes, confs

def draw_bbox(boxes, nimg, color):
    if len(boxes) != 0:
        for box in boxes:
            nimg = cv2.rectangle(nimg, (int(box[0]), int(box[1])),
                                (int( box[2]), int(box[3])),
                                color, 5)
    
    return nimg


def kpts_to_person_pose(output):
    person_pose = PersonPose()
    pose = []

    # Select the keypoints
    for kpts in output:  # Range through the 17 keypoints
        i = 0
        det_pose = Point()
        x_pos = []
        y_pos = []
        for _ in range(17):
            # Define the position of each keypoint
            kpt_pose = Point()
            kpt_pose.x = kpts[i]
            x_pos.append(kpts[i])
            kpt_pose.y = kpts[i+1]
            y_pos.append(kpts[i+1])
            kpt_pose.z = 0.0

            # Append the positions of the keypoints and the confidence
            person_pose.kpt_conf.append(kpts[i+2])
            person_pose.keypoints.append(kpt_pose)

            # Increase i to the next set of kpt values {x, y, conf.}
            i += 3

        # Position of the person in the image
        det_pose.x = (np.round(np.mean(x_pos)))
        det_pose.y = (np.round(np.mean(y_pos)))
        pose.append((int(det_pose.x), int(det_pose.y)))
        person_pose.person_position.append(det_pose)

        # Check if person is looking at the camera
        person_pose.looking.append(person_front(kpts))

    return person_pose, pose


def compute_detections(boxes, confs):
    dets = []
    # The tracker accepts detection input as ([x,y,w,h], conf, class)
    for box, conf in zip(boxes, confs):
        dets.append((box, conf, 'person'))

    return dets

def compute_bbox(kpts):
    boxes = []
    offset = 20
    for kpt in kpts:
        kpt_x = []
        kpt_y = []
        for i, _ in enumerate(kpt):
            if i % 3 != 0 and i != 0:
                continue
            if kpt[i+2] > 0.5: # Check that the kpt is visible
                kpt_x.append(kpt[i])
                kpt_y.append(kpt[i+1])
            i =+ 2
        if len(kpt_x) == 0 or len(kpt_y) == 0:
            continue
        w = np.max(kpt_x) - np.min(kpt_x) + offset
        h = np.max(kpt_y) - np.min(kpt_y) + offset
        boxes.append([np.min(kpt_x) - offset, np.min(kpt_y) - offset, w, h])
    return boxes




def person_front(kpts):
    # If ALL the keypoints of the face are visible, the person is probably looking at the camera

    # TO DO: If head keypoints are not visible (partial visibility) then consider the hips of the person
    # x_left_hip > x_right_hip = looking at camera

    # Vore for the visibility of the face
    vote_front = 0
    for i in range(5):
        if kpts[i * 3 + 2] > 0.5:
            vote_front += 1

    # Check the votes
    if vote_front >= 4:
        return True
    else:
        return False


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
