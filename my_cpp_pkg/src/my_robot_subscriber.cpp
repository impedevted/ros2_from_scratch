#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusSubscriber : public rclcpp::Node {
public:
    HardwareStatusSubscriber()
    : Node("hardware_status_subscriber") {
        subscription_ = this->create_subscription<my_robot_interfaces::msg::HardwareStatus>(
            "hardware_status",
            10,
            std::bind(&HardwareStatusSubscriber::statusCallback, this, std::placeholders::_1)
        );
    }

private:
    void statusCallback(const my_robot_interfaces::msg::HardwareStatus::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received: version=%ld, temperature=%.2f, motors_ready=%s, debug=%s, counter_=%d",
                    msg->version, msg->temperature, msg->are_motors_ready ? "true" : "false",
                    msg->debug_message.c_str(), counter_);
        counter_ += msg->temperature;
    }

    int counter_;
    rclcpp::Subscription<my_robot_interfaces::msg::HardwareStatus>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HardwareStatusSubscriber>());
    rclcpp::shutdown();
    return 0;
}
