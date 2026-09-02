// 自定义全局规划器：两点直线插值（教学用，不做避障）
// 通过 pluginlib 动态加载进 Nav2，无需修改 Nav2 一行代码
#ifndef CH8_CUSTOM_PLANNER__STRAIGHT_LINE_PLANNER_HPP_
#define CH8_CUSTOM_PLANNER__STRAIGHT_LINE_PLANNER_HPP_

#include <memory>
#include <string>

#include "nav2_core/global_planner.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

namespace ch8_custom_planner
{

class StraightLinePlanner : public nav2_core::GlobalPlanner
{
public:
  StraightLinePlanner() = default;
  ~StraightLinePlanner() override = default;

  // 接口五个函数（继承 nav2_core::GlobalPlanner）：

  // 初始化：拿到父节点（logger/参数）、TF、代价地图（本教程用不到）
  void configure(
    const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
    std::string name,
    std::shared_ptr<tf2_ros::Buffer> tf,
    std::shared_ptr<nav2_costmap_2d::Costmap2DROS> costmap_ros) override;

  // 生命周期：教学插件无需资源管理，空实现即可
  void activate() override;
  void deactivate() override;
  void cleanup() override;

  // 核心：给定起点/终点，返回一条路径
  nav_msgs::msg::Path createPlan(
    const geometry_msgs::msg::PoseStamped & start,
    const geometry_msgs::msg::PoseStamped & goal) override;

private:
  rclcpp_lifecycle::LifecycleNode::WeakPtr node_;
  std::string name_;
  std::shared_ptr<tf2_ros::Buffer> tf_;
  std::shared_ptr<nav2_costmap_2d::Costmap2DROS> costmap_ros_;
  rclcpp::Logger logger_{rclcpp::get_logger("StraightLinePlanner")};
};

}  // namespace ch8_custom_planner

#endif  // CH8_CUSTOM_PLANNER__STRAIGHT_LINE_PLANNER_HPP_
