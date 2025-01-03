#include "ros2_from_scratch_cpp/my_first_node.hpp"

// Primary constructor (delegating target)
MyCustomNode::MyCustomNode(const std::string &node_name, 
                           std::chrono::milliseconds delay, 
                           const std::string &msg)
 : Node(node_name), counter_ {0}, msg_ {msg}
{
    timer_ = this->create_wall_timer(
        delay,
        std::bind(&MyCustomNode::print_msg, this)
    );
}


// Function to print messages
void MyCustomNode::print_msg()
{
    RCLCPP_INFO(this->get_logger(), "%s %d", msg_.c_str(), counter_++);
}