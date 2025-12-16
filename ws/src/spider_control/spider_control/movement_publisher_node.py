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
        pose = self.correct_rad(pose)
        msg = Float64MultiArray()
        
        if self.get_publisher_index(publisher) == 2:
            pose[1] = pose[1] - math.radians(5) + math.radians(50)
        else :
            pose[1] = pose[1] + math.radians(50)
            
        pose[2] = pose[2] + math.radians(130)
        
        msg.data = [-pose[0], -pose[1], -pose[2]]

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
        P1 = (mid - (1 - t_mid)*2 * P0 - t_mid*2 * P2) / (2 * (1 - t_mid) * t_mid)

        t = t[:, None]
        trajectory = (1 - t)*2 * P0 + 2 * (1 - t) * t * P1 + t*2 * P2

        for i in range(len(trajectory)):
            x, y, z = trajectory[i]
            q = inverse_kinematics(x, y, z)

            if i == 0:
                print(x, y ,z)

            if q is not None:
                q = list(q)

                self.publish([q[0], q[1], q[2]], publisher)
                self.set_pose(q, self.get_publisher_index(publisher))
                time.sleep(0.02)
                
    def Rz(self, a):
        """Matriz de rotación alrededor de Z."""
        c, s = np.cos(a), np.sin(a)
        return np.array([[c, -s, 0],
                        [s,  c, 0],
                        [0,  0, 1]])
    
    def move_base(self, base, hip_local, feet, hip_len, leg_len, foot_len, yaw_deg):
        """
        Mueve las patas a las posiciones deseadas de los pies (coordenadas del mundo)
        base: posición del cuerpo (xyz)
        hip_local: offsets de caderas respecto al cuerpo
        feet: posiciones objetivo de los pies en coordenadas globales
        hip_len, leg_len, foot_len: longitudes de los segmentos
        yaw_deg: orientación de cada pata en grados (FR, FL, RR, RL)
        """
        for i in range(4):
            # posición de la cadera en mundo
            hip_world = np.array(base) + np.array(hip_local[i])
            alpha = np.deg2rad(yaw_deg[i])

            # vector del hip al foot en coordenadas globales
            v_world = np.array(feet[i]) - hip_world

            # transformar al marco de la pata
            v_hip = self.Rz(-alpha) @ v_world
            x_rel, y_rel, z_rel = v_hip

            # calcular IK en marco de la pata
            pose = inverse_kinematics(x_rel, y_rel, z_rel)
            if pose is None:
                print(f"IK imposible para pata {i}")
                continue

            print("i: ", i, " | pose: ", pose)

            # publicar pose
            self.publish(pose, self.publisher_list[i])
            self.set_pose(pose, i)

    def direct_base(self, base_pose):
        hip_local = [[0.4949, 0.4949, 0], [0.4949, -0.4949, 0], [-0.4949, 0.4949, 0], [-0.4949, -0.4949, 0]]
        # feet = [[0.88, 0.4, -0.8], [0.88, -0.4, -0.8], [0.88, 0.4, -0.8], [0.88, -0.4, -0.8]]
        feet=[[1.3, 0.8, -0.8], [1.3, -0.8, -0.8], [-1.3, 0.8, -0.8], [-1.3, -0.8, -0.8]]
        hip_len = 0.37
        leg_len = 0.507
        foot_len = 0.8

        yaw_deg = [45, -45, 135, -135]
        self.move_base(base_pose, hip_local, feet, hip_len, leg_len, foot_len, yaw_deg)

    def moveForward(self):
        self.direct_base([0.0, 0.25, 0])
        time.sleep(0.1)
        
        start = [0.6, 0.65, -0.8]
        mid   = [1.4,  0.05, -0.2]
        end   = [0.6,  -0.65, -0.8]        
        self.moveLift(start, mid, end, self.publisher_back_left_)
        time.sleep(0.1)

        start = [0.6, 0.65, -0.8]
        mid   = [1.4,  0.05, -0.2]
        end   = [0.6,  -0.65, -0.8]       
        self.moveLift(start, mid, end, self.publisher_front_left_)
        time.sleep(0.1)

        self.set_pose([0.88, 0.0, -0.8], 2)
        self.set_pose([0.88, 0.0, -0.8], 1)

        self.direct_base([0.0, 0.0, 0])
        time.sleep(0.1)
        self.direct_base([0.0, -0.25, 0])
        time.sleep(0.1)

        start   = [0.6,  -0.65, -0.8]
        mid   = [1.4,  0.05, -0.2]
        end = [0.6, 0.65, -0.8]        
        self.moveLift(start, mid, end, self.publisher_back_right_)
        time.sleep(0.1)

        start   = [0.6,  -0.65, -0.8]
        mid   = [1.4,  0.05, -0.2]
        end = [0.6, 0.65, -0.8]
        self.moveLift(start, mid, end, self.publisher_front_right_)
        time.sleep(0.1)

        self.KI_move(0.88, 0.0, -0.8, self.publisher_front_left_)
        self.KI_move(0.88, 0.0, -0.8, self.publisher_back_left_)
        self.KI_move(0.88, 0.0, -0.8, self.publisher_front_right_)
        self.KI_move(0.88, 0.0, -0.8, self.publisher_back_right_)
        time.sleep(0.1)

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

            self.flag_backward = False

        if self.flag_right:
            print("move right")
            self.flag_right = False

        if self.flag_left:
            print("move left")
            self.flag_left = False
        
        if self.flag_set:
            print("setamos a 0")
            self.KI_move(0.88, 0.0, -0.8, self.publisher_front_left_)
            self.KI_move(0.88, 0.0, -0.8, self.publisher_back_left_)
            self.KI_move(0.88, 0.0, -0.8, self.publisher_front_right_)
            self.KI_move(0.88, 0.0, -0.8, self.publisher_back_right_)
            self.set = False
        
        if self.flag_setangle:
            base = [0.35, 0.0, 0.0]
            self.direct_base(base)
            self.flag_setangle = False


def main(args=None):
    rclpy.init(args=args)

    movement_publisher = MovementPublisher()

    rclpy.spin(movement_publisher)

    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
