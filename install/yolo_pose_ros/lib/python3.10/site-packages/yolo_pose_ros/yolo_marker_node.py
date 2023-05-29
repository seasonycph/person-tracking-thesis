#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import numpy as np

from visualization_msgs.msg import Marker
from custom_interfaces.msg import Associations
from geometry_msgs.msg import Point


class YOLOMarkerNode(Node):
    def __init__(self):
        super().__init__("yolo_marker_node")

        # Initialize the node
        self.get_logger().info("YOLO Marker node initialized.")

        # Initialize the communications
        self.init_communication()

    def init_communication(self):
        """
        Initialize ROS 2 communication
        """

        # Publisher
        topic = "/yolo_pose/rviz"
        self.rviz_pub_ = self.create_publisher(Marker, topic, qos_profile=10)

        # Subscriber
        topic = "tracker/associations"
        self.associations_sub_ = self.create_subscription(Associations, topic, self.callback_associations, qos_profile=10)

        topic = "/dr_spaam/tracker"

    def callback_associations(self, msg):
        # Take the associated IDs
        yolo_ids = msg.yolo_ids
        drspaam_ids = msg.drspaam_ids

        # Save the associated positions
        yolo_positions = msg.yolo_positions
        drspaam_positions = msg.drspaam_positions

        # Extract the useful data
        dets_xy = []
        for i, yolo_pos in enumerate(yolo_positions):
            alpha = np.deg2rad(yolo_pos.z)
            y_dr = drspaam_positions[i].y
            x_yolo = y_dr * np.tan(alpha)

            dets_xy.append([x_yolo, y_dr])

        # Create the message
        rviz_msg = position_to_rviz_marker(dets_xy)
        rviz_msg.header = msg.header
        self.rviz_pub_.publish(rviz_msg)

def position_to_rviz_marker(dets_xy):
    """
    Convert detection to RViz marker msg. Each detection is marked as a circle approximated by line segments.
    """

    msg = Marker()
    msg.action  = Marker.ADD
    msg.ns = "yolo_pose"
    msg.id = 0
    msg.type = Marker.LINE_LIST

    msg.scale.x = 0.03 # Line width
    # Green color
    msg.color.g = 1.0
    msg.color.a = 1.0

    # Circle
    r = 0.2
    ang = np.linspace(0, 2 * np.pi, 20)
    xy_offsets = r * np.stack((np.cos(ang), np.sin(ang)), axis=1)

    # To msg
    for d_xy in dets_xy:
        for i in range(len(xy_offsets) - 1):
            # Start point of a segment
            p0 = Point()
            p0.x = d_xy[1] + xy_offsets[i, 0]
            p0.y = d_xy[0] + xy_offsets[i, 1]
            p0.z = 0.0
            msg.points.append(p0)

            # End point
            p1 = Point()
            p1.x = d_xy[1] + xy_offsets[i + 1, 0]
            p1.y = d_xy[0] + xy_offsets[i + 1, 1]
            p1.z = 0.0
            msg.points.append(p1)

    return msg





def main(args=None):
    rclpy.init(args=args)
    node = YOLOMarkerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
