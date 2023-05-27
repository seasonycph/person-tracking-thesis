#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

import numpy as np

from custom_interfaces.msg import Tracker
from collections import OrderedDict


class TrackerNode(Node):
    def __init__(self):
        super().__init__("tracker_node")

        # Initialize the node
        self.get_logger().info("Tracker node initialized")

        # Initialize the subscriber and the publisher
        self.init_communication()

    def init_communication(self):
        """
        Initialize ROS2 communications
        """

        # Publisher

        # Subscriber
        topic = "/yolo_pose/tracker"
        self.yolo_subs_ = self.create_subscription(
            Tracker, topic, self.callback_yolo_tracker, qos_profile=10)

        topic = "/dr_spaam/tracker"
        self.drspaam_subs_ = self.create_subscription(
            Tracker, topic, self.callback_drspaam_tracker, qos_profile=5)

    def callback_yolo_tracker(self, msg):
        # Transform the message to dictionary
        self.yolo_track_ = tracker_to_dict(msg)

        # Compute the relative angle of each detection
        # 34.5 is half of the HFOV of the camera
        # 480 is half of the size of the picture
        # THe halves are taken so the coordinate system starts at the middle, like in the LiDAR
        # The new tracking dictionary will be
        # {'ID': [x, y, angle]}
        for key, poses in self.yolo_track_.items():
            xp = poses[0] - 480
            self.yolo_track_[key].append((xp * 34.5) / 480)

        # print(f"Angles from yolo: {self.yolo_track_.items()}")
        # Call the association then new YOLO data arrives bc the drspaam is faster
        # so it would mean we would have redundant calculations
        self.tracklets_association()

    def callback_drspaam_tracker(self, msg):
        # Transform the message to dictionary
        self.drspaam_track_ = tracker_to_dict(msg)

        # Compute the angle at which there is a detection
        for key, poses in self.drspaam_track_.items():
            self.drspaam_track_[key].append(
                np.rad2deg(np.arctan(poses[0] / poses[1])))

        # print(f"Angles from dr-spaam: {self.drspaam_track_.items()}")

    def tracklets_association(self):
        associated_tracklets = OrderedDict()

        # Iterate over the YOLO tracklets
        for yolo_id, yolo_data in self.yolo_track_.items():
            yolo_angle = yolo_data[2]
            min_angle_diff = float('inf')
            associated_drspaam_id = None

            print(f"YOLO tracklet {yolo_id} with angle {yolo_angle}")

            for drspaam_id, drspaam_data in self.drspaam_track_.items():
                # Check that the ID is not already associated
                if drspaam_id in associated_tracklets.values():
                    continue

                drspaam_angle = drspaam_data[2]
                angle_diff = abs(yolo_angle - drspaam_angle)

                print(f"DR-SPAAM tracklet {drspaam_id} with angle {drspaam_angle}")

                # Check if it is the closes angle so far
                if angle_diff < min_angle_diff:
                    associated_drspaam_id = drspaam_id
                    min_angle_diff = angle_diff

            # Associate the YOLO tracklet with the closes DR-SPAAM tracklet
            if associated_drspaam_id is not None:
                # self.drspaam_track_[associated_drspaam_id]
                associated_tracklets[yolo_id] = associated_drspaam_id

        print(f"Associated tracklets: {associated_tracklets.items()}")


def tracker_to_dict(tracker_msg):
    tracker = OrderedDict()
    for ids, poses in zip(tracker_msg.ids, tracker_msg.positions):
        tracker[ids] = [poses.x, poses.y]

    return tracker


def main(args=None):
    rclpy.init(args=args)
    node = TrackerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
