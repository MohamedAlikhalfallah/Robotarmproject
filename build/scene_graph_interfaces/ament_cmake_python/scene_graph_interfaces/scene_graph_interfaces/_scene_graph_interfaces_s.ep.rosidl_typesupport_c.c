// generated from rosidl_generator_py/resource/_idl_pkg_typesupport_entry_point.c.em
// generated code does not contain a copyright notice
#include <Python.h>

static PyMethodDef scene_graph_interfaces__methods[] = {
  {NULL, NULL, 0, NULL}  /* sentinel */
};

static struct PyModuleDef scene_graph_interfaces__module = {
  PyModuleDef_HEAD_INIT,
  "_scene_graph_interfaces_support",
  "_scene_graph_interfaces_doc",
  -1,  /* -1 means that the module keeps state in global variables */
  scene_graph_interfaces__methods,
  NULL,
  NULL,
  NULL,
  NULL,
};

#include <stdbool.h>
#include <stdint.h>
#include "rosidl_runtime_c/visibility_control.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__type_support.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"

static void * scene_graph_interfaces__msg__fun_object3_d_bounding_box__create_ros_message(void)
{
  return scene_graph_interfaces__msg__FunObject3DBoundingBox__create();
}

static void scene_graph_interfaces__msg__fun_object3_d_bounding_box__destroy_ros_message(void * raw_ros_message)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message = (scene_graph_interfaces__msg__FunObject3DBoundingBox *)raw_ros_message;
  scene_graph_interfaces__msg__FunObject3DBoundingBox__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(scene_graph_interfaces, msg, FunObject3DBoundingBox);

int8_t
_register_msg_type__msg__fun_object3_d_bounding_box(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__fun_object3_d_bounding_box",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__fun_object3_d_bounding_box",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__fun_object3_d_bounding_box",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__fun_object3_d_bounding_box",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(scene_graph_interfaces, msg, FunObject3DBoundingBox),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__fun_object3_d_bounding_box",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__type_support.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box_list__functions.h"

static void * scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__create_ros_message(void)
{
  return scene_graph_interfaces__msg__FunObject3DBoundingBoxList__create();
}

static void scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__destroy_ros_message(void * raw_ros_message)
{
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList * ros_message = (scene_graph_interfaces__msg__FunObject3DBoundingBoxList *)raw_ros_message;
  scene_graph_interfaces__msg__FunObject3DBoundingBoxList__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(scene_graph_interfaces, msg, FunObject3DBoundingBoxList);

int8_t
_register_msg_type__msg__fun_object3_d_bounding_box_list(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__fun_object3_d_bounding_box_list",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__fun_object3_d_bounding_box_list",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__fun_object3_d_bounding_box_list",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&scene_graph_interfaces__msg__fun_object3_d_bounding_box_list__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__fun_object3_d_bounding_box_list",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(scene_graph_interfaces, msg, FunObject3DBoundingBoxList),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__fun_object3_d_bounding_box_list",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

PyMODINIT_FUNC
PyInit_scene_graph_interfaces_s__rosidl_typesupport_c(void)
{
  PyObject * pymodule = NULL;
  pymodule = PyModule_Create(&scene_graph_interfaces__module);
  if (!pymodule) {
    return NULL;
  }
  int8_t err;

  err = _register_msg_type__msg__fun_object3_d_bounding_box(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__fun_object3_d_bounding_box_list(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  return pymodule;
}
