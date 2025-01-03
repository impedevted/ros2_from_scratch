#ifndef NUMBERS_COUNTER_HPP
#define NUMBERS_COUNTER_HPP

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include <chrono>
#include <string>

class NumberCounterNode : public rclcpp::Node
{
public:
    NumberCounterNode();

private:

    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg);

    int counter_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr number_subscriber_;
};

#endif // MY_FIRST_NODE_HPP