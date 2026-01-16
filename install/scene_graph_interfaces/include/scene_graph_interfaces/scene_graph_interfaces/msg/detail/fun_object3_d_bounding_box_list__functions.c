// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `bbox`
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"

bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(msg);
    return false;
  }
  // bbox
  if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init(&msg->bbox, 0)) {
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(msg);
    return false;
  }
  return true;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // bbox
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini(&msg->bbox);
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // bbox
  if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__are_equal(
      &(lhs->bbox), &(rhs->bbox)))
  {
    return false;
  }
  return true;
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // bbox
  if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__copy(
      &(input->bbox), &(output->bbox)))
  {
    return false;
  }
  return true;
}

scene_graph_interfaces__msg__FunObject3DBoundingBoxList *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg = (scene_graph_interfaces__msg__FunObject3DBoundingBoxList *)allocator.allocate(sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList));
  bool success = scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBoxList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__init(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * data = NULL;

  if (size) {
    data = (scene_graph_interfaces__msg__FunObject3DBoundingBoxList *)allocator.zero_allocate(size, sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__fini(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array = (scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence *)allocator.allocate(sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scene_graph_interfaces__msg__FunObject3DBoundingBoxList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBoxList);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scene_graph_interfaces__msg__FunObject3DBoundingBoxList * data =
      (scene_graph_interfaces__msg__FunObject3DBoundingBoxList *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scene_graph_interfaces__msg__FunObject3DBoundingBoxList__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scene_graph_interfaces__msg__FunObject3DBoundingBoxList__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scene_graph_interfaces__msg__FunObject3DBoundingBoxList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
