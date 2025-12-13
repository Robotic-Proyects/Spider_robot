import rclpy
import time
import math
import numpy as np
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from enum import Enum, auto

from spider_control.KI import forward_kinematics, inverse_kinematics
from spider_msgs.msg import SpiderLeg, SpiderSwitch
from sensor_msgs.msg import Joy

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
        self.publisher_back_left_ = self.create_publisher(SpiderLeg, '/arm/backleft', 10)
        self.publisher_back_right_ = self.create_publisher(SpiderLeg, '/arm/backright', 10)
        self.publisher_front_left_ = self.create_publisher(SpiderLeg, '/arm/frontleft', 10)
        self.publisher_front_right_ = self.create_publisher(SpiderLeg, '/arm/frontright', 10)
        self.publisher_oe_ = self.create_publisher(SpiderSwitch, '/oe_value', 10)

        self.subscription = self.create_subscription(
            Joy,
            '/joy',
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
        self.prev_buttons = {
            0: 0,  # X
            1: 0,  # O
            2: 0,  # T
            3: 0,  # C
            8: 0,  # SHARE
            9: 0   # OPTIONS
        }

        self.X_flag = False
        self.O_flag = False
        self.T_flag = False
        self.C_flag = False

    def set_pose(self, pose, index):
        self.poses[index] = pose

    def get_publisher_index(self, publisher):
        return self.publisher_list.index(publisher)

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

            # Limit of hip
            if i == 0:
                if pose[i] > 1.0:
                    pose[i] = 1.0
                elif pose[i] < -1.0:
                    pose[i] = -1.0


        return pose

    def publish(self, pose, publisher):

        """
            Publish the especific pose to the especific publisher
        """
        msg = SpiderLeg()
        pose = self.correct_rad(pose)
        msg.hip = pose[0]
        msg.leg = pose[1]
        msg.foot = pose[2]
        msg.smooth_value = 1.0

        publisher.publish(msg)
    
    def KD_move(self, q0, q1, q2, publisher):

        """
            Move a leg to the coordinate
        """
        pose[2] += math.radians(90)

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
        pose[2] += math.radians(90)

        self.publish(pose, publisher)
        self.set_pose(pose, self.get_publisher_index(publisher))
        return pose

    def moveLift(self, start, mid, end, publisher):

        """
            Divide the leg's movement in three: elevate, move to the point and low down.
        """

        start = np.array(start)
        target = np.array(end)
        mid = np.array(mid)

        t = np.linspace(0, 1, 50)
        t_mid = 0.5

        P0 = start
        P2 = target
        P1 = (mid - (1 - t_mid)**2 * P0 - t_mid**2 * P2) / (2 * (1 - t_mid) * t_mid)

        t = t[:, None]
        trajectory = (1 - t)**2 * P0 + 2 * (1 - t) * t * P1 + t**2 * P2

        for i in range(len(trajectory)):
            x, y, z = trajectory[i]
            q = inverse_kinematics(x, y, z)

            if q is not None:
                q = list(q)
                q[2] += math.radians(90)

                self.publish([q[0], q[1], q[2]], publisher)
                self.set_pose(q, self.get_publisher_index(publisher))
                time.sleep(0.01)
        
    """
    def moveBase(self, index_hip, index_hip2, index_leg, inv_= 1):
        pose_hip = self.poses[index_hip]
        pose_hip2 = self.poses[index_hip2]
        pose_leg = self.poses[index_leg]

        publisher_hip = self.publisher_list[index_hip]
        publisher_hip2 = self.publisher_list[index_hip2]
        publisher_leg = self.publisher_list[index_leg]

        turn_ = 40 * inv_
        
        pose_hip = [pose_hip[0] + math.radians(turn_), pose_hip[1], pose_hip[2]]
        self.publish(pose_hip, publisher_hip)

        pose_hip2 = [pose_hip2[0] + math.radians(turn_*-1), pose_hip2[1], pose_hip2[2]]
        self.publish(pose_hip2, publisher_hip2)

        pose_leg = [pose_leg[0], pose_leg[1] + math.radians(10), pose_leg[2] - math.radians(5)]
        self.publish(pose_leg, publisher_leg)

        self.set_pose(pose_hip, index_hip)
        self.set_pose(pose_hip2, index_hip2)
        self.set_pose(pose_leg, index_leg)
    """

    def move_base(self, base, hip_local, feet, hip_len, leg_len, foot_len):
        # base: posición del cuerpo en coordenadas del mundo
        # hip_local: offsets de las caderas respecto al cuerpo (local)
        # feet: posiciones objetivo de los pies EN COORDENADAS DEL MUNDO (no locales)
        for i in range(4):
            hip_world = np.array(base) + np.array(hip_local[i])
            foot_world = np.array(feet[i])

            x_rel = foot_world[0] - hip_world[0]
            y_rel = foot_world[1] - hip_world[1]
            z_rel = foot_world[2] - hip_world[2]

            pose = inverse_kinematics(x_rel, y_rel, z_rel)
            if pose is None:
                print("IK imposible:", i)
                continue

            pose = list(pose)
            pose[2] += math.radians(90)
            self.publish(pose, self.publisher_list[i])
            self.set_pose(pose, i)

    def direct_base(self, base_pose):
        hip_local = [[0.07, 0.07, 0], [0.07, -0.07, 0], [-0.07, 0.07, 0], [-0.07, -0.07, 0]]
        feet = [[0.88, 0.4, -0.9], [0.88, -0.4, -0.9], [0.88, 0.4, -0.9], [0.88, -0.4, -0.9]]
        hip_len = 0.37
        leg_len = 0.507
        foot_len = 0.9

        self.move_base(base_pose, hip_local, feet, hip_len, leg_len, foot_len)

    def moveForward(self):
        start = [0.6, 0.65, -0.9]
        mid   = [1.4,  0.05, -0.2]
        end   = [0.6,  -0.65, -0.9]

        self.direct_base([0.0, 0.25, 0])
        time.sleep(0.25)
        self.moveLift(start, mid, end, self.publisher_back_left_)
        time.sleep(0.25)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        time.sleep(0.25)

        start   = [0.6,  -0.45, -0.9]
        mid   = [1.4,  0.05, -0.2]
        end = [0.6, 0.45, -0.9]

        print(self.poses[1])
        print(self.poses[2])
        self.set_pose([0.88, 0.0, -0.9], 2)
        self.set_pose([0.88, 0.0, -0.9], 1)
        print(self.poses[1])
        print(self.poses[2])

        self.direct_base([0.0, -0.25, 0])
        time.sleep(0.25)
        self.moveLift(start, mid, end, self.publisher_back_right_)
        time.sleep(0.25)
        self.moveLift(start, mid, end, self.publisher_front_right_)
        time.sleep(0.25)

        self.KI_move(0.88, 0.0, -0.9, self.publisher_front_left_)
        self.KI_move(0.88, 0.0, -0.9, self.publisher_back_left_)
        self.KI_move(0.88, 0.0, -0.9, self.publisher_front_right_)
        self.KI_move(0.88, 0.0, -0.9, self.publisher_back_right_)
        time.sleep(0.25)
    
    def listener_callback(self, msg):
        self.msg = msg
        self.state = State.JOY

    def expo_axis(self, x, expo=0.4):
        return math.copysign(abs(x) ** (1 + expo), x)

    def rising_edge(self, btn_id):
        b = self.msg.buttons[btn_id]
        prev = self.prev_buttons[btn_id]
        self.prev_buttons[btn_id] = b
        return b == 1 and prev == 0

    def timer_callback(self):
        global state_legs

        pose = self.poses[self.indice]
        publisher = self.publisher_list[self.indice]

        if self.msg is None:
            return

        if self.state != State.JOY:
            return

        if self.rising_edge(8):  # SHARE
            msg_ = SpiderSwitch()
            msg_.oe_value = 0
            self.publisher_oe_.publish(msg_)

        if self.rising_edge(9):  # OPTIONS
            msg_ = SpiderSwitch()
            msg_.oe_value = 1
            self.publisher_oe_.publish(msg_)

        if self.rising_edge(0):  # X
            self.X_flag = True
            self.O_flag = False
            self.T_flag = False
            self.C_flag = False

        if self.rising_edge(1):  # CIRCLE
            self.X_flag = False
            self.O_flag = True
            self.T_flag = False
            self.C_flag = False

        if self.rising_edge(2):  # TRIANGLE
            self.X_flag = False
            self.O_flag = False
            self.T_flag = True
            self.C_flag = False

        if self.rising_edge(3):  # SQUARE
            self.X_flag = False
            self.O_flag = False
            self.T_flag = False
            self.C_flag = True
        
        if self.T_flag: # TRIANGLE button
            self.KI_move(0.88, 0.0, -0.9, self.publisher_front_left_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_back_left_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_front_right_)
            self.KI_move(0.88, 0.0, -0.9, self.publisher_back_right_)
            self.T_flag = False

        if self.C_flag: # SQUARE button
            base = [0.25, 0.25, 0.0]
            self.direct_base(base)
            self.C_flag = False

        if self.O_flag:
            base = [0.3, -0.6, 0.0]
            self.direct_base(base)
            self.O_flag = False


        if self.msg.axes[7] == -1:
            print("Move backward")
            #self.backwardMove(step_length, z)

        if self.msg.axes[7] == 1:
            print("move forward")
            self.moveForward()

        if self.msg.axes[6] == 1:
            print("move left")
            #self.leftMove(step_length, z)

        if self.msg.axes[6] == -1:
            print("move right")
            #self.rightMove(step_length, z)



def main(args=None):
    rclpy.init(args=args)

    movement_publisher = MovementPublisher()

    rclpy.spin(movement_publisher)

    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()