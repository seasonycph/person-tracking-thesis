// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/associations__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Associations_drspaam_positions
{
public:
  explicit Init_Associations_drspaam_positions(::custom_interfaces::msg::Associations & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Associations drspaam_positions(::custom_interfaces::msg::Associations::_drspaam_positions_type arg)
  {
    msg_.drspaam_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Associations msg_;
};

class Init_Associations_yolo_positions
{
public:
  explicit Init_Associations_yolo_positions(::custom_interfaces::msg::Associations & msg)
  : msg_(msg)
  {}
  Init_Associations_drspaam_positions yolo_positions(::custom_interfaces::msg::Associations::_yolo_positions_type arg)
  {
    msg_.yolo_positions = std::move(arg);
    return Init_Associations_drspaam_positions(msg_);
  }

private:
  ::custom_interfaces::msg::Associations msg_;
};

class Init_Associations_drspaam_ids
{
public:
  explicit Init_Associations_drspaam_ids(::custom_interfaces::msg::Associations & msg)
  : msg_(msg)
  {}
  Init_Associations_yolo_positions drspaam_ids(::custom_interfaces::msg::Associations::_drspaam_ids_type arg)
  {
    msg_.drspaam_ids = std::move(arg);
    return Init_Associations_yolo_positions(msg_);
  }

private:
  ::custom_interfaces::msg::Associations msg_;
};

class Init_Associations_yolo_ids
{
public:
  explicit Init_Associations_yolo_ids(::custom_interfaces::msg::Associations & msg)
  : msg_(msg)
  {}
  Init_Associations_drspaam_ids yolo_ids(::custom_interfaces::msg::Associations::_yolo_ids_type arg)
  {
    msg_.yolo_ids = std::move(arg);
    return Init_Associations_drspaam_ids(msg_);
  }

private:
  ::custom_interfaces::msg::Associations msg_;
};

class Init_Associations_header
{
public:
  Init_Associations_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Associations_yolo_ids header(::custom_interfaces::msg::Associations::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Associations_yolo_ids(msg_);
  }

private:
  ::custom_interfaces::msg::Associations msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Associations>()
{
  return custom_interfaces::msg::builder::Init_Associations_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__BUILDER_HPP_
