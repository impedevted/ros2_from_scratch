#ifndef NUMBERS_PUBLISHER_HPP
#define NUMBERS_PUBLISHER_HPP

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include <chrono>
#include <string>

class NumberPublisherNode : public rclcpp::Node
{
public:
    explicit NumberPublisherNode(const std::string &node_name = "Number_Plublisher", 
                                std::chrono::milliseconds delay = std::chrono::milliseconds(1000));

    void publishNumber();

private:
    int number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;
};

#endif // MY_FIRST_NODE_HPP