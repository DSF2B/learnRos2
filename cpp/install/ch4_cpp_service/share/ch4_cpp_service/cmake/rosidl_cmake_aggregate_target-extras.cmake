# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ch4_cpp_service::ch4_cpp_service
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ch4_cpp_service_TARGETS}.
if(ch4_cpp_service_TARGETS AND NOT TARGET ch4_cpp_service::ch4_cpp_service)
  add_library(ch4_cpp_service::ch4_cpp_service INTERFACE IMPORTED)
  set_target_properties(ch4_cpp_service::ch4_cpp_service PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ch4_cpp_service_TARGETS}")
endif()
