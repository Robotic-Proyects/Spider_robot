#include "spider_driver/ControllerNode.hpp"
#include <chrono>

namespace controller
{

using namespace std::chrono_literals;

void set_gpio_value(int pin, int value) {
    std::ofstream("/sys/class/gpio/gpio" + std::to_string(pin) + "/value") << value;
}

ControllerNode::ControllerNode()
: Node("controller_node"), pca_()
{
    oe_pin_ = 16;
    oe_disable();

    pca_.begin();
    pca_.setPWMFreq(50);

    this->declare_parameter<double>("initial_rad", -1.5);
    initial_rad_ = this->get_parameter("initial_rad").as_double();

    pca_frontright_[0] = 9;
    pca_frontright_[1] = 10;
    pca_frontright_[2] = 11;

    pca_backright_[0] = 0;
    pca_backright_[1] = 1;
    pca_backright_[2] = 2;

    pca_frontleft_[0] = 6;
    pca_frontleft_[1] = 7;
    pca_frontleft_[2] = 8;

    pca_backleft_[0] = 3;
    pca_backleft_[1] = 4;
    pca_backleft_[2] = 5;

    ultrasonic_channel_ = 15;

    smooth_ = 0.1;

    memset(frontleft_pose_, 0, sizeof(frontleft_pose_));
    memset(frontright_pose_, 0, sizeof(frontright_pose_));
    memset(backright_pose_, 0, sizeof(backright_pose_));
    memset(backleft_pose_, 0, sizeof(backleft_pose_));

    ultrasonic_pose_ = 0.0;

    memset(frontleft_target_, 0, sizeof(frontleft_target_));
    memset(frontright_target_, 0, sizeof(frontright_target_));
    memset(backright_target_, 0, sizeof(backright_target_));
    memset(backleft_target_, 0, sizeof(backleft_target_));

    ultrasonic_target_ = 0.0;

    ultrasonic_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "/ultrasonic", 10, std::bind(&ControllerNode::ultrasonic, this, std::placeholders::_1));

    frontleft_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/frontleft", 10, std::bind(&ControllerNode::frontleft, this, std::placeholders::_1));

    frontright_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/frontright", 10, std::bind(&ControllerNode::frontright, this, std::placeholders::_1));

    backright_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/backright", 10, std::bind(&ControllerNode::backright, this, std::placeholders::_1));

    backleft_leg_ = this->create_subscription<spider_msgs::msg::SpiderLeg>(
        "/arm/backleft", 10, std::bind(&ControllerNode::backleft, this, std::placeholders::_1));

    oe_value_ = this->create_subscription<spider_msgs::msg::SpiderSwitch>(
        "/oe_value", 10, std::bind(&ControllerNode::oe, this, std::placeholders::_1));

    calibrate_service_ = this->create_service<spider_msgs::srv::ServoCalibrate>(
        "/servo_calibrate",
        std::bind(&ControllerNode::calibrate_callback, this, std::placeholders::_1, std::placeholders::_2));

    for (int i = 0; i < 16; i++) {
        last_pwm_[i] = -1;
    }
    last_pwm_[ultrasonic_channel_] = -1;

    configure_all_servos();

    timer_ = this->create_wall_timer(
            20ms, std::bind(&ControllerNode::update_servos, this));
}

ControllerNode::~ControllerNode() 
{
}

void ControllerNode::configure_all_servos()
{
    int pwm_init = rad_to_pwm(initial_rad_, -1.57, 1.57, 110, 510);

    auto set_group = [&](const int channels[3], double pose[3], double target[3], const int pwm_init) {
        pose[0] = initial_rad_;
        pose[1] = initial_rad_;
        pose[2] = initial_rad_;

        target[0] = initial_rad_;
        target[1] = initial_rad_;
        target[2] = initial_rad_;

        last_pwm_[channels[0]] = pwm_init;
        last_pwm_[channels[1]] = pwm_init;
        last_pwm_[channels[2]] = pwm_init;

        pca_.setPWM(channels[0], pwm_init);
        pca_.setPWM(channels[1], pwm_init);
        pca_.setPWM(channels[2], pwm_init);
    };

    set_group(pca_frontleft_,  frontleft_pose_, frontleft_target_, pwm_init);
    set_group(pca_frontright_, frontright_pose_, frontright_target_, pwm_init);
    set_group(pca_backright_,  backright_pose_, backright_target_, pwm_init);
    set_group(pca_backleft_,   backleft_pose_, backleft_target_, pwm_init);

    RCLCPP_INFO(this->get_logger(), "Servos rad %.2f → PWM %d", initial_rad_, pwm_init);
}

void ControllerNode::set_pose(double poses[3], double f_pose, double s_pose, double t_pose)
{
    poses[0] = f_pose;
    poses[1] = s_pose;
    poses[2] = t_pose;
}

int ControllerNode::rad_to_pwm(double angle_rad, double min_rad, double max_rad, int min_pwm, int max_pwm)
{
    if (angle_rad < min_rad) angle_rad = min_rad;
    if (angle_rad > max_rad) angle_rad = max_rad;
    double ratio = (angle_rad - min_rad) / (max_rad - min_rad);
    int pwm = static_cast<int>(min_pwm + ratio * (max_pwm - min_pwm));
    return pwm;
}

// ------- ------------- ------- //
// ------- LEG CALLBACKS ------- //
// ------- ------------- ------- //
template<typename T, size_t N>
constexpr size_t array_size(const T (&)[N]) { return N; }

void ControllerNode::ultrasonic(const std_msgs::msg::Float64::SharedPtr msg)
{
    ultrasonic_target_ = msg->data;
}

void ControllerNode::frontleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    if (msg->smooth_value == 0) {
        //move_servo(pca_frontleft_, msg);
        set_pose(frontleft_pose_, msg->hip, msg->leg, msg->foot);
        set_pose(frontleft_target_, msg->hip, msg->leg, msg->foot);
    } else {
        set_pose(frontleft_target_, msg->hip, msg->leg, msg->foot);
    }
    smooth_ = msg->smooth_value;
}

void ControllerNode::frontright(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    if (msg->smooth_value == 0) {
        //move_servo(pca_frontright_, msg);
        set_pose(frontright_pose_, msg->hip, msg->leg, msg->foot);
        set_pose(frontright_target_, msg->hip, msg->leg, msg->foot);
    } else {
        set_pose(frontright_target_, msg->hip, msg->leg, msg->foot);
    }
    smooth_ = msg->smooth_value;
}

void ControllerNode::backright(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    if (msg->smooth_value == 0) {
        //move_servo(pca_backright_, msg);
        set_pose(backright_pose_, msg->hip, msg->leg, msg->foot);
        set_pose(backright_target_, msg->hip, msg->leg, msg->foot);
    } else {
        set_pose(backright_target_, msg->hip, msg->leg, msg->foot);
    }
    smooth_ = msg->smooth_value;
}

void ControllerNode::backleft(const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    if (msg->smooth_value == 0) {
        //move_servo(pca_backleft_, msg);
        set_pose(backleft_pose_, msg->hip, msg->leg, msg->foot);
        set_pose(backleft_target_, msg->hip, msg->leg, msg->foot);
    } else {
        set_pose(backleft_target_, msg->hip, msg->leg, msg->foot);
    }
    smooth_ = msg->smooth_value;
}

// ------- ------------- ------- //
// -------- OE CALLBACKS ------- //
// ------- ------------- ------- //

void ControllerNode::oe(const spider_msgs::msg::SpiderSwitch::SharedPtr msg)
{
    if (msg->oe_value == 0) {
        oe_enable();
    } else {
        oe_disable();
    }
}

// ------- ------------- ------- //
// ------- SRV CALLBACKS ------- //
// ------- ------------- ------- //
void ControllerNode::calibrate_callback(
    const std::shared_ptr<spider_msgs::srv::ServoCalibrate::Request> request,
    std::shared_ptr<spider_msgs::srv::ServoCalibrate::Response> response)
{
    int channel = request->channel;
    int pwm = request->pwm;

    if (pwm < 0) pwm = 0;
    if (pwm > 4095) pwm = 4095;

    pca_.setPWM(channel, pwm);

    RCLCPP_INFO(this->get_logger(),
        "Calibrando canal %d → PWM %d", channel, pwm);

    response->pwm_value = pwm;
    response->status = "Servo movido correctamente";

    std::ofstream file("/home/pi/servo_calibration.yaml", std::ios::app);
    file << "channel_" << channel << ":\n";
    file << "  pwm: " << pwm << "\n";
    file.close();
}

// ------- ------------- ------- //
// --------- OE CONTROL -------- //
// ------- ------------- ------- //

void ControllerNode::oe_enable() {
    set_gpio_value(oe_pin_, 0);
}

void ControllerNode::oe_disable() {
    set_gpio_value(oe_pin_, 1);
}

// ------- ------------- ------- //
// ------ PWM CONTROLLERS ------ //
// ------- ------------- ------- //
void ControllerNode::move_servo(const int channels[3], const spider_msgs::msg::SpiderLeg::SharedPtr msg)
{
    int pwm_hip  = rad_to_pwm(msg->hip, -1.57, 1.57, 110, 510);
    int pwm_leg  = rad_to_pwm(msg->leg, -1.57, 1.57, 110, 510);
    int pwm_foot = rad_to_pwm(msg->foot, -1.57, 1.57, 110, 510); // 290

    pca_.setPWM(channels[0], rad_to_pwm(msg->hip, -1.57, 1.57, 110, 510));
    pca_.setPWM(channels[1], rad_to_pwm(msg->leg, -1.57, 1.57, 110, 510));
    pca_.setPWM(channels[2], rad_to_pwm(msg->foot, -1.57, 1.57, 110, 510));

    RCLCPP_INFO(this->get_logger(),
        "HIP %.2f → %d | LEG %.2f → %d | FOOT %.2f → %d",
        msg->hip, pwm_hip, msg->leg, pwm_leg, msg->foot, pwm_foot);
}

void ControllerNode::update_servos()
{
    auto move_towards = [this](double current[3], double target[3], int channels[3], auto &pca, double alpha = 0.05) {
        int pwm_values[3];
        double alpha_ = alpha;
        if (alpha_ > 1) {
            alpha_ = 1.0;
        } else if (alpha_ <= 0.05) {
            alpha_ = 0.05;
        }
        for (int i = 0; i < 3; i++) {
            current[i] += (target[i] - current[i]) * alpha_;
            pwm_values[i] = rad_to_pwm(current[i], -1.57, 1.57, 110, 510);

            if (pwm_values[i] != last_pwm_[channels[i]]) {
                pca.setPWM(channels[i], pwm_values[i]);
                last_pwm_[channels[i]] = pwm_values[i];
            }
        }
        return std::vector<int>{pwm_values[0], pwm_values[1], pwm_values[2]};
    };

    auto pwm_fl = move_towards(frontleft_pose_, frontleft_target_, pca_frontleft_, pca_, smooth_);
    auto pwm_fr = move_towards(frontright_pose_, frontright_target_, pca_frontright_, pca_, smooth_);
    auto pwm_br = move_towards(backright_pose_, backright_target_, pca_backright_, pca_, smooth_);
    auto pwm_bl = move_towards(backleft_pose_, backleft_target_, pca_backleft_, pca_, smooth_);

    ultrasonic_pose_ += (ultrasonic_target_ - ultrasonic_pose_);

    int pwm_ultra = rad_to_pwm(ultrasonic_pose_, 0.0, 3.002, 110, 510);

    if (pwm_ultra != last_pwm_[ultrasonic_channel_]) {
        pca_.setPWM(ultrasonic_channel_, pwm_ultra);
        last_pwm_[ultrasonic_channel_] = pwm_ultra;
    }

    // std::cout << "Poses rad: "
    //           << frontleft_pose_[0] << " " << frontleft_pose_[1] << " " << frontleft_pose_[2] << " | "
    //           << frontright_pose_[0] << " " << frontright_pose_[1] << " " << frontright_pose_[2] << " | "
    //           << backright_pose_[0] << " " << backright_pose_[1] << " " << backright_pose_[2] << " | "
    //           << backleft_pose_[0] << " " << backleft_pose_[1] << " " << backleft_pose_[2] << std::endl;

    // std::cout << "PWM: "
    //           << pwm_fl[0] << " " << pwm_fl[1] << " " << pwm_fl[2] << " | "
    //           << pwm_fr[0] << " " << pwm_fr[1] << " " << pwm_fr[2] << " | "
    //           << pwm_br[0] << " " << pwm_br[1] << " " << pwm_br[2] << " | "
    //           << pwm_bl[0] << " " << pwm_bl[1] << " " << pwm_bl[2] << std::endl;
}

}  // namespace controller