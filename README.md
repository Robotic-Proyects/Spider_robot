# Spider Robot

Robotic spider project using ROS 2.

This repository contains the software required to run and control a robotic spider using **ROS 2 Humble** on a **Raspberry Pi 3 B+**.

---

## Hardware Requirements

* Raspberry Pi 3 B+
* microSD card (minimum 16 GB recommended)
* Stable power supply
* Fully assembled robotic spider
* PS4 controller with Bluetooth connection

---

## Operating System

The system is designed to run on **Ubuntu 22.04 LTS (64-bit)** for Raspberry Pi.

Installation can be done directly using **Raspberry Pi Imager**:

1. Open **Raspberry Pi Imager**
2. Select *Ubuntu 22.04 LTS (64-bit)*
3. Flash the image to the microSD card
4. Insert the microSD card into the Raspberry Pi and boot

---

## Installing ROS 2 Humble

### Update the system

```bash
sudo apt update && sudo apt upgrade -y
```

### Install basic dependencies

```bash
sudo apt install software-properties-common curl -y
sudo add-apt-repository universe
```

### Add the ROS 2 repository

```bash
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=arm64 signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu jammy main" | \
  sudo tee /etc/apt/sources.list.d/ros2.list
```

### Install ROS 2 Humble

```bash
sudo apt update
sudo apt install ros-humble-desktop -y
```

### Automatically source ROS at terminal startup

```bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

---

## Additional Tools

Install the required tools to build the workspace:

```bash
sudo apt install python3-colcon-common-extensions python3-rosdep -y
sudo rosdep init
rosdep update
```

---

## Project Workspace

The project uses a workspace named `ws_pi` with the following structure:

```text
ws_pi/
 ├── src/
 │    ├── spider_driver
 │    ├── spider_control
 │    └── ...
```

### Build the workspace

```bash
cd ~/ws_pi
rosdep install --from-paths src --ignore-src -r -y
colcon build
```

### Source the workspace environment

```bash
echo "source ~/ws_pi/install/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

---

## Manual System Startup

### Before starting

* The PS4 controller must be powered on and connected
* ROS 2 and the workspace must be sourced

```bash
source /opt/ros/humble/setup.bash
source ~/ws_pi/install/setup.bash
```

### Required execution order

1. Launch the joystick node:

```bash
ros2 run joy joy_node &
```

2. Launch the main driver in the background:

```bash
ros2 run spider_driver control_main initial_rad:=0.0 &
```

3. Launch the high-level controller:

```bash
ros2 run spider_driver control_hc_main &
```

4. Launch the motion publisher:

```bash
ros2 run spider_control movement_publisher_node.py
```

---

## Stopping the System

To stop foreground nodes:

```text
Ctrl + C
```

To stop background processes:

```bash
jobs
kill %<number>
```

---

## Notes

* Connect motors and sensors before startup
* Optimized for Raspberry Pi 3 B+
* The controller must be powered on before launching `joy_node`
