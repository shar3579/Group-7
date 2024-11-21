# Group-7
Embedded Systems Case Study
## Case Study: Guided Vision: An object Detection Guide for the Blind
### Overview
This case study documents the implementation and demonstration of an embedded system project that utilizes an ultrasonic sensor in conjunction with an STM32F401CCU6 microcontroller and a buzzer. The project showcases how the sensor detects obstacles and triggers an audible alert via the buzzer, making it suitable for applications such as obstacle detection or distance measurement systems.

### Objective
The primary objective of this project is to demonstrate the integration of an ultrasonic sensor with the STM32F401CCU6 microcontroller to:
    ▶ Measure the distance to an obstacle using the ultrasonic sensor.
    ▶ Trigger the buzzer when the measured distance falls below a predefined threshold.

### System Components
The system comprises the following components:
  ⫸ Ultrasonic Sensor (HC-SR04 or equivalent):
    ▶ Emits ultrasonic waves and measures the time taken for the echo to return.
    ▶ Outputs the calculated distance to the microcontroller.
  ⫸ STM32F401CCU6 Microcontroller:
    ▶ Acts as the central processing unit.
    ▶ Receives signals from the ultrasonic sensor, calculates the distance, and controls the buzzer.
  ⫸ Buzzer:
    ▶ Provides an audible alert when the detected object is too close.
  ⫸ Power Supply:
    ▶ Provides the required power to the microcontroller and peripherals.
