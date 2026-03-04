# 🤖 Vision-Guided Affordance-Based Robotic Grasping System

## 📖 Project Description

This project implements an intelligent robotic grasping module for ROS2 that enables autonomous object manipulation through vision-guided affordance recognition. The system receives 3D bounding box data from a vision pipeline, uses TF2 for coordinate transformation from camera frame to robot base frame, and classifies objects based on their affordances (GRASPABLE, PUSHABLE, PULLABLE). It automatically selects optimal grasp strategies—SIDE grasp for tall objects or TOP grasp for flat objects—based on aspect ratio analysis. The system employs a state machine for robust execution control and coordinates with navigation and motion planning modules through ROS2 topics. Built with C++17, it integrates MoveIt2 for motion planning, TF2 for coordinate transformations, and ros2_control for gripper management. The module supports pick-and-place operations, push actions for doors and cabinets, and pull actions for drawers, making it suitable for warehouse automation, manufacturing, and assistive robotics applications.

## 🛠️ Technologies Used

![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue?style=flat-square&logo=ros)
![C++](https://img.shields.io/badge/C++-17-00599C?style=flat-square&logo=c%2B%2B)
![MoveIt2](https://img.shields.io/badge/MoveIt-2-orange?style=flat-square)
![TF2](https://img.shields.io/badge/TF2-Transform-green?style=flat-square)

**Core Technologies:** ROS2 Jazzy • C++17 • MoveIt2 • TF2 • ros2_control  
**Architecture:** State Machine • Custom ROS2 Messages • Action Servers
