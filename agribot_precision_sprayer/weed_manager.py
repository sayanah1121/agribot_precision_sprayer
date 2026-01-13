#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Bool

class WeedManager(Node):
    def __init__(self):
        super().__init__('weed_manager')
        
        self.sub = self.create_subscription(
            Point, 
            '/weed/pixel_coords', 
            self.callback, 
            10
        )
        
        self.pub_fire = self.create_publisher(Bool, '/actuator/fire', 10)
        
        # Image is 320x240. Center X is 160.
        self.center_x = 160 
        self.tolerance = 30 # How close to center (pixels) to trigger fire
        
        self.get_logger().info("Weed Logic Manager Started")

    def callback(self, msg):
        # Calculate distance from center
        offset = abs(msg.x - self.center_x)
        
        if offset < self.tolerance:
            fire_msg = Bool()
            fire_msg.data = True
            self.pub_fire.publish(fire_msg)
            self.get_logger().info(f"Target Locked (Offset: {offset:.0f}px) -> FIRING")

def main(args=None):
    rclpy.init(args=args)
    node = WeedManager()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
