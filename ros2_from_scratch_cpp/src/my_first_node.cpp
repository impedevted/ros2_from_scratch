#include "ros2_from_scratch_cpp/my_first_node.hpp"

/*
MyCustomNode::MyCustomNode(const std::string &node_name)
 : Node(node_name), counter_(0)
{
    timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                     std::bind(&MyCustomNode::print_msg, this));
}

void MyCustomNode::print_msg()
{
    RCLCPP_INFO(this->get_logger(), "Hello, world! %d", counter_++);
}
*/

/*
// Default constructor (delegates to primary constructor)
MyCustomNode::MyCustomNode()
    : MyCustomNode("default_node", std::chrono::milliseconds(1000), "Hello from Default Node") {}

// Constructor with only node_name (delegates to primary constructor)
MyCustomNode::MyCustomNode(const std::string &node_name)
    : MyCustomNode(node_name, std::chrono::milliseconds(1000), "Hello from " + node_name) {}

// Constructor with node_name and msg (delegates to primary constructor)
MyCustomNode::MyCustomNode(const std::string &node_name, const std::string &msg)
    : MyCustomNode(node_name, std::chrono::milliseconds(1000), msg) {}
*/

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