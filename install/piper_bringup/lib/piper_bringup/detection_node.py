#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

class DetectionTerminal(Node):
    def __init__(self):
        super().__init__('detection_terminal')
        self.publisher_ = self.create_publisher(PoseStamped, '/detected_object_pose', 10)
        self.get_logger().info('Terminal Ready.')

    def send_coords(self):
        try:
            print("\n--- New Command ---")
            mode = input("Enter Mode (1 for PICK, 2 for PLACE): ")
            line = input("Enter coordinates (x y z): ")
            x, y, z = map(float, line.split())
            
            msg = PoseStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            # We use frame_id to tell C++ if this is a pick or a place target
            msg.header.frame_id = "pick_target" if mode == "1" else "place_target"
            
            msg.pose.position.x = x
            msg.pose.position.y = y
            msg.pose.position.z = z
            msg.pose.orientation.y = 1.0 
            msg.pose.orientation.w = 0.0

            self.publisher_.publish(msg)
            print(f"✔️ Sent {msg.header.frame_id} -> X:{x} Y:{y} Z:{z}")
        except ValueError:
            print("❌ Invalid input.")

def main():
    rclpy.init()
    node = DetectionTerminal()
    try:
        while rclpy.ok():
            node.send_coords()
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()
