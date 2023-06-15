// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_size
{
public:
  explicit Init_BoundingBox_size(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::BoundingBox size(::custom_interfaces::msg::BoundingBox::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_corner_pos
{
public:
  explicit Init_BoundingBox_corner_pos(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_size corner_pos(::custom_interfaces::msg::BoundingBox::_corner_pos_type arg)
  {
    msg_.corner_pos = std::move(arg);
    return Init_BoundingBox_size(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_ids
{
public:
  Init_BoundingBox_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_corner_pos ids(::custom_interfaces::msg::BoundingBox::_ids_type arg)
  {
    msg_.ids = std::move(arg);
    return Init_BoundingBox_corner_pos(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::BoundingBox>()
{
  return custom_interfaces::msg::builder::Init_BoundingBox_ids();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
