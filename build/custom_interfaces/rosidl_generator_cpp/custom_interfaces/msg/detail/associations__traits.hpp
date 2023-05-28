// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Associations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/associations__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'yolo_positions'
// Member 'drspaam_positions'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Associations & msg,
  std::ostream & out)
{
  out << "{";
  // member: yolo_ids
  {
    if (msg.yolo_ids.size() == 0) {
      out << "yolo_ids: []";
    } else {
      out << "yolo_ids: [";
      size_t pending_items = msg.yolo_ids.size();
      for (auto item : msg.yolo_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: drspaam_ids
  {
    if (msg.drspaam_ids.size() == 0) {
      out << "drspaam_ids: []";
    } else {
      out << "drspaam_ids: [";
      size_t pending_items = msg.drspaam_ids.size();
      for (auto item : msg.drspaam_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: yolo_positions
  {
    if (msg.yolo_positions.size() == 0) {
      out << "yolo_positions: []";
    } else {
      out << "yolo_positions: [";
      size_t pending_items = msg.yolo_positions.size();
      for (auto item : msg.yolo_positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: drspaam_positions
  {
    if (msg.drspaam_positions.size() == 0) {
      out << "drspaam_positions: []";
    } else {
      out << "drspaam_positions: [";
      size_t pending_items = msg.drspaam_positions.size();
      for (auto item : msg.drspaam_positions) {
        to_flow_style_yaml(item, out);
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
  const Associations & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yolo_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.yolo_ids.size() == 0) {
      out << "yolo_ids: []\n";
    } else {
      out << "yolo_ids:\n";
      for (auto item : msg.yolo_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: drspaam_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.drspaam_ids.size() == 0) {
      out << "drspaam_ids: []\n";
    } else {
      out << "drspaam_ids:\n";
      for (auto item : msg.drspaam_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: yolo_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.yolo_positions.size() == 0) {
      out << "yolo_positions: []\n";
    } else {
      out << "yolo_positions:\n";
      for (auto item : msg.yolo_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: drspaam_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.drspaam_positions.size() == 0) {
      out << "drspaam_positions: []\n";
    } else {
      out << "drspaam_positions:\n";
      for (auto item : msg.drspaam_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Associations & msg, bool use_flow_style = false)
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
  const custom_interfaces::msg::Associations & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Associations & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Associations>()
{
  return "custom_interfaces::msg::Associations";
}

template<>
inline const char * name<custom_interfaces::msg::Associations>()
{
  return "custom_interfaces/msg/Associations";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Associations>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Associations>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Associations>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ASSOCIATIONS__TRAITS_HPP_
