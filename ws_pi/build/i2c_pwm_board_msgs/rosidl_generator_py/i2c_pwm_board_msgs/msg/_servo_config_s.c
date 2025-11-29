// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
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
#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.h"
#include "i2c_pwm_board_msgs/msg/detail/servo_config__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool i2c_pwm_board_msgs__msg__servo_config__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("i2c_pwm_board_msgs.msg._servo_config.ServoConfig", full_classname_dest, 48) == 0);
  }
  i2c_pwm_board_msgs__msg__ServoConfig * ros_message = _ros_message;
  {  // servo
    PyObject * field = PyObject_GetAttrString(_pymsg, "servo");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->servo = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // center
    PyObject * field = PyObject_GetAttrString(_pymsg, "center");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // range
    PyObject * field = PyObject_GetAttrString(_pymsg, "range");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->range = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->direction = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * i2c_pwm_board_msgs__msg__servo_config__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ServoConfig */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("i2c_pwm_board_msgs.msg._servo_config");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ServoConfig");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  i2c_pwm_board_msgs__msg__ServoConfig * ros_message = (i2c_pwm_board_msgs__msg__ServoConfig *)raw_ros_message;
  {  // servo
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->servo);
    {
      int rc = PyObject_SetAttrString(_pymessage, "servo", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->center);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
