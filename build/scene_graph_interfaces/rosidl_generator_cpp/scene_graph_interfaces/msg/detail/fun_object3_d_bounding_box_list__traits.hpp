// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__TRAITS_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'bbox'
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__traits.hpp"

namespace scene_graph_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FunObject3DBoundingBoxList & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: bbox
  {
    if (msg.bbox.size() == 0) {
      out << "bbox: []";
    } else {
      out << "bbox: [";
      size_t pending_items = msg.bbox.size();
      for (auto item : msg.bbox) {
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
  const FunObject3DBoundingBoxList & msg,
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

  // member: bbox
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bbox.size() == 0) {
      out << "bbox: []\n";
    } else {
      out << "bbox:\n";
      for (auto item : msg.bbox) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FunObject3DBoundingBoxList & msg, bool use_flow_style = false)
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
  const scene_graph_interfaces::msg::FunObject3DBoundingBoxList & msg,
  std::ostream & out, size_t indentation = 0)
{
  scene_graph_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scene_graph_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const scene_graph_interfaces::msg::FunObject3DBoundingBoxList & msg)
{
  return scene_graph_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>()
{
  return "scene_graph_interfaces::msg::FunObject3DBoundingBoxList";
}

template<>
inline const char * name<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>()
{
  return "scene_graph_interfaces/msg/FunObject3DBoundingBoxList";
}

template<>
struct has_fixed_size<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__TRAITS_HPP_
