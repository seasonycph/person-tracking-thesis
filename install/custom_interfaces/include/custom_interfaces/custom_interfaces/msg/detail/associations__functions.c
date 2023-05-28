// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/associations__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `yolo_ids`
// Member `drspaam_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `yolo_positions`
// Member `drspaam_positions`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
custom_interfaces__msg__Associations__init(custom_interfaces__msg__Associations * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_interfaces__msg__Associations__fini(msg);
    return false;
  }
  // yolo_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->yolo_ids, 0)) {
    custom_interfaces__msg__Associations__fini(msg);
    return false;
  }
  // drspaam_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->drspaam_ids, 0)) {
    custom_interfaces__msg__Associations__fini(msg);
    return false;
  }
  // yolo_positions
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->yolo_positions, 0)) {
    custom_interfaces__msg__Associations__fini(msg);
    return false;
  }
  // drspaam_positions
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->drspaam_positions, 0)) {
    custom_interfaces__msg__Associations__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__Associations__fini(custom_interfaces__msg__Associations * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // yolo_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->yolo_ids);
  // drspaam_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->drspaam_ids);
  // yolo_positions
  geometry_msgs__msg__Point__Sequence__fini(&msg->yolo_positions);
  // drspaam_positions
  geometry_msgs__msg__Point__Sequence__fini(&msg->drspaam_positions);
}

bool
custom_interfaces__msg__Associations__are_equal(const custom_interfaces__msg__Associations * lhs, const custom_interfaces__msg__Associations * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // yolo_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->yolo_ids), &(rhs->yolo_ids)))
  {
    return false;
  }
  // drspaam_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->drspaam_ids), &(rhs->drspaam_ids)))
  {
    return false;
  }
  // yolo_positions
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->yolo_positions), &(rhs->yolo_positions)))
  {
    return false;
  }
  // drspaam_positions
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->drspaam_positions), &(rhs->drspaam_positions)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__Associations__copy(
  const custom_interfaces__msg__Associations * input,
  custom_interfaces__msg__Associations * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // yolo_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->yolo_ids), &(output->yolo_ids)))
  {
    return false;
  }
  // drspaam_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->drspaam_ids), &(output->drspaam_ids)))
  {
    return false;
  }
  // yolo_positions
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->yolo_positions), &(output->yolo_positions)))
  {
    return false;
  }
  // drspaam_positions
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->drspaam_positions), &(output->drspaam_positions)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__Associations *
custom_interfaces__msg__Associations__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Associations * msg = (custom_interfaces__msg__Associations *)allocator.allocate(sizeof(custom_interfaces__msg__Associations), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__Associations));
  bool success = custom_interfaces__msg__Associations__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__Associations__destroy(custom_interfaces__msg__Associations * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__Associations__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__Associations__Sequence__init(custom_interfaces__msg__Associations__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Associations * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__Associations *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__Associations), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__Associations__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__Associations__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__Associations__Sequence__fini(custom_interfaces__msg__Associations__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__Associations__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__Associations__Sequence *
custom_interfaces__msg__Associations__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Associations__Sequence * array = (custom_interfaces__msg__Associations__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__Associations__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__Associations__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__Associations__Sequence__destroy(custom_interfaces__msg__Associations__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__Associations__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__Associations__Sequence__are_equal(const custom_interfaces__msg__Associations__Sequence * lhs, const custom_interfaces__msg__Associations__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__Associations__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__Associations__Sequence__copy(
  const custom_interfaces__msg__Associations__Sequence * input,
  custom_interfaces__msg__Associations__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__Associations);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__Associations * data =
      (custom_interfaces__msg__Associations *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__Associations__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__Associations__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__Associations__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
