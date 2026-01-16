// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_type_hash_t *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd3, 0x4c, 0xd4, 0x3d, 0x65, 0x94, 0x3c, 0x6a,
      0x0f, 0x63, 0x70, 0x76, 0x8d, 0x58, 0x93, 0x41,
      0xac, 0x2a, 0xce, 0x27, 0x4c, 0xd2, 0xc9, 0x19,
      0x72, 0x20, 0x04, 0x79, 0x97, 0x9c, 0xd1, 0x0c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/string__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t std_msgs__msg__String__EXPECTED_HASH = {1, {
    0xdf, 0x66, 0x8c, 0x74, 0x04, 0x82, 0xbb, 0xd4,
    0x8f, 0xb3, 0x9d, 0x76, 0xa7, 0x0d, 0xfd, 0x4b,
    0xd5, 0x9d, 0xb1, 0x28, 0x80, 0x21, 0x74, 0x35,
    0x03, 0x25, 0x9e, 0x94, 0x8f, 0x6b, 0x1a, 0x18,
  }};
#endif

static char scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME[] = "scene_graph_interfaces/msg/FunObject3DBoundingBox";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char std_msgs__msg__String__TYPE_NAME[] = "std_msgs/msg/String";

// Define type names, field names, and default values
static char scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__name[] = "name";
static char scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__bounding_box[] = "bounding_box";
static char scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__graspable[] = "graspable";

static rosidl_runtime_c__type_description__Field scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELDS[] = {
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__String__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__bounding_box, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      2,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELD_NAME__graspable, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription scene_graph_interfaces__msg__FunObject3DBoundingBox__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__String__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME, 49, 49},
      {scene_graph_interfaces__msg__FunObject3DBoundingBox__FIELDS, 3, 3},
    },
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__String__EXPECTED_HASH, std_msgs__msg__String__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__String__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/String name\n"
  "geometry_msgs/Point[2] bounding_box\n"
  "bool graspable";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME, 49, 49},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 72, 72},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *scene_graph_interfaces__msg__FunObject3DBoundingBox__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__String__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
