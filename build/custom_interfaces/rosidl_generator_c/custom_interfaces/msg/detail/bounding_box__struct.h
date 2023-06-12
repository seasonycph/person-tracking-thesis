// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'coner_pos'
// Member 'size'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/BoundingBox in the package custom_interfaces.
/**
  * Message to save the bounding box {x_top, y_left, w, h} along with the ids
 */
typedef struct custom_interfaces__msg__BoundingBox
{
  /// IDS of the detected objects
  rosidl_runtime_c__int32__Sequence ids;
  /// Postions of the top left corner
  geometry_msgs__msg__Point__Sequence coner_pos;
  /// Width and heigh of the bounding box, saved in the x and y fields respectivelly
  geometry_msgs__msg__Point__Sequence size;
} custom_interfaces__msg__BoundingBox;

// Struct for a sequence of custom_interfaces__msg__BoundingBox.
typedef struct custom_interfaces__msg__BoundingBox__Sequence
{
  custom_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
