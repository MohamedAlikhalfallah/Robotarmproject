// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "std_msgs/msg/detail/string__functions.h"
// Member `bounding_box`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__init(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!std_msgs__msg__String__init(&msg->name)) {
    scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(msg);
    return false;
  }
  // bounding_box
  for (size_t i = 0; i < 2; ++i) {
    if (!geometry_msgs__msg__Point__init(&msg->bounding_box[i])) {
      scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(msg);
      return false;
    }
  }
  // graspable
  return true;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // name
  std_msgs__msg__String__fini(&msg->name);
  // bounding_box
  for (size_t i = 0; i < 2; ++i) {
    geometry_msgs__msg__Point__fini(&msg->bounding_box[i]);
  }
  // graspable
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBox * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!std_msgs__msg__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // bounding_box
  for (size_t i = 0; i < 2; ++i) {
    if (!geometry_msgs__msg__Point__are_equal(
        &(lhs->bounding_box[i]), &(rhs->bounding_box[i])))
    {
      return false;
    }
  }
  // graspable
  if (lhs->graspable != rhs->graspable) {
    return false;
  }
  return true;
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBox * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!std_msgs__msg__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // bounding_box
  for (size_t i = 0; i < 2; ++i) {
    if (!geometry_msgs__msg__Point__copy(
        &(input->bounding_box[i]), &(output->bounding_box[i])))
    {
      return false;
    }
  }
  // graspable
  output->graspable = input->graspable;
  return true;
}

scene_graph_interfaces__msg__FunObject3DBoundingBox *
scene_graph_interfaces__msg__FunObject3DBoundingBox__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBox * msg = (scene_graph_interfaces__msg__FunObject3DBoundingBox *)allocator.allocate(sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox));
  bool success = scene_graph_interfaces__msg__FunObject3DBoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBox__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBox * data = NULL;

  if (size) {
    data = (scene_graph_interfaces__msg__FunObject3DBoundingBox *)allocator.zero_allocate(size, sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scene_graph_interfaces__msg__FunObject3DBoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(&data[i - 1]);
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
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array)
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
      scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(&array->data[i]);
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

scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array = (scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence *)allocator.allocate(sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__destroy(scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__are_equal(const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * lhs, const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence__copy(
  const scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * input,
  scene_graph_interfaces__msg__FunObject3DBoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scene_graph_interfaces__msg__FunObject3DBoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scene_graph_interfaces__msg__FunObject3DBoundingBox * data =
      (scene_graph_interfaces__msg__FunObject3DBoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scene_graph_interfaces__msg__FunObject3DBoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scene_graph_interfaces__msg__FunObject3DBoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
