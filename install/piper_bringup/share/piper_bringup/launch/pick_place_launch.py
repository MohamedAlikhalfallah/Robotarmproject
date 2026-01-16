from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # This node will now rely on the 'piper_moveit.launch.py' 
    # (which you should run first) to provide the robot description.
    arm_node = Node(
        package='piper_bringup',
        executable='moveit_pick_and_place_cpp',
        name='piper_dynamic_engine',
        output='screen',
        parameters=[{'use_sim_time': True}]
    )

    return LaunchDescription([
        arm_node
    ])
