#include <iostream>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std;

typedef std_msgs::msg::String StringType;

class CustomPublisher: public rclcpp::Node
{
public:
	CustomPublisher() : Node("custom_publisher") {
		this->declare_parameter("msg_text", "CALLBACK");
		// string msg_text = this->get_parameter("msg_text").as_string();

		timer_ = this->create_wall_timer(
			1ms, std::bind(&CustomPublisher::custom_callback, this)
		);
		publisher_ = this->create_publisher<StringType>("custom_topic", 20);

		callback_handle_ = this->add_on_set_parameters_callback(
			std::bind(&CustomPublisher::paramsCallback, this, placeholders::_1)
		);
	}
	// ~CustomPublisher();

	void custom_callback();
	rcl_interfaces::msg::SetParametersResult paramsCallback(const std::vector<rclcpp::Parameter>& params);

	rclcpp::Publisher<StringType>::SharedPtr publisher_;
	rclcpp::Subscription<StringType>::SharedPtr subscription_;
	rclcpp::TimerBase::SharedPtr timer_;

	std::shared_ptr<rclcpp::ParameterEventHandler> param_subscriber_;
	OnSetParametersCallbackHandle::SharedPtr callback_handle_;

	string msg_data_;
};

rcl_interfaces::msg::SetParametersResult CustomPublisher::paramsCallback(const std::vector<rclcpp::Parameter>& params) {
	rcl_interfaces::msg::SetParametersResult result;
	result.successful = false;
	result.reason = "debug";
	result.successful = true;

	this->msg_data_ = this->get_parameter("msg_text").as_string();

	// this->msg_data_ = msg_text.c_str();

	// strcpy(this->msg_data_, msg_text.c_str());

	return result;
}

void CustomPublisher::custom_callback() {
	// RCLCPP_INFO(this->get_logger(), "CALLBACK...");

	// char* msg_text = this->msg_data_;
	
	if (rclcpp::ok()) {
		// RCLCPP_INFO(this->get_logger(), this->msg_data_);
		cout << this->msg_data_ << endl;
	}
}

int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<CustomPublisher>());
	rclcpp::shutdown();
	
	return 0;
}