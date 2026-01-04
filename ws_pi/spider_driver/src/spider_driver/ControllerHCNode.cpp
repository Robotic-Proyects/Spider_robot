#include "spider_driver/ControllerHCNode.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

namespace controller_hc
{

ControllerHCNode::ControllerHCNode()
: Node("controller_hc_node"), ultrasonic_driver_(21, 20),
  blocked_(false), min_angle_(0.0), max_angle_(3.002)
{
    laser_pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/sonar_scan", 10);
    hc_servo_pub_ = this->create_publisher<std_msgs::msg::Float64>("/ultrasonic", 10);

    blocked_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "/blocked",
        10,
        std::bind(&ControllerHCNode::blocked_callback, this, std::placeholders::_1)
    );

    range_sub_ = this->create_subscription<std_msgs::msg::UInt8MultiArray>(
        "/range",
        10,
        std::bind(&ControllerHCNode::range_callback, this, std::placeholders::_1)
    );

    timer_ = this->create_wall_timer(20ms, std::bind(&ControllerHCNode::timer_callback, this));

    sonar_readings_.resize(final_step_ - initial_step_ + 1, -1.0f);
}

void ControllerHCNode::publisher(double angle)
{
    auto msg = std_msgs::msg::Float64();
    angle = (angle * 3.1415) / 180;
    msg.data = angle;
    hc_servo_pub_->publish(msg);
}

void ControllerHCNode::blocked_callback(
    const std_msgs::msg::UInt8::SharedPtr msg)
{
    blocked_ = (msg->data == 1);
}

void ControllerHCNode::range_callback(
    const std_msgs::msg::UInt8MultiArray::SharedPtr msg)
{ 
    if (msg->data.size() >= 2) {
        initial_step_ = msg->data[0];
        final_step_ = msg->data[1];

        int size = final_step_ - initial_step_ + 1;
        sonar_readings_.resize(size, -1.0f);

        current_step_ = initial_step_;
        direction_ = 1;
    }
}

void ControllerHCNode::timer_callback()
{
    if (!blocked_) {
        // Publica el ángulo actual
        publisher(current_step_);

        // Lee la distancia del sensor
        double distance = ultrasonic_driver_.read();
        sonar_readings_[current_step_] = distance;

        // Actualiza el paso según la dirección
        current_step_ += direction_;

        // Revisa límites usando initial_step_ y final_step_
        if (current_step_ >= final_step_) {
            current_step_ = final_step_;
            direction_ = -1;
        } else if (current_step_ <= initial_step_) {
            current_step_ = initial_step_;
            direction_ = 1;
        }

        // Publica LaserScan al inicio o al final del barrido
        if (current_step_ == initial_step_ || current_step_ == final_step_) {
            sensor_msgs::msg::LaserScan scan_msg;
            scan_msg.header.stamp = this->now();
            scan_msg.header.frame_id = "sonar_link";

            scan_msg.angle_min = min_angle_;
            scan_msg.angle_max = max_angle_;
            scan_msg.angle_increment = 1;
            scan_msg.range_min = 0.02;
            scan_msg.range_max = 4.0;
            scan_msg.ranges = sonar_readings_;

            laser_pub_->publish(scan_msg);
        }
    } else {
        // Si está bloqueado, publica solo la lectura actual en la posición 0
        double distance = ultrasonic_driver_.read();
        sonar_readings_[0] = distance;

        sensor_msgs::msg::LaserScan scan_msg;
        scan_msg.header.stamp = this->now();
        scan_msg.header.frame_id = "sonar_link";

        scan_msg.angle_min = min_angle_;
        scan_msg.angle_max = max_angle_;
        scan_msg.angle_increment = 1;
        scan_msg.range_min = 0.02;
        scan_msg.range_max = 4.0;
        scan_msg.ranges = {static_cast<float>(distance)};

        laser_pub_->publish(scan_msg);
    }
}

}  // namespace controller_hc
