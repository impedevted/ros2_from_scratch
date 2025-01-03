#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "ros2_from_scratch_cpp/number_counter.hpp"

using namespace std::placeholders;


NumberCounterNode::NumberCounterNode() : Node("number_counter"), counter_(0)
{
    number_subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 10, std::bind(&NumberCounterNode::callbackNumber, this, _1));
        
    RCLCPP_INFO(this->get_logger(), "Number Counter has been started.");
}

void NumberCounterNode::callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
{
    counter_ += msg->data;
    RCLCPP_INFO(this->get_logger(), "Counter: %d", counter_);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}