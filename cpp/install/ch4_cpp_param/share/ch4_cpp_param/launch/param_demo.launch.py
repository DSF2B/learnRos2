# 一条命令同时启动两个参数节点，体会 launch 的威力
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # 实例一：名字/参数在 launch 里注入，代码一行不改
        Node(
            package='ch4_cpp_param',
            executable='param_demo',
            name='demo1',
            parameters=[{'robot_name': '巡检员一号', 'speed': 0.8}],
        ),
        # 实例二：同名节点不冲突，参数互相独立
        Node(
            package='ch4_cpp_param',
            executable='param_demo',
            name='demo2',
            parameters=[{'robot_name': '巡检员二号', 'speed': 1.2}],
        ),
    ])
