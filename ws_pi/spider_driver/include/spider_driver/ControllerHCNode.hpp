#pragma once

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/float64.hpp"
#include "HCSR04.hpp"
#include <vector>
#include <memory>

namespace controller_hc
{

class ControllerHCNode : public rclcpp::Node
{
public:
    ControllerHCNode();
    ~ControllerHCNode() = default;

private:
    void timer_callback();
    void publisher(double angle);

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr laser_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr hc_servo_pub_;

    HCSR04 ultrasonic_driver_;

    const int steps_ = 172;
    std::vector<float> sonar_readings_;
    double min_angle_;
    double max_angle_;
    int current_step_ = 0;
    int direction_ = 1;
};

}  // namespace controller
