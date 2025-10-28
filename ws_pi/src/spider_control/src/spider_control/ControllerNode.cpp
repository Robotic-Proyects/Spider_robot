#include "spider_control/ControllerNode.hpp"

namespace controller
{
ControllerNode::ControllerNode()
: Node("controller_node")
{
    pca_frontleft_[0] = 0; pca_frontleft_[1] = 1; pca_frontleft_[2] = 2;
    pca_frontright_[0] = 3; pca_frontright_[1] = 4; pca_frontright_[2] = 5;
    pca_backright_[0] = 6; pca_backright_[1] = 7; pca_backright_[2] = 8;
    pca_backleft_[0] = 9; pca_backleft_[1] = 10; pca_backleft_[2] = 11;

    frontleft_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/frontleft", 10, std::bind(&ControllerNode::frontleft, this, std::placeholders::_1));

    frontright_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/frontright", 10, std::bind(&ControllerNode::frontright, this, std::placeholders::_1));

    backright_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/backright", 10, std::bind(&ControllerNode::backright, this, std::placeholders::_1));

    backleft_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/backleft", 10, std::bind(&ControllerNode::backleft, this, std::placeholders::_1));

    servo_pub_ = this->create_publisher<i2c_pwm_board_msgs::msg::ServoArray>("/servos_proportional_1", 10);
    configure_all_servos();
}

ControllerNode::~ControllerNode() 
{
}

void ControllerNode::configure_all_servos()
{
    auto freq_client = this->create_client<i2c_pwm_board_msgs::srv::IntValue>("/set_pwm_frequency_1");
    while(!freq_client->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_WARN(this->get_logger(), "Shutdown detected, exiting service wait.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Waitting frecuency service...");
    }
    auto freq_req = std::make_shared<i2c_pwm_board_msgs::srv::IntValue::Request>();
    freq_req->value = 50;
    freq_client->async_send_request(freq_req);

    auto cfg_client = this->create_client<i2c_pwm_board_msgs::srv::ServosConfig>("/config_servos_1");
    while(!cfg_client->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_WARN(this->get_logger(), "Shutdown detected, exiting service wait.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Waitting configure service...");
    }
    
    auto cfg_req = std::make_shared<i2c_pwm_board_msgs::srv::ServosConfig::Request>();

    for(int i=0; i<12; i++)
    {
        i2c_pwm_board_msgs::msg::ServoConfig s;
        s.servo = i;
        s.center = 1500;
        s.range  = 1000;
        s.direction = 1;
        cfg_req->servos.push_back(s);
    }

    cfg_client->async_send_request(cfg_req);
}

template<typename T, size_t N>
constexpr size_t array_size(const T (&)[N]) { return N; }

void ControllerNode::frontleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    move_servo(pca_frontleft_, msg);
}

void ControllerNode::frontright(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    move_servo(pca_frontright_, msg);
}

void ControllerNode::backright(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    move_servo(pca_backright_, msg);
}

void ControllerNode::backleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    move_servo(pca_backleft_, msg);
}

int rad_to_proportional(double angle_rad, double min_rad = -1.56, double max_rad = 1.56,
                 int min_pulse = 500, int max_pulse = 2400)
{
    (void) min_pulse;
    (void) max_pulse;
    if(angle_rad < min_rad) angle_rad = min_rad;
    if(angle_rad > max_rad) angle_rad = max_rad;
    return 2.0 * (angle_rad - min_rad) / (max_rad - min_rad) - 1.0;
}

void ControllerNode::move_servo(const int channels[3], const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    i2c_pwm_board_msgs::msg::ServoArray array;

    i2c_pwm_board_msgs::msg::Servo s0;
    s0.servo = channels[0];
    s0.value = rad_to_proportional(msg->hip);

    i2c_pwm_board_msgs::msg::Servo s1;
    s1.servo = channels[1];
    s1.value = rad_to_proportional(msg->leg);

    i2c_pwm_board_msgs::msg::Servo s2;
    s2.servo = channels[2];
    s2.value = rad_to_proportional(msg->foot);

    array.servos.clear();
    array.servos.push_back(s0);
    array.servos.push_back(s1);
    array.servos.push_back(s2);

    servo_pub_->publish(array);
}

}  // namespace controller
