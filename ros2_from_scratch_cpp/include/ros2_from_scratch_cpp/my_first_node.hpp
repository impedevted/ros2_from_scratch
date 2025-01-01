#ifndef MY_FIRST_NODE_HPP
#define MY_FIRST_NODE_HPP

#include "rclcpp/rclcpp.hpp"

/*
class MyCustomNode : public rclcpp::Node
{
public:
    explicit MyCustomNode(const std::string &node_name);
    void print_hello();

private:
    int counter_;
    rclcpp::TimerBase::SharedPtr timer_;
};
*/

class MyCustomNode : public rclcpp::Node
{
public:
    explicit MyCustomNode(const std::string &node_name, std::chrono::milliseconds delay, const std::string &msg_);
    void print_msg();

private:
    int counter_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string msg_;
};

#endif // MY_FIRST_NODE_HPP