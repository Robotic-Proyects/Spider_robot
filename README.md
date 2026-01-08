# Spider Robot

Simulation and control project for a *spider-type* robot using **ROS 2 Jazzy** and **Gazebo Sim**.

---

## Requirements

* Ubuntu compatible with ROS 2 Jazzy
* ROS 2 Jazzy installed and configured
* Gazebo Sim
* `colcon`
* Git

---

## Installation

1. Move to `src` of your workspace

2. Clone the repository (branch `jazzy`):

```bash
git clone -b jazzy https://github.com/usuario/repo.git](https://github.com/Robotic-Proyects/Spider_robot.git
```

3. Source the ROS 2 Jazzy environment:

```bash
source /opt/ros/jazzy/setup.bash
```

4. Build the workspace:

```bash
cd ws
colcon build --symlink-install
```

5. Source the built workspace:

```bash
source install/setup.bash
```

---

## Running the Simulator

### World with walls (room)

Launch Gazebo Sim with a custom world that includes walls:

```bash
ros2 launch spider gazebo.launch.py gui:=False use_custom_world:=true world_name:=room
```

### Empty world

Launch Gazebo Sim with an empty world:

```bash
ros2 launch spider gazebo.launch.py gui:=False
```

### With graphical interface

Launch Gazebo Sim with the graphical user interface enabled:

```bash
ros2 launch spider gazebo.launch.py gui:=True
```

---

## Robot Control

> **Note:** Each command must be executed in a separate terminal, with the workspace properly sourced.

### 1. Keyboard reader node

Allows controlling the robot using the keyboard:

```bash
source install/setup.bash
ros2 run keyboard_reader key_reader
```

### 2. Motion controller node

Publishes motion commands to the robot:

```bash
source install/setup.bash
ros2 run spider_control movement_publisher
```

---

## Additional Notes

* Make sure to run `source install/setup.bash` in **every new terminal**.
* The simulator must be running before launching the control nodes.
