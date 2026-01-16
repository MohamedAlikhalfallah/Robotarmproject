// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace scene_graph_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FunObject3DBoundingBox_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) scene_graph_interfaces::msg::FunObject3DBoundingBox(_init);
}

void FunObject3DBoundingBox_fini_function(void * message_memory)
{
  auto typed_message = static_cast<scene_graph_interfaces::msg::FunObject3DBoundingBox *>(message_memory);
  typed_message->~FunObject3DBoundingBox();
}

size_t size_function__FunObject3DBoundingBox__bounding_box(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__FunObject3DBoundingBox__bounding_box(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<geometry_msgs::msg::Point, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__FunObject3DBoundingBox__bounding_box(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<geometry_msgs::msg::Point, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__FunObject3DBoundingBox__bounding_box(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__FunObject3DBoundingBox__bounding_box(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__FunObject3DBoundingBox__bounding_box(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__FunObject3DBoundingBox__bounding_box(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FunObject3DBoundingBox_message_member_array[3] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::String>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces::msg::FunObject3DBoundingBox, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bounding_box",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is key
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces::msg::FunObject3DBoundingBox, bounding_box),  // bytes offset in struct
    nullptr,  // default value
    size_function__FunObject3DBoundingBox__bounding_box,  // size() function pointer
    get_const_function__FunObject3DBoundingBox__bounding_box,  // get_const(index) function pointer
    get_function__FunObject3DBoundingBox__bounding_box,  // get(index) function pointer
    fetch_function__FunObject3DBoundingBox__bounding_box,  // fetch(index, &value) function pointer
    assign_function__FunObject3DBoundingBox__bounding_box,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "graspable",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces::msg::FunObject3DBoundingBox, graspable),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FunObject3DBoundingBox_message_members = {
  "scene_graph_interfaces::msg",  // message namespace
  "FunObject3DBoundingBox",  // message name
  3,  // number of fields
  sizeof(scene_graph_interfaces::msg::FunObject3DBoundingBox),
  false,  // has_any_key_member_
  FunObject3DBoundingBox_message_member_array,  // message members
  FunObject3DBoundingBox_init_function,  // function to initialize message memory (memory has to be allocated)
  FunObject3DBoundingBox_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FunObject3DBoundingBox_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FunObject3DBoundingBox_message_members,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace scene_graph_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<scene_graph_interfaces::msg::FunObject3DBoundingBox>()
{
  return &::scene_graph_interfaces::msg::rosidl_typesupport_introspection_cpp::FunObject3DBoundingBox_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, scene_graph_interfaces, msg, FunObject3DBoundingBox)() {
  return &::scene_graph_interfaces::msg::rosidl_typesupport_introspection_cpp::FunObject3DBoundingBox_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
