#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std;

typedef std_msgs::msg::String StringType;

class CustomPublisher: public rclcpp::Node
{
public:
	CustomPublisher() : Node("custom_publisher") {
		timer_ = this->create_wall_timer(
			1ms, std::bind(&CustomPublisher::custom_callback, this)
		);
		publisher_ = this->create_publisher<StringType>("/custom_topic", 20);
	}
	~CustomPublisher();

	void custom_callback();

	rclcpp::Publisher<StringType>::SharedPtr publisher_;
	rclcpp::TimerBase::SharedPtr timer_;

	std::shared_ptr<rclcpp::ParameterEventHandler> param_subscriber_;
	OnSetParametersCallbackHandle::SharedPtr callback_handle_;


};

void CustomPublisher::custom_callback() {
	
}

int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<CustomPublisher>());
	rclcpp::shutdown();
	
	return 0;
}