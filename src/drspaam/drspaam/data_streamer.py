#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from custom_interfaces.msg import Tracker
from std_msgs.msg import Header

import numpy as np
import time
import sys


class DataStreamerNode(Node):
    def __init__(self):
        super().__init__("data_streamer")

        # Read the parameters of the streamer
        self.read_params()

        # Info on initialized node
        self.get_logger().info("Data streamer node initialized.")
        self.get_logger().info(f"Running test for {self.test_type} with test case {self.test_case}")

        # Initialize the communications
        self.init_communications()

    def read_params(self):
        # File name for generalization
        self.test_type = "static_robot"
        file_name = f"{self.test_type}_data"

        # Name of the file from which read the data
        self.data_file = f"/media/taras/5038-A14F/dataset_lidar/gt/selected/{self.test_type}/{file_name}.csv"

        # Calculate the number of lines in the file and save the scans
        self.seq_len = 0
        self.scans = []
        with open(self.data_file, "r") as file:
            for line in file:
                self.seq_len += 1
                self.scans.append(list(map(float, line.split(','))))

        # Calculate the angle increment
        self.angle_increment = np.deg2rad(225 / len(self.scans[0][2:])) # 225 degrees is the range of the laser used in the model 

        # Time increment
        self.scan_time = self.scans[0][1] - self.scans[1][1]

        # Scan number
        self.scan_num = 0

        # Test case
        self.test_case = "9"
        
        # File to which write the results
        self.result_file = open(f"/media/taras/5038-A14F/dataset_lidar/tracker/{self.test_type}/{self.test_case}/{file_name}_result.txt", "+w")


    def init_communications(self):
        """
        Initialize communications with DR-SPAAM node
        """

        # Publisher
        topic = "/data_streamer/laser_scan"
        self.scan_pub_ = self.create_publisher(
            LaserScan, topic, qos_profile=10)
        self.timer_ = self.create_timer(
            timer_period_sec=0.07, callback=self.publish_scan)

        # Subscriber
        topic = "/dr_spaam/tracker"
        self.tracker_sub_ = self.create_subscription(
            Tracker, topic, self.callback_tracker, qos_profile=10)

    def publish_scan(self):
        """
        Pubish the message from the test file
        """
        #t = time.time()

        # Increment san number
        if self.scan_num == self.seq_len:
            self.get_logger().info("Sequence finalized!")
            sys.exit()
        else:
            self.scan_num += 1

        # Create the header of the message
        msg_header = Header()
        # Timestamp
        msg_header.stamp = self.get_clock().now().to_msg()
        # Frame id -> Scan id
        msg_header.frame_id = str(self.scans[self.scan_num - 1][0])

        # Take a scan variable
        scan = self.scans[self.scan_num - 1][2:]

        # Laser scanner message 
        laser_msg = LaserScan()

        # Header
        laser_msg.header = msg_header

        # Angles info
        laser_msg.angle_min = 0.0
        laser_msg.angle_max = np.deg2rad(225)
        laser_msg.angle_increment = self.angle_increment

        # Scan time
        laser_msg.scan_time = self.scan_time

        # Max and min ranges
        laser_msg.range_max = float(max(scan))
        laser_msg.range_min = float(min(scan))

        # Ranges
        laser_msg.ranges = scan

        # Publish the message
        self.scan_pub_.publish(laser_msg)

        self.get_logger().info(f"Published scan {self.scan_num}")

        #print(f"Publication time: {time.time() - t}")



    def callback_tracker(self, msg):
        """
        Print the results of the detections into a file
        """
        self.get_logger().info(f"Recieved tracker message from frame {msg.header.frame_id}")

        # Write the results in the file
        ids = []
        positions = [] 
        for i, id in enumerate(msg.ids):
            # IDs
            ids.append(id)

            # Positions
            x = (msg.positions[i].x)
            y = (msg.positions[i].y)
            positions.append([x, y])

        # Result line for each scan
        result = msg.header.frame_id.split('.')[0] + ',' + str(ids) + ',' + str(positions) + '\n'

        self.result_file.write(result)



def main(args=None):
    rclpy.init(args=args)
    node = DataStreamerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
