// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__type_support.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace scene_graph_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _FunObject3DBoundingBox_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FunObject3DBoundingBox_type_support_ids_t;

static const _FunObject3DBoundingBox_type_support_ids_t _FunObject3DBoundingBox_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FunObject3DBoundingBox_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FunObject3DBoundingBox_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FunObject3DBoundingBox_type_support_symbol_names_t _FunObject3DBoundingBox_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)),
  }
};

typedef struct _FunObject3DBoundingBox_type_support_data_t
{
  void * data[2];
} _FunObject3DBoundingBox_type_support_data_t;

static _FunObject3DBoundingBox_type_support_data_t _FunObject3DBoundingBox_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FunObject3DBoundingBox_message_typesupport_map = {
  2,
  "scene_graph_interfaces",
  &_FunObject3DBoundingBox_message_typesupport_ids.typesupport_identifier[0],
  &_FunObject3DBoundingBox_message_typesupport_symbol_names.symbol_name[0],
  &_FunObject3DBoundingBox_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FunObject3DBoundingBox_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FunObject3DBoundingBox_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace scene_graph_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)() {
  return &::scene_graph_interfaces::msg::rosidl_typesupport_c::FunObject3DBoundingBox_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
