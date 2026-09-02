# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ch10_cpp_advanced_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ch10_cpp_advanced_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ch10_cpp_advanced_FOUND FALSE)
  elseif(NOT ch10_cpp_advanced_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ch10_cpp_advanced_FOUND FALSE)
  endif()
  return()
endif()
set(_ch10_cpp_advanced_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ch10_cpp_advanced_FIND_QUIETLY)
  message(STATUS "Found ch10_cpp_advanced: 0.0.0 (${ch10_cpp_advanced_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ch10_cpp_advanced' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ch10_cpp_advanced_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ch10_cpp_advanced_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ch10_cpp_advanced_DIR}/${_extra}")
endforeach()
