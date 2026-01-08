import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from pynput import keyboard


class KeyReader(Node):
    def __init__(self):
        super().__init__('key_reader')
        self.pub = self.create_publisher(String, 'key_pressed', 10)

        self.get_logger().info('Keyboard listener iniciado. Presiona ESC para salir.')

        # Listener de pynput
        self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.listener.start()

    def on_press(self, key):
        try:
            msg = String()
            msg.data = f"{key.char}"
            self.pub.publish(msg)
            self.get_logger().info(f"Tecla: {msg.data}")
        except AttributeError:
            # Flechas y teclas especiales
            msg = String()
            msg.data = f"{key}"
            self.pub.publish(msg)
            self.get_logger().info(f"Tecla especial: {msg.data}")

        # Salir con ESC
        if key == keyboard.Key.esc:
            self.get_logger().info("Cerrando nodo (ESC presionado)")
            rclpy.shutdown()

    def on_release(self, key):
        pass


def main(args=None):
        rclpy.init(args=args)
        node = KeyReader()
        rclpy.spin(node)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
