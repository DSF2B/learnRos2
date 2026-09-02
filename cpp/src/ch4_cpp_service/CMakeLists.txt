cmake_minimum_required(VERSION 3.8)
project(ch4_cpp_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 由 srv/TurtlePatrol.srv 生成 C++/Python 代码
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/TurtlePatrol.srv"
)

add_executable(patrol_server src/patrol_server.cpp)
add_executable(patrol_client src/patrol_client.cpp)

# 链接本包自己生成的 srv 代码（官方推荐写法）
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

foreach(target patrol_server patrol_client)
  ament_target_dependencies(${target} rclcpp geometry_msgs)
  target_link_libraries(${target} "${cpp_typesupport_target}")
endforeach()

install(TARGETS patrol_server patrol_client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
