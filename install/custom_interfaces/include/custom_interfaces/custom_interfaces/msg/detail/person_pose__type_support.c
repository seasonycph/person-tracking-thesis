// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/PersonPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/person_pose__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/person_pose__functions.h"
#include "custom_interfaces/msg/detail/person_pose__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `keypoints`
// Member `person_position`
#include "geometry_msgs/msg/point.h"
// Member `keypoints`
// Member `person_position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `kpt_conf`
// Member `looking`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__PersonPose__init(message_memory);
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_fini_function(void * message_memory)
{
  custom_interfaces__msg__PersonPose__fini(message_memory);
}

size_t custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__keypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__keypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__keypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__keypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__keypoints(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__keypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__keypoints(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__keypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__kpt_conf(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__kpt_conf(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__kpt_conf(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__kpt_conf(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__kpt_conf(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__kpt_conf(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__kpt_conf(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__kpt_conf(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__person_position(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__person_position(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__person_position(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__person_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__person_position(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__person_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__person_position(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__person_position(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__looking(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__looking(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__looking(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__looking(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__looking(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__looking(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__looking(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__looking(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__PersonPose, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "keypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__PersonPose, keypoints),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__keypoints,  // size() function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__keypoints,  // get_const(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__keypoints,  // get(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__keypoints,  // fetch(index, &value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__keypoints,  // assign(index, value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__keypoints  // resize(index) function pointer
  },
  {
    "kpt_conf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__PersonPose, kpt_conf),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__kpt_conf,  // size() function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__kpt_conf,  // get_const(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__kpt_conf,  // get(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__kpt_conf,  // fetch(index, &value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__kpt_conf,  // assign(index, value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__kpt_conf  // resize(index) function pointer
  },
  {
    "person_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__PersonPose, person_position),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__person_position,  // size() function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__person_position,  // get_const(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__person_position,  // get(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__person_position,  // fetch(index, &value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__person_position,  // assign(index, value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__person_position  // resize(index) function pointer
  },
  {
    "looking",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__PersonPose, looking),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__size_function__PersonPose__looking,  // size() function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_const_function__PersonPose__looking,  // get_const(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__get_function__PersonPose__looking,  // get(index) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__fetch_function__PersonPose__looking,  // fetch(index, &value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__assign_function__PersonPose__looking,  // assign(index, value) function pointer
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__resize_function__PersonPose__looking  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_members = {
  "custom_interfaces__msg",  // message namespace
  "PersonPose",  // message name
  5,  // number of fields
  sizeof(custom_interfaces__msg__PersonPose),
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_member_array,  // message members
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_type_support_handle = {
  0,
  &custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, PersonPose)() {
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__PersonPose__rosidl_typesupport_introspection_c__PersonPose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
