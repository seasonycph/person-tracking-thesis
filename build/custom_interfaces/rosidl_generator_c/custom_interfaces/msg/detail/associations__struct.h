// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'yolo_ids'
// Member 'drspaam_ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'yolo_positions'
// Member 'drspaam_positions'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Associations in the package custom_interfaces.
/**
  * Message to publish the associated IDs and their respective positions 
 */
typedef struct custom_interfaces__msg__Associations
{
  /// Associated IDs from the YOLO tracker
  rosidl_runtime_c__int32__Sequence yolo_ids;
  /// Associated IDs from the DR-SPAAM tracker
  rosidl_runtime_c__int32__Sequence drspaam_ids;
  /// Positions of the associated IDs of YOLO tracklets
  geometry_msgs__msg__Point__Sequence yolo_positions;
  ///  Positions of the associated IDs of DR-SPAAM tracklets
  /// - Point.x: x-axis position
  /// - Point.y: y-axis position
  /// - Point.z: relative angle in the FOV of each sensor
  geometry_msgs__msg__Point__Sequence drspaam_positions;
} custom_interfaces__msg__Associations;

// Struct for a sequence of custom_interfaces__msg__Associations.
typedef struct custom_interfaces__msg__Associations__Sequence
{
  custom_interfaces__msg__Associations * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Associations__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_H_
