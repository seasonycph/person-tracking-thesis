# Message to save the keypoints, the confidences and other info. 
#about the pose of a person

std_msgs/Header header

geometry_msgs/Point[]   keypoints        # Positions of the keypoints in the same order than in YOLO-Pose

float32[]               kpt_conf         # Confidences of each keypoints

geometry_msgs/Point[]   person_position  # Position of the person in the image

bool[]                  looking          # Flag to asses whether the person is looking at the robot or not 