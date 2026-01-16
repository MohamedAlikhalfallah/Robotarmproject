// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice
#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "scene_graph_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_serialize_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_deserialize_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  eprosima::fastcdr::Cdr &,
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t get_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t max_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_serialize_key_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t get_serialized_size_key_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t max_serialized_size_key_scene_graph_interfaces__msg__FunObject3DBoundingBoxList(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scene_graph_interfaces, msg, FunObject3DBoundingBoxList)();

#ifdef __cplusplus
}
#endif

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
