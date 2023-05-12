#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import torch
from torchvision import transforms
import math
import cv2
import numpy as np
import os

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from yolo_pose_ros.utils.datasets import letterbox
from yolo_pose_ros.utils.general import non_max_suppression_kpt
from yolo_pose_ros.utils.plots import output_to_keypoint, plot_skeleton_kpts
from yolo_pose_ros.models.yolo import Model


class YoloPoseNode(Node):
    def __init__(self):
        super().__init__("yolo_pose_node")

        # Initialize the node
        self.get_logger().info("YOLOPose node initialized.")
        self.get_logger().info(f"Current directory: {os.getcwd()}")

        # Read the parameters for the model
        self.read_parameters()

        # Initialize the subscriber and the publishers
        self.init_communications()

    def read_parameters(self):
        # Chack availability of GPU
        if torch.cuda.is_available():
            self.get_logger().info(f"GPU available: {torch.cuda.device.__name__}")
            self.device_ = "cuda:0"
        else:
            self.get_logger().warn("GPU not available, using CPU instead.")
            self.device_ = "cpu"
        
        self.weight_file_ = "weights/yolo-pose/yolov7-w6-pose.pt"

        # Load the model
        self.get_logger().info("Loading model...")
        self.model_ = load_model(self.weight_file_, self.device_)
        
        

    def init_communications(self):
        """
        Initialize ROS connection
        """

        # Publisher

        # Subscriber
        topic = "/lewis_b1/camera_front/rgb/image_raw"
        self.image_sub_ = self.create_subscription(
            Image, topic, self.callback_camera_front, qos_profile=10)

    def callback_camera_front(self, msg):
        
        # Convert the raw image into a .jpg file

        pass

def load_model(weight_file, device):
    """
    Load the pre-trained YOLOv7 pose estimation model
    """
    #model = Model(cfg="/home/taras/thesis_ws/src/yolo_pose_ros/yolo_pose_ros/cfg/yolov7-w6-pose.yaml")

    #model.load_state_dict(torch.load('yolov7-w6-pose2.pt', map_location=device))

    model = torch.load(weight_file, map_location=device)['model']
    print("Model loaded")
    #model.load_state_dict()

    # Put model in inference mode
    model.float().eval()

    if torch.cuda.is_available():
        # half() turns predicitons into float16 tensors, 
        # which lowers inference time
        model.half().to(device)
    
    return model

def main(args=None):
    rclpy.init(args=args)
    node = YoloPoseNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
