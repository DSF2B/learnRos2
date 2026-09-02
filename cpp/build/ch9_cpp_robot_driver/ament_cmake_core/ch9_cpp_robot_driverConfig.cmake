# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ch9_cpp_robot_driver_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ch9_cpp_robot_driver_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ch9_cpp_robot_driver_FOUND FALSE)
  elseif(NOT ch9_cpp_robot_driver_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ch9_cpp_robot_driver_FOUND FALSE)
  endif()
  return()
endif()
set(_ch9_cpp_robot_driver_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ch9_cpp_robot_driver_FIND_QUIETLY)
  message(STATUS "Found ch9_cpp_robot_driver: 0.0.0 (${ch9_cpp_robot_driver_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ch9_cpp_robot_driver' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ch9_cpp_robot_driver_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ch9_cpp_robot_driver_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ch9_cpp_robot_driver_DIR}/${_extra}")
endforeach()
