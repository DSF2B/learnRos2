#include "ch8_custom_planner/straight_line_planner.hpp"

#include <algorithm>
#include <cmath>

#include "pluginlib/class_list_macros.hpp"
#include "rclcpp/rclcpp.hpp"

namespace ch8_custom_planner
{

void StraightLinePlanner::configure(
  const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
  std::string name,
  std::shared_ptr<tf2_ros::Buffer> tf,
  std::shared_ptr<nav2_costmap_2d::Costmap2DROS> costmap_ros)
{
  node_ = parent;
  name_ = name;
  tf_ = tf;
  costmap_ = costmap_ros;
  logger_ = node_.lock()->get_logger();
  RCLCPP_INFO(logger_, "StraightLinePlanner [%s] 已配置", name_.c_str());
}

void StraightLinePlanner::activate() {}

void StraightLinePlanner::deactivate() {}

void StraightLinePlanner::cleanup() {}

nav_msgs::msg::Path StraightLinePlanner::createPlan(
  const geometry_msgs::msg::PoseStamped & start,
  const geometry_msgs::msg::PoseStamped & goal)
{
  nav_msgs::msg::Path path;
  path.header.stamp = node_.lock()->now();
  path.header.frame_id = start.header.frame_id;

  // 直线距离，每 0.05m 取一个路径点
  double dx = goal.pose.position.x - start.pose.position.x;
  double dy = goal.pose.position.y - start.pose.position.y;
  double dist = std::hypot(dx, dy);
  int n = std::max(1, static_cast<int>(dist / 0.05));

  RCLCPP_INFO(logger_, "规划直线路径：起点(%.2f,%.2f) -> 终点(%.2f,%.2f)，共 %d 个点",
    start.pose.position.x, start.pose.position.y,
    goal.pose.position.x, goal.pose.position.y, n + 1);

  for (int i = 0; i <= n; ++i) {
    geometry_msgs::msg::PoseStamped pose;
    pose.header = path.header;
    pose.pose.position.x = start.pose.position.x + dx * i / n;
    pose.pose.position.y = start.pose.position.y + dy * i / n;
    // 朝向统一用终点朝向（简单做法；更平滑的做法是朝向下一路径点）
    pose.pose.orientation = goal.pose.orientation;
    path.poses.push_back(pose);
  }
  return path;
}

}  // namespace ch8_custom_planner

// pluginlib 注册宏：类名 -> 完整类型，供运行时按名字加载
PLUGINLIB_EXPORT_CLASS(ch8_custom_planner::StraightLinePlanner, nav2_core::GlobalPlanner)
