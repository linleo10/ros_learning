import os
from launch import LaunchDescription
from launch_ros.actions import Node

from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    share_path = get_package_share_directory('params_learning')
    params_config = os.path.join(share_path, 'config/params.yaml')

    return LaunchDescription([
        DeclareLaunchArgument(name='params_file', default_value=params_config),
        Node(
            name="publisher_node",
            package = "params_learning",
            executable = "pub",
            parameters = [LaunchConfiguration('params_file')],
            namespace = "",    
            output = 'screen',
            emulate_tty=True,
        ),
        # Node(
        #     name="subscriber_node",
        #     package = "cam",
        #     executable = "sub",
        #     parameters = [LaunchConfiguration('params_file')],
        #     namespace = "",    
        #     output = 'screen',
        #     emulate_tty=True,
        # )
    ])