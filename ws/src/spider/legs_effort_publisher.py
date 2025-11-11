import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32

class LegsEffortPublisher(Node):
    def __init__(self):
        super().__init__('legs_effort_publisher')

        # Suscripción a joint_states
        self.sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_states_callback,
            10
        )

        # Definición de los joints por pata
        self.legs_joints = {
            'leg1': ['hip_backright', 'leg_backright', 'foot_backright'],
            'leg2': ['hip_backleft', 'leg_backleft', 'foot_backleft'],
            'leg3': ['hip_frontleft', 'leg_frontleft', 'foot_frontleft'],
            'leg4': ['hip_frontright', 'leg_frontright', 'foot_frontright'],
        }

        # Crear publicadores individuales para cada joint
        self.pubs = {}
        for leg, joints in self.legs_joints.items():
            self.pubs[leg] = {}
            for joint in joints:
                # Crear un topic con el nombre de la pata y el miembro
                joint_name = joint.split('_')[0]  # hip, leg o foot
                topic_name = f"/{leg}/{joint_name}_effort"
                self.pubs[leg][joint_name] = self.create_publisher(Float32, topic_name, 10)

    def joint_states_callback(self, msg):
        efforts = dict(zip(msg.name, msg.effort))

        for leg, joints in self.legs_joints.items():
            for joint in joints:
                try:
                    joint_name = joint.split('_')[0]  # hip, leg o foot
                    torque = abs(efforts[joint])
                    msg_out = Float32()
                    msg_out.data = torque
                    self.pubs[leg][joint_name].publish(msg_out)
                    self.get_logger().info(f"{leg} {joint_name} torque: {torque:.3f}")
                except KeyError:
                    # Si el joint no está aún en joint_states
                    continue

def main(args=None):
    rclpy.init(args=args)
    node = LegsEffortPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
