// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Tracker.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'positions'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Tracker in the package custom_interfaces.
/**
  * Message to register the tracklets with their ID and position
 */
typedef struct custom_interfaces__msg__Tracker
{
  std_msgs__msg__Header header;
  /// IDS of the detected objects
  rosidl_runtime_c__int32__Sequence ids;
  /// Positions of the keypoints in the same order than in YOLO-Pose
  geometry_msgs__msg__Point__Sequence positions;
} custom_interfaces__msg__Tracker;

// Struct for a sequence of custom_interfaces__msg__Tracker.
typedef struct custom_interfaces__msg__Tracker__Sequence
{
  custom_interfaces__msg__Tracker * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Tracker__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__STRUCT_H_
