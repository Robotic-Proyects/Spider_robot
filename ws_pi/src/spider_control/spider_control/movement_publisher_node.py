import rclpy
import time
import math
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from enum import Enum, auto

from spider_control.KI import get_configurations, get_initial_pose, KI
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

        self.msg = auto()


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

        msg = SpiderLeg()
        pose = self.correct_rad(pose)
        msg.hip = pose[0]
        msg.leg = pose[1]
        msg.foot = pose[2]
        msg.smooth_value = 0.07
        print("hip: ", msg.hip, "leg: ", msg.leg, "foot: ", msg.foot)
        #publisher.publish(msg)
        #self.get_logger().info('Publishing: "%f %f %f"' ,msg.hip, msg.leg, msg.foot)
    
    def move(self, x, y, z, publisher):

        """
            Move a leg to the coordinate
        """

        pose = KI(x, y, z)
        #print("move: ", x,y,z)

        pose = self.correct_rad(pose)

        pose[1] = -pose[1]
        pose[2] = -pose[2]
        if (pose[2] > 1):
            pose[2] = 1.0
        elif (pose[2] < -1):
            pose[2] = -1.0

        pose[0] += math.radians(-53)
        pose[1] += math.radians(90)
        pose[2] += math.radians(120)

        #print("Pose: ", pose)
        self.publish(pose, publisher)


    def moveLift(self, publisher, delta_x, delta_y, 
                 offset_x, offset_y , lift_z):

        """
            Divide the leg's movement in three: elevate, move to the point and low down.
        """

        self.coordinate['x'] += offset_x
        self.coordinate['y'] += offset_y
        self.coordinate['z'] += lift_z

        self.move(self.coordinate['x'], self.coordinate['y'], self.coordinate['z'], 
                  publisher)

        time.sleep(0.1)

        self.coordinate['x'] += delta_x - offset_x
        self.coordinate['y'] += delta_y - offset_y

        self.move(self.coordinate['x'], self.coordinate['y'], self.coordinate['z'], 
                  publisher)

        time.sleep(0.1) 

        self.coordinate['z'] -= lift_z

        self.move(self.coordinate['x'], self.coordinate['y'], self.coordinate['z'], 
                  publisher)


    def moveBase(self, x_, y_, z_):

        self.move(self.coordinate_front_left['x'] - x_ + self.coordinate['x'], 
                  self.coordinate_front_left['y'] - y_ + self.coordinate['y'], 
                  self.coordinate_front_left['z'] - z_ + self.coordinate['z'], 
                  self.publisher_front_left_)
        self.move(self.coordinate_front_right['x'] - x_ + self.coordinate['x'], 
                  self.coordinate_front_right['y'] - y_ + self.coordinate['y'], 
                  self.coordinate_front_right['z'] - z_ + self.coordinate['z'], 
                  self.publisher_front_right_)
        self.move(self.coordinate_back_left['x'] - x_ + self.coordinate['x'], 
                  self.coordinate_back_left['y'] - y_ + self.coordinate['y'], 
                  self.coordinate_back_left['z'] - z_ + self.coordinate['z'], 
                  self.publisher_back_left_)
        self.move(self.coordinate_back_right['x'] - x_ + self.coordinate['x'], 
                  self.coordinate_back_right['y'] - y_ + self.coordinate['y'], 
                  self.coordinate_back_right['z'] - z_ + self.coordinate['z'], 
                  self.publisher_back_right_)

        print(x_, y_, z_)
        self.set_coordinate(x_, y_, z_)

    def tiltBase(self, alpha, beta, gamma):

        deltax = - (HALFWIDTH - HALFWIDTH * math.cos(alpha)) + (HALFWIDTH - HALFWIDTH * math.cos(self.angles['alpha']))
        deltay = - (HALFWIDTH - HALFWIDTH * math.cos(beta)) + (HALFWIDTH - HALFWIDTH * math.cos(self.angles['beta']))

        if gamma <= 0:
            deltaxy2_gamma = - HALFWIDTH * (1 - math.sin(gamma)) * math.sin(gamma)
            deltaxy1_gamma = - HALFWIDTH * (1 - (1 - math.sin(gamma)) * math.cos(gamma) + math.sin(gamma))
            deltaxy2_gamma *= -1
            deltaxy1_gamma *= -1
        else:
            deltaxy1_gamma = + HALFWIDTH * (1 + math.sin(gamma)) * math.sin(gamma)
            deltaxy2_gamma = - HALFWIDTH * (1 - (1 + math.sin(gamma)) * math.cos(gamma) - math.sin(gamma))


        if self.angles['gamma'] <= 0:
            deltaxy2_gamma += -HALFWIDTH * (1 - math.sin(self.angles['gamma'])) * math.sin(self.angles['gamma'])
            deltaxy1_gamma += -HALFWIDTH * (1 - (1 - math.sin(self.angles['gamma'])) * math.cos(self.angles['gamma']) + math.sin(self.angles['gamma']))
        else:
            deltaxy1_gamma += -HALFWIDTH * (1 + math.sin(self.angles['gamma'])) * math.sin(self.angles['gamma'])
            deltaxy2_gamma += HALFWIDTH * (1 - (1 + math.sin(self.angles['gamma'])) * math.cos(self.angles['gamma']) - math.sin(self.angles['gamma']))

        deltaz_alpha = - HALFWIDTH * math.sin(alpha) + HALFWIDTH * math.sin(self.angles['alpha'])
        deltaz_beta = - HALFWIDTH * math.sin(beta) + HALFWIDTH * math.sin(self.angles['beta'])


        self.move(self.coordinate_front_left['x'] + deltax - deltaxy1_gamma,
                    self.coordinate_front_left['y'] - deltay - deltaxy2_gamma,
                    self.coordinate_front_left['z'] - deltaz_alpha + deltaz_beta,
                    self.publisher_front_left_)

        self.move(self.coordinate_front_right['x'] - deltax - deltaxy2_gamma,
                    self.coordinate_front_right['y'] - deltay + deltaxy1_gamma,
                    self.coordinate_front_right['z'] + deltaz_alpha + deltaz_beta,
                    self.publisher_front_right_)

        self.move(self.coordinate_back_left['x'] - deltax + deltaxy1_gamma,
                    self.coordinate_back_left['y'] + deltay + deltaxy2_gamma,
                    self.coordinate_back_left['z'] + deltaz_alpha - deltaz_beta,
                    self.publisher_back_left_)

        self.move(self.coordinate_back_right['x'] + deltax + deltaxy2_gamma,
                    self.coordinate_back_right['y'] + deltay - deltaxy1_gamma,
                    self.coordinate_back_right['z'] - deltaz_alpha - deltaz_beta,
                    self.publisher_back_right_)

        print(alpha, beta, gamma)
        self.set_angles(alpha, beta, gamma)

    def forwardMove(self, step_length, z_base):

        base_movement = step_length / 3

        lift_z = 5
        offset = 3

        self.moveBase(1.45, base_movement, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_back_right_, 0, step_length, 0 , 0 , lift_z)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_left_, 0, step_length, -offset, offset, lift_z)
        time.sleep(0.1)
        self.moveBase(-1.45, 2 * base_movement, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_back_left_, 0, step_length, 0 , 0, lift_z)
        time.sleep(0.1)
        self.tiltBase(5, 5, 0)
        self.moveLift(self.publisher_front_right_, 0, step_length, offset + 2 , offset + 2 , 4)
        time.sleep(0.1)

        self.tiltBase(0, 0, 0)
        self.moveBase(0, 3 * base_movement, z_base)

        self.set_coordinate(0,0,0)
        self.set_angles(0,0,0)

    def backwardMove(self, step_length, z_base):

        step_length *= -1
        base_movement = step_length / 3

        lift_z = 3
        offset = 3

        self.moveBase(1.45, base_movement, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_left_, 0, step_length, 0 , 0 , lift_z)
        time.sleep(0.1)
        self.moveLift(self.publisher_back_right_, 0, step_length, -offset, -offset, lift_z)
        time.sleep(0.1)
        self.moveBase(-1.45, 2 * base_movement, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_right_, 0, step_length, 0 , 0, lift_z)
        time.sleep(0.1)
        self.tiltBase(5, -5, 0)
        self.moveLift(self.publisher_back_left_, 0, step_length, offset + 2 , -offset - 2 , 4)
        time.sleep(0.1)
        self.tiltBase(0, 0, 0)
        self.moveBase(0, 3 * base_movement, z_base)

        self.set_coordinate(0,0,0)
        self.set_angles(0,0,0)

    def rightMove(self, step_length, z_base):
        
        base_movement = step_length / 3

        lift_z = 3
        offset = 3

        self.moveBase(base_movement, -1.45, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_left_, step_length, 0, 0 , 0 , lift_z)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_right_, step_length, 0, offset, offset, lift_z)
        time.sleep(0.1)
        self.moveBase( 2 * base_movement, +1.45, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_back_right_,step_length, 0, 0 , 0, lift_z)
        time.sleep(0.1)
        self.tiltBase(5, -5, 0)
        self.moveLift(self.publisher_back_left_, step_length, 0, offset + 2 , -offset - 2 , 4)
        time.sleep(0.1)
        self.tiltBase(0, 0, 0)
        self.moveBase(3 * base_movement, 0, z_base)

        self.set_coordinate(0,0,0)
        self.set_angles(0,0,0)

    def leftMove(self, step_length, z_base):

        step_length *= -1
        base_movement = step_length / 3

        lift_z = 3
        offset = 3
        
        self.moveBase(base_movement, -1.45, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_right_, step_length, 0, 0 , 0 , lift_z)
        time.sleep(0.1)
        self.moveLift(self.publisher_front_left_, step_length, 0, -offset, offset, lift_z)
        time.sleep(0.1)

        self.moveBase( 2 * base_movement, +1.45, z_base)
        time.sleep(0.1)
        self.moveLift(self.publisher_back_left_, step_length, 0, 0 , 0, lift_z)
        time.sleep(0.1)
        self.tiltBase(-5, -5, 0)
        self.moveLift(self.publisher_back_right_, step_length, 0, -offset - 2 , -offset - 2 , 4)
        time.sleep(0.1)

        self.tiltBase(0, 0, 0)
        self.moveBase(3 * base_movement, 0, z_base)

        self.set_coordinate(0,0,0)
        self.set_angles(0,0,0)

    def turn(self, gamma_, z_base):

        lift_z = 2
        offset = 3

        self.tiltBase(0, 0, gamma_)

        self.move(self.coordinate_front_left['x'], self.coordinate_front_left['y'], self.coordinate_front_left['z'] + lift_z , self.publisher_front_left_)
        self.move(self.coordinate_back_left['x'], self.coordinate_back_left['y'], self.coordinate_back_left['z'] + lift_z , self.publisher_back_left_)
        time.sleep(0.075)
        self.move(-6, 6, self.coordinate_front_left['z'], self.publisher_front_left_)
        self.move(6, -6, self.coordinate_back_left['z'], self.publisher_back_left_)
        time.sleep(0.075)
        self.move(-6, 6, self.coordinate_front_left['z'] - lift_z , self.publisher_front_left_)
        self.move(6, -6, self.coordinate_back_left['z'] - lift_z , self.publisher_back_left_)

        time.sleep(0.2)

        self.move(self.coordinate_front_right['x'], self.coordinate_front_right['y'], self.coordinate_front_right['z'] + lift_z , self.publisher_front_right_)
        self.move(self.coordinate_back_right['x'],self.coordinate_back_right['y'], self.coordinate_back_right['z'] + lift_z , self.publisher_back_right_)
        time.sleep(0.075)
        self.move(6, 6, self.coordinate_front_right['z'] , self.publisher_front_right_)
        self.move(-6, -6, self.coordinate_back_right['z'] , self.publisher_back_right_)
        time.sleep(0.075)
        self.move(6, 6, self.coordinate_front_right['z'] - lift_z , self.publisher_front_right_)
        self.move(-6, -6, self.coordinate_back_right['z'] - lift_z , self.publisher_back_right_)

        self.set_coordinate(0,0,0)
        self.set_angles(0,0,0)
    

    def listener_callback(self, msg):
        self.state = State.JOY
        self.msg = msg

    def expo_axis(self, x, expo=0.4):
        return math.copysign(abs(x) ** (1 + expo), x)

    def timer_callback(self):
        global state_legs

        pose = self.poses[self.indice]
        publisher = self.publisher_list[self.indice]

        if self.state == State.JOY:

            if self.msg.buttons[8]: # SHARE button
                msg_ = SpiderSwitch()
                msg_.oe_value = 0
                self.publisher_oe_.publish(msg_)
            
            if self.msg.buttons[9]: # OPTIONS button
                msg_ = SpiderSwitch()
                msg_.oe_value = 1
                self.publisher_oe_.publish(msg_)

            if self.msg.buttons[2]: # TRIANGLE button

                self.moveBase(0,0,0)
            
            if self.msg.buttons[4] and not self.msg.buttons[5]:

                alpha = self.msg.axes[0] * 0.349 # -20º -> 20º
                beta = self.msg.axes[1] * 0.349 # -20º -> 20º
                gamma = self.msg.axes[4] * 0.218 - 0.218 # -25º -> 25º

                if self.msg.buttons[0]: #buttom A
                    #print("MOVIENDO LA BASE")
                    x = x_ 
                    y = y_
                    z = z_

                    # Limites
                    x = max(min(x, 5), -5)
                    y = max(min(y, 5), -5)
                    z = max(min(z, 7), -1)

                    alpha_ = max(min(alpha, 0.349), -0.349)
                    beta_  = max(min(beta, 0.349), -0.349)
                    gamma_ = max(min(gamma, 0.218), -0.218)

                    self.moveBase(x, y, z)
                    self.tiltBase(alpha_, beta_, gamma_)

            if self.msg.buttons[5] and not self.msg.buttons[4]:

                x_ = self.expo_axis(self.msg.axes[0]) * 5 # -5 -> 5
                y_ = self.expo_axis(self.msg.axes[1]) * -5 # -5 -> 5
                z_ = self.expo_axis(self.msg.axes[4]) * 5 #* 9 - 1  
            
                print("Joy: ", x_, y_, z_)

                if self.msg.buttons[1]: # buttom B

                    """
                                    ^ front_left 7 = 1
                    front_right < - | - >  back_right 6 = -1
                                    back_left 7 = -1
                    """

                    x = x_ 
                    y = y_
                    z = z_
                    print("Z DE PATA: ", z)
                    if self.msg.axes[6] != 0 or self.msg.axes[7] != 0:
                        if self.msg.axes[7] != 0:
                            if self.msg.axes[7] == 1: # move front_left 
                                #print("MOVIENDO PATA FRONT LEFT")
                                state_legs = 1
                            else:                # move back_left
                                #print("MOVIENDO PATA BACK LEFT")
                                state_legs = 3
                        else:
                            if self.msg.axes[6] != 0:
                                if self.msg.axes[6] == 1: # move front_right
                                    state_legs = 2
                                    #print("MOVIENDO PATA FRONT RIGHT")
                                else:                # move back_right
                                    #print("MOVIENDO PATA BACK RIGHT")
                                    state_legs = 4

                    if state_legs == 1:
                        self.move(x, y, z, self.publisher_front_left_)
                    elif state_legs == 2:
                        self.move(x, y, z, self.publisher_front_right_)
                    elif state_legs == 3:
                        self.move(x, y, z, self.publisher_back_left_)
                    else:
                        self.move(x, y, z, self.publisher_back_right_)
                else:
                    #print("MOVIENDO LA ARAÑA")
                    x = x_
                    y = y_
                    z = z_

                    threshold = 0.3  # sensibilidad mínima para caminar
                    step_length = 5

                    if y > threshold:
                        #print("Move backward")
                        self.backwardMove(step_length, z)
                    elif y < -threshold:
                        #print("move forward")
                        self.forwardMove(step_length, z)
                    elif x > threshold:
                        #print("move left")
                        self.leftMove(step_length, z)
                    elif x < -threshold:
                        #print("move right")
                        self.rightMove(step_length, z)


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