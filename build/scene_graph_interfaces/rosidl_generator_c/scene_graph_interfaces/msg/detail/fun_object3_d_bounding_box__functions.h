// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.h"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__FUNCTIONS_H_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__FUNCTIONS_H_

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

#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"

/// Initialize msg/FunObject3DBoundingBox message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * scene_graph_interfaces__msg__FunObject3DBoundingBox
 * )) before or use
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__init(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg);

/// Finalize msg/FunObject3DBoundingBox message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg);

/// Create msg/FunObject3DBoundingBox message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
scene_graph_interfaces__msg__FunObject3DBoundingBox *
scene_graph_interfaces__msg__FunObject3DBoundingBox__create(void);

/// Destroy msg/FunObject3DBoundingBox message.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBox__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg);

/// Check for msg/FunObject3DBoundingBox message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBox * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBox * rhs);

/// Copy a msg/FunObject3DBoundingBox message.
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
scene_graph_interfaces__msg__FunObject3DBoundingBox__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBox * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_type_hash_t *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeSource *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBox__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/FunObject3DBoundingBox messages.
/**
 * It allocates the memory for the number of elements and calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array, size_t size);

/// Finalize array of msg/FunObject3DBoundingBox messages.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array);

/// Create array of msg/FunObject3DBoundingBox messages.
/**
 * It allocates the memory for the array and calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__create(size_t size);

/// Destroy array of msg/FunObject3DBoundingBox messages.
/**
 * It calls
 * scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
void
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array);

/// Check for msg/FunObject3DBoundingBox message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scene_graph_interfaces
bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * rhs);

/// Copy an array of msg/FunObject3DBoundingBox messages.
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
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__FUNCTIONS_H_
