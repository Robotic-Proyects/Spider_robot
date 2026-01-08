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

F_OFF = math.radians(0.0)
S_OFF = math.radians(-35.0) # S_OFF = math.radians(0.0) 
T_OFF = math.radians(50.0) # T_OFF = math.radians(90.0)

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

        self.pose_back_right = [0.507, 0.0, -0.8]
        self.pose_back_left = [0.507, 0.0, -0.8]
        self.pose_front_right = [0.507, 0.0, -0.8]
        self.pose_front_left = [0.507, 0.0, -0.8]

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
        
        msg.data = [-pose[0], -pose[1], -pose[2]]

        publisher.publish(msg)
    
    def KD_move(self, q0, q1, q2, publisher):

        """
            Move a leg to the coordinate
        """

        pose = forward_kinematics(q0, q1, q2, F_OFF, S_OFF, T_OFF)

        if pose == None:
            print("KD imposible")
            return

        pose = list(pose)
        self.publish([q0, q1, q2], publisher)
        return pose
    
    def KI_move(self, x, y, z, publisher):

        """
            Move a leg to the coordinate
        """
        pose = inverse_kinematics(x, y, z, F_OFF, S_OFF, T_OFF)

        if pose == None:
            print("IK imposible")
            return        #msg.foot = pose[2] + math.radians(35)
        #msg.foot = pose[2] + math.radians(110)
        
        pose = list(pose)

        self.publish(pose, publisher)
        self.set_pose([x, y, z], self.get_publisher_index(publisher))
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
            q = inverse_kinematics(x, y, z, F_OFF, S_OFF, T_OFF)

            if q is not None:
                q = list(q)

                self.publish([q[0], q[1], q[2]], publisher)
                self.set_pose([x, y, z], self.get_publisher_index(publisher))
                time.sleep(0.01)
                
    def R(self, a):
        """Matriz de rotación."""
        c, s = np.cos(a), np.sin(a)
        
        rz = np.array([[c, -s, 0],
                        [s,  c, 0],
                        [0,  0, 1]])

        rx = np.array([[1, 0, 0],
                        [0,  1, 0],
                        [0,  0, 1]])

        ry = np.array([[1, 0, 0],
                        [0,  1, 0],
                        [0,  0, 1]])
        
        return rz @ rx @ ry
    
    def move_base(self, base, hip_local, feet_global, yaw_deg):
        """
        Mueve las patas a las posiciones deseadas de los pies (coordenadas del mundo)
        base: posición del cuerpo (xyz)
        hip_local: offsets de caderas respecto al cuerpo
        feet_local: posiciones objetivo de los pies en coordenadas de la pata
        hip_len, leg_len, foot_len: longitudes de los segmentos
        yaw_deg: orientación de cada pata en grados (FR, FL, RR, RL)
        """
        feet_local = []
        for i in range(4):
            # posición de la cadera en mundo
            hip_world = np.array(base) + np.array(hip_local[i])
            alpha = np.deg2rad(yaw_deg[i])

            # vector del hip al foot en coordenadas globales
            v_world = np.array(feet_global[i]) - hip_world

            # transformar al marco de la pata
            v_hip = self.R(-alpha) @ v_world
            x_rel, y_rel, z_rel = v_hip
            feet_local.append(v_hip)

            # calcular IK en marco de la pata
            pose = inverse_kinematics(x_rel, y_rel, z_rel, F_OFF, S_OFF, T_OFF)
            if pose is None:
                print(f"IK imposible para pata {i}")
                continue

            # publicar pose
            self.publish(pose, self.publisher_list[i])
            self.set_pose([x_rel, y_rel, z_rel], i)

        return feet_local

    def local2Global(self, base, feet_local):
        """
        Convierte posiciones locales de las patas a coordenadas globales

        base: [x, y, z] posición del cuerpo
        hip_local: offsets de las caderas respecto al cuerpo
        feet_local: posiciones de los pies en marco de la pata
        yaw_deg: yaw de cada pata
        """
        hip_local = [[0.4949, 0.4949, 0], [0.4949, -0.4949, 0], [-0.4949, 0.4949, 0], [-0.4949, -0.4949, 0]]
        yaw_deg = [45, -45, 135, -135]
        feet_global = []

        for i in range(4):
            alpha = np.deg2rad(yaw_deg[i])

            # rotar del marco de la pata al mundo
            v_world = self.R(alpha) @ np.array(feet_local[i])

            # sumar base y offset de cadera
            p_world = np.array(base) + np.array(hip_local[i]) + v_world

            feet_global.append(p_world)

        return feet_global


    def direct_base(self, base_pose):
        """
        Mueve el cuerpo a base_pose usando las posiciones actuales de las patas.
        """
        # Usamos la pose actual de cada pata en marco local
        feet_local = []
        for pose in self.poses:
            feet_local.append(pose)  # suposición: self.poses ya son locales a cada pata

        # Convertimos a coordenadas globales usando la base actual
        feet_global = self.local2Global(base_pose, feet_local)

        # Offsets de cadera y yaw de cada pata
        hip_local = [[0.4949, 0.4949, 0], [0.4949, -0.4949, 0], [-0.4949, 0.4949, 0], [-0.4949, -0.4949, 0]]
        yaw_deg = [45, -45, 135, -135]

        # Movemos las patas
        self.move_base(base_pose, hip_local, feet_global, yaw_deg)


        
    def calculate_mid_pose(self, start, end):
        mid = [0.0, 0.0, 0.0]

        mid[0] = (start[0] + end[0]) / 2
        mid[1] = (start[1] + end[1]) / 2
        mid[2] = (start[2] + end[2]) / 2

        mid[2] += 0.1
        return mid

    def moveForward(self):
        self.direct_base([0.15, -0.15, 0])
        # time.sleep(0.2)
        
        start = self.pose_back_left
        end   = [0.45, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)

        start = self.pose_front_left
        end   = [0.45, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)    
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])

        self.direct_base([0.15, 0.15, 0])
        # time.sleep(0.2)

        start   = self.pose_back_right
        end = [0.45, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)   
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)

        start   = self.pose_front_right
        end = [0.45, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end) 
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        # time.sleep(0.2)

    def moveBackward(self):
        self.direct_base([-0.15, -0.15, 0])
        # time.sleep(0.2)
        
        start = self.pose_back_left
        end   = [0.45, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)

        start = self.pose_front_left
        end   = [0.45, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)    
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])

        self.direct_base([-0.15, 0.15, 0])
        # time.sleep(0.2)

        start   = self.pose_back_right
        end = [0.45, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)   
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)

        start   = self.pose_front_right
        end = [0.45, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end) 
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        # time.sleep(0.2)
    
    def turnRight(self):
        start = self.pose_back_left
        # end   = [0.2742,  -0.4271, -0.8] 
        end   = [0.45, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)

        self.direct_base([-0.1, 0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)
        self.direct_base([0.1, 0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)
        self.direct_base([0.1, -0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)
        self.direct_base([-0.1, -0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)
        self.direct_base([0, 0, 0])

    def turnLeft(self):
        start = self.pose_back_left
        # end   = [0.2742, 0.4271, -0.8] 
        end   = [0.45, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)

        self.direct_base([-0.1, -0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)
        self.direct_base([0.1, -0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)
        self.direct_base([0.1, 0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)
        self.direct_base([-0.1, 0.1, 0])
        # time.sleep(0.2)
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)
        self.direct_base([0, 0, 0])


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
            base = [0.0, 0.0, 0.0]
            hip_local = [
                [0.4949,  0.4949, 0],
                [0.4949, -0.4949, 0],
                [-0.4949, 0.4949, 0],
                [-0.4949,-0.4949, 0]
            ]
            feet_global = [
                [ 0.8534,  0.8534, -0.8],
                [ 0.8534, -0.8534, -0.8],
                [-0.8534,  0.8534, -0.8],
                [-0.8534, -0.8534, -0.8]
            ]
            yaw_deg = [45, -45, 135, -135]

            # Global → Local
            feet_local_cal = self.move_base(base, hip_local, feet_global, yaw_deg)

            # Local → Global
            feet_global_rec = self.local2Global(base, feet_local_cal)

            print("original =", feet_global)
            print("feet_local_cal=", feet_local_cal)
            print("recalc   =", feet_global_rec)
            print("ok =", np.allclose(feet_global, feet_global_rec))

            self.moveBackward()
            self.flag_backward = False

        if self.flag_right:
            self.turnRight()
            self.flag_right = False

        if self.flag_left:
            self.turnLeft()
            self.flag_left = False
        
        if self.flag_set:
            self.KI_move(0.507, 0.0, -0.8, self.publisher_front_left_)
            self.KI_move(0.507, 0.0, -0.8, self.publisher_back_left_)
            self.KI_move(0.507, 0.0, -0.8, self.publisher_front_right_)
            self.KI_move(0.507, 0.0, -0.8, self.publisher_back_right_)
            self.set = False
        
        if self.flag_setangle:
            base = [0.0, 0.0, 0.0]
            self.direct_base(base)
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
