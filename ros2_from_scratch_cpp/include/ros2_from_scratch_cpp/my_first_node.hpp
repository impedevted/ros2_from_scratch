#ifndef MY_FIRST_NODE_HPP
#define MY_FIRST_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <string>

class MyCustomNode : public rclcpp::Node
{
public:
    explicit MyCustomNode(const std::string &node_name = "Default_node", 
                                std::chrono::milliseconds delay = std::chrono::milliseconds(1000), 
                                const std::string &msg = "Hello from Default Node");

    void print_msg();

private:
    int counter_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string msg_;
};

#endif // MY_FIRST_NODE_HPP