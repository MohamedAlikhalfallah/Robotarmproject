// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__TRAITS_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'name'
#include "std_msgs/msg/detail/string__traits.hpp"
// Member 'bounding_box'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace scene_graph_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FunObject3DBoundingBox & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    to_flow_style_yaml(msg.name, out);
    out << ", ";
  }

  // member: bounding_box
  {
    if (msg.bounding_box.size() == 0) {
      out << "bounding_box: []";
    } else {
      out << "bounding_box: [";
      size_t pending_items = msg.bounding_box.size();
      for (auto item : msg.bounding_box) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: graspable
  {
    out << "graspable: ";
    rosidl_generator_traits::value_to_yaml(msg.graspable, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FunObject3DBoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name:\n";
    to_block_style_yaml(msg.name, out, indentation + 2);
  }

  // member: bounding_box
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bounding_box.size() == 0) {
      out << "bounding_box: []\n";
    } else {
      out << "bounding_box:\n";
      for (auto item : msg.bounding_box) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: graspable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "graspable: ";
    rosidl_generator_traits::value_to_yaml(msg.graspable, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FunObject3DBoundingBox & msg, bool use_flow_style = false)
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

}  // namespace scene_graph_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use scene_graph_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scene_graph_interfaces::msg::FunObject3DBoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  scene_graph_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scene_graph_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const scene_graph_interfaces::msg::FunObject3DBoundingBox & msg)
{
  return scene_graph_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scene_graph_interfaces::msg::FunObject3DBoundingBox>()
{
  return "scene_graph_interfaces::msg::FunObject3DBoundingBox";
}

template<>
inline const char * name<scene_graph_interfaces::msg::FunObject3DBoundingBox>()
{
  return "scene_graph_interfaces/msg/FunObject3DBoundingBox";
}

template<>
struct has_fixed_size<scene_graph_interfaces::msg::FunObject3DBoundingBox>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<scene_graph_interfaces::msg::FunObject3DBoundingBox>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<scene_graph_interfaces::msg::FunObject3DBoundingBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__TRAITS_HPP_
