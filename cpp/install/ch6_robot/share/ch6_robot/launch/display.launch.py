# 只在 RViz2 里显示模型：xacro 展开 + robot_state_publisher 发布 TF
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory('ch6_robot')
    xacro_file = os.path.join(pkg_share, 'urdf', 'robot.xacro')

    return LaunchDescription([
        DeclareLaunchArgument(
            'gui', default_value='true',
            description='是否打开关节调节面板（joint_state_publisher_gui）'),

        # robot_state_publisher：读取 robot_description 参数，发布机器人各 link 的 TF
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': Command(['xacro ', xacro_file])}],
        ),

        # joint_state_publisher_gui：用滑动条手动控制各关节，测试模型用
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            condition=IfCondition(LaunchConfiguration('gui')),
        ),
    ])
