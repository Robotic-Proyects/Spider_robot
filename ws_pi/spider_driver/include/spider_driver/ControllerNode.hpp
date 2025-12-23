#ifndef SPIDER_CONTROLLER__CONTROLLER_HPP_
#define SPIDER_CONTROLLER__CONTROLLER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"

#include "PCA9685.hpp"
#include "spider_msgs/msg/spider_leg.hpp"
#include "spider_msgs/msg/spider_switch.hpp"
#include "spider_msgs/srv/servo_calibrate.hpp"

#include <yaml-cpp/yaml.h>
#include <fstream>
#include <string>

namespace controller
{
class ControllerNode : public rclcpp::Node
{
public:
    ControllerNode();
    ~ControllerNode();

private:
    rclcpp::Subscription<spider_msgs::msg::SpiderLeg>::SharedPtr frontleft_leg_;
    rclcpp::Subscription<spider_msgs::msg::SpiderLeg>::SharedPtr frontright_leg_;
    rclcpp::Subscription<spider_msgs::msg::SpiderLeg>::SharedPtr backright_leg_;
    rclcpp::Subscription<spider_msgs::msg::SpiderLeg>::SharedPtr backleft_leg_;

    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr ultrasonic_sub_;

    PCA9685 pca_;

    void ultrasonic(const std_msgs::msg::Float64::SharedPtr msg);

    void frontleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void frontright(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void backright(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void backleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg);

    int pca_frontleft_[3];
    int pca_frontright_[3];
    int pca_backright_[3];
    int pca_backleft_[3];

    int ultrasonic_channel_;

    double frontleft_pose_[3];
    double frontright_pose_[3];
    double backright_pose_[3];
    double backleft_pose_[3];

    double ultrasonic_pose_;

    double frontleft_target_[3];
    double frontright_target_[3];
    double backright_target_[3];
    double backleft_target_[3];

    double ultrasonic_target_;

    double initial_rad_;
    double smooth_;

    int last_pwm_[16];

    int oe_pin_;

    rclcpp::Subscription<spider_msgs::msg::SpiderSwitch>::SharedPtr oe_value_;
    void oe(const spider_msgs::msg::SpiderSwitch::SharedPtr msg);

    void oe_enable();
    void oe_disable();

    void configure_all_servos();
    void set_pose(double poses[3], double f_pose, double s_pose, double t_pose);
    int rad_to_pwm(double angle_rad, double min_rad = -1.56, double max_rad = 1.56,
                   int min_pwm = 150, int max_pwm = 600);

    void move_servo(const int channels[3], const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void update_servos();
    
    void calibrate_callback(
        const std::shared_ptr<spider_msgs::srv::ServoCalibrate::Request> request,
        std::shared_ptr<spider_msgs::srv::ServoCalibrate::Response> response);

    rclcpp::Service<spider_msgs::srv::ServoCalibrate>::SharedPtr calibrate_service_;
    rclcpp::TimerBase::SharedPtr timer_;
};
}

#endif  // SPIDER_CONTROLLER__CONTROLLER_HPP_