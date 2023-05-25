// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Tracker.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/tracker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Tracker_positions
{
public:
  explicit Init_Tracker_positions(::custom_interfaces::msg::Tracker & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Tracker positions(::custom_interfaces::msg::Tracker::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Tracker msg_;
};

class Init_Tracker_ids
{
public:
  explicit Init_Tracker_ids(::custom_interfaces::msg::Tracker & msg)
  : msg_(msg)
  {}
  Init_Tracker_positions ids(::custom_interfaces::msg::Tracker::_ids_type arg)
  {
    msg_.ids = std::move(arg);
    return Init_Tracker_positions(msg_);
  }

private:
  ::custom_interfaces::msg::Tracker msg_;
};

class Init_Tracker_header
{
public:
  Init_Tracker_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_ids header(::custom_interfaces::msg::Tracker::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Tracker_ids(msg_);
  }

private:
  ::custom_interfaces::msg::Tracker msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Tracker>()
{
  return custom_interfaces::msg::builder::Init_Tracker_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TRACKER__BUILDER_HPP_
