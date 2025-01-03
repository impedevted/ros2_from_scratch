#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "ros2_from_scratch_cpp/number_publisher.hpp"

NumberPublisherNode::NumberPublisherNode(const std::string &node_name,
                                        std::chrono::milliseconds delay)
    : Node(node_name), number_ {2}
{
    number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
    number_timer_ = this->create_wall_timer(std::chrono::milliseconds(delay), 
                                                std::bind(&NumberPublisherNode::publishNumber, this));

    RCLCPP_INFO(this->get_logger(), "Number publisher has been started.");

}

void NumberPublisherNode::publishNumber()
{
    auto msg = example_interfaces::msg::Int64();
    msg.data = number_;
    number_publisher_->publish(msg);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}