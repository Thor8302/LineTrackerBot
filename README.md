# Arduino Line Follower Robot

## Overview

This project demonstrates an Arduino-based line follower robot using L293D motor drivers and infrared (IR) sensors. The robot can autonomously follow a line by detecting the color contrast between the line and the surface using two IR sensors. When the sensors detect white or black, the robot adjusts its motors accordingly to follow the line.

## Video Demonstration

Watch the robot in action! Below is a video demonstrating the line follower robot navigating a path.

## Project Details

- **Motor Driver:** L293D
- **Sensors:** IR sensors (for line detection)
- **Microcontroller:** Arduino (compatible with any model)
- **Motors:** Two DC motors (left and right) to drive the wheels
- **Speed Control:** Using PWM (Pulse Width Modulation) for motor speed adjustments

### Components Used:
- 2 x DC motors
- 1 x L293D motor driver
- 2 x IR sensors (for line detection)
- 1 x Arduino board (any model)
- Jumper wires
- Chassis for the robot
- Wheels and castor

## Code

The robot follows the line using the logic below:

- **Forward Movement:** When both sensors detect the line.
- **Turn Right:** When the right sensor is off the line.
- **Turn Left:** When the left sensor is off the line.
- **Stop:** When both sensors are off the line.

## Usage Instructions

1. **Wiring:** Connect the motors to the L293D motor driver, and connect the IR sensors to the analog pins A0 and A1 on the Arduino.
2. **Upload Code:** Upload the Arduino sketch provided in this repository to your Arduino board.
3. **Power Up:** Power the Arduino, and the robot will begin following the line on the ground.
4. **Adjustments:** You can tweak the motor speeds and sensor thresholds in the code to improve performance on different surfaces.

## Future Improvements

- Implement PID (Proportional-Integral-Derivative) control to enhance line-following accuracy.
- Add more sensors to allow for complex line paths or intersections.
- Introduce wireless control for manual overrides.

## Contributions

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have suggestions or improvements.