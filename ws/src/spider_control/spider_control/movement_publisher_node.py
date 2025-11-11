import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from enum import Enum, auto

class State(Enum):
    START = auto()
    ELEVATE_FOOT = auto()
    MOVE = auto()

class MovementPublisher(Node):

    def __init__(self):
        super().__init__('movement_publisher')

        # Publicadores para cada pata
        self.publisher_back_left_ = self.create_publisher(Float64MultiArray, '/spider_leg_back_left_controller/commands', 10)
        self.publisher_back_right_ = self.create_publisher(Float64MultiArray, '/spider_leg_back_right_controller/commands', 10)
        self.publisher_front_left_ = self.create_publisher(Float64MultiArray, '/spider_leg_front_left_controller/commands', 10)
        self.publisher_front_right_ = self.create_publisher(Float64MultiArray, '/spider_leg_front_right_controller/commands', 10)
        
        timer_period = 0.5  # segundos
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.state = State.START

        # Pose fija para todas las patas
        self.pose_back_right = [0.0, 0.0, 0.0]
        self.pose_back_left = [0.0, 0.0, 0.0]
        self.pose_front_right = [0.0, 0.0, 0.0]
        self.pose_front_left = [0.0, 0.0, 0.0]

    def publish(self, pose, publisher, name):
        msg = Float64MultiArray()
        msg.data = pose
        publisher.publish(msg)
        self.get_logger().info(f'Publishing to {name}: {msg.data}')

    def timer_callback(self):

        if self.state == State.START:
            self.get_logger().info(f"Current state: {self.state.name}")
            self.state = State.ELEVATE_FOOT

        elif self.state == State.ELEVATE_FOOT:
            # En este estado publicamos la pose fija a todas las patas
            self.publish(self.pose_back_left, self.publisher_back_left_, "back_left")
            self.publish(self.pose_back_right, self.publisher_back_right_, "back_right")
            self.publish(self.pose_front_left, self.publisher_front_left_, "front_left")
            self.publish(self.pose_front_right, self.publisher_front_right_, "front_right")

            # Pasamos al siguiente estado (opcional)
            self.state = State.MOVE

        elif self.state == State.MOVE:
            # Mantiene la misma pose o puedes agregar lógica extra
            self.get_logger().info(f"State: {self.state.name} (holding fixed pose)")
            
            self.publish(self.pose_back_left, self.publisher_back_left_, "back_left")
            self.publish(self.pose_back_right, self.publisher_back_right_, "back_right")
            self.publish(self.pose_front_left, self.publisher_front_left_, "front_left")
            self.publish(self.pose_front_right, self.publisher_front_right_, "front_right")

        else:
            self.get_logger().info(f"Unknown state: {self.state.name}")


def main(args=None):
    rclpy.init(args=args)
    movement_publisher = MovementPublisher()
    rclpy.spin(movement_publisher)
    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
