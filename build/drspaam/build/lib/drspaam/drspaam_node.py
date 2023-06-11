#!/usr/bin/env python3

import numpy as np
import time
import rclpy
import torch
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Point, Pose, PoseArray
from custom_interfaces.msg import Tracker, Associations
from visualization_msgs.msg import Marker, MarkerArray
from collections import OrderedDict

from dr_spaam.detector import Detector, _TrackingExtension
from .centroid_tracker.centroidtracker import CentroidTracker


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
            tracking=False)

        # Initialize tracker
        self.centroid_tracker_ = CentroidTracker(maxDisappeared=25)

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
        self.conf_thresh = 0.75

    def init_communication(self):
        """
        Initialize ROS connection
        """
        # Publisher
        topic = "/dr_spaam/detections"
        self.dets_pub_ = self.create_publisher(
            PoseArray, topic, qos_profile=10)

        topic = "/dr_spaam/detections_rviz"
        self.det_rviz_pub_ = self.create_publisher(
            Marker, topic, qos_profile=10)

        topic = "/dr_spaam/tracker"
        self.tracker_pub_ = self.create_publisher(
            Tracker, topic, qos_profile=10)

        topic = "/dr_spaam/tracker_rviz"
        self.tracker_rviz_pub_ = self.create_publisher(
            Marker, topic, qos_profile=10)

        topic = "/dr_spaam/tracker_id_rviz"
        self.tracker_id_tviz_pub_ = self.create_publisher(
            MarkerArray, topic, qos_profile=10)

        # Subscriber
        topic = "/tracker/associations"
        self.associations_sub_ = self.create_subscription(
            Associations, topic, self.callback_associations, qos_profile=10)

        topic = "/lewis_b1/scan_front"
        self.scan_sub_ = self.create_subscription(
            LaserScan, topic, self.callback_scan_front, qos_profile=10)

    def callback_associations(self, msg):
        # Save the message into a class attribute to use it in the scanner callback
        self.associations_msg = msg

        # Function called from this callback because from the scan it does not work
        # self.associations_to_rviz_marker()

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
        #t = time.time()
        dets_xy, dets_cls, _ = self._detector(scan)

        # Confidence threshold
        conf_mask = (dets_cls >= self.conf_thresh).reshape(-1)

        # Apply the confidence mask
        dets_xy = dets_xy[conf_mask]
        dets_cls = dets_cls[conf_mask]

        # Track the detected objects
        track_dict, prediction_dict = self.centroid_tracker_.update(dets_xy)
        self.predictions = process_predictions(prediction_dict)
        self.tracker = track_dict

        # Convert to tracker message
        track_msg = dict_to_tracker(self.predictions)  # (track_dict)
        track_msg.header = msg.header
        self.tracker_pub_.publish(track_msg)

        # Convert to pose array
        dets_xy = np.array(list(track_dict.values()))
        dets_msg = detections_to_pose_array(dets_xy, dets_cls)
        dets_msg.header = msg.header
        self.dets_pub_.publish(dets_msg)

        # Convert the detections to rviz markers
        dets_xy = np.array(list(track_dict.values()))
        det_rviz_msg = detections_to_circle_rviz_marker(
            dets_xy, self.det_rviz_pub_.topic)
        det_rviz_msg.header = msg.header
        self.det_rviz_pub_.publish(det_rviz_msg)

        # Convert the predictions to rviz markers
        preds_xy = np.array(list(self.predictions.values()))
        pred_rviz_msg = detections_to_square_rviz_marker(
            preds_xy, self.tracker_rviz_pub_.topic)
        pred_rviz_msg.header = msg.header
        self.tracker_rviz_pub_.publish(pred_rviz_msg)

        # Print the ids in rviz
        tracker_ids_msg = print_id_rviz(msg.header,
            self.predictions.keys(), preds_xy, self.tracker_id_tviz_pub_.topic)
        self.tracker_id_tviz_pub_.publish(tracker_ids_msg)

        # Time until detection message is published
        #self.get_logger().info(f"End-to-end inference time: {time.time() - t}")

    def associations_to_rviz_marker(self):
        # We will use the associations only to draw the rviz tracklets

        # Extract the dr-spaam detections from the association message
        dets_xy = []
        for pose in self.associations_msg.drspaam_positions:
            dets_xy.append([pose.x, pose.y])

        # Convert the detections into rviz message
        rviz_msg = detections_to_circle_rviz_marker(dets_xy)
        rviz_msg.header = self.associations_msg.header
        self.rviz_pub_.publish(rviz_msg)


def process_predictions(prediction_dict):
    predictions = OrderedDict()

    for key, pred_obj in prediction_dict.items():
        predictions[key] = [pred_obj.state[0].item(), pred_obj.state[2].item()]

    return predictions


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


def detections_to_circle_rviz_marker(dets_xy, topic):
    """
    Convert detection to RViz marker msg. Each detection is marked as a circle approximated by line segments.
    """

    msg = Marker()
    msg.action = Marker.ADD
    msg.ns = topic
    msg.id = 0
    msg.type = Marker.LINE_LIST

    msg.scale.x = 0.03  # Line width
    # Red color
    msg.color.r = 1.0
    msg.color.a = 1.0

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


def detections_to_square_rviz_marker(preds_xy, topic):
    """
    Convert predicitons to RViz marker msg. Each prediciton is marked as a circle approximated by line segments.
    """
    pred_marker = MarkerArray()

    # Square marker
    square = Marker()
    square.action = Marker.ADD
    square.ns = topic
    square.id = 0
    square.type = Marker.LINE_LIST

    square.scale.x = 0.03
    # Color red
    square.color.r = 1.0
    square.color.a = 1.0

    # Square
    a = 0.6  # Square's side

    for pred in preds_xy:
        for i in range(4):
            match i:
                case 0:
                    # Start point of segment
                    p0 = Point()
                    p0.x = pred[1] - a / 2
                    p0.y = pred[0] + a / 2
                    p0.z = 0.0
                    square.points.append(p0)

                    # End point
                    p1 = Point()
                    p1.x = pred[1] + a / 2
                    p1.y = pred[0] + a / 2
                    square.points.append(p1)
                case 1:
                    # Start point of segment
                    p0 = Point()
                    p0.x = pred[1] + a / 2
                    p0.y = pred[0] + a / 2
                    p0.z = 0.0
                    square.points.append(p0)

                    # End point
                    p1 = Point()
                    p1.x = pred[1] + a / 2
                    p1.y = pred[0] - a / 2
                    square.points.append(p1)
                case 2:
                    # Start point of segment
                    p0 = Point()
                    p0.x = pred[1] + a / 2
                    p0.y = pred[0] - a / 2
                    p0.z = 0.0
                    square.points.append(p0)

                    # End point
                    p1 = Point()
                    p1.x = pred[1] - a / 2
                    p1.y = pred[0] - a / 2
                    square.points.append(p1)
                case 3:
                    # Start point of segment
                    p0 = Point()
                    p0.x = pred[1] - a / 2
                    p0.y = pred[0] - a / 2
                    p0.z = 0.0
                    square.points.append(p0)

                    # End point
                    p1 = Point()
                    p1.x = pred[1] - a / 2
                    p1.y = pred[0] + a / 2
                    square.points.append(p1)

    return square


def print_id_rviz(header, ids, preds_xy, topic):
    """
    Send the ids of the DR-SPAAM tracklets.
    """

    # Text marker
    id_msg = MarkerArray()
    id_msg.markers.clear()

    # Length of a square's side
    a = 0.6

    # Set the id and position (left top corner)
    for id, pos in zip(ids, preds_xy):
        id_marker = Marker()
        id_marker.header = header
        id_marker.action = Marker.ADD
        id_marker.ns = topic
        id_marker.id = 0
        id_marker.type = Marker.TEXT_VIEW_FACING

        id_marker.pose.orientation.w = 1.0
        id_marker.scale.z = 0.2

        # Color: Black and opaque
        id_marker.color.a = 1.0
        id_marker.text = f"ID:{str(id)}"
        id_marker.pose.position.x = pos[1] - a / 2
        id_marker.pose.position.y = pos[0] + a / 2

        # Add the text marker to the array
        id_msg.markers.append(id_marker)

    return id_msg


def dict_to_tracker(tracker_dict):
    tracker = Tracker()

    for key, pose in tracker_dict.items():
        # Save the IDs of the tracklets
        tracker.ids.append(int(key))
        # Save the tracked centroid
        pos = Point()
        pos.x = pose[0]
        pos.y = pose[1]
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
