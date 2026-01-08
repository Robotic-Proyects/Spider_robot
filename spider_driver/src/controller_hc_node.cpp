#include "rclcpp/rclcpp.hpp"
#include "spider_driver/ControllerHCNode.hpp"
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<controller_hc::ControllerHCNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}