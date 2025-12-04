import rclpy
import time
import math
import numpy as np
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray, String
from enum import Enum, auto

from spider_control.KI import forward_kinematics, inverse_kinematics

HALFWIDTH = 5
state_legs = 0

class State(Enum):
    START = auto()
    ELEVATE_FOOT = auto()
    MOVE = auto()
    CHANGE_LEG = auto()
    LOWER = auto()
    JOY = auto()

class MovementPublisher(Node):

    def __init__(self):
        super().__init__('movement_publisher')
        self.publisher_back_left_ = self.create_publisher(Float64MultiArray, '/spider_leg_back_left_controller/commands', 10)
        self.publisher_back_right_ = self.create_publisher(Float64MultiArray, '/spider_leg_back_right_controller/commands', 10)
        self.publisher_front_left_ = self.create_publisher(Float64MultiArray, '/spider_leg_front_left_controller/commands', 10)
        self.publisher_front_right_ = self.create_publisher(Float64MultiArray, '/spider_leg_front_right_controller/commands', 10)
        #self.publisher_oe_ = self.create_publisher(SpiderSwitch, '/oe_value', 10)

        self.subscription = self.create_subscription(
            String,
            '/key_pressed',
            self.listener_callback,
            10)
        
        self.subscription

        timer_period = 0.02  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.state = State.START

        self.pose_back_right = [0.0, 0.0, 0.0]
        self.pose_back_left = [0.0, 0.0, 0.0]
        self.pose_front_right = [0.0, 0.0, 0.0]
        self.pose_front_left = [0.0, 0.0, 0.0]

        self.coordinate_back_right = {'x':0.0, 'y':0.0, 'z':0.0}
        self.coordinate_back_left = {'x':0.0, 'y':0.0, 'z':0.0}
        self.coordinate_front_right = {'x':0.0, 'y':0.0, 'z':0.0}
        self.coordinate_front_left = {'x':0.0, 'y':0.0, 'z':0.0}

        self.coordinate = {'x':0.0, 'y':0.0, 'z':0.0}
        self.angles = {'alpha':0.0, 'beta':0.0, 'gamma':0.0}

        self.poses = [self.pose_front_left, self.pose_front_right, 
                      self.pose_back_left, self.pose_back_right]
        
        self.publisher_list = [self.publisher_front_left_, 
                               self.publisher_front_right_, 
                               self.publisher_back_left_, 
                               self.publisher_back_right_]
        self.indice = 0

        self.msg = None

        self.flag_forward = False
        self.flag_backward = False
        self.flag_right = False
        self.flag_left = False
        self.flag_set = False
        self.flag_setangle = False

    def set_coordinate(self, x_, y_, z_):
        self.coordinate['x'] = x_
        self.coordinate['y'] = y_
        self.coordinate['z'] = z_

    def set_angles(self, alpha_, beta_, gamma_):
        self.angles['alpha'] = alpha_
        self.angles['beta'] = beta_
        self.angles['gamma'] = gamma_

    def correct_rad(self, pose):
        pose = list(pose)
        for i,q in enumerate(pose):
            if q > 1.57:
                pose[i] = 1.57
            elif q < -1.57:
                pose[i] = -1.57
        return pose

    def publish(self, pose, publisher):

        """
            Publish the especific pose to the especific publisher
        """

        msg = Float64MultiArray()

        msg.data = [pose[0], pose[1], pose[2]]

        publisher.publish(msg)

    def KD_move(self, q0, q1, q2, publisher):

        """
            Move a leg to the coordinate
        """

        pose = forward_kinematics(q0, q1, q2)

        if pose == None:
            print("KD imposible")
            return

        pose = list(pose)

        self.publish(pose, publisher)
        return pose
    
    def KI_move(self, x, y, z, publisher):

        """
            Move a leg to the coordinate
        """

        pose = inverse_kinematics(x, y, z)

        if pose == None:
            print("IK imposible")
            return

        pose = list(pose)
        pose[1] *= -1
        pose[2] += math.radians(90)

        self.publish(pose, publisher)
        return pose


    def moveLift(self, start, mid, end, publisher):

        """
            Divide the leg's movement in three: elevate, move to the point and low down.
        """

        P0 = np.array(start)
        P2 = np.array(end)
        mid = np.array(mid)

        t = np.linspace(0, 1, 50)

        t_mid = 0.5

        P1 = (mid - (1 - t_mid)**2 * P0 - t_mid**2 * P2) / (2 * (1 - t_mid) * t_mid)

        trajectory = np.array([(1 - ti)**2 * P0 + 2 * (1 - ti) * ti * P1 + ti**2 * P2 for ti in t])

        for i in range(len(trajectory)):
            x, y, z = trajectory[i]
            q = inverse_kinematics(x, y, z)
            
            if q is not None:
                q = list(q)
                q[1] *= -1
                q[2] += math.radians(90)
                if 2 <= i <= (len(trajectory) - 2):
                    self.publish([q[0], q[1], q[2] - 1.57], publisher)
                else:
                    self.publish([q[0], q[1], q[2]], publisher)
            time.sleep(0.05)
    
    def moveForward(self):
        start = [0.6, -0.65, -0.9]
        mid   = [1.4,  0.05, -0.2]
        end   = [0.6,  0.65, -0.9]

        self.moveLift(start, mid, end, self.publisher_back_left_)
        time.sleep(1)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        time.sleep(1)

        end = [0.6, -0.65, -0.9]
        mid   = [1.4,  0.05, -0.2]
        start   = [0.6,  0.65, -0.9]

        self.moveLift(start, mid, end, self.publisher_back_right_)
        time.sleep(1)
        self.moveLift(start, mid, end, self.publisher_front_right_)

    def listener_callback(self, msg):
        self.msg = msg
        self.state = State.JOY

    def timer_callback(self):
        global state_legs

        if self.msg is None:
            return

        if self.state != State.JOY:
            return

        if self.msg.data == "Key.up":
            self.flag_forward = True

        if self.msg.data == "Key.down":
            self.flag_backward = True

        if self.msg.data == "Key.right":
            self.flag_right = True

        if self.msg.data == "Key.left":
            self.flag_left = True

        if self.msg.data == "o":
            self.flag_set = True
        
        if self.msg.data == "k":
            self.flag_setangle = True

        if self.flag_forward:
            print("move forward")
            self.moveForward()
            self.flag_forward = False

        if self.flag_backward:
            print("move backward")
            self.flag_backward = False

        if self.flag_right:
            print("move right")
            self.flag_right = False

        if self.flag_left:
            print("move left")
            self.flag_left = False
        
        if self.flag_set:
            print("setamos a 0")
            self.KI_move(0.88, 0.0, -0.9, self.publisher_front_left_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_back_left_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_back_right_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_front_right_)
            self.set = False
        
        if self.flag_setangle:
            start = [0.6, -0.65, -0.9]
            mid   = [1.4,  0.05, -0.2]
            end   = [0.6,  0.65, -0.9]
            self.moveLift(start, mid, end, self.publisher_front_left_)
            self.flag_setangle = False

        self.msg = None


def main(args=None):
    rclpy.init(args=args)

    movement_publisher = MovementPublisher()

    rclpy.spin(movement_publisher)

    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
