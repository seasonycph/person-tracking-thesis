"""
Centroid tracker in python
"""

from scipy.spatial import distance as dist
from collections import OrderedDict
import numpy as np

class CentroidTracker():
    def __init__(self, maxDisappeared=50) -> None:
        # Initialize the next object ID along with two ordered dictionaries
        # used to keep track of mapping a given object IF
        # to its centroid and number of consecutive frames it has been marked as "disappeared"

        self.nextObjectID = 0
        self.objects = OrderedDict()
        self.bounding_boxes = OrderedDict()
        self.disappeared = OrderedDict()

        # Store the num. of maximim consecutive scans an object is allowed to be marked as 
        # "disappeared" until we need to deregister the object from tracking
        self.maxDisappeared = maxDisappeared
    
    def register(self, centroid, box):
        # When registering an object we use the next available object
        # ID t ostore the centroid
        self.objects[self.nextObjectID] = centroid

        # ID to store the bounding ox
        self.bounding_boxes[self.nextObjectID] = box

        # Initialize object's disappearence to 0
        self.disappeared[self.nextObjectID] = 0

        # Increse object counter
        self.nextObjectID += 1
    
    def deregister(self, objectID):
        # Delete object from both of respective dictionaries
        del self.objects[objectID]
        del self.disappeared[objectID]
        del self.bounding_boxes[objectID]

    def update(self, rects, boxes):
        # If there are no inputs and no objects, just return
        if len(rects) == 0 and len(self.objects) == 0:
            return self.objects, self.bounding_boxes

        # Check to see if the list of poses is empty
        if len(rects) == 0:
            # Mark existing objects as disappeared
            for objectID in list(self.disappeared.keys()):
                self.disappeared[objectID] += 1
            
            # Deregister the objects that reached the maximum of allowed frames
            if self.disappeared[objectID] > self.maxDisappeared:
                self.deregister(objectID)
        
            return self.objects, self.bounding_boxes

        # Initialize an array of input centroids for the current frame
        inputCentroids = np.zeros((len(rects), 2), dtype="float64")

        # Loop over the recieved poses
        for i, pose in enumerate(rects):
            inputCentroids[i] = (pose[0], pose[1])
        
        inputCentroids = inputCentroids.tolist()
        
        # If no objects are being tracked take the input centroids
        # and register them
        if len(self.objects) == 0:
            for i in range(0, len(inputCentroids)):
                self.register(inputCentroids[i], boxes[i])
        
         # Otherwise we need to match the input 
         # centroids with the ones we are tracking 
        else:
            # Cehck if the new inputs are not already in the objects
            # inputCentroids_copy = inputCentroids.copy()
            # matched_centroids = []

            # for centroid in inputCentroids_copy:
            #     # Convert the centroid list to a tuple
            #     centroid_tuple = tuple(centroid)
            #     # Check if the centroid exists in the objects dictionary
            #     if centroid_tuple in [tuple(v) for v in self.objects.values()]:
            #         # Find tje object with the same centroid
            #         existing_object_id = None
            #         for object_id, object_centroid in self.objects.items():
            #             if tuple(object_centroid) == centroid_tuple:
            #                 existing_object_id = object_id
            #                 break
                    
            #         # Merge the objects by keeping the lowest ID and updating the centroid
            #         if existing_object_id is not None:
            #             min_object_id = min(existing_object_id, self.nextObjectID - 1)
            #             self.objects[min_object_id] = centroid
            #             self.disappeared[min_object_id] = 0

            #             # Remoce the merged object with the higher ID
            #             if existing_object_id != min_object_id:
            #                 del self.objects[existing_object_id]
            #                 del self.disappeared[existing_object_id]
                        
            #             matched_centroids.append(centroid)

            #         # Remove the centroid from inputCentroids
            #         for centroid in matched_centroids:
            #             inputCentroids.remove(centroid)

            objectIDs = list(self.objects.keys())
            objectCentroids = list(self.objects.values())
        
            # Compute the Euclidean distance between each pair of centroids
            D = dist.cdist(np.array(objectCentroids), np.array(inputCentroids))

            # For the matching:
            #   1. Find smallest value in each row.
            #   2. Sort row indeces based on their minimum
            #   values so that the row with smalles values 
            #   is the "front" of the index.
            rows = D.min(axis=1).argsort()

            # Perform similar process on the columns
            # Sort using the previously computed row index list
            cols = D.argmin(axis=1)[rows]

            # Keep track of which of the rows and columns indeces we have examined
            usedRows = set()
            usedCols = set()

            # Loop over the combination of the (row, col) index tuples
            for (row, col) in zip(rows, cols):
                # Check if col or row have already been examined
                if row in usedRows or col in usedCols:
                    continue

                # Grab object ID for current row, set its new centroid and
                # reset the disappeared counter
                #print(f"Input centroids: {inputCentroids}")
                #print(f"Input boxes: {boxes}")
                objectID = objectIDs[row]
                self.objects[objectID] = inputCentroids[col]
                self.bounding_boxes[objectID] = boxes[col]
                self.disappeared[objectID] = 0

                # Check the column and the row as used
                usedRows.add(row)
                usedCols.add(col)

                # Compute the rows and cols that have not been used
                unusedRows = set(range(0, D.shape[0])).difference(usedRows)
                unusedCols = set(range(0, D.shape[1])).difference(usedCols)

                # If there are more objects than input centroids, check if any has disappeared
                if D.shape[0] >= D.shape[1]:
                    for row in unusedRows:
                        # print(objectIDs[row])
                        # print(self.disappeared)
                        if objectIDs[row] not in self.disappeared:
                            continue

                        # Increase object's disappeared counter
                        objectID = objectIDs[row]
                        self.disappeared[objectID] += 1

                        # Check if object should be thrown away
                        if self.disappeared[objectID] > self.maxDisappeared:
                            self.deregister(objectID)
                else:
                    # If there are more inputs, register the new object
                    for col in unusedCols:
                        self.register(inputCentroids[col], boxes[col])
                
                

        return self.objects, self.bounding_boxes





        





