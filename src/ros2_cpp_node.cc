
#include<iostream>
#include<rclcpp/rclcpp.hpp>
#include<memory>
int main(int argc,char** argv){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<rclcpp::Node>("cpp_node");//应该是个节点名
    RCLCPP_INFO(node->get_logger(),"hello world");
    //循环检测节点内容
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}