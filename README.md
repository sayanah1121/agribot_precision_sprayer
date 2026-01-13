# Agribot Precision shooter 
# Agribot: Precision Weed shooter (ROS 2 + Arduino)

An autonomous robotics project that uses Computer Vision on a Raspberry Pi 5 to detect weeds and an Arduino to actuate a precision shooter/laser.

## Hardware Architecture
- **Brain:** Raspberry Pi 5 (Ubuntu 24.04 / ROS 2 Jazzy)
- **Actuator Controller:** Arduino Uno
- **Sensor:** USB Webcam
- **Actuators:** DC Motors, Laser Module

## Directory Structure
- `agribot_precision_shooter/`: ROS 2 Python nodes
- `arduino_code/`: C++ Firmware for the microcontroller
- `launch/`: System startup scripts

## Installation

1. **Clone the repository:**
   ```bash
   mkdir -p ~/ros2_ws/src
   cd ~/ros2_ws/src
   git clone [https://github.com/sayanah1121/agribot_precision_shooter.git](https://github.com/sayanah1121/agribot_precision_shooter.git)
