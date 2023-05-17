// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/PersonPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__STRUCT_H_

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
// Member 'keypoints'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'kpt_conf'
// Member 'looking'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PersonPose in the package custom_interfaces.
/**
  *  Message to save the keypoints, the confidences and other info. 
  * about the pose of a person
 */
typedef struct custom_interfaces__msg__PersonPose
{
  std_msgs__msg__Header header;
  /// Positions of the keypoints in the same order than in YOLO-Pose
  geometry_msgs__msg__Point__Sequence keypoints;
  /// Confidences of each keypoints
  rosidl_runtime_c__float__Sequence kpt_conf;
  /// Flag to asses whether the person is looking at the robot or not
  rosidl_runtime_c__boolean__Sequence looking;
} custom_interfaces__msg__PersonPose;

// Struct for a sequence of custom_interfaces__msg__PersonPose.
typedef struct custom_interfaces__msg__PersonPose__Sequence
{
  custom_interfaces__msg__PersonPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__PersonPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__STRUCT_H_
