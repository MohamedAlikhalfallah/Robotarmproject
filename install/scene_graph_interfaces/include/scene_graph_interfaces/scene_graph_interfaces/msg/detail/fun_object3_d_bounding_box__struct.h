// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.h"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_H_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "std_msgs/msg/detail/string__struct.h"
// Member 'bounding_box'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/FunObject3DBoundingBox in the package scene_graph_interfaces.
typedef struct scene_graph_interfaces__msg__FunObject3DBoundingBox
{
  std_msgs__msg__String name;
  geometry_msgs__msg__Point bounding_box[2];
  bool graspable;
} scene_graph_interfaces__msg__FunObject3DBoundingBox;

// Struct for a sequence of scene_graph_interfaces__msg__FunObject3DBoundingBox.
typedef struct scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_H_
