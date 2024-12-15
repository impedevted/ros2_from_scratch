#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisher : public rclcpp::Node {
public:
    HardwareStatusPublisher()
    : Node("hardware_status_publisher") {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_status", 10);

        // Publish at 1 Hz
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&HardwareStatusPublisher::publishStatus, this)
        );
    }

private:
    void publishStatus() {
        auto message = my_robot_interfaces::msg::HardwareStatus();
        message.version = 1;
        message.temperature = 36.5;
        message.are_motors_ready = true;
        message.debug_message = "All systems nominal";

        RCLCPP_INFO(this->get_logger(), "Publishing: version=%ld, temperature=%.2f, motors_ready=%s, debug=%s",
                    message.version, message.temperature, message.are_motors_ready ? "true" : "false",
                    message.debug_message.c_str());

        publisher_->publish(message);
    }

    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HardwareStatusPublisher>());
    rclcpp::shutdown();
    return 0;
}
