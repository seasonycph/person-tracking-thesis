// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/PersonPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/person_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_PersonPose_looking
{
public:
  explicit Init_PersonPose_looking(::custom_interfaces::msg::PersonPose & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::PersonPose looking(::custom_interfaces::msg::PersonPose::_looking_type arg)
  {
    msg_.looking = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::PersonPose msg_;
};

class Init_PersonPose_person_position
{
public:
  explicit Init_PersonPose_person_position(::custom_interfaces::msg::PersonPose & msg)
  : msg_(msg)
  {}
  Init_PersonPose_looking person_position(::custom_interfaces::msg::PersonPose::_person_position_type arg)
  {
    msg_.person_position = std::move(arg);
    return Init_PersonPose_looking(msg_);
  }

private:
  ::custom_interfaces::msg::PersonPose msg_;
};

class Init_PersonPose_kpt_conf
{
public:
  explicit Init_PersonPose_kpt_conf(::custom_interfaces::msg::PersonPose & msg)
  : msg_(msg)
  {}
  Init_PersonPose_person_position kpt_conf(::custom_interfaces::msg::PersonPose::_kpt_conf_type arg)
  {
    msg_.kpt_conf = std::move(arg);
    return Init_PersonPose_person_position(msg_);
  }

private:
  ::custom_interfaces::msg::PersonPose msg_;
};

class Init_PersonPose_keypoints
{
public:
  explicit Init_PersonPose_keypoints(::custom_interfaces::msg::PersonPose & msg)
  : msg_(msg)
  {}
  Init_PersonPose_kpt_conf keypoints(::custom_interfaces::msg::PersonPose::_keypoints_type arg)
  {
    msg_.keypoints = std::move(arg);
    return Init_PersonPose_kpt_conf(msg_);
  }

private:
  ::custom_interfaces::msg::PersonPose msg_;
};

class Init_PersonPose_header
{
public:
  Init_PersonPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PersonPose_keypoints header(::custom_interfaces::msg::PersonPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PersonPose_keypoints(msg_);
  }

private:
  ::custom_interfaces::msg::PersonPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::PersonPose>()
{
  return custom_interfaces::msg::builder::Init_PersonPose_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__BUILDER_HPP_
