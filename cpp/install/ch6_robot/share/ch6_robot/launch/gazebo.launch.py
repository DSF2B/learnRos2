# 完整仿真：Gazebo 物理世界 + 生成机器人 + 加载 ros2_control 控制器
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.substitutions import Command
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory('ch6_robot')
    xacro_file = os.path.join(pkg_share, 'urdf', 'robot.xacro')

    # 1. 启动 Gazebo（-s 加载 ros 插件，Gazebo 里才认 URDF 的 <gazebo> 标签）
    gazebo = ExecuteProcess(
        cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
        output='screen')

    # 2. robot_state_publisher 展开 xacro 并发布 TF
    #    use_sim_time：仿真里时间由 Gazebo 的 /clock 提供，不用系统时间
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': Command(['xacro ', xacro_file]),
                     'use_sim_time': True}],
        output='screen')

    # 3. 把模型生成到 Gazebo 世界里
    spawn_entity = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', 'robot_description', '-entity', 'mini_car'],
        output='screen')

    # 4. controller_manager spawner：加载并启动两个控制器
    jsb_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
        output='screen')
    ddc_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['diff_drive_controller'],
        output='screen')

    return LaunchDescription([
        gazebo, robot_state_publisher, spawn_entity, jsb_spawner, ddc_spawner,
    ])
