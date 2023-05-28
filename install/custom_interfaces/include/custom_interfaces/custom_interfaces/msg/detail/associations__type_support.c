// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/associations__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/associations__functions.h"
#include "custom_interfaces/msg/detail/associations__struct.h"


// Include directives for member types
// Member `yolo_ids`
// Member `drspaam_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `yolo_positions`
// Member `drspaam_positions`
#include "geometry_msgs/msg/point.h"
// Member `yolo_positions`
// Member `drspaam_positions`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__Associations__init(message_memory);
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_fini_function(void * message_memory)
{
  custom_interfaces__msg__Associations__fini(message_memory);
}

size_t custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__yolo_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__yolo_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__yolo_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__yolo_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__drspaam_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__drspaam_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__drspaam_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__drspaam_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__yolo_positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__yolo_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__yolo_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__yolo_positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__drspaam_positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__drspaam_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__drspaam_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__drspaam_positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_member_array[4] = {
  {
    "yolo_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Associations, yolo_ids),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__yolo_ids,  // size() function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_ids,  // get_const(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_ids,  // get(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__yolo_ids,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__yolo_ids,  // assign(index, value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__yolo_ids  // resize(index) function pointer
  },
  {
    "drspaam_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Associations, drspaam_ids),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__drspaam_ids,  // size() function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_ids,  // get_const(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_ids,  // get(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__drspaam_ids,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__drspaam_ids,  // assign(index, value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__drspaam_ids  // resize(index) function pointer
  },
  {
    "yolo_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Associations, yolo_positions),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__yolo_positions,  // size() function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__yolo_positions,  // get_const(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__yolo_positions,  // get(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__yolo_positions,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__yolo_positions,  // assign(index, value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__yolo_positions  // resize(index) function pointer
  },
  {
    "drspaam_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Associations, drspaam_positions),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__size_function__Associations__drspaam_positions,  // size() function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_const_function__Associations__drspaam_positions,  // get_const(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__get_function__Associations__drspaam_positions,  // get(index) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__fetch_function__Associations__drspaam_positions,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__assign_function__Associations__drspaam_positions,  // assign(index, value) function pointer
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__resize_function__Associations__drspaam_positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_members = {
  "custom_interfaces__msg",  // message namespace
  "Associations",  // message name
  4,  // number of fields
  sizeof(custom_interfaces__msg__Associations),
  custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_member_array,  // message members
  custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_type_support_handle = {
  0,
  &custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, Associations)() {
  custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__Associations__rosidl_typesupport_introspection_c__Associations_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
