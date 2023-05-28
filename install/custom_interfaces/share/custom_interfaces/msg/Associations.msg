# Message to publish the associated IDs and their respective positions 

std_msgs/Header header

int32[]                     yolo_ids             # Associated IDs from the YOLO tracker

int32[]                     drspaam_ids          # Associated IDs from the DR-SPAAM tracker

geometry_msgs/Point[]       yolo_positions       # Positions of the associated IDs of YOLO tracklets

geometry_msgs/Point[]       drspaam_positions    # Positions of the associated IDs of DR-SPAAM tracklets

# NOTE: The aboce poses are computed in the following manner: 
    #- Point.x: x-axis position
    #- Point.y: y-axis position
    #- Point.z: relative angle in the FOV of each sensor