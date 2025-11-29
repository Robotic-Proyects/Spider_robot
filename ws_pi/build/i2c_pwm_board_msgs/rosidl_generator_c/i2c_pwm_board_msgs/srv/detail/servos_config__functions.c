// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from i2c_pwm_board_msgs:srv/ServosConfig.idl
// generated code does not contain a copyright notice
#include "i2c_pwm_board_msgs/srv/detail/servos_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `servos`
#include "i2c_pwm_board_msgs/msg/detail/servo_config__functions.h"

bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__init(i2c_pwm_board_msgs__srv__ServosConfig_Request * msg)
{
  if (!msg) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__ServoConfig__Sequence__init(&msg->servos, 0)) {
    i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(msg);
    return false;
  }
  return true;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(i2c_pwm_board_msgs__srv__ServosConfig_Request * msg)
{
  if (!msg) {
    return;
  }
  // servos
  i2c_pwm_board_msgs__msg__ServoConfig__Sequence__fini(&msg->servos);
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__are_equal(const i2c_pwm_board_msgs__srv__ServosConfig_Request * lhs, const i2c_pwm_board_msgs__srv__ServosConfig_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__ServoConfig__Sequence__are_equal(
      &(lhs->servos), &(rhs->servos)))
  {
    return false;
  }
  return true;
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__copy(
  const i2c_pwm_board_msgs__srv__ServosConfig_Request * input,
  i2c_pwm_board_msgs__srv__ServosConfig_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // servos
  if (!i2c_pwm_board_msgs__msg__ServoConfig__Sequence__copy(
      &(input->servos), &(output->servos)))
  {
    return false;
  }
  return true;
}

i2c_pwm_board_msgs__srv__ServosConfig_Request *
i2c_pwm_board_msgs__srv__ServosConfig_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Request * msg = (i2c_pwm_board_msgs__srv__ServosConfig_Request *)allocator.allocate(sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Request));
  bool success = i2c_pwm_board_msgs__srv__ServosConfig_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Request__destroy(i2c_pwm_board_msgs__srv__ServosConfig_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__init(i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Request * data = NULL;

  if (size) {
    data = (i2c_pwm_board_msgs__srv__ServosConfig_Request *)allocator.zero_allocate(size, sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i2c_pwm_board_msgs__srv__ServosConfig_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(&data[i - 1]);
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
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__fini(i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * array)
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
      i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(&array->data[i]);
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

i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence *
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * array = (i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence *)allocator.allocate(sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__destroy(i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__are_equal(const i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * lhs, const i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i2c_pwm_board_msgs__srv__ServosConfig_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence__copy(
  const i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * input,
  i2c_pwm_board_msgs__srv__ServosConfig_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i2c_pwm_board_msgs__srv__ServosConfig_Request * data =
      (i2c_pwm_board_msgs__srv__ServosConfig_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i2c_pwm_board_msgs__srv__ServosConfig_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i2c_pwm_board_msgs__srv__ServosConfig_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i2c_pwm_board_msgs__srv__ServosConfig_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__init(i2c_pwm_board_msgs__srv__ServosConfig_Response * msg)
{
  if (!msg) {
    return false;
  }
  // error
  return true;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Response__fini(i2c_pwm_board_msgs__srv__ServosConfig_Response * msg)
{
  if (!msg) {
    return;
  }
  // error
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__are_equal(const i2c_pwm_board_msgs__srv__ServosConfig_Response * lhs, const i2c_pwm_board_msgs__srv__ServosConfig_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error
  if (lhs->error != rhs->error) {
    return false;
  }
  return true;
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__copy(
  const i2c_pwm_board_msgs__srv__ServosConfig_Response * input,
  i2c_pwm_board_msgs__srv__ServosConfig_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // error
  output->error = input->error;
  return true;
}

i2c_pwm_board_msgs__srv__ServosConfig_Response *
i2c_pwm_board_msgs__srv__ServosConfig_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Response * msg = (i2c_pwm_board_msgs__srv__ServosConfig_Response *)allocator.allocate(sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Response));
  bool success = i2c_pwm_board_msgs__srv__ServosConfig_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Response__destroy(i2c_pwm_board_msgs__srv__ServosConfig_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i2c_pwm_board_msgs__srv__ServosConfig_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__init(i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Response * data = NULL;

  if (size) {
    data = (i2c_pwm_board_msgs__srv__ServosConfig_Response *)allocator.zero_allocate(size, sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i2c_pwm_board_msgs__srv__ServosConfig_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i2c_pwm_board_msgs__srv__ServosConfig_Response__fini(&data[i - 1]);
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
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__fini(i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * array)
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
      i2c_pwm_board_msgs__srv__ServosConfig_Response__fini(&array->data[i]);
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

i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence *
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * array = (i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence *)allocator.allocate(sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__destroy(i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__are_equal(const i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * lhs, const i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i2c_pwm_board_msgs__srv__ServosConfig_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence__copy(
  const i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * input,
  i2c_pwm_board_msgs__srv__ServosConfig_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i2c_pwm_board_msgs__srv__ServosConfig_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i2c_pwm_board_msgs__srv__ServosConfig_Response * data =
      (i2c_pwm_board_msgs__srv__ServosConfig_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i2c_pwm_board_msgs__srv__ServosConfig_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i2c_pwm_board_msgs__srv__ServosConfig_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i2c_pwm_board_msgs__srv__ServosConfig_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
