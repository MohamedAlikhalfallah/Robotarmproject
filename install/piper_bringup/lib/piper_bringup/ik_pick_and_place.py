#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from control_msgs.action import ParallelGripperCommand
from builtin_interfaces.msg import Duration
import numpy as np
from scipy.optimize import minimize
import time


class IKPickAndPlaceNode(Node):
    def __init__(self):
        super().__init__('ik_pick_and_place_node')

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

        # Simplified link lengths from URDF
        self.link_lengths = {
            'base_height': 0.123,
            'link2': 0.28503,
            'link3': 0.25075,
            'link5': 0.091
        }

        # Joint limits from URDF
        self.joint_limits = [
            [-2.68, 2.68],    # Joint 1
            [0, 3.4],         # Joint 2
            [-3.0, 0],        # Joint 3
            [-1.85, 1.85],    # Joint 4
            [-1.3, 1.3],      # Joint 5
            [-np.pi, np.pi]   # Joint 6
        ]

        self.get_logger().info('IK Pick and Place Node initialized with corrected FK!')

    def forward_kinematics(self, joint_angles):
        """
        Simplified forward kinematics for the Piper arm
        Focuses on the main positioning joints (1, 2, 3, 5)
        """
        theta1, theta2, theta3, theta4, theta5, theta6 = joint_angles
        
        # Base height
        z = self.link_lengths['base_height']
        
        # Link 2 contribution (first arm segment)
        l2 = self.link_lengths['link2']
        x2 = l2 * np.cos(theta2)
        z2 = l2 * np.sin(theta2)
        
        # Link 3 contribution (second arm segment)
        l3 = self.link_lengths['link3']
        theta23 = theta2 + theta3  # Combined angle
        x3 = l3 * np.cos(theta23)
        z3 = l3 * np.sin(theta23)
        
        # Link 5 (wrist to end-effector)
        l5 = self.link_lengths['link5']
        theta_total = theta23 + theta5
        x5 = l5 * np.cos(theta_total)
        z5 = l5 * np.sin(theta_total)
        
        # Total reach in XZ plane
        reach_xz = x2 + x3 + x5
        height = z + z2 + z3 + z5
        
        # Joint 1 rotates around Z axis
        x = reach_xz * np.cos(theta1)
        y = reach_xz * np.sin(theta1)
        z = height
        
        return np.array([x, y, z])

    def inverse_kinematics(self, target_pos, initial_guess=None):
        """
        Solve inverse kinematics using numerical optimization
        """
        if initial_guess is None:
            # Smart initial guess based on target position
            target_x, target_y, target_z = target_pos
            theta1_guess = np.arctan2(target_y, target_x)
            initial_guess = [theta1_guess, 1.5, -1.0, 0.0, 0.3, 0.0]

        def cost_function(joint_angles):
            """Cost function: distance to target + penalties"""
            try:
                current_pos = self.forward_kinematics(joint_angles)
                error = np.linalg.norm(current_pos - target_pos)

                # Joint limit penalties
                penalty = 0
                for i, angle in enumerate(joint_angles):
                    if angle < self.joint_limits[i][0]:
                        penalty += 100 * (self.joint_limits[i][0] - angle)**2
                    if angle > self.joint_limits[i][1]:
                        penalty += 100 * (angle - self.joint_limits[i][1])**2

                # Small penalty to prefer configurations close to known working pose
                preferred = np.array([0.463650, 1.5, -0.9, 0.0, 0.364, -0.439823])
                config_penalty = 0.01 * np.linalg.norm(joint_angles - preferred)

                return error + penalty + config_penalty
            except:
                return 1e6

        bounds = self.joint_limits

        # Try multiple optimization methods
        best_result = None
        best_error = float('inf')
        
        methods = ['SLSQP', 'L-BFGS-B', 'Powell']
        
        for method in methods:
            try:
                result = minimize(
                    cost_function,
                    initial_guess,
                    method=method,
                    bounds=bounds,
                    options={'maxiter': 3000, 'ftol': 1e-8}
                )
                
                if result.fun < best_error:
                    best_error = result.fun
                    best_result = result
                    
                if best_error < 0.02:  # Good solution found
                    break
            except:
                continue

        if best_result and best_error < 0.10:  # Accept solutions within 10cm
            self.get_logger().info(f'IK solved! Error: {best_error:.4f}m')
            # Verify with FK
            fk_pos = self.forward_kinematics(best_result.x)
            self.get_logger().info(f'Target: [{target_pos[0]:.3f}, {target_pos[1]:.3f}, {target_pos[2]:.3f}]')
            self.get_logger().info(f'FK check: [{fk_pos[0]:.3f}, {fk_pos[1]:.3f}, {fk_pos[2]:.3f}]')
            return best_result.x
        else:
            self.get_logger().error(f'IK failed! Best error: {best_error:.4f}m')
            return None

    def send_joint_trajectory(self, positions, duration_sec):
        """Send joint trajectory command"""
        msg = JointTrajectory()
        msg.joint_names = ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'joint_6']

        point = JointTrajectoryPoint()
        point.positions = positions.tolist() if isinstance(positions, np.ndarray) else positions
        point.time_from_start = Duration(sec=duration_sec)

        msg.points = [point]

        self.trajectory_pub.publish(msg)
        self.get_logger().info(f'Sent trajectory: {[f"{p:.3f}" for p in point.positions]}')

    def send_gripper_command(self, position):
        """Send gripper command"""
        goal_msg = ParallelGripperCommand.Goal()
        goal_msg.command.position = [position]

        self.get_logger().info(f'Sending gripper command: {position}')

        send_goal_future = self.gripper_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)

        goal_handle = send_goal_future.result()
        if goal_handle.accepted:
            result_future = goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, result_future)

    def pick_and_place_ik(self, pick_xyz, place_xyz):
        """Execute pick and place using IK"""
        self.get_logger().info('=' * 60)
        self.get_logger().info('Starting IK-based pick and place')
        self.get_logger().info(f'Pick position: {pick_xyz}')
        self.get_logger().info(f'Place position: {place_xyz}')
        self.get_logger().info('=' * 60)

        # Test FK with known working position
        test_joints = [0.463650, 1.5, -0.9, 0.0, 0.364, -0.439823]
        test_fk = self.forward_kinematics(test_joints)
        self.get_logger().info(f'FK test with working joints gives: {test_fk}')

        home = [0.0, 1.0, -1.0, 0.0, 0.0, 0.0]
        
        self.get_logger().info('Step 1: Moving to home')
        self.send_joint_trajectory(home, 3)
        time.sleep(4)

        self.get_logger().info('Step 2: Opening gripper')
        self.send_gripper_command(0.04)
        time.sleep(2)

        self.get_logger().info('Step 3: Calculating IK for pre-pick position')
        pre_pick_xyz = np.array([pick_xyz[0], pick_xyz[1], pick_xyz[2] + 0.08])
        pre_pick_joints = self.inverse_kinematics(pre_pick_xyz, initial_guess=home)

        if pre_pick_joints is None:
            self.get_logger().error('Failed to calculate pre-pick IK')
            return

        self.send_joint_trajectory(pre_pick_joints, 4)
        time.sleep(5)

        self.get_logger().info('Step 4: Calculating IK for pick position')
        pick_joints = self.inverse_kinematics(np.array(pick_xyz), initial_guess=pre_pick_joints)

        if pick_joints is None:
            self.get_logger().error('Failed to calculate pick IK')
            return

        self.send_joint_trajectory(pick_joints, 3)
        time.sleep(4)

        self.get_logger().info('Step 5: Closing gripper')
        self.send_gripper_command(0.02)
        time.sleep(2)

        self.get_logger().info('Step 6: Lifting object')
        self.send_joint_trajectory(pre_pick_joints, 3)
        time.sleep(4)

        self.get_logger().info('Step 7: Calculating IK for pre-place position')
        pre_place_xyz = np.array([place_xyz[0], place_xyz[1], place_xyz[2] + 0.08])
        pre_place_joints = self.inverse_kinematics(pre_place_xyz, initial_guess=pre_pick_joints)

        if pre_place_joints is None:
            self.get_logger().error('Failed to calculate pre-place IK')
            return

        self.send_joint_trajectory(pre_place_joints, 4)
        time.sleep(5)

        self.get_logger().info('Step 8: Calculating IK for place position')
        place_joints = self.inverse_kinematics(np.array(place_xyz), initial_guess=pre_place_joints)

        if place_joints is None:
            self.get_logger().error('Failed to calculate place IK')
            return

        self.send_joint_trajectory(place_joints, 3)
        time.sleep(4)

        self.get_logger().info('Step 9: Opening gripper')
        self.send_gripper_command(0.04)
        time.sleep(2)

        self.get_logger().info('Step 10: Retreating')
        self.send_joint_trajectory(pre_place_joints, 3)
        time.sleep(4)

        self.get_logger().info('Step 11: Returning to home')
        self.send_joint_trajectory(home, 4)
        time.sleep(5)

        self.get_logger().info('=' * 60)
        self.get_logger().info('IK-based pick and place completed!')
        self.get_logger().info('=' * 60)


def main(args=None):
    rclpy.init(args=args)
    node = IKPickAndPlaceNode()

    try:
        # Cube position from Gazebo
        pick_position = [0.275, 0.139, 0.137]
        
        # Place position (reachable location)
        place_position = [0.275, -0.139, 0.137]

        node.pick_and_place_ik(pick_position, place_position)
        time.sleep(2)
    except KeyboardInterrupt:
        node.get_logger().info('Interrupted by user')
    except Exception as e:
        node.get_logger().error(f'Error: {e}')
        import traceback
        traceback.print_exc()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main() 
