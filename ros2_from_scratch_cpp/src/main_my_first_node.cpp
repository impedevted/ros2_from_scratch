#include "rclcpp/rclcpp.hpp"
#include "ros2_from_scratch_cpp/my_first_node.hpp"

/*
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create two nodes with differnt names
    auto node1 = std::make_shared<MyCustomNode>("node1");
    auto node2 = std::make_shared<MyCustomNode>("node2");

    // Create an executor to run the nodes
    rclcpp::executors::StaticSingleThreadedExecutor executor;
    executor.add_node(node1);
    executor.add_node(node2);

    // Spin the nodes
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
*/

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create two nodes with different delays and messages
    auto node1 = std::make_shared<MyCustomNode>("node1", std::chrono::milliseconds(500), "Hello from Node 1");
    auto node2 = std::make_shared<MyCustomNode>("node2", std::chrono::milliseconds(1000), "Hello from Node 2");

    // Create an executor to run the nodes
    rclcpp::executors::StaticSingleThreadedExecutor executor;
    executor.add_node(node1);
    executor.add_node(node2);

    // Spin the nodes
    executor.spin();
    rclcpp::shutdown();
    return 0;
}