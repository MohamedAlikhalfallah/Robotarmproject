// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__BUILDER_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scene_graph_interfaces
{

namespace msg
{

namespace builder
{

class Init_FunObject3DBoundingBox_graspable
{
public:
  explicit Init_FunObject3DBoundingBox_graspable(::scene_graph_interfaces::msg::FunObject3DBoundingBox & msg)
  : msg_(msg)
  {}
  ::scene_graph_interfaces::msg::FunObject3DBoundingBox graspable(::scene_graph_interfaces::msg::FunObject3DBoundingBox::_graspable_type arg)
  {
    msg_.graspable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scene_graph_interfaces::msg::FunObject3DBoundingBox msg_;
};

class Init_FunObject3DBoundingBox_bounding_box
{
public:
  explicit Init_FunObject3DBoundingBox_bounding_box(::scene_graph_interfaces::msg::FunObject3DBoundingBox & msg)
  : msg_(msg)
  {}
  Init_FunObject3DBoundingBox_graspable bounding_box(::scene_graph_interfaces::msg::FunObject3DBoundingBox::_bounding_box_type arg)
  {
    msg_.bounding_box = std::move(arg);
    return Init_FunObject3DBoundingBox_graspable(msg_);
  }

private:
  ::scene_graph_interfaces::msg::FunObject3DBoundingBox msg_;
};

class Init_FunObject3DBoundingBox_name
{
public:
  Init_FunObject3DBoundingBox_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FunObject3DBoundingBox_bounding_box name(::scene_graph_interfaces::msg::FunObject3DBoundingBox::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_FunObject3DBoundingBox_bounding_box(msg_);
  }

private:
  ::scene_graph_interfaces::msg::FunObject3DBoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scene_graph_interfaces::msg::FunObject3DBoundingBox>()
{
  return scene_graph_interfaces::msg::builder::Init_FunObject3DBoundingBox_name();
}

}  // namespace scene_graph_interfaces

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__BUILDER_HPP_
