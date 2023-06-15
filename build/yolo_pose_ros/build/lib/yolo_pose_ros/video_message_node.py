#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge, CvBridgeError
import os
import numpy as np

from sensor_msgs.msg import Image
from custom_interfaces.msg import BoundingBox
from std_msgs.msg import Header


class VideoStreamNode(Node):
    def __init__(self):
        super().__init__("video_stream")

        # Initialize the needed parameters
        self.init_parameters()

        # Initialize communications
        self.init_communications()

        # Initialize the node
        self.get_logger().info("Video Stremer node initialized.")

    def init_parameters(self):
        data = 'MOT17-11-DPM'
        tracker = 'CentroidTracker'
        evaluation = "4"
        # Image directory
        self.image_dir = f"/media/taras/5038-A14F/tracking_datasets/MOT17/train/{data}/img1/"

        # Get the length of the sequence
        seq_path = f"/media/taras/5038-A14F/tracking_datasets/MOT17/train/{data}/seqinfo.ini"
        with open(seq_path) as seq_file:
            for line in seq_file:
                line = line.split("=")
                if line[0] == "seqLength":
                    self.seq_length = int(line[1])
        
        # Get image names
        self.images = []
        for file in sorted(os.listdir(self.image_dir)):
            self.images.append(file)

        # Image number
        self.im_num = 0

        # The file to which write the results
        self.res_file = open(f"/home/taras/thesis_ws/track_results/{tracker}/{evaluation}/{data}.txt", "+w")

        # Create bridge to convert image to Image message
        self.bridge_ = CvBridge()

    def init_communications(self):
        """
        Initialize ROS 2 communications
        """

        # Subscriber
        topic = "/yolo_pose/bounding_boxes"
        self.bb_sub_ = self.create_subscription(
            BoundingBox, topic, self.callback_yolo_track, qos_profile=10)
        
        # Publisher
        topic = "/MOT/image_raw"
        self.image_pub_ = self.create_publisher(Image, topic, qos_profile=10)
        self.timer_ = self.create_timer(
            timer_period_sec=0.4, callback=self.publish_image)

    def publish_image(self):
        """
        Publish the video images from the MOT17 challenge
        """

        # Increase image number until reaching the end
        if self.im_num == self.seq_length:
            return 0
        else:
            self.im_num += 1
    
        self.get_logger().info(f"Processing image {self.images[self.im_num-1]}")

        # Get the path of the image
        image_path = os.path.join(self.image_dir, self.images[self.im_num-1])

        # Compute the header and the encoding
        encoding = "bgr8"
        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = image_path.split("/")[-1].split(".")[0]
        # Convert the image to Image message
        try:
            cv2_im = cv2.imread(image_path)
            image_msg = self.bridge_.cv2_to_imgmsg(
                cv2_im, encoding=encoding, header=header)
        except CvBridgeError as e:
            self.get_logger().error(e)

        # Publish the image
        self.image_pub_.publish(image_msg)

    def callback_yolo_track(self, msg):
        """
        Callback for tracker message. In theory the callback will be activated when ot finds the message publishing.
        """
        self.get_logger().info(f"Writing results for frame {self.images[self.im_num-1].split('.')[0]}")

        # Frame id
        frame_id = str(self.im_num)

        for i, id in enumerate(np.asarray(msg.ids)):
            # Convert the values to strings
            x = str(msg.corner_pos[i].x)
            y = str(msg.corner_pos[i].y)
            w = str(msg.size[i].x)
            h = str(msg.size[i].y)

            # Write the result line
            result = frame_id + "," + str(float(id)) + "," + x + "," + y + "," + w + "," + h + "," + "1,-1,-1,-1\n"
            self.res_file.write(result)
            if frame_id == "1":
                print("Done")


def main(args=None):
    rclpy.init(args=args)
    node = VideoStreamNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
