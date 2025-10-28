#include "rclcpp/rclcpp.hpp"
#include "spider_control/ControllerNode.hpp"
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<controller::ControllerNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}