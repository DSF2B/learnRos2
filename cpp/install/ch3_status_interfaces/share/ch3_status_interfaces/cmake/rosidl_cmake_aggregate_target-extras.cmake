# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ch3_status_interfaces::ch3_status_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ch3_status_interfaces_TARGETS}.
if(ch3_status_interfaces_TARGETS AND NOT TARGET ch3_status_interfaces::ch3_status_interfaces)
  add_library(ch3_status_interfaces::ch3_status_interfaces INTERFACE IMPORTED)
  set_target_properties(ch3_status_interfaces::ch3_status_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ch3_status_interfaces_TARGETS}")
endif()
