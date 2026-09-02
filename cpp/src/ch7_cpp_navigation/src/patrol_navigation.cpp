// 自动巡检机器人：发布初始位姿 -> 依次前往 4 个航点 -> 循环巡检
// 运行前提：Nav2 已启动（导航 action 服务 navigate_to_pose 在线）
#include <chrono>
#include <cmath>
#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"

using namespace std::chrono_literals;
using NavigateToPose = nav2_msgs::action::NavigateToPose;
using GoalHandle = rclcpp_action::ClientGoalHandle<NavigateToPose>;

// 航点：位置 + 朝向（map 坐标系）
struct Waypoint
{
  double x;
  double y;
  double yaw;
};

class PatrolNavigation : public rclcpp::Node
{
public:
  PatrolNavigation() : Node("patrol_navigation")
  {
    // 巡检路线：4 个航点构成一个矩形回路
    waypoints_ = {
      {1.0, 1.0, 0.0},
      {4.0, 1.0, M_PI_2},
      {4.0, 3.0, M_PI},
      {1.0, 3.0, -M_PI_2},
    };

    // 初始位姿参数 [x, y, yaw]，启动时发布到 /initialpose 供 AMCL 初始化
    this->declare_parameter<std::vector<double>>("initial_pose", {0.0, 0.0, 0.0});

    initial_pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
      "/initialpose", 10);
    action_client_ = rclcpp_action::create_client<NavigateToPose>(this, "navigate_to_pose");

    this->publish_initial_pose();
    // 每秒检查一次导航服务是否上线，上线后开始巡检
    timer_ = this->create_wall_timer(1s, [this]() { this->try_start_patrol(); });
    RCLCPP_INFO(this->get_logger(), "patrol_navigation 就绪，等待 Nav2 导航服务...");
  }

private:
  void publish_initial_pose()
  {
    auto params = this->get_parameter("initial_pose").as_double_array();
    if (params.size() < 3) {
      RCLCPP_ERROR(this->get_logger(), "initial_pose 参数需要 [x, y, yaw] 三个值");
      return;
    }
    auto msg = geometry_msgs::msg::PoseWithCovarianceStamped();
    msg.header.frame_id = "map";
    msg.header.stamp = this->now();
    msg.pose.pose.position.x = params[0];
    msg.pose.pose.position.y = params[1];
    double half = params[2] / 2.0;   // yaw -> 四元数
    msg.pose.pose.orientation.z = std::sin(half);
    msg.pose.pose.orientation.w = std::cos(half);
    // 协方差略大于 0，表示"比较确定"
    msg.pose.covariance[0] = 0.25;
    msg.pose.covariance[7] = 0.25;
    msg.pose.covariance[35] = 0.0685;
    initial_pose_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "已发布初始位姿 (%.2f, %.2f, yaw=%.2f)",
      params[0], params[1], params[2]);
  }

  void try_start_patrol()
  {
    if (patrol_started_) {
      return;
    }
    // 服务没上线就继续等（wait 0s 立即返回，不阻塞）
    if (!action_client_->wait_for_action_server(0s)) {
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
        "等待 navigate_to_pose action 服务上线...");
      return;
    }
    patrol_started_ = true;
    timer_->cancel();
    RCLCPP_INFO(this->get_logger(), "导航服务已上线，开始巡检");
    this->send_next_waypoint();
  }

  void send_next_waypoint()
  {
    // 走完一圈回到起点，继续循环（巡检任务通常 24h 循环执行）
    if (waypoint_index_ >= waypoints_.size()) {
      waypoint_index_ = 0;
      RCLCPP_INFO(this->get_logger(), "完成一圈巡检，开始新一圈");
    }

    const Waypoint & wp = waypoints_[waypoint_index_];

    auto goal = NavigateToPose::Goal();
    goal.pose.header.frame_id = "map";
    goal.pose.header.stamp = this->now();
    goal.pose.pose.position.x = wp.x;
    goal.pose.pose.position.y = wp.y;
    double half = wp.yaw / 2.0;
    goal.pose.pose.orientation.z = std::sin(half);
    goal.pose.pose.orientation.w = std::cos(half);

    RCLCPP_INFO(this->get_logger(), "目标航点 %d: (%.1f, %.1f, yaw=%.1f°)",
      waypoint_index_, wp.x, wp.y, wp.yaw * 180.0 / M_PI);

    auto send_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();

    // 进度反馈：每秒节流打印剩余距离
    send_options.feedback_callback =
      [this](GoalHandle::SharedPtr,
        const std::shared_ptr<const NavigateToPose::Feedback> feedback)
      {
        auto now = this->now();
        if (now - last_feedback_log_ < 1s) {
          return;
        }
        last_feedback_log_ = now;
        RCLCPP_INFO(this->get_logger(), "前往航点 %d 中，剩余 %.2f m",
          waypoint_index_, feedback->distance_remaining);
      };

    // 结果回调：成功则去下一个航点，失败记录后继续（真实系统应重试/告警）
    send_options.result_callback =
      [this](const GoalHandle::WrappedResult & result)
      {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
          RCLCPP_INFO(this->get_logger(), "航点 %d 到达", waypoint_index_);
        } else {
          RCLCPP_WARN(this->get_logger(), "航点 %d 失败 (code=%d)，跳过继续",
            waypoint_index_, static_cast<int>(result.code));
        }
        waypoint_index_++;
        this->send_next_waypoint();
      };

    action_client_->async_send_goal(goal, send_options);
  }

  std::vector<Waypoint> waypoints_;
  size_t waypoint_index_{0};
  bool patrol_started_{false};

  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr initial_pose_pub_;
  rclcpp_action::Client<NavigateToPose>::SharedPtr action_client_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Time last_feedback_log_{0, 0, RCL_ROS_TIME};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PatrolNavigation>());
  rclcpp::shutdown();
  return 0;
}
