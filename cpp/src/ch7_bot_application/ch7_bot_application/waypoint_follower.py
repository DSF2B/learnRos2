from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import rclpy
import math

def main():
   rclpy.init()
   nav=BasicNavigator()
   goal_poses=[]
   for i in range(0,5):
      goal_pose=PoseStamped()
      goal_pose.header.frame_id="map"
      goal_pose.header.stamp=nav.get_clock().now().to_msg()
      goal_pose.pose.position.x=float(i)
      goal_pose.pose.position.y=1.0
      goal_pose.pose.orientation.w=1.0
      goal_poses.append(goal_pose)
   nav.waitUntilNav2Active()
   nav.followWaypoints(goal_poses)
   while not nav.isTaskComplete():
      feedback=nav.getFeedback()
      nav.get_logger().info(f'路点编号{feedback.current_waypoint}')
      # nav.cancelTask()
   result=nav.getResult()
   nav.get_logger().info(f'导航结果{result}')
