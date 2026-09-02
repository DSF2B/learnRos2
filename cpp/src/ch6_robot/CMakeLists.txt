cmake_minimum_required(VERSION 3.8)
project(ch6_robot)

# 纯描述包：没有 C++ 代码，只把 urdf/config/launch 安装到 share 目录
find_package(ament_cmake REQUIRED)

install(DIRECTORY urdf config launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
