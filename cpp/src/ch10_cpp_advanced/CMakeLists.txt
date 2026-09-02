cmake_minimum_required(VERSION 3.8)
project(ch10_cpp_advanced)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(message_filters REQUIRED)

# --- QoS ---
add_executable(qos_pub src/qos_pub.cpp)
ament_target_dependencies(qos_pub rclcpp std_msgs)
add_executable(qos_sub src/qos_sub.cpp)
ament_target_dependencies(qos_sub rclcpp std_msgs)

# --- 执行器与回调组 ---
add_executable(callback_group_demo src/callback_group_demo.cpp)
ament_target_dependencies(callback_group_demo rclcpp std_msgs)

# --- 生命周期节点 ---
add_executable(lifecycle_demo src/lifecycle_demo.cpp)
ament_target_dependencies(lifecycle_demo rclcpp rclcpp_lifecycle std_msgs)

# --- 节点组合：组件库 ---
add_library(talker_component SHARED src/talker_component.cpp)
ament_target_dependencies(talker_component rclcpp rclcpp_components std_msgs)
rclcpp_components_register_nodes(talker_component "composition::TalkerComponent")

add_library(listener_component SHARED src/listener_component.cpp)
ament_target_dependencies(listener_component rclcpp rclcpp_components std_msgs)
rclcpp_components_register_nodes(listener_component "composition::ListenerComponent")

# 组件也可以作为普通可执行文件独立运行
add_executable(standalone_talker src/standalone_talker.cpp)
ament_target_dependencies(standalone_talker rclcpp rclcpp_components std_msgs)

# 手动组合：一个进程内多个组件节点
add_executable(manual_composition src/manual_composition.cpp)
ament_target_dependencies(manual_composition rclcpp rclcpp_components std_msgs)

# --- 消息过滤器 ---
add_executable(message_filter_demo src/message_filter_demo.cpp)
ament_target_dependencies(message_filter_demo rclcpp std_msgs message_filters)

install(TARGETS
  qos_pub qos_sub callback_group_demo lifecycle_demo
  standalone_talker manual_composition message_filter_demo
  DESTINATION lib/${PROJECT_NAME})
install(TARGETS talker_component listener_component
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin)

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
