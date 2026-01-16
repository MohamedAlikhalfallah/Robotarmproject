// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "scene_graph_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // bounding_box
#include "std_msgs/msg/detail/string__functions.h"  // name

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_serialize_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_deserialize_geometry_msgs__msg__Point(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_serialize_key_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t get_serialized_size_key_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t max_serialized_size_key_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_serialize_std_msgs__msg__String(
  const std_msgs__msg__String * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_deserialize_std_msgs__msg__String(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__String * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
bool cdr_serialize_key_std_msgs__msg__String(
  const std_msgs__msg__String * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t get_serialized_size_key_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
size_t max_serialized_size_key_std_msgs__msg__String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_scene_graph_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();


using _FunObject3DBoundingBox__ros_msg_type = scene_graph_interfaces__msg__FunObject3DBoundingBox;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_serialize_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name
  {
    cdr_serialize_std_msgs__msg__String(
      &ros_message->name, cdr);
  }

  // Field name: bounding_box
  {
    size_t size = 2;
    auto array_ptr = ros_message->bounding_box;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_geometry_msgs__msg__Point(
        &array_ptr[i], cdr);
    }
  }

  // Field name: graspable
  {
    cdr << (ros_message->graspable ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_deserialize_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  eprosima::fastcdr::Cdr & cdr,
  scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message)
{
  // Field name: name
  {
    cdr_deserialize_std_msgs__msg__String(cdr, &ros_message->name);
  }

  // Field name: bounding_box
  {
    size_t size = 2;
    auto array_ptr = ros_message->bounding_box;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_geometry_msgs__msg__Point(cdr, &array_ptr[i]);
    }
  }

  // Field name: graspable
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->graspable = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t get_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FunObject3DBoundingBox__ros_msg_type * ros_message = static_cast<const _FunObject3DBoundingBox__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name
  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->name), current_alignment);

  // Field name: bounding_box
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->bounding_box;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__Point(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: graspable
  {
    size_t item_size = sizeof(ros_message->graspable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t max_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounding_box
  {
    size_t array_size = 2;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: graspable
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = scene_graph_interfaces__msg__FunObject3DBoundingBox;
    is_plain =
      (
      offsetof(DataType, graspable) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
bool cdr_serialize_key_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name
  {
    cdr_serialize_key_std_msgs__msg__String(
      &ros_message->name, cdr);
  }

  // Field name: bounding_box
  {
    size_t size = 2;
    auto array_ptr = ros_message->bounding_box;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_geometry_msgs__msg__Point(
        &array_ptr[i], cdr);
    }
  }

  // Field name: graspable
  {
    cdr << (ros_message->graspable ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t get_serialized_size_key_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FunObject3DBoundingBox__ros_msg_type * ros_message = static_cast<const _FunObject3DBoundingBox__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name
  current_alignment += get_serialized_size_key_std_msgs__msg__String(
    &(ros_message->name), current_alignment);

  // Field name: bounding_box
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->bounding_box;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_geometry_msgs__msg__Point(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: graspable
  {
    size_t item_size = sizeof(ros_message->graspable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scene_graph_interfaces
size_t max_serialized_size_key_scene_graph_interfaces__msg__FunObject3DBoundingBox(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounding_box
  {
    size_t array_size = 2;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: graspable
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = scene_graph_interfaces__msg__FunObject3DBoundingBox;
    is_plain =
      (
      offsetof(DataType, graspable) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FunObject3DBoundingBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message = static_cast<const scene_graph_interfaces__msg__FunObject3DBoundingBox *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_scene_graph_interfaces__msg__FunObject3DBoundingBox(ros_message, cdr);
}

static bool _FunObject3DBoundingBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message = static_cast<scene_graph_interfaces__msg__FunObject3DBoundingBox *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_scene_graph_interfaces__msg__FunObject3DBoundingBox(cdr, ros_message);
}

static uint32_t _FunObject3DBoundingBox__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBox(
      untyped_ros_message, 0));
}

static size_t _FunObject3DBoundingBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_scene_graph_interfaces__msg__FunObject3DBoundingBox(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FunObject3DBoundingBox = {
  "scene_graph_interfaces::msg",
  "FunObject3DBoundingBox",
  _FunObject3DBoundingBox__cdr_serialize,
  _FunObject3DBoundingBox__cdr_deserialize,
  _FunObject3DBoundingBox__get_serialized_size,
  _FunObject3DBoundingBox__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FunObject3DBoundingBox__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FunObject3DBoundingBox,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scene_graph_interfaces, msg, FunObject3DBoundingBox)() {
  return &_FunObject3DBoundingBox__type_support;
}

#if defined(__cplusplus)
}
#endif
