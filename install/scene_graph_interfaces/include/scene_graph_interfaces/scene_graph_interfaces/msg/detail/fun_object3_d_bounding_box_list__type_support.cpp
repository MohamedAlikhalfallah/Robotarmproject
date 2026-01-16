// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.hpp"
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

void FunObject3DBoundingBoxList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) scene_graph_interfaces::msg::FunObject3DBoundingBoxList(_init);
}

void FunObject3DBoundingBoxList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<scene_graph_interfaces::msg::FunObject3DBoundingBoxList *>(message_memory);
  typed_message->~FunObject3DBoundingBoxList();
}

size_t size_function__FunObject3DBoundingBoxList__bbox(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FunObject3DBoundingBoxList__bbox(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox> *>(untyped_member);
  return &member[index];
}

void * get_function__FunObject3DBoundingBoxList__bbox(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox> *>(untyped_member);
  return &member[index];
}

void fetch_function__FunObject3DBoundingBoxList__bbox(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const scene_graph_interfaces::msg::FunObject3DBoundingBox *>(
    get_const_function__FunObject3DBoundingBoxList__bbox(untyped_member, index));
  auto & value = *reinterpret_cast<scene_graph_interfaces::msg::FunObject3DBoundingBox *>(untyped_value);
  value = item;
}

void assign_function__FunObject3DBoundingBoxList__bbox(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<scene_graph_interfaces::msg::FunObject3DBoundingBox *>(
    get_function__FunObject3DBoundingBoxList__bbox(untyped_member, index));
  const auto & value = *reinterpret_cast<const scene_graph_interfaces::msg::FunObject3DBoundingBox *>(untyped_value);
  item = value;
}

void resize_function__FunObject3DBoundingBoxList__bbox(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FunObject3DBoundingBoxList_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces::msg::FunObject3DBoundingBoxList, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bbox",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<scene_graph_interfaces::msg::FunObject3DBoundingBox>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces::msg::FunObject3DBoundingBoxList, bbox),  // bytes offset in struct
    nullptr,  // default value
    size_function__FunObject3DBoundingBoxList__bbox,  // size() function pointer
    get_const_function__FunObject3DBoundingBoxList__bbox,  // get_const(index) function pointer
    get_function__FunObject3DBoundingBoxList__bbox,  // get(index) function pointer
    fetch_function__FunObject3DBoundingBoxList__bbox,  // fetch(index, &value) function pointer
    assign_function__FunObject3DBoundingBoxList__bbox,  // assign(index, value) function pointer
    resize_function__FunObject3DBoundingBoxList__bbox  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FunObject3DBoundingBoxList_message_members = {
  "scene_graph_interfaces::msg",  // message namespace
  "FunObject3DBoundingBoxList",  // message name
  2,  // number of fields
  sizeof(scene_graph_interfaces::msg::FunObject3DBoundingBoxList),
  false,  // has_any_key_member_
  FunObject3DBoundingBoxList_message_member_array,  // message members
  FunObject3DBoundingBoxList_init_function,  // function to initialize message memory (memory has to be allocated)
  FunObject3DBoundingBoxList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FunObject3DBoundingBoxList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FunObject3DBoundingBoxList_message_members,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace scene_graph_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<scene_graph_interfaces::msg::FunObject3DBoundingBoxList>()
{
  return &::scene_graph_interfaces::msg::rosidl_typesupport_introspection_cpp::FunObject3DBoundingBoxList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, scene_graph_interfaces, msg, FunObject3DBoundingBoxList)() {
  return &::scene_graph_interfaces::msg::rosidl_typesupport_introspection_cpp::FunObject3DBoundingBoxList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
