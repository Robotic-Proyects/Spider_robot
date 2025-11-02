import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from enum import Enum, auto

from spider_control.KI import get_configurations, get_initial_pose

class State(Enum):
    START = auto()
    ELEVATE_FOOT = auto()
    MOVE = auto()

class MovementPublisher(Node):

    def __init__(self):
        super().__init__('movement_publisher')
        self.publisher_ = self.create_publisher(Float64MultiArray, '/spider_controller/commands', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.state = State.START
        self.pose = [0.0, 0.0, 0.0, 0.0, 0.0, -0.7, -0.7, -0.7, -0.7, -0.8, -0.8, -0.8, -0.8]

    def publish(self, pose):
        msg = Float64MultiArray()
        """
        msg.data = [rad_dome, rad_hip_br, rad_hip_bl, rad_hip_fr, rad_hip_fl, 
                    rad_leg_br, rad_leg_bl, rad_leg_fr, rad_leg_fl, rad_foot_fl, 
                    rad_foot_fr, rad_foot_br, rad_foot_bl]
        """
        msg.data = pose
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)

    def timer_callback(self):

        if self.state == State.START:
            print(self.state)
            self.state = State.ELEVATE_FOOT

        elif self.state == State.ELEVATE_FOOT:

            initial_pose = get_initial_pose(pose_interface=1)
            
            hip_rad = 2.1187 - initial_pose[1]
            foot_rad = 0.86 - initial_pose[2]

            self.pose[6] = hip_rad
            self.pose[12] = foot_rad
            
            self.publish(self.pose)

        elif self.state == State.MOVE:

            q1, q2, q3 = get_configurations(pose_interface=1, ejeX = -127.61, ejeY = -1.28, ejeZ = 0)
            print(self.state)
        else:
            print(self.state)


def main(args=None):
    rclpy.init(args=args)

    movement_publisher = MovementPublisher()

    rclpy.spin(movement_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()