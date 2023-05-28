// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'yolo_positions'
// Member 'drspaam_positions'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Associations __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Associations __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Associations_
{
  using Type = Associations_<ContainerAllocator>;

  explicit Associations_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Associations_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _yolo_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _yolo_ids_type yolo_ids;
  using _drspaam_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _drspaam_ids_type drspaam_ids;
  using _yolo_positions_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _yolo_positions_type yolo_positions;
  using _drspaam_positions_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _drspaam_positions_type drspaam_positions;

  // setters for named parameter idiom
  Type & set__yolo_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->yolo_ids = _arg;
    return *this;
  }
  Type & set__drspaam_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->drspaam_ids = _arg;
    return *this;
  }
  Type & set__yolo_positions(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->yolo_positions = _arg;
    return *this;
  }
  Type & set__drspaam_positions(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->drspaam_positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Associations_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Associations_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Associations_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Associations_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Associations_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Associations_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Associations_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Associations_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Associations_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Associations_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Associations
    std::shared_ptr<custom_interfaces::msg::Associations_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Associations
    std::shared_ptr<custom_interfaces::msg::Associations_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Associations_ & other) const
  {
    if (this->yolo_ids != other.yolo_ids) {
      return false;
    }
    if (this->drspaam_ids != other.drspaam_ids) {
      return false;
    }
    if (this->yolo_positions != other.yolo_positions) {
      return false;
    }
    if (this->drspaam_positions != other.drspaam_positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const Associations_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Associations_

// alias to use template instance with default allocator
using Associations =
  custom_interfaces::msg::Associations_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__STRUCT_HPP_
