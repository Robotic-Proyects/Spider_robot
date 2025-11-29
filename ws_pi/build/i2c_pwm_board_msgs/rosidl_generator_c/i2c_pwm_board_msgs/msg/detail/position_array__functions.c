// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from i2c_pwm_board_msgs:msg/PositionArray.idl
// generated code does not contain a copyright notice
#include "i2c_pwm_board_msgs/msg/detail/position_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `servos`
#include "i2c_pwm_board_msgs/msg/detail/position__functions.h"

bool
i2c_pwm_board_msgs__msg__PositionArray__init(i2c_pwm_board_msgs__msg__PositionArray * msg)
{
  if (!msg) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__Position__Sequence__init(&msg->servos, 0)) {
    i2c_pwm_board_msgs__msg__PositionArray__fini(msg);
    return false;
  }
  return true;
}

void
i2c_pwm_board_msgs__msg__PositionArray__fini(i2c_pwm_board_msgs__msg__PositionArray * msg)
{
  if (!msg) {
    return;
  }
  // servos
  i2c_pwm_board_msgs__msg__Position__Sequence__fini(&msg->servos);
}

bool
i2c_pwm_board_msgs__msg__PositionArray__are_equal(const i2c_pwm_board_msgs__msg__PositionArray * lhs, const i2c_pwm_board_msgs__msg__PositionArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__Position__Sequence__are_equal(
      &(lhs->servos), &(rhs->servos)))
  {
    return false;
  }
  return true;
}

bool
i2c_pwm_board_msgs__msg__PositionArray__copy(
  const i2c_pwm_board_msgs__msg__PositionArray * input,
  i2c_pwm_board_msgs__msg__PositionArray * output)
{
  if (!input || !output) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__Position__Sequence__copy(
      &(input->servos), &(output->servos)))
  {
    return false;
  }
  return true;
}

i2c_pwm_board_msgs__msg__PositionArray *
i2c_pwm_board_msgs__msg__PositionArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__msg__PositionArray * msg = (i2c_pwm_board_msgs__msg__PositionArray *)allocator.allocate(sizeof(i2c_pwm_board_msgs__msg__PositionArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i2c_pwm_board_msgs__msg__PositionArray));
  bool success = i2c_pwm_board_msgs__msg__PositionArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i2c_pwm_board_msgs__msg__PositionArray__destroy(i2c_pwm_board_msgs__msg__PositionArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i2c_pwm_board_msgs__msg__PositionArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i2c_pwm_board_msgs__msg__PositionArray__Sequence__init(i2c_pwm_board_msgs__msg__PositionArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__msg__PositionArray * data = NULL;

  if (size) {
    data = (i2c_pwm_board_msgs__msg__PositionArray *)allocator.zero_allocate(size, sizeof(i2c_pwm_board_msgs__msg__PositionArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i2c_pwm_board_msgs__msg__PositionArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i2c_pwm_board_msgs__msg__PositionArray__fini(&data[i - 1]);
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
i2c_pwm_board_msgs__msg__PositionArray__Sequence__fini(i2c_pwm_board_msgs__msg__PositionArray__Sequence * array)
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
      i2c_pwm_board_msgs__msg__PositionArray__fini(&array->data[i]);
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

i2c_pwm_board_msgs__msg__PositionArray__Sequence *
i2c_pwm_board_msgs__msg__PositionArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__msg__PositionArray__Sequence * array = (i2c_pwm_board_msgs__msg__PositionArray__Sequence *)allocator.allocate(sizeof(i2c_pwm_board_msgs__msg__PositionArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i2c_pwm_board_msgs__msg__PositionArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i2c_pwm_board_msgs__msg__PositionArray__Sequence__destroy(i2c_pwm_board_msgs__msg__PositionArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i2c_pwm_board_msgs__msg__PositionArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i2c_pwm_board_msgs__msg__PositionArray__Sequence__are_equal(const i2c_pwm_board_msgs__msg__PositionArray__Sequence * lhs, const i2c_pwm_board_msgs__msg__PositionArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i2c_pwm_board_msgs__msg__PositionArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i2c_pwm_board_msgs__msg__PositionArray__Sequence__copy(
  const i2c_pwm_board_msgs__msg__PositionArray__Sequence * input,
  i2c_pwm_board_msgs__msg__PositionArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i2c_pwm_board_msgs__msg__PositionArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i2c_pwm_board_msgs__msg__PositionArray * data =
      (i2c_pwm_board_msgs__msg__PositionArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i2c_pwm_board_msgs__msg__PositionArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i2c_pwm_board_msgs__msg__PositionArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i2c_pwm_board_msgs__msg__PositionArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
