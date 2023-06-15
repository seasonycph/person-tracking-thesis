# Message to save the bounding box {x_top, y_left, w, h} along with the ids

int32[]                 ids              # IDS of the detected objects

geometry_msgs/Point[]   corner_pos        # Postions of the top left corner

geometry_msgs/Point[]   size             # Width and heigh of the bounding box, saved in the x and y fields respectivelly