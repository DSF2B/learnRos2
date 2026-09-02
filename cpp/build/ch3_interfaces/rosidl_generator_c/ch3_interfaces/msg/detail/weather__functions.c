// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice
#include "ch3_interfaces/msg/detail/weather__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `condition`
#include "rosidl_runtime_c/string_functions.h"

bool
ch3_interfaces__msg__Weather__init(ch3_interfaces__msg__Weather * msg)
{
  if (!msg) {
    return false;
  }
  // temperature
  // humidity
  // condition
  if (!rosidl_runtime_c__String__init(&msg->condition)) {
    ch3_interfaces__msg__Weather__fini(msg);
    return false;
  }
  return true;
}

void
ch3_interfaces__msg__Weather__fini(ch3_interfaces__msg__Weather * msg)
{
  if (!msg) {
    return;
  }
  // temperature
  // humidity
  // condition
  rosidl_runtime_c__String__fini(&msg->condition);
}

bool
ch3_interfaces__msg__Weather__are_equal(const ch3_interfaces__msg__Weather * lhs, const ch3_interfaces__msg__Weather * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // humidity
  if (lhs->humidity != rhs->humidity) {
    return false;
  }
  // condition
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->condition), &(rhs->condition)))
  {
    return false;
  }
  return true;
}

bool
ch3_interfaces__msg__Weather__copy(
  const ch3_interfaces__msg__Weather * input,
  ch3_interfaces__msg__Weather * output)
{
  if (!input || !output) {
    return false;
  }
  // temperature
  output->temperature = input->temperature;
  // humidity
  output->humidity = input->humidity;
  // condition
  if (!rosidl_runtime_c__String__copy(
      &(input->condition), &(output->condition)))
  {
    return false;
  }
  return true;
}

ch3_interfaces__msg__Weather *
ch3_interfaces__msg__Weather__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ch3_interfaces__msg__Weather * msg = (ch3_interfaces__msg__Weather *)allocator.allocate(sizeof(ch3_interfaces__msg__Weather), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ch3_interfaces__msg__Weather));
  bool success = ch3_interfaces__msg__Weather__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ch3_interfaces__msg__Weather__destroy(ch3_interfaces__msg__Weather * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ch3_interfaces__msg__Weather__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ch3_interfaces__msg__Weather__Sequence__init(ch3_interfaces__msg__Weather__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ch3_interfaces__msg__Weather * data = NULL;

  if (size) {
    data = (ch3_interfaces__msg__Weather *)allocator.zero_allocate(size, sizeof(ch3_interfaces__msg__Weather), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ch3_interfaces__msg__Weather__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ch3_interfaces__msg__Weather__fini(&data[i - 1]);
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
ch3_interfaces__msg__Weather__Sequence__fini(ch3_interfaces__msg__Weather__Sequence * array)
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
      ch3_interfaces__msg__Weather__fini(&array->data[i]);
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

ch3_interfaces__msg__Weather__Sequence *
ch3_interfaces__msg__Weather__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ch3_interfaces__msg__Weather__Sequence * array = (ch3_interfaces__msg__Weather__Sequence *)allocator.allocate(sizeof(ch3_interfaces__msg__Weather__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ch3_interfaces__msg__Weather__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ch3_interfaces__msg__Weather__Sequence__destroy(ch3_interfaces__msg__Weather__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ch3_interfaces__msg__Weather__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ch3_interfaces__msg__Weather__Sequence__are_equal(const ch3_interfaces__msg__Weather__Sequence * lhs, const ch3_interfaces__msg__Weather__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ch3_interfaces__msg__Weather__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ch3_interfaces__msg__Weather__Sequence__copy(
  const ch3_interfaces__msg__Weather__Sequence * input,
  ch3_interfaces__msg__Weather__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ch3_interfaces__msg__Weather);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ch3_interfaces__msg__Weather * data =
      (ch3_interfaces__msg__Weather *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ch3_interfaces__msg__Weather__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ch3_interfaces__msg__Weather__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ch3_interfaces__msg__Weather__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
