#include "spider_driver/ControllerHCNode.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

namespace controller_hc
{

ControllerHCNode::ControllerHCNode()
: Node("controller_hc_node"), ultrasonic_driver_(21, 20), 
    sonar_readings_(steps_, 0.0), min_angle_(0.0), max_angle_(3.002)
{
    laser_pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/sonar_scan", 10);
    hc_servo_pub_ = this->create_publisher<std_msgs::msg::Float64>("/ultrasonic", 10);
    timer_ = this->create_wall_timer(20ms, std::bind(&ControllerHCNode::timer_callback, this));
}

void ControllerHCNode::publisher(double angle)
{
    auto msg = std_msgs::msg::Float64();
    angle = (angle * 3.1415) / 180;
    msg.data = angle;
    hc_servo_pub_->publish(msg);
}

void ControllerHCNode::timer_callback()
{
    double step = (max_angle_ - min_angle_) / (steps_ - 1);

    publisher(current_step_);

    double distance = ultrasonic_driver_.read();
    sonar_readings_[current_step_] = distance;

    current_step_ += direction_;

    if (current_step_ >= steps_ - 1)
    {
        current_step_ = steps_ - 1;
        direction_ = -1;  // cambiar a vuelta
    }
    else if (current_step_ <= 0)
    {
        current_step_ = 0;
        direction_ = 1;   // cambiar a ida
    }

    if (current_step_ == 0 && direction_ == 1)
    {
        sensor_msgs::msg::LaserScan scan_msg;
        scan_msg.header.stamp = this->now();
        scan_msg.header.frame_id = "sonar_link";

        scan_msg.angle_min = min_angle_;
        scan_msg.angle_max = max_angle_;
        scan_msg.angle_increment = step;
        scan_msg.range_min = 0.02;
        scan_msg.range_max = 4.0;
        scan_msg.ranges = sonar_readings_;

        laser_pub_->publish(scan_msg);
    }
}


}  // namespace controller
