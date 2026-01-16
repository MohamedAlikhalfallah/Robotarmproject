#!/usr/bin/env python3

import numpy as np

# Test forward kinematics with known joint positions
def forward_kinematics_test():
    # Known working joint positions from your manual test
    joint_angles = [0.463650, 1.5, -0.9, 0.0, 0.364, -0.439823]
    
    # Link transforms from URDF
    link_transforms = [
        {'xyz': [0, 0, 0.123], 'rpy': [0, 0, -np.pi/2]},
        {'xyz': [0, 0, 0], 'rpy': [np.pi/2, -0.10095, -np.pi/2]},
        {'xyz': [0.28503, 0, 0], 'rpy': [0, 0, 1.3826]},
        {'xyz': [0.021984, 0.25075, 0], 'rpy': [-np.pi/2, 0, 0]},
        {'xyz': [0, 0, 0], 'rpy': [np.pi/2, -0.087266, 0]},
        {'xyz': [0, 0.091, 0.0014], 'rpy': [-np.pi/2, 0, 0]},
    ]
    
    T = np.eye(4)
    
    for i, transform in enumerate(link_transforms):
        theta = joint_angles[i]
        xyz = transform['xyz']
        rpy = transform['rpy']
        
        roll, pitch, yaw = rpy
        
        # Rotation matrices
        Rx = np.array([
            [1, 0, 0, 0],
            [0, np.cos(roll), -np.sin(roll), 0],
            [0, np.sin(roll), np.cos(roll), 0],
            [0, 0, 0, 1]
        ])
        
        Ry = np.array([
            [np.cos(pitch), 0, np.sin(pitch), 0],
            [0, 1, 0, 0],
            [-np.sin(pitch), 0, np.cos(pitch), 0],
            [0, 0, 0, 1]
        ])
        
        Rz = np.array([
            [np.cos(yaw), -np.sin(yaw), 0, 0],
            [np.sin(yaw), np.cos(yaw), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ])
        
        Trans = np.array([
            [1, 0, 0, xyz[0]],
            [0, 1, 0, xyz[1]],
            [0, 0, 1, xyz[2]],
            [0, 0, 0, 1]
        ])
        
        if i == 3 or i == 5:
            theta = -theta
        
        Joint_rot = np.array([
            [np.cos(theta), -np.sin(theta), 0, 0],
            [np.sin(theta), np.cos(theta), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ])
        
        T = T @ Trans @ Rz @ Ry @ Rx @ Joint_rot
    
    position = T[:3, 3]
    print(f"Joint angles: {joint_angles}")
    print(f"End-effector position: X={position[0]:.4f}, Y={position[1]:.4f}, Z={position[2]:.4f}")
    print(f"Cube position:        X=0.3000, Y=0.1500, Z=1.0200")
    print(f"Distance to cube: {np.linalg.norm(position - np.array([0.3, 0.15, 1.02])):.4f}m")

if __name__ == '__main__':
    forward_kinematics_test()
