// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.h"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_H_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'bbox'
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"

/// Struct defined in msg/FunObject3DBoundingBoxList in the package scene_graph_interfaces.
typedef struct scene_graph_interfaces__msg__FunObject3DBoundingBoxList
{
  std_msgs__msg__Header header;
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence bbox;
} scene_graph_interfaces__msg__FunObject3DBoundingBoxList;

// Struct for a sequence of scene_graph_interfaces__msg__FunObject3DBoundingBoxList.
typedef struct scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence
{
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_H_
