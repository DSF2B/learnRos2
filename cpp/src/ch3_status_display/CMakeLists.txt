cmake_minimum_required(VERSION 3.8)
project(ch3_status_display)

# Qt 装在 /opt/Qt（不在系统默认路径），让安装后的可执行文件带上 Qt 库路径，运行时不用配 LD_LIBRARY_PATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ch3_status_interfaces REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(hello_qt
  src/hello_qt.cpp)
target_link_libraries(hello_qt Qt6::Widgets)

add_executable(sys_status_display
  src/sys_status_display.cpp)
target_link_libraries(sys_status_display Qt6::Widgets)
ament_target_dependencies(sys_status_display rclcpp ch3_status_interfaces)
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

install(TARGETS hello_qt DESTINATION lib/${PROJECT_NAME})
install(TARGETS sys_status_display DESTINATION lib/${PROJECT_NAME})
ament_package()
