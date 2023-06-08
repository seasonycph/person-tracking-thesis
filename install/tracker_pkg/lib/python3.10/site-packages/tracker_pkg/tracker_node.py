#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

import numpy as np

from custom_interfaces.msg import Tracker, Associations
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
from collections import OrderedDict


class TrackerNode(Node):
    def __init__(self):
        super().__init__("tracker_node")

        # Initialize the node
        self.get_logger().info("Tracker node initialized")

        # Initialize the needed attributes
        self.init_parameters()

        # Initialize the subscriber and the publisher
        self.init_communication()

    def init_communication(self):
        """
        Initialize ROS2 communications
        """

        # Publisher
        topic = "/tracker/associations"
        self.associations_pub_ = self.create_publisher(
            Associations, topic, qos_profile=10)

        topic = "/tracker/rviz"
        self.associations_rviz_pub_ = self.create_publisher(
            Marker, topic, qos_profile=10)

        topic = "/yolo_pose/rviz"
        self.yolo_rviz_pub_ = self.create_publisher(
            Marker, topic, qos_profile=10)

        # Subscriber
        topic = "/dr_spaam/tracker"
        self.drspaam_subs_ = self.create_subscription(
            Tracker, topic, self.callback_drspaam_tracker, qos_profile=10)

        topic = "/yolo_pose/tracker"
        self.yolo_subs_ = self.create_subscription(
            Tracker, topic, self.callback_yolo_tracker, qos_profile=10)

    def init_parameters(self):
        # Initialize YOLO tracker
        self.yolo_track_ = None

        # Initialize DR-SPAAM tracker
        self.drspaam_track_ = None

        # Initialize the last known positions
        self.last_known_positions = OrderedDict()

        # Initialize the lost detections counter
        self.lost_detection_counter = OrderedDict()

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

        # Take the msg header (needed for yolo marker)
        self.drspaam_header_ = msg.header

        # Compute the angle at which there is a detection
        for key, poses in self.drspaam_track_.items():
            self.drspaam_track_[key].append(
                np.rad2deg(np.arctan(poses[0] / poses[1])))

        # print(f"Angles from dr-spaam: {self.drspaam_track_.items()}")

    def tracklets_association(self):
        # Do not do anything if there are no messages
        if self.yolo_track_ is None or self.drspaam_track_ is None:
            return

        associated_tracklets = OrderedDict()
        self.associations_msg = Associations()

        # Choose which tracklets will be used
        # If yolo tracklets are empty, there will be no associations and same if drspaam's are e,pty
        # Otherwise use yolo's as a base
        if len(list(self.yolo_track_.keys())) == 0:
            tracklets = self.drspaam_track_
            other_tracklets = self.yolo_track_
        else:
            tracklets = self.yolo_track_
            other_tracklets = self.drspaam_track_

        # Iterate over the tracklets
        for yolo_id, yolo_data in tracklets.items():
            yolo_angle = yolo_data[2]
            min_angle_diff = float('inf')
            associated_drspaam_id = None

            # print(f"YOLO tracklet {yolo_id} with angle {yolo_angle}")
            for drspaam_id, drspaam_data in other_tracklets.items():
                # Check that the ID is not already associated
                if drspaam_id in associated_tracklets.values():
                    continue

                drspaam_angle = drspaam_data[2]
                angle_diff = abs(yolo_angle - drspaam_angle)

                # print(f"DR-SPAAM tracklet {drspaam_id} with angle {drspaam_angle}")

                # Check if it is the closes angle so far
                if angle_diff < min_angle_diff:
                    if angle_diff < 35:
                        associated_drspaam_id = drspaam_id
                    min_angle_diff = angle_diff

            # Associate the YOLO tracklet with the closest DR-SPAAM tracklet
            if associated_drspaam_id is not None:
                # self.drspaam_track_[associated_drspaam_id]
                associated_tracklets[yolo_id] = associated_drspaam_id

                # Save the drspaam data corresponding with the associated id
                associated_drspaam_data = self.drspaam_track_[
                    associated_drspaam_id]
                
                # Create the association message
                self.associations_msg.yolo_ids.append(yolo_id)
                self.associations_msg.drspaam_ids.append(associated_drspaam_id)
                self.associations_msg.yolo_positions.append(
                    Point(x=yolo_data[0], y=yolo_data[1], z=yolo_data[2]))
                self.associations_msg.drspaam_positions.append(Point(
                    x=associated_drspaam_data[0], y=associated_drspaam_data[1], z=associated_drspaam_data[2]))

            # Publish the association message
            self.associations_msg.header = self.drspaam_header_
            self.associations_pub_.publish(self.associations_msg)

        # Create and publish the message for YOLO marker
        self.yolo_marker_msg()

        # Create and publish the message for association marker
        self.association_marker_msg()
        # print(f"Associated tracklets: {associated_tracklets.items()}")

    def association_marker_msg(self):
        """
        Create a marker that representes the association between DR-SPAAM and YOLO
        """

        # Take the average of the positions
        av_pos = []
        yolo_positions = compute_yolo_detections(self.associations_msg)
        for i, position in enumerate(self.associations_msg.drspaam_positions):
            av_pos.append([(yolo_positions[i][0] + position.x) / 2,
                          (yolo_positions[i][1] + position.y) / 2])

        # Convert detections to rviz marker
        rviz_msg = position_to_rviz_marker(av_pos, [0.0, 0.0, 1.0, 1.0], self.associations_rviz_pub_.topic)
        rviz_msg.header = self.associations_msg.header
        self.associations_rviz_pub_.publish(rviz_msg)

    def yolo_marker_msg(self):
        """
        Transform YOLO associacion to be represented in the DR-SPAAM coordinates
        """

        # Convert the YOLO detections into the same space as DR-SPAAM
        yolo_dets_xy = compute_yolo_detections(self.associations_msg)

        # Convert the detections to rvis marker
        rviz_msg = position_to_rviz_marker(
            yolo_dets_xy, [0.0, 1.0, 0.0, 1.0], self.yolo_rviz_pub_.topic)
        rviz_msg.header = self.associations_msg.header
        self.yolo_rviz_pub_.publish(rviz_msg)


def compute_yolo_detections(associations):

    # Convert the YOLO detections into the same space as DR-SPAAM
    yolo_dets_xy = []
    yolo_positions = associations.yolo_positions
    drspaam_positions = associations.drspaam_positions
    for i, yolo_pos in enumerate(yolo_positions):
        alpha = np.deg2rad(yolo_pos.z)
        y_dr = drspaam_positions[i].y
        x_yolo = y_dr * np.tan(alpha)

        yolo_dets_xy.append([x_yolo, y_dr])

    return yolo_dets_xy


def position_to_rviz_marker(dets_xy, color, topic):
    """
    Convert detections to RViz marker msg. Each detection is marked as a cirlce approximated by line segments.
    """

    msg = Marker()
    msg.action = Marker.ADD
    msg.ns = topic
    msg.id = 0
    msg.type = Marker.LINE_LIST

    msg.scale.x = 0.03  # Line width
    # Selected color
    msg.color.r = color[0]
    msg.color.g = color[1]
    msg.color.b = color[2]
    msg.color.a = color[3]

    # Circle
    r = 0.3
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
