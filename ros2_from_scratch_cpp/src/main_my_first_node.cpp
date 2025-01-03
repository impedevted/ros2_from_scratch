#include "rclcpp/rclcpp.hpp"
#include "ros2_from_scratch_cpp/my_first_node.hpp"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create three nodes with different configurations
    auto node1 = std::make_shared<MyCustomNode>(); // Default constructor
    auto node2 = std::make_shared<MyCustomNode>("node2"); // Constructor with node_name
    auto node3 = std::make_shared<MyCustomNode>("node3", std::chrono::milliseconds(500), "Hello from Node 3"); // Constructor with node_name and msg

    // Create an executor to run the nodes
    rclcpp::executors::StaticSingleThreadedExecutor executor;
    executor.add_node(node1);
    executor.add_node(node2);
    executor.add_node(node3);

    // Spin the nodes
    executor.spin();
    rclcpp::shutdown();
    return 0;
}