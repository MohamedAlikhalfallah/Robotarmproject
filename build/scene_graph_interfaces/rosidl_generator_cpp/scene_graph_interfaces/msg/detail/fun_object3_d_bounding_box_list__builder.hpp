// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__BUILDER_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scene_graph_interfaces
{

namespace msg
{

namespace builder
{

class Init_FunObject3DBoundingBoxList_bbox
{
public:
  explicit Init_FunObject3DBoundingBoxList_bbox(::scene_graph_interfaces::msg::FunObject3DBoundingBoxList & msg)
  : msg_(msg)
  {}
  ::scene_graph_interfaces::msg::FunObject3DBoundingBoxList bbox(::scene_graph_interfaces::msg::FunObject3DBoundingBoxList::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scene_graph_interfaces::msg::FunObject3DBoundingBoxList msg_;
};

class Init_FunObject3DBoundingBoxList_header
{
public:
  Init_FunObject3DBoundingBoxList_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FunObject3DBoundingBoxList_bbox header(::scene_graph_interfaces::msg::FunObject3DBoundingBoxList::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FunObject3DBoundingBoxList_bbox(msg_);
  }

private:
  ::scene_graph_interfaces::msg::FunObject3DBoundingBoxList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scene_graph_interfaces::msg::FunObject3DBoundingBoxList>()
{
  return scene_graph_interfaces::msg::builder::Init_FunObject3DBoundingBoxList_header();
}

}  // namespace scene_graph_interfaces

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__BUILDER_HPP_
