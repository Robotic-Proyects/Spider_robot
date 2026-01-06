import rclpy
import time
import math
import numpy as np
from rclpy.node import Node

from std_msgs.msg import UInt8MultiArray, Float64, UInt8
from enum import Enum, auto

from spider_control.KI import forward_kinematics, inverse_kinematics
from spider_msgs.msg import SpiderLeg, SpiderSwitch
from sensor_msgs.msg import Joy, LaserScan

import board
import busio
import adafruit_ssd1306
from PIL import Image, ImageDraw, ImageFont

HALFWIDTH = 5
state_legs = 0

F_OFF = math.radians(0.0)
S_OFF = math.radians(-35.0) # S_OFF = math.radians(-35.0) # S_OFF = math.radians(0.0) 
T_OFF = math.radians(45.0) # T_OFF = math.radians(50.0) # T_OFF = math.radians(90.0)

class State(Enum):
    CONTROL = auto()
    QUEST1 = auto()
    QUEST1_2 = auto()
    QUEST2 = auto()
    OFF = auto()

class MovementPublisher(Node):

    def __init__(self):
        super().__init__('movement_publisher')
        self.publisher_back_left_ = self.create_publisher(SpiderLeg, '/arm/backleft', 10)
        self.publisher_back_right_ = self.create_publisher(SpiderLeg, '/arm/backright', 10)
        self.publisher_front_left_ = self.create_publisher(SpiderLeg, '/arm/frontleft', 10)
        self.publisher_front_right_ = self.create_publisher(SpiderLeg, '/arm/frontright', 10)

        self.publisher_ultrasonic = self.create_publisher(Float64, '/ultrasonic', 10)
        self.publisher_head = self.create_publisher(Float64, '/head', 10)
        self.publisher_range = self.create_publisher(UInt8MultiArray, '/range', 10)
        self.publisher_blocked_ = self.create_publisher(UInt8, '/blocked', 10)
        self.publisher_oe_ = self.create_publisher(SpiderSwitch, '/oe_value', 10)

        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.oled = adafruit_ssd1306.SSD1306_I2C(128, 64, self.i2c, addr=0x3C)
        self.font = ImageFont.load_default()

        self.subscription = self.create_subscription(
            Joy,
            '/joy',
            self.listener_callback,
            1)
        
        self.sonar_subscription = self.create_subscription(
            LaserScan,
            '/sonar_scan',
            self.sonar_callback,
            10)

        self.subscription
        self.sonar_subscription

        self.msg = None
        self.sonar_data = None

        timer_period = 0.02  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.state = State.CONTROL

        self.pose_back_right = [0.0, 0.0, 0.0]
        self.pose_back_left = [0.0, 0.0, 0.0]
        self.pose_front_right = [0.0, 0.0, 0.0]
        self.pose_front_left = [0.0, 0.0, 0.0]

        self.base_pose = [0.0, 0.0, 0.0]

        self.angles = {'alpha':0.0, 'beta':0.0, 'gamma':0.0}

        self.poses = [self.pose_front_left, self.pose_front_right, 
                      self.pose_back_left, self.pose_back_right]
        
        self.publisher_list = [self.publisher_front_left_, 
                               self.publisher_front_right_, 
                               self.publisher_back_left_, 
                               self.publisher_back_right_]

        self.prev_buttons = {
            0: 0,  # X
            1: 0,  # O
            2: 0,  # T
            3: 0,  # C
            4: 0,  # L1
            5: 0,  # R1
            6: 0,  # L2
            7: 0,  # R2
            8: 0,  # SHARE
            9: 0   # OPTIONS
        }

        self.X_flag = False
        self.O_flag = False
        self.T_flag = False
        self.C_flag = False

        self.walls = []
        self._last_screen = None

        self.head_rad = 0.0

        self.KI_move(0.507, 0.0, -0.8, self.publisher_front_left_)
        self.KI_move(0.507, 0.0, -0.8, self.publisher_back_left_)
        self.KI_move(0.507, 0.0, -0.8, self.publisher_front_right_)
        self.KI_move(0.507, 0.0, -0.8, self.publisher_back_right_)

        msg_blocked = UInt8()
        msg_blocked.data = 0
        self.publisher_blocked_.publish(msg_blocked)

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

        msg.smooth_value = 0.5

        # if publisher == self.publisher_front_left_:
        #     msg.leg += math.radians(-5.0)

        if publisher == self.publisher_back_left_:
            msg.leg += math.radians(-8.0)
            # msg.foot += math.radians(-5.0)

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
        # print("KI: ", pose)
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
        for i in range(4):
            # posición de la cadera en mundo
            hip_world = np.array(base) + np.array(hip_local[i])
            alpha = np.deg2rad(yaw_deg[i])

            # vector del hip al foot en coordenadas globales
            v_world = np.array(feet_global[i]) - hip_world

            # transformar al marco de la pata
            v_hip = self.R(-alpha) @ v_world
            x_rel, y_rel, z_rel = v_hip

            # calcular IK en marco de la pata
            pose = inverse_kinematics(x_rel, y_rel, z_rel, F_OFF, S_OFF, T_OFF)
            if pose is None:
                print(f"IK imposible para pata {i}")
                continue

            # publicar pose
            # print("Move_base: ",pose)
            self.publish(pose, self.publisher_list[i])
            self.set_pose([x_rel, y_rel, z_rel], i)
            time.sleep(0.01)

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

    def direct_base(self, new_base_pose):
        feet_local = [[0.507, 0.0, -0.8], [0.507, 0.0, -0.8], [0.507, 0.0, -0.8], [0.507, 0.0, -0.8]]
        feet_global = self.local2Global([0.0, 0.0, 0.0], feet_local)

        hip_local = [[0.4949, 0.4949, 0], [0.4949, -0.4949, 0], [-0.4949, 0.4949, 0], [-0.4949, -0.4949, 0]]
        yaw_deg = [45, -45, 135, -135]

        self.move_base(new_base_pose, hip_local, feet_global, yaw_deg)

        self.base_pose = new_base_pose

    def calculate_mid_pose(self, start, end):
        mid = [0.0, 0.0, 0.0]

        mid[0] = (start[0] + end[0]) / 2
        mid[1] = (start[1] + end[1]) / 2
        mid[2] = (start[2] + end[2]) / 2

        mid[2] += 0.1
        return mid

    def moveForward(self):
        self.direct_base([0.15, -0.15, 0])
        time.sleep(0.1)
        
        start = self.pose_back_left
        end   = [0.65, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)

        start = self.pose_front_left
        end   = [0.65, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)    
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        time.sleep(0.1)

        self.direct_base([0.15, 0.15, 0])
        time.sleep(0.1)

        start   = self.pose_back_right
        end = [0.65, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)   
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)

        start   = self.pose_front_right
        end = [0.65, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end) 
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        time.sleep(0.1)

    def moveBackward(self):
        self.direct_base([-0.15, -0.15, 0])
        time.sleep(0.1)
        
        start = self.pose_back_left
        end   = [0.65, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)
        self.moveLift(start, mid, end, self.publisher_front_left_)
        # time.sleep(0.2)

        start = self.pose_front_left
        end   = [0.65, 0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)    
        self.moveLift(start, mid, end, self.publisher_back_left_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        time.sleep(0.1)

        self.direct_base([-0.15, 0.15, 0])
        time.sleep(0.1)

        start   = self.pose_back_right
        end = [0.65, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end)   
        self.moveLift(start, mid, end, self.publisher_front_right_)
        # time.sleep(0.2)

        start   = self.pose_front_right
        end = [0.65, -0.35, -0.8] 
        mid   = self.calculate_mid_pose(start, end) 
        self.moveLift(start, mid, end, self.publisher_back_right_)
        # time.sleep(0.2)

        self.direct_base([0.0, 0.0, 0])
        time.sleep(0.1)
    
    def turnRight(self):
        start = self.pose_back_left
        # end   = [0.2742,  -0.4271, -0.8] 
        end   = [0.65, -0.35, -0.8] 
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
        end   = [0.65, 0.35, -0.8] 
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
    
    def sonar_callback(self, msg):
        self.sonar_data = msg
        #print(len(msg.ranges))

    def display_msgs(self, header_text, text_lines):
        current_screen = (header_text, tuple(text_lines) if text_lines else None)

        if current_screen == self._last_screen:
            return

        self._last_screen = current_screen

        image = Image.new("1", (self.oled.width, self.oled.height))
        draw = ImageDraw.Draw(image)

        draw.rectangle((0, 0, self.oled.width-1, 15), fill=1)
        w, h = draw.textsize(header_text, font=self.font)
        draw.text(((self.oled.width - w)//2, (15 - h)//2), header_text, font=self.font, fill=0)

        draw.rectangle((0, 15, self.oled.width-1, self.oled.height-1), fill=0)

        if text_lines:
            y = 15
            for line in text_lines:
                draw.text((0, y), line, font=self.font, fill=1)
                y += 10
        else:
            draw.rectangle((0, 15, self.oled.width-1, self.oled.height-1), fill=1)

        self.oled.image(image)
        self.oled.show()

    def rising_edge(self, btn_id):
        b = self.msg.buttons[btn_id]
        prev = self.prev_buttons[btn_id]
        self.prev_buttons[btn_id] = b
        return b == 1 and prev == 0

    def detect_walls(self):
        data = np.array(self.sonar_data.ranges)
        mid_index = len(data) // 2
        window = 5
        threshold = 0.5

        def wall_side(segment):
            for i in range(len(segment) - window + 1):
                slice_window = segment[i:i+window]
                slice_window = slice_window[slice_window != -1]
                if len(slice_window) == 0:
                    continue 
                if slice_window[0] < threshold:
                    diffs = np.diff(slice_window)
                    if np.all(diffs >= 0):
                        return True
            return False

        right_wall = wall_side(data[:mid_index])
        left_wall = wall_side(data[mid_index:])
        return (left_wall, right_wall)

    def timer_callback(self):
        global state_legs, F_OFF, S_OFF, T_OFF

        if self.sonar_data is not None:
            print(len(self.sonar_data.ranges))

        if self.msg is not None:
            if self.rising_edge(8): # Share
                msg_ = SpiderSwitch()
                msg_.oe_value = 0
                self.publisher_oe_.publish(msg_)
                self.state = State.CONTROL

            if self.rising_edge(9): # Options
                msg_ = SpiderSwitch()
                msg_.oe_value = 1
                self.publisher_oe_.publish(msg_)
                self.state = State.OFF

        match self.state:
            case State.CONTROL:
                self.display_msgs(
                    "OFFSETS",
                    [
                        f"F_OFF: {math.degrees(F_OFF):.1f}",
                        f"S_OFF: {math.degrees(S_OFF):.1f}",
                        f"T_OFF: {math.degrees(T_OFF):.1f}"
                    ]
                )

                if self.msg is None:
                    msg_range = UInt8MultiArray()
                    msg_range.data = [60, 120]
                    self.publisher_range.publish(msg_range)

                    time.sleep(2)

                    self.state = State.QUEST2

                    return

                if self.rising_edge(0): # X
                    self.direct_base([0.0, 0.0, 0.0])

                if self.rising_edge(1): # O
                    msg_range = UInt8MultiArray()
                    msg_range.data = [0, 165]
                    self.publisher_range.publish(msg_range)

                    time.sleep(2)

                    self.state = State.QUEST2

                if self.rising_edge(2): # △
                    msg_blocked = UInt8()
                    msg_blocked.data = 0
                    self.publisher_blocked_.publish(msg_blocked)

                    msg_range = UInt8MultiArray()
                    msg_range.data = [0, 165]
                    self.publisher_range.publish(msg_range)

                if self.rising_edge(3): # □
                    self.walls = [None, None]

                    # Marcar que se mueva el ultrasonidos de 0 a 172 grados
                    msg_range = UInt8MultiArray()
                    msg_range.data = [0, 165]
                    self.publisher_range.publish(msg_range)

                    time.sleep(2)

                    self.state = State.QUEST1

                if self.rising_edge(4):  # L1
                    msg = Float64()
                    self.head_rad += 0.1
                    msg.data = self.head_rad
                    self.publisher_head.publish(msg)

                if self.rising_edge(5):  # R1
                    msg = Float64()
                    self.head_rad -= 0.1
                    msg.data = self.head_rad
                    self.publisher_head.publish(msg)

                if self.rising_edge(6): # L2
                    F_OFF, S_OFF, T_OFF = math.radians(0.0), math.radians(-35.0), math.radians(45.0)
                    self.direct_base([0.0, 0.0, 0.0])

                if self.rising_edge(7): # R2
                    F_OFF, S_OFF, T_OFF = math.radians(0.0), math.radians(0.0), math.radians(90.0)
                    self.direct_base([0.0, 0.0, 0.0])

                if self.msg.axes[7] == 1:
                    self.moveForward()
                if self.msg.axes[7] == -1:
                    self.moveBackward()
                if self.msg.axes[6] == 1:
                    self.turnLeft()
                if self.msg.axes[6] == -1:
                    self.turnRight()

            case State.QUEST1:
                F_OFF, S_OFF, T_OFF = math.radians(0.0), math.radians(-35.0), math.radians(45.0)
                self.display_msgs("WALLS", ["Detecting walls..."])

                if self.sonar_data is not None:
                    left, right = self.detect_walls()

                    msg_blocked = UInt8()
                    msg_ultra = Float64()

                    if left:
                        msg_blocked.data = 1
                        self.publisher_blocked_.publish(msg_blocked)
                        time.sleep(0.5)
                        msg_ultra.data = 2.5
                        self.publisher_ultrasonic.publish(msg_ultra)
                        self.state = State.QUEST1_2
                        time.sleep(0.5)

                        # print("LEFT")
                        self.display_msgs("WALLS", ["Detected left wall"])

                    elif right:
                        msg_blocked.data = 1
                        self.publisher_blocked_.publish(msg_blocked)
                        time.sleep(0.5)
                        msg_ultra.data = 0.0
                        self.publisher_ultrasonic.publish(msg_ultra)
                        self.state = State.QUEST1_2
                        time.sleep(0.5)

                        # print("RIGHT")
                        self.display_msgs("WALLS", ["Detected right wall"])

                    self.walls = [left, right]
                else:
                    self.walls = [None, None]

            case State.QUEST1_2:
                F_OFF, S_OFF, T_OFF = math.radians(0.0), math.radians(-35.0), math.radians(45.0)

                sonar_dist = self.sonar_data.ranges[0]

                move = ""
                wall_detected = ""
                if sonar_dist < 1.0:
                    self.moveForward()
                    move = "Moving Forward"
                else:
                    if self.walls[0]:
                        self.turnLeft()
                        move = "Turning Left"
                        wall_detected = "Left Wall"
                    else:
                        self.turnRight()
                        move = "Turning Right"
                        wall_detected = "Right Wall"

                self.display_msgs("FOLLOWING WALL", [f"Detected {wall_detected}", f"Action: {move}"])
            case State.QUEST2:
                F_OFF, S_OFF, T_OFF = math.radians(0.0), math.radians(-35.0), math.radians(45.0)

                if self.sonar_data is None:
                    return

                data = np.array(self.sonar_data.ranges)
                print(data)
                data = data[data != -1]

                if np.any(data < 0.35):
                    print("Obstáculo muy cercano, girando dos veces y deteniendo")
                    for _ in range(5):
                        self.turnLeft()
                    self.state = State.OFF
                    return
                else:
                    self.moveForward()

            case State.OFF:
                self.display_msgs("SLEEPING", [])
                pass

def main(args=None):
    rclpy.init(args=args)

    movement_publisher = MovementPublisher()

    rclpy.spin(movement_publisher)

    movement_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()