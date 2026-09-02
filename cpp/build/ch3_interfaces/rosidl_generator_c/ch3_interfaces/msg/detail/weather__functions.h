// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice

#ifndef CH3_INTERFACES__MSG__DETAIL__WEATHER__FUNCTIONS_H_
#define CH3_INTERFACES__MSG__DETAIL__WEATHER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ch3_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ch3_interfaces/msg/detail/weather__struct.h"

/// Initialize msg/Weather message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ch3_interfaces__msg__Weather
 * )) before or use
 * ch3_interfaces__msg__Weather__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__init(ch3_interfaces__msg__Weather * msg);

/// Finalize msg/Weather message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
void
ch3_interfaces__msg__Weather__fini(ch3_interfaces__msg__Weather * msg);

/// Create msg/Weather message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ch3_interfaces__msg__Weather__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
ch3_interfaces__msg__Weather *
ch3_interfaces__msg__Weather__create();

/// Destroy msg/Weather message.
/**
 * It calls
 * ch3_interfaces__msg__Weather__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
void
ch3_interfaces__msg__Weather__destroy(ch3_interfaces__msg__Weather * msg);

/// Check for msg/Weather message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__are_equal(const ch3_interfaces__msg__Weather * lhs, const ch3_interfaces__msg__Weather * rhs);

/// Copy a msg/Weather message.
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
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__copy(
  const ch3_interfaces__msg__Weather * input,
  ch3_interfaces__msg__Weather * output);

/// Initialize array of msg/Weather messages.
/**
 * It allocates the memory for the number of elements and calls
 * ch3_interfaces__msg__Weather__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__Sequence__init(ch3_interfaces__msg__Weather__Sequence * array, size_t size);

/// Finalize array of msg/Weather messages.
/**
 * It calls
 * ch3_interfaces__msg__Weather__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
void
ch3_interfaces__msg__Weather__Sequence__fini(ch3_interfaces__msg__Weather__Sequence * array);

/// Create array of msg/Weather messages.
/**
 * It allocates the memory for the array and calls
 * ch3_interfaces__msg__Weather__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
ch3_interfaces__msg__Weather__Sequence *
ch3_interfaces__msg__Weather__Sequence__create(size_t size);

/// Destroy array of msg/Weather messages.
/**
 * It calls
 * ch3_interfaces__msg__Weather__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
void
ch3_interfaces__msg__Weather__Sequence__destroy(ch3_interfaces__msg__Weather__Sequence * array);

/// Check for msg/Weather message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__Sequence__are_equal(const ch3_interfaces__msg__Weather__Sequence * lhs, const ch3_interfaces__msg__Weather__Sequence * rhs);

/// Copy an array of msg/Weather messages.
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
ROSIDL_GENERATOR_C_PUBLIC_ch3_interfaces
bool
ch3_interfaces__msg__Weather__Sequence__copy(
  const ch3_interfaces__msg__Weather__Sequence * input,
  ch3_interfaces__msg__Weather__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CH3_INTERFACES__MSG__DETAIL__WEATHER__FUNCTIONS_H_
