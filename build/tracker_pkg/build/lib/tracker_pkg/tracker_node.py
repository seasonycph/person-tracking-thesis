#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from custom_interfaces.msg import Tracker


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
        #self.get_logger().info(f"YOLO TRACKER: {str(msg.ids)}")
        print(f"YOLO TRACKER: {str(msg.ids)}")

    def callback_drspaam_tracker(self, msg):
        #self.get_logger().info(f"DR-SPAAM TRACKER: {str(msg.ids)}")
        print(f"DR-SPAAM TRACKER: {str(msg.ids)}")


def main(args=None):
    rclpy.init(args=args)
    node = TrackerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
