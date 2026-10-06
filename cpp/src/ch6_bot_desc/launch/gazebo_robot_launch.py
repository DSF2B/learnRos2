import launch
import launch_ros
from ament_index_python import get_package_share_directory
import os
import launch.launch_description_sources
import launch.event_handlers

def generate_launch_description():
   # 功能包路径
   urdf_package_path = get_package_share_directory('ch6_bot_desc')
   # bot xacro路径
   default_xacro_path = os.path.join(urdf_package_path, 'urdf','fishbot/fishbot.urdf.xacro')
   default_gazebo_world_path = os.path.join(urdf_package_path, 'world','custom_room.world')

   # 声明urdf目录参数，方便修改
   action_declare_arg_mode_path = launch.actions.DeclareLaunchArgument(
      name = 'model',
      default_value=str(default_xacro_path),
      description='加载的模型文件路径'
   )  
   
   #通过文件路径，获取内容，并转换成参数值对象，传入robot_state_publisher
   substitutions_command_result = launch.substitutions.Command(['xacro ',launch.substitutions.LaunchConfiguration('model')])
   robot_description_value = launch_ros.parameter_descriptions.ParameterValue(substitutions_command_result,value_type=str)
   
   action_robot_state_publisher = launch_ros.actions.Node(
      package='robot_state_publisher',
      executable='robot_state_publisher',
      parameters=[{'robot_description':robot_description_value}]
   )
   
   action_launch_gazebo = launch.actions.IncludeLaunchDescription(
      launch.launch_description_sources.PythonLaunchDescriptionSource(
         [get_package_share_directory('gazebo_ros'),'/launch','/gazebo.launch.py']
      ),
      launch_arguments=[('world',default_gazebo_world_path),('verbose','true')]
   )
   
   action_spawn_entity = launch_ros.actions.Node(
      package='gazebo_ros',
      executable='spawn_entity.py',
      # WSL2 下 gzserver 初始化世界需要约 30 秒（卡在音频设备），
      # 默认 30 秒等待超时太紧张，放宽到 120 秒
      arguments=['-topic','/robot_description','-entity','fishbot','-timeout','120']
   )

   # WSL2 没有音频设备，OpenAL 打开默认设备会干等 ~30 秒才报错，
   # 用 OpenAL 的 null 驱动跳过音频初始化，加快世界加载
   action_set_audio_env = launch.actions.SetEnvironmentVariable('ALSOFT_DRIVERS','null')

   # 加载并激活fishbot_joint_state_broadcaster
   action_load_joint_state_controller = launch.actions.ExecuteProcess(
      cmd='ros2 control load_controller fishbot_joint_state_broadcaster --set-state active'.split(' '),
      output='screen'
   )
   
   # 加载并激活fishbot_effort_controller
   # action_load_effort_controller = launch.actions.ExecuteProcess(
   #    cmd='ros2 control load_controller fishbot_effort_controller --set-state active'.split(' '),
   #    output='screen'
   # )
   
   # 加载并激活fishbot_diff_drive_controller
   action_load_diff_drive_controller = launch.actions.ExecuteProcess(
      cmd='ros2 control load_controller fishbot_diff_drive_controller --set-state active'.split(' '),
      output='screen'
   )
   return launch.LaunchDescription([
      action_declare_arg_mode_path,
      action_robot_state_publisher,
      action_set_audio_env,
      action_launch_gazebo,
      action_spawn_entity,
      launch.actions.RegisterEventHandler(
         event_handler=launch.event_handlers.OnProcessExit(
            target_action=action_spawn_entity,
            on_exit=[action_load_joint_state_controller]  
         )
      ),
      launch.actions.RegisterEventHandler(
         event_handler=launch.event_handlers.OnProcessExit(
            target_action=action_load_joint_state_controller,
            on_exit=[action_load_diff_drive_controller]  
         )
      )
   ])
