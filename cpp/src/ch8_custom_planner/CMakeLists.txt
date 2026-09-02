cmake_minimum_required(VERSION 3.8)
project(ch8_custom_planner)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(nav2_core REQUIRED)
find_package(nav2_util REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(pluginlib REQUIRED)

# 插件编译为动态库，pluginlib 运行时按名字加载
add_library(straight_line_planner SHARED src/straight_line_planner.cpp)
ament_target_dependencies(straight_line_planner
  rclcpp rclcpp_lifecycle nav2_core nav2_util nav2_costmap_2d
  nav_msgs geometry_msgs tf2_ros pluginlib)
target_include_directories(straight_line_planner PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/>)

# 安装库、头文件、插件清单
install(TARGETS straight_line_planner
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include/)
install(FILES plugins.xml DESTINATION share/${PROJECT_NAME})

# 在 ament 索引里注册插件描述（nav2_core 运行时靠它发现插件）
pluginlib_export_plugin_description_file(nav2_core plugins.xml)

ament_package()
