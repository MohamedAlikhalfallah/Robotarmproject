// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__rosidl_typesupport_introspection_c.h"
#include "scene_graph_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"


// Include directives for member types
// Member `name`
#include "std_msgs/msg/string.h"
// Member `name`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"
// Member `bounding_box`
#include "geometry_msgs/msg/point.h"
// Member `bounding_box`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  scene_graph_interfaces__msg__FunObject3DBoundingBox__init(message_memory);
}

void scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_fini_function(void * message_memory)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(message_memory);
}

size_t scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__size_function__FunObject3DBoundingBox__bounding_box(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBox__bounding_box(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point * member =
    (const geometry_msgs__msg__Point *)(untyped_member);
  return &member[index];
}

void * scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBox__bounding_box(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point * member =
    (geometry_msgs__msg__Point *)(untyped_member);
  return &member[index];
}

void scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__fetch_function__FunObject3DBoundingBox__bounding_box(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBox__bounding_box(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__assign_function__FunObject3DBoundingBox__bounding_box(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBox__bounding_box(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_member_array[3] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces__msg__FunObject3DBoundingBox, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces__msg__FunObject3DBoundingBox, bounding_box),  // bytes offset in struct
    NULL,  // default value
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__size_function__FunObject3DBoundingBox__bounding_box,  // size() function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBox__bounding_box,  // get_const(index) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBox__bounding_box,  // get(index) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__fetch_function__FunObject3DBoundingBox__bounding_box,  // fetch(index, &value) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__assign_function__FunObject3DBoundingBox__bounding_box,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "graspable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces__msg__FunObject3DBoundingBox, graspable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_members = {
  "scene_graph_interfaces__msg",  // message namespace
  "FunObject3DBoundingBox",  // message name
  3,  // number of fields
  sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox),
  false,  // has_any_key_member_
  scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_member_array,  // message members
  scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_init_function,  // function to initialize message memory (memory has to be allocated)
  scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_type_support_handle = {
  0,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_members,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_scene_graph_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)() {
  scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_type_support_handle.typesupport_identifier) {
    scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &scene_graph_interfaces__msg__FunObject3DBoundingBox__rosidl_typesupport_introspection_c__FunObject3DBoundingBox_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
