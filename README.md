# Spider Robot

This repository contains the complete design, documentation, simulation results, and software of a spider-type robotic platform developed using **ROS 2**.

The project covers the full development lifecycle of a robotic system, including mechanical design, actuator selection through simulation, control architecture, and deployment on embedded hardware.

---

## Project Overview

The Spider Robot is a multi-legged robotic platform designed for research, education, and experimental purposes.

The project integrates:

- Fully 3D-printable mechanical design
- Simulation-based actuator selection
- ROS 2–based modular control architecture
- Embedded execution on a Raspberry Pi
- Teleoperation using a PS4 controller

The repository is structured to ensure **full reproducibility**, from mechanical fabrication to software execution.

---

## Mechanical Design & 3D Printing

The stl/ directory contains all mechanical components required to manufacture the robotic spider.

- All parts are provided in STL format
- Designed for FDM 3D printers
- Modular structure for simplified assembly and maintenance
- Optimized for lightweight construction and structural robustness

Detailed information regarding materials, printing parameters, tolerances, and assembly procedures can be found in the technical report.

---

 ## Documentation

All project documentation is located in the docs/ directory.

### Technical Report

- The technical report provides a detailed description of:
- Mechanical and structural design
- Kinematic configuration
- Actuator selection methodology
- Simulation environment and results
- Control architecture
- Software design decisions

### User Manual

- The user manual includes:
- System startup and shutdown procedures
- Teleoperation instructions
- Basic operation guidelines
- Safety considerations

### Maintenance Manual

- The maintenance manual describes:
- Preventive maintenance procedures
- Calibration processes
- Component replacement
-Long-term reliability guidelines
-Together, these documents allow full understanding, operation, and maintenance of the robotic system.

## Simulation & Motor Selection

The images/ directory contains figures and plots obtained from the simulation environment, including:

- Joint torque requirements
- Speed and load profiles
- Gait performance analysis
- Comparison of candidate actuators

These results were used to:

- Validate the mechanical design
- Select appropriate motors
- Ensure safe operating margins
- All simulations were performed prior to hardware implementation to reduce development risk and cost

## Software Architecture

The software stack is based on ROS 2 and is divided into two main environments.

### Simulation Environment

- Located in the simulation/ directory:

- Gazebo-based robot simulation

- Used for validation, testing, and design decisions

- Includes custom worlds, robot models, and control nodes

### Embedded Execution

Located in the ws_pi/ directory:

- Targeted for Raspberry Pi 3 B+

- Interfaces with real hardware

- Supports joystick-based teleoperation

- Designed to run on ROS 2 Humble

Each workspace contains its own README with detailed build and execution instructions.

## Control Interface

The robot is operated using a PS4 controller connected via Bluetooth.

- Joystick input is handled using the ROS 2 joy package

- High-level control nodes translate user commands into motion references

- Designed for intuitive teleoperation and testing

## Target Platform

- Raspberry Pi 3 B+

- Ubuntu 22.04 LTS (64-bit)

- ROS 2 Humble / Jazzy

- Servo-based actuation

- Bluetooth PS4 controller

- The system is optimized for embedded execution under limited computational resources.

## Reproducibility

This repository is structured to allow the following workflow:

- 3D printing and mechanical assembly

- Review of design decisions through documentation

- Validation through simulation

- Deployment on real hardware

- No proprietary software or tools are required.

## Credits / Acknowledgements

The original 3D design of the robotic spider was created by a contributor on **[Thingiverse](https://www.thingiverse.com/thing:1677703)**.  

We have **modified and adapted** the design to suit our robotic platform and integrate it with our ROS 2 control system.  

Full credit for the original design goes to the creator, whose work inspired and enabled this project.
