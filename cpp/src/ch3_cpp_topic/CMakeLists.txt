cmake_minimum_required(VERSION 3.8)
project(ch3_cpp_topic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(ch3_interfaces REQUIRED)

# --- 基础话题：talker / listener ---
add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

# --- 自定义消息：weather ---
add_executable(weather_pub src/weather_pub.cpp)
ament_target_dependencies(weather_pub rclcpp ch3_interfaces)

add_executable(weather_sub src/weather_sub.cpp)
ament_target_dependencies(weather_sub rclcpp ch3_interfaces)

# --- 闭环控制：海龟画圆 ---
add_executable(turtle_circle src/turtle_circle.cpp)
ament_target_dependencies(turtle_circle rclcpp turtlesim geometry_msgs)

add_executable(turtle_control src/turtle_control.cpp)
ament_target_dependencies(turtle_control rclcpp turtlesim geometry_msgs)

install(TARGETS talker listener weather_pub weather_sub turtle_circle turtle_control
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
