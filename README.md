# Spider_robot
Proyecto de araña robótica con ROS 2

Este repositorio contiene el software necesario para ejecutar y controlar una araña robótica utilizando ROS 2 Humble sobre una Raspberry Pi 3 B+.

Requisitos de hardware
- Raspberry Pi 3 B+
- Tarjeta microSD (mínimo 16 GB recomendado)
- Fuente de alimentación estable
- Araña robótica completamente ensamblada
- Mando PS4 con conexión Bluetooth

Sistema operativo

El sistema está diseñado para funcionar con Ubuntu 22.04 LTS (64-bit) para Raspberry Pi.

La instalación puede realizarse directamente desde Raspberry Pi Imager:
1. Abrir Raspberry Pi Imager
2. Seleccionar Ubuntu 22.04 LTS (64-bit)
3. Grabar la imagen en la microSD
4. Insertar la microSD en la Raspberry Pi y arrancar

Instalación de ROS 2 Humble

Actualizar el sistema:
sudo apt update && sudo apt upgrade -y

Instalar dependencias básicas:
sudo apt install software-properties-common curl -y
sudo add-apt-repository universe

Añadir el repositorio de ROS 2:
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=arm64 signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu jammy main" | sudo tee /etc/apt/sources.list.d/ros2.list

Instalar ROS 2 Humble:
sudo apt update
sudo apt install ros-humble-desktop -y

Cargar ROS automáticamente al iniciar la terminal:
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc

Herramientas adicionales

Instalar herramientas necesarias para compilar el workspace:
sudo apt install python3-colcon-common-extensions python3-rosdep -y
sudo rosdep init
rosdep update

Workspace del proyecto

El proyecto utiliza un workspace llamado ws_pi con la siguiente estructura:
ws_pi/
 ├── src/
 │    ├── spider_driver
 │    ├── spider_control
 │    └── ...

Compilación del workspace:
cd ~/ws_pi
rosdep install --from-paths src --ignore-src -r -y
colcon build

Añadir el workspace al entorno:
echo "source ~/ws_pi/install/setup.bash" >> ~/.bashrc
source ~/.bashrc

Arranque manual del sistema

Antes de comenzar:
- El mando PS4 debe estar encendido y conectado
- ROS 2 y el workspace deben estar cargados

source /opt/ros/humble/setup.bash
source ~/ws_pi/install/setup.bash

Orden de ejecución obligatorio:

1. Lanzar el nodo del joystick:
ros2 run joy joy_node

2. Lanzar el driver principal en segundo plano:
ros2 run spider_driver control_main initial_rad:=0.0 &

3. Lanzar el control de alto nivel:
ros2 run spider_driver control_hc_main

4. Lanzar el publicador de movimiento:
ros2 run spider_control movement_publisher_node.py

Detención del sistema

Para detener nodos en primer plano:
Ctrl + C

Para detener procesos en segundo plano:
jobs
kill %<número>

Notas
- Conectar motores y sensores antes del arranque
- Optimizado para Raspberry Pi 3 B+
- El mando debe estar encendido antes de lanzar joy_node

Autor
Proyecto de araña robótica con ROS 2 Humble
