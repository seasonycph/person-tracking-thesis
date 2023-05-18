// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/PersonPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/person_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'keypoints'
// Member 'person_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PersonPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: keypoints
  {
    if (msg.keypoints.size() == 0) {
      out << "keypoints: []";
    } else {
      out << "keypoints: [";
      size_t pending_items = msg.keypoints.size();
      for (auto item : msg.keypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: kpt_conf
  {
    if (msg.kpt_conf.size() == 0) {
      out << "kpt_conf: []";
    } else {
      out << "kpt_conf: [";
      size_t pending_items = msg.kpt_conf.size();
      for (auto item : msg.kpt_conf) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: person_position
  {
    if (msg.person_position.size() == 0) {
      out << "person_position: []";
    } else {
      out << "person_position: [";
      size_t pending_items = msg.person_position.size();
      for (auto item : msg.person_position) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: looking
  {
    if (msg.looking.size() == 0) {
      out << "looking: []";
    } else {
      out << "looking: [";
      size_t pending_items = msg.looking.size();
      for (auto item : msg.looking) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PersonPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: keypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.keypoints.size() == 0) {
      out << "keypoints: []\n";
    } else {
      out << "keypoints:\n";
      for (auto item : msg.keypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: kpt_conf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kpt_conf.size() == 0) {
      out << "kpt_conf: []\n";
    } else {
      out << "kpt_conf:\n";
      for (auto item : msg.kpt_conf) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: person_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.person_position.size() == 0) {
      out << "person_position: []\n";
    } else {
      out << "person_position:\n";
      for (auto item : msg.person_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: looking
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.looking.size() == 0) {
      out << "looking: []\n";
    } else {
      out << "looking:\n";
      for (auto item : msg.looking) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PersonPose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::PersonPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::PersonPose & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::PersonPose>()
{
  return "custom_interfaces::msg::PersonPose";
}

template<>
inline const char * name<custom_interfaces::msg::PersonPose>()
{
  return "custom_interfaces/msg/PersonPose";
}

template<>
struct has_fixed_size<custom_interfaces::msg::PersonPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::PersonPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::PersonPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__PERSON_POSE__TRAITS_HPP_
