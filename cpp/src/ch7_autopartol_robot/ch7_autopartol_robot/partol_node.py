from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator,TaskResult
import rclpy
from rclpy.node import Node
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion,quaternion_from_euler
import math
from ch7_autopartol_interfaces.srv import SpeechText
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class PartolNode(BasicNavigator):
   def __init__(self, node_name='partol_node'):
      super().__init__(node_name)
      #声明参数
      self.declare_parameter('init_point',[0.0,0.0,0.0])
      self.declare_parameter('target_points',[0.0,0.0,0.0,1.0,1.0,1.57])
      self.declare_parameter('img_save_path','')

      self.init_point=self.get_parameter('init_point').value
      self.target_points=self.get_parameter('target_points').value
      self.img_save_path = self.get_parameter('img_save_path').value

      self.buffer = Buffer()
      self.listener = TransformListener(self.buffer, self)
      self.speech_client=self.create_client(SpeechText, 'speech_text')
      
      self.cv_bridge = CvBridge()
      self.latest_img=Node
      self.img_sub = self.create_subscription(Image, '/camera_sensor/image_raw', self.image_callback)

   def image_callback(self, msg):
      self.latest_img = msg.msg
      
   def record_img(self):
      if self.latest_img is not None:
         pose = self.get_current_pose()
         cv_image = self.cv_bridge.imgmsg_to_cv2(self.latest_img)
         cv2.imwrite(
            f'{self.img_save_path}img_{pose.translation.x:3.2f}_{pose.translation.y:3.2f}.png',
            cv_image
         )
      
   def get_pose_by_xyyaw(self,x,y,yaw):
      pose=PoseStamped()
      pose.header.frame_id='map'
      pose.pose.position.x=x
      pose.pose.position.y=y
      quat=quaternion_from_euler(0,0,yaw)
      pose.pose.orientation.x=quat[0]
      pose.pose.orientation.y=quat[1]
      pose.pose.orientation.z=quat[2]
      pose.pose.orientation.w=quat[3]
      return pose
      
   def init_robot_pose(self):
      self.init_point=self.get_parameter('init_point').value
      init_pose=self.get_pose_by_xyyaw(self.init_point[0], self.init_point[1], self.init_point[2])
      self.setInitialPose(init_pose)
      self.waitUntilNav2Active()
   
   def get_target_points(self):
      points=[]
      self.target_points=self.get_parameter('target_points').value
      for index in range(len(self.target_points)//3):
         x=self.target_points[index*3]
         y=self.target_points[index*3+1]
         yaw=self.target_points[index*3+2]
         points.append([x,y,yaw])
      return points
         
   def nav_to_pose(self, target_points):
      self.goToPose(target_points)
      while not self.isTaskComplete():
         feedback=self.getFeedback()
         self.get_logger().info(f'剩余距离{feedback.distance_remaining}')
      result=self.getResult()
      self.get_logger().info(f'导航结果{result}')
   
   def get_current_pose(self):
      while rclpy.ok():
         try:
            tf = self.buffer.lookup_transform(
                  'map', 'base_footprint', rclpy.time.Time(seconds=0), rclpy.time.Duration(seconds=1))
            transform = tf.transform
            self.get_logger().info(f'平移:{transform.translation}')
            return transform
         except Exception as e:
            self.get_logger().warn(f'不能够获取坐标变换，原因: {str(e)}')
      
   def speech_text(self, text):
      while not self.speech_client.wait_for_service(timeout_sec=1):
         self.get_logger().warn('语音服务未上线，等待中。。。')
      request = SpeechText.Request()
      request.text=text
      future = self.speech_client.call_async(request)
      rclpy.spin_until_future_complete(self,future)
      if future.result() is not None:
         result = future.result().result
         if result:
             self.get_logger().info(f'语音合成成功：{text}')
         else:
             self.get_logger().warn(f'语音合成失败：{text}')
      else:
         self.get_logger().warn('语音合成服务请求失败')
            
            
def main():
   rclpy.init()
   partol=PartolNode()
   partol.speech_text(text='正在初始化位置')
   partol.init_robot_pose()
   partol.speech_text(text='位置初始化完成')
   while rclpy.ok():
      points=partol.get_target_points()
      for point in points:
         x,y,yaw=point[0],point[1],point[2]
         target_pose=partol.get_pose_by_xyyaw(x,y,yaw)
         partol.speech_text(text=f'准备前往目标点{x},{y}')
         partol.nav_to_pose(target_pose)
         partol.speech_text(text=f"已到达目标点{x},{y}")
         partol.record_img()
         partol.speach_text(text=f"图像记录完成")
   rclpy.shutdown()