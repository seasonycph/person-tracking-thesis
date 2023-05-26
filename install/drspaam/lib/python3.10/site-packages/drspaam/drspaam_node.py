#!/usr/bin/env python3

import numpy as np
import time
import rclpy
import torch
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Point, Pose, PoseArray
from custom_interfaces.msg import Tracker
from visualization_msgs.msg import Marker

from dr_spaam.detector import Detector, _TrackingExtension
from .drspaam_tracker.centroidtracker import CentroidTracker


class DrSpaamNode(Node):

    def __init__(self):
        super().__init__("dr_spaam_ros")

        # Read the parameters for the detector
        self.read_params()

        # Initialize the node
        self.get_logger().info("DR-SPAAM node initialized.")

        # Initialize the detector
        self._detector = Detector(
            model_name="DR-SPAAM",
            ckpt_file=self.weight_file,
            gpu=torch.cuda.is_available(),
            stride=self.stride,
            tracking=True)

        # Initialize tracker
        self.centroid_tracker_ = CentroidTracker()

        # Previous deections
        self.prev_dets_xy = np.array([0, 0])

        # Initialize the comunication
        self.init_communication()

    def read_params(self):
        """
        Reads parameters from ROS server
        """
        self.weight_file = "weights/dr-spaam/dr_spaam_e40.pth"
        self.stride = 1
        self.conf_thresh = 0.6

    def init_communication(self):
        """
        Initialize ROS connection
        """
        # Publisher
        self.dets_pub_ = self.create_publisher(
            msg_type=PoseArray, topic="/dr_spaam/detections", qos_profile=10)

        self.rviz_pub_ = self.create_publisher(
            msg_type=Marker, topic="/dr_spaam/rviz", qos_profile=10)

        self.tracker_pub_ = self.create_publisher(
            msg_type=Tracker, topic="/dr_spaam/tracker", qos_profile=10)

        # Subscriber
        topic = "/lewis_b1/scan_front"
        self.scan_sub_ = self.create_subscription(
            LaserScan, topic, self.callback_scan_front, qos_profile=10)

    def callback_scan_front(self, msg):
        # Check if laser specifications have been set
        if not self._detector.laser_spec_set():
            self._detector.set_laser_spec(angle_inc=msg.angle_increment,
                                          num_pts=len(msg.ranges))

        # Handle the 'inf' values
        scan = np.array(msg.ranges)
        scan[np.isinf(scan)] = 39.99
        scan[np.isnan(scan)] = 39.99

        # Extract the detections
        # t = time.time()
        dets_xy, dets_cls, _ = self._detector(scan)

        # Confidence threshold
        conf_mask = (dets_cls >= self.conf_thresh).reshape(-1)

        # Apply the confidence mask
        dets_xy = dets_xy[conf_mask]
        dets_cls = dets_cls[conf_mask]

        # Velocities
        vel_xy = np.array([(dets_xy)])
        self.prev_dets_xy = dets_xy

        # Track the detected objects
        track_dict = self.centroid_tracker_.update(dets_xy)

        # Internal Dr-SPAAM tracker
        tracks, tracks_cls = self._detector.get_tracklets()
        trks = []
        for t, tc in zip(tracks, tracks_cls):
            if tc >= self.conf_thresh and len(t) > 1:
                trks.append(t)
        #print(trks)

        #tracks_cls = np.array([tracks_cls]).T
       
        #conf_mask = (tracks_cls >= self.conf_thresh).reshape(-1)
        
        #tracks = tracks[conf_mask]
        #tracks_cls = tracks_cls[conf_mask]

        # print(f"Tracks: {tracks}")
        # print(f"Tracks Confindence: {tracks_cls}")

        # Convert to pose array
        dets_xy = np.array(list(track_dict.values()))
        dets_msg = detections_to_pose_array(dets_xy, dets_cls)
        dets_msg.header = msg.header
        self.dets_pub_.publish(dets_msg)

        # Convert to tracker message
        track_msg = dict_to_tracker(track_dict)
        track_msg.header = msg.header
        self.tracker_pub_.publish(track_msg)

        # Time until detection message is published
        # self.get_logger().info(f"End-to-end inference time: {time.time() - t}"

        # Convert to rviz markers
        rviz_msg = detections_to_rviz_marker(dets_xy, dets_cls)
        rviz_msg.header = msg.header
        self.rviz_pub_.publish(rviz_msg)

        # self.get_logger().info(f"Detections: {dets_msg}")


def compute_velocities(dets_xy):
    vels_xy = []
    for dets in dets_xy:
        vels_xy.append([])


def detections_to_pose_array(dets_xy, dets_cls):
    pose_array = PoseArray()
    for d_xy, d_cls in zip(dets_xy, dets_cls):
        # If the laser is facing front, DR-SPAAM's y-axis aligns with the laser center array,
        # x-axis points to the right and z-axis points upwards

        p = Pose()

        p.position.x = d_xy[0]
        p.position.y = d_xy[1]
        p.position.z = 0.0
        pose_array.poses.append(p)

    return pose_array


def detections_to_rviz_marker(dets_xy, dets_cls):
    """
    Convert detection to RViz marker msg. Each detection is marked as a circle approximated by line segments.
    """

    msg = Marker()
    msg.action = Marker.ADD
    msg.ns = "drspaam"
    msg.id = 0
    msg.type = Marker.LINE_LIST

    msg.scale.x = 0.03  # Line width
    # Red color
    msg.color.r = 1.0
    msg.color.a = 1.0

    # Circle
    r = 0.2
    ang = np.linspace(0, 2 * np.pi, 20)
    xy_offsets = r * np.stack((np.cos(ang), np.sin(ang)), axis=1)

    # To msg
    for d_xy, d_cls in zip(dets_xy, dets_cls):
        for i in range(len(xy_offsets) - 1):
            # print(f"The number it complains about: {i}")
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


def dict_to_tracker(tracker_dict):
    tracker = Tracker()
    pos = Point()
    for key in tracker_dict:
        # Save the IDs of the tracklets
        tracker.ids.append(int(key))

        # Save the tracked centroid
        pos.x = tracker_dict[key][0]
        pos.y = tracker_dict[key][1]
        tracker.positions.append(pos)

    return tracker


def main(args=None):
    rclpy.init(args=args)

    node = DrSpaamNode()

    # Make the node run continuously and the shut down
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
