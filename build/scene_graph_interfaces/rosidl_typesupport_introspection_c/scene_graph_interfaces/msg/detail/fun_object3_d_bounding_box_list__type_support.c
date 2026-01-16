// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__rosidl_typesupport_introspection_c.h"
#include "scene_graph_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `bbox`
#include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.h"
// Member `bbox`
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(message_memory);
}

void scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_fini_function(void * message_memory)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(message_memory);
}

size_t scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__size_function__FunObject3DBoundingBoxList__bbox(
  const void * untyped_member)
{
  const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * member =
    (const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *)(untyped_member);
  return member->size;
}

const void * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBoxList__bbox(
  const void * untyped_member, size_t index)
{
  const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * member =
    (const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBoxList__bbox(
  void * untyped_member, size_t index)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * member =
    (scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__fetch_function__FunObject3DBoundingBoxList__bbox(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * item =
    ((const scene_graph_interfaces__msg__FunObject3DBoundingBox *)
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBoxList__bbox(untyped_member, index));
  scene_graph_interfaces__msg__FunObject3DBoundingBox * value =
    (scene_graph_interfaces__msg__FunObject3DBoundingBox *)(untyped_value);
  *value = *item;
}

void scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__assign_function__FunObject3DBoundingBoxList__bbox(
  void * untyped_member, size_t index, const void * untyped_value)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox * item =
    ((scene_graph_interfaces__msg__FunObject3DBoundingBox *)
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBoxList__bbox(untyped_member, index));
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * value =
    (const scene_graph_interfaces__msg__FunObject3DBoundingBox *)(untyped_value);
  *item = *value;
}

bool scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__resize_function__FunObject3DBoundingBoxList__bbox(
  void * untyped_member, size_t size)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * member =
    (scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *)(untyped_member);
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini(member);
  return scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList, bbox),  // bytes offset in struct
    NULL,  // default value
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__size_function__FunObject3DBoundingBoxList__bbox,  // size() function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_const_function__FunObject3DBoundingBoxList__bbox,  // get_const(index) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__get_function__FunObject3DBoundingBoxList__bbox,  // get(index) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__fetch_function__FunObject3DBoundingBoxList__bbox,  // fetch(index, &value) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__assign_function__FunObject3DBoundingBoxList__bbox,  // assign(index, value) function pointer
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__resize_function__FunObject3DBoundingBoxList__bbox  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_members = {
  "scene_graph_interfaces__msg",  // message namespace
  "FunObject3DBoundingBoxList",  // message name
  2,  // number of fields
  sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList),
  false,  // has_any_key_member_
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_member_array,  // message members
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_init_function,  // function to initialize message memory (memory has to be allocated)
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_type_support_handle = {
  0,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_members,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_scene_graph_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scene_graph_interfaces, msg, FunObject3DBoundingBoxList)() {
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)();
  if (!scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_type_support_handle.typesupport_identifier) {
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &scene_graph_interfaces__msg__FunObject3DBoundingBoxList__rosidl_typesupport_introspection_c__FunObject3DBoundingBoxList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
