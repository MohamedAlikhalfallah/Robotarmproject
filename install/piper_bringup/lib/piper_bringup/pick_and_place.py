#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from control_msgs.action import ParallelGripperCommand
from builtin_interfaces.msg import Duration
import time


class PickAndPlaceNode(Node):
    def __init__(self):
        super().__init__('pick_and_place_node')

        self.trajectory_pub = self.create_publisher(
            JointTrajectory,
            '/joint_trajectory_controller/joint_trajectory',
            10
        )

        self.gripper_client = ActionClient(
            self,
            ParallelGripperCommand,
            '/gripper_controller/gripper_cmd'
        )

        self.get_logger().info('Waiting for gripper action server...')
        self.gripper_client.wait_for_server()

        time.sleep(1)

        self.home_position = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.pre_pick_position = [0.463650, 1.5, -0.9, 0.0, 0.364, -0.439823]
        self.pick_position = [0.463650, 1.806, -0.9, 0.0, 0.364, -0.439823]
        self.drop_position = [-0.501150, 1.466, -0.9, 0.0, 0.364, -0.439823]

        self.get_logger().info('Pick and Place Node initialized!')

    def send_joint_trajectory(self, positions, duration_sec):
        """Send a joint trajectory command"""
        msg = JointTrajectory()
        msg.joint_names = ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'joint_6']

        point = JointTrajectoryPoint()
        point.positions = positions
        point.time_from_start = Duration(sec=duration_sec)

        msg.points = [point]

        self.trajectory_pub.publish(msg)
        self.get_logger().info(f'Sent trajectory: {positions}')

    def send_gripper_command(self, position):
        """Send gripper command using action"""
        goal_msg = ParallelGripperCommand.Goal()
        goal_msg.command.position =[position]

        self.get_logger().info(f'Sending gripper command: {position}')

        send_goal_future = self.gripper_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)

        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Gripper goal rejected')
            return

        self.get_logger().info('Gripper goal accepted')

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)

        self.get_logger().info('Gripper command completed')

    def execute_pick_and_place(self):
        """Execute the complete pick and place sequence"""
        self.get_logger().info('=' * 50)
        self.get_logger().info('Starting pick and place sequence...')
        self.get_logger().info('=' * 50)

        self.get_logger().info('Step 1: Moving to home position')
        self.send_joint_trajectory(self.home_position, 3)
        time.sleep(4)

        self.get_logger().info('Step 2: Opening gripper')
        self.send_gripper_command(0.04)
        time.sleep(2)

        self.get_logger().info('Step 3: Moving to pre-pick position (above cube)')
        self.send_joint_trajectory(self.pre_pick_position, 4)
        time.sleep(5)

        self.get_logger().info('Step 4: Moving down to pick position')
        self.send_joint_trajectory(self.pick_position, 3)
        time.sleep(4)

        self.get_logger().info('Step 5: Closing gripper to grab cube')
        self.send_gripper_command(0.02)
        time.sleep(2)

        self.get_logger().info('Step 6: Lifting cube')
        self.send_joint_trajectory(self.pre_pick_position, 3)
        time.sleep(4)

        self.get_logger().info('Step 7: Moving to drop position')
        self.send_joint_trajectory(self.drop_position, 4)
        time.sleep(5)

        self.get_logger().info('Step 8: Opening gripper to release cube')
        self.send_gripper_command(0.04)
        time.sleep(2)

        self.get_logger().info('Step 9: Returning to home position')
        self.send_joint_trajectory(self.home_position, 4)
        time.sleep(5)

        self.get_logger().info('=' * 50)
        self.get_logger().info('Pick and place sequence completed successfully!')
        self.get_logger().info('=' * 50)


def main(args=None):
    rclpy.init(args=args)
    node = PickAndPlaceNode()

    try:
        node.execute_pick_and_place()

        time.sleep(2)
    except KeyboardInterrupt:
        node.get_logger().info('Interrupted by user')
    except Exception as e:
        node.get_logger().error(f'Error: {e}')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
