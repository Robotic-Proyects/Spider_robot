#ifndef SPIDER_CONTROLLER__CONTROLLER_HPP_
#define SPIDER_CONTROLLER__CONTROLLER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "spider_msgs/msg/spider_leg.hpp"
#include "i2c_pwm_board_msgs/msg/servo_array.hpp"
#include "i2c_pwm_board_msgs/msg/servo_config.hpp"
#include "i2c_pwm_board_msgs/srv/servos_config.hpp"
#include "i2c_pwm_board_msgs/srv/int_value.hpp"

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

    rclcpp::Publisher<i2c_pwm_board_msgs::msg::ServoArray>::SharedPtr servo_pub_;

    void frontleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void frontright(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void backright(const spider_msgs::msg::SpiderLeg::SharedPtr msg);
    void backleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg);

    int pca_frontleft_[3];
    int pca_frontright_[3];
    int pca_backright_[3];
    int pca_backleft_[3];

    void configure_all_servos();
    void move_servo(const int channels[3], const spider_msgs::msg::SpiderLeg::SharedPtr msg);
};
}

#endif  // SPIDER_CONTROLLER__CONTROLLER_HPP_