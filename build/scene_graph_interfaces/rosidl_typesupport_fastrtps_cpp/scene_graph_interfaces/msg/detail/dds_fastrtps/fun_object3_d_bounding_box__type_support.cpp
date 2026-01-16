// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__rosidl_typesupport_fastrtps_cpp.hpp"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::String &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::String &);
size_t get_serialized_size(
  const std_msgs::msg::String &,
  size_t current_alignment);
size_t
max_serialized_size_String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const std_msgs::msg::String &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const std_msgs::msg::String &,
  size_t current_alignment);
size_t
max_serialized_size_key_String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Point &);
size_t get_serialized_size(
  const geometry_msgs::msg::Point &,
  size_t current_alignment);
size_t
max_serialized_size_Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const geometry_msgs::msg::Point &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const geometry_msgs::msg::Point &,
  size_t current_alignment);
size_t
max_serialized_size_key_Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace scene_graph_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
cdr_serialize(
  const scene_graph_interfaces::msg::FunObject3DBoundingBox & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.name,
    cdr);

  // Member: bounding_box
  {
    for (size_t i = 0; i < 2; i++) {
      geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.bounding_box[i],
        cdr);
    }
  }

  // Member: graspable
  cdr << (ros_message.graspable ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  scene_graph_interfaces::msg::FunObject3DBoundingBox & ros_message)
{
  // Member: name
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.name);

  // Member: bounding_box
  {
    for (size_t i = 0; i < 2; i++) {
      geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.bounding_box[i]);
    }
  }

  // Member: graspable
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.graspable = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
get_serialized_size(
  const scene_graph_interfaces::msg::FunObject3DBoundingBox & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.name, current_alignment);

  // Member: bounding_box
  {
    size_t array_size = 2;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.bounding_box[index], current_alignment);
    }
  }

  // Member: graspable
  {
    size_t item_size = sizeof(ros_message.graspable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
max_serialized_size_FunObject3DBoundingBox(
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

  // Member: name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: bounding_box
  {
    size_t array_size = 2;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: graspable
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
    using DataType = scene_graph_interfaces::msg::FunObject3DBoundingBox;
    is_plain =
      (
      offsetof(DataType, graspable) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
cdr_serialize_key(
  const scene_graph_interfaces::msg::FunObject3DBoundingBox & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.name,
    cdr);

  // Member: bounding_box
  {
    for (size_t i = 0; i < 2; i++) {
      geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.bounding_box[i],
        cdr);
    }
  }

  // Member: graspable
  cdr << (ros_message.graspable ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
get_serialized_size_key(
  const scene_graph_interfaces::msg::FunObject3DBoundingBox & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.name, current_alignment);

  // Member: bounding_box
  {
    size_t array_size = 2;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.bounding_box[index], current_alignment);
    }
  }

  // Member: graspable
  {
    size_t item_size = sizeof(ros_message.graspable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scene_graph_interfaces
max_serialized_size_key_FunObject3DBoundingBox(
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

  // Member: name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bounding_box
  {
    size_t array_size = 2;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: graspable
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
    using DataType = scene_graph_interfaces::msg::FunObject3DBoundingBox;
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
  auto typed_message =
    static_cast<const scene_graph_interfaces::msg::FunObject3DBoundingBox *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FunObject3DBoundingBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<scene_graph_interfaces::msg::FunObject3DBoundingBox *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FunObject3DBoundingBox__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const scene_graph_interfaces::msg::FunObject3DBoundingBox *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FunObject3DBoundingBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FunObject3DBoundingBox(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FunObject3DBoundingBox__callbacks = {
  "scene_graph_interfaces::msg",
  "FunObject3DBoundingBox",
  _FunObject3DBoundingBox__cdr_serialize,
  _FunObject3DBoundingBox__cdr_deserialize,
  _FunObject3DBoundingBox__get_serialized_size,
  _FunObject3DBoundingBox__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FunObject3DBoundingBox__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FunObject3DBoundingBox__callbacks,
  get_message_typesupport_handle_function,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description,
  &scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace scene_graph_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_scene_graph_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<scene_graph_interfaces::msg::FunObject3DBoundingBox>()
{
  return &scene_graph_interfaces::msg::typesupport_fastrtps_cpp::_FunObject3DBoundingBox__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, scene_graph_interfaces, msg, FunObject3DBoundingBox)() {
  return &scene_graph_interfaces::msg::typesupport_fastrtps_cpp::_FunObject3DBoundingBox__handle;
}

#ifdef __cplusplus
}
#endif
