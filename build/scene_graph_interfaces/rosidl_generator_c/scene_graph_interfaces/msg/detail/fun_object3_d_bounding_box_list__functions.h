// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.h"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__FUNCTIONS_H_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "scene_graph_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.h"

/// Initialize msg/FunObject3DBoundingBoxList message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList
 * )) before or use
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg);

/// Finalize msg/FunObject3DBoundingBoxList message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg);

/// Create msg/FunObject3DBoundingBoxList message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
scene_graph_interfaces__msg__FunObject3DBoundingBoxList *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__create(void);

/// Destroy msg/FunObject3DBoundingBoxList message.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg);

/// Check for msg/FunObject3DBoundingBoxList message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * rhs);

/// Copy a msg/FunObject3DBoundingBoxList message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_type_hash_t *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeSource *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/FunObject3DBoundingBoxList messages.
/**
 * It allocates the memory for the number of elements and calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__init(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array, size_t size);

/// Finalize array of msg/FunObject3DBoundingBoxList messages.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__fini(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array);

/// Create array of msg/FunObject3DBoundingBoxList messages.
/**
 * It allocates the memory for the array and calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__create(size_t size);

/// Destroy array of msg/FunObject3DBoundingBoxList messages.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array);

/// Check for msg/FunObject3DBoundingBoxList message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * rhs);

/// Copy an array of msg/FunObject3DBoundingBoxList messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__FUNCTIONS_H_
