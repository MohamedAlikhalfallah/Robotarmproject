// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.h"
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "geometry_msgs/msg/detail/point__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__string__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__string__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[78];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("scene_graph_interfaces.msg._fun_object3_d_bounding_box.FunObject3DBoundingBox", full_classname_dest, 77) == 0);
  }
  scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__string__convert_from_py(field, &ros_message->name)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // bounding_box
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_box");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'bounding_box'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = 2;
    geometry_msgs__msg__Point * dest = ros_message->bounding_box;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!geometry_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // graspable
    PyObject * field = PyObject_GetAttrString(_pymsg, "graspable");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->graspable = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * scene_graph_interfaces__msg__fun_object3_d_bounding_box__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FunObject3DBoundingBox */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("scene_graph_interfaces.msg._fun_object3_d_bounding_box");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FunObject3DBoundingBox");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  scene_graph_interfaces__msg__FunObject3DBoundingBox * ros_message = (scene_graph_interfaces__msg__FunObject3DBoundingBox *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = std_msgs__msg__string__convert_to_py(&ros_message->name);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_box
    PyObject * field = NULL;
    size_t size = 2;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    geometry_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->bounding_box[i]);
      PyObject * pyitem = geometry_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_box", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // graspable
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->graspable ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "graspable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
