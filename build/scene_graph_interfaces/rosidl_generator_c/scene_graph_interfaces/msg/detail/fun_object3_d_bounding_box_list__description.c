// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_type_hash_t *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9f, 0x86, 0x0a, 0xe1, 0x04, 0xbf, 0x2f, 0xfc,
      0x47, 0xbe, 0xb6, 0x8d, 0x85, 0xb1, 0x51, 0x37,
      0x75, 0xe8, 0x63, 0x35, 0x08, 0xca, 0x57, 0xef,
      0xfd, 0xf9, 0x40, 0x8c, 0x7e, 0xfa, 0x52, 0x2f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"
#include "std_msgs/msg/detail/string__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t scene_graph_interfaces__msg__FunObject3DBoundingBox__EXPECTED_HASH = {1, {
    0xd3, 0x4c, 0xd4, 0x3d, 0x65, 0x94, 0x3c, 0x6a,
    0x0f, 0x63, 0x70, 0x76, 0x8d, 0x58, 0x93, 0x41,
    0xac, 0x2a, 0xce, 0x27, 0x4c, 0xd2, 0xc9, 0x19,
    0x72, 0x20, 0x04, 0x79, 0x97, 0x9c, 0xd1, 0x0c,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t std_msgs__msg__String__EXPECTED_HASH = {1, {
    0xdf, 0x66, 0x8c, 0x74, 0x04, 0x82, 0xbb, 0xd4,
    0x8f, 0xb3, 0x9d, 0x76, 0xa7, 0x0d, 0xfd, 0x4b,
    0xd5, 0x9d, 0xb1, 0x28, 0x80, 0x21, 0x74, 0x35,
    0x03, 0x25, 0x9e, 0x94, 0x8f, 0x6b, 0x1a, 0x18,
  }};
#endif

static char scene_graph_interfaces__msg__FunObject3DBoundingBoxList__TYPE_NAME[] = "scene_graph_interfaces/msg/FunObject3DBoundingBoxList";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME[] = "scene_graph_interfaces/msg/FunObject3DBoundingBox";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char std_msgs__msg__String__TYPE_NAME[] = "std_msgs/msg/String";

// Define type names, field names, and default values
static char scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELD_NAME__header[] = "header";
static char scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELD_NAME__bbox[] = "bbox";

static rosidl_runtime_c__type_description__Field scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELDS[] = {
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELD_NAME__bbox, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription scene_graph_interfaces__msg__FunObject3DBoundingBoxList__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {scene_graph_interfaces__msg__FunObject3DBoundingBox__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__String__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__TYPE_NAME, 53, 53},
      {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__FIELDS, 2, 2},
    },
    {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&scene_graph_interfaces__msg__FunObject3DBoundingBox__EXPECTED_HASH, scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__String__EXPECTED_HASH, std_msgs__msg__String__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__String__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "FunObject3DBoundingBox[] bbox";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {scene_graph_interfaces__msg__FunObject3DBoundingBoxList__TYPE_NAME, 53, 53},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 53, 53},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *scene_graph_interfaces__msg__FunObject3DBoundingBox__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__String__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
