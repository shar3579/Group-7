# **Group-7**  
**19CSE305 Embedded Systems Case Study**

## **Case Study: Guided Vision: An Object Detection Guide for the Blind**

### **Overview**  
This case study documents the implementation and demonstration of an embedded system project that utilizes an **ultrasonic sensor** in conjunction with an **STM32F401CCU6 microcontroller** and a **buzzer**. The project showcases how the sensor detects obstacles and triggers an audible alert via the buzzer, making it suitable for applications such as obstacle detection or distance measurement systems.

---

### **Objective**  
The primary objective of this project is to demonstrate the integration of an ultrasonic sensor with the STM32F401CCU6 microcontroller to:  
- Measure the distance to an obstacle using the ultrasonic sensor.  
- Trigger the buzzer when the measured distance falls below a predefined threshold.

---

### **System Components**  
The system comprises the following components:  

1. **Ultrasonic Sensor (HC-SR04):**  
   - Emits ultrasonic waves and measures the time taken for the echo to return.  
   - Outputs the calculated distance to the microcontroller.  

2. **STM32F401CCU6 Microcontroller:**  
   - Acts as the central processing unit.  
   - Receives signals from the ultrasonic sensor, calculates the distance, and controls the buzzer.  

3. **Buzzer:**  
   - Provides an audible alert when the detected object is too close.  

4. **Power Supply:**  
   - Provides the required power to the microcontroller and peripherals.

---

### **Usage Instructions**  
1. **Hardware Setup:**
   - Connect the ultrasonic sensor’s `TRIG` and `ECHO` pins to the STM32F401CCU6 GPIO pins.
   - Connect the buzzer to the STM32F401CCU6 GPIO pin.
   - Ensure proper power supply to the components.

2. **Programming:**
   - Use Keilµ5 Vision to write and upload the code to the microcontroller using ST-Link.
   - Configure GPIO pins and timers for sensor and buzzer operations.

3. **Testing:**
   - Place obstacles at varying distances and verify the buzzer triggers appropriately when below the threshold.

---

### **Applications**  
This system can be used in:  
- **Obstacle Detection Systems:** Useful in robotics, automotive parking sensors, and security systems.  
- **Distance Measurement Tools:** Applicable in industrial or educational purposes.  
- **Assistive Devices:** Provides guidance for visually impaired individuals to detect nearby obstacles.

---

### **Contributors**  
- **Poornima A  - CB.EN.U4CSE22402**  
- **Sharmila M  - CB.EN.U4CSE22423**  
- **P Ramya Sri - CB.EN.U4CSE22429**  
- **B Hemanth   - CB.EN.U4CSE22464**

---
### **19CSE305 Embedded Systems**  
**Department of Computer Science and Engineering**  
**Amrita School of Computing**  
**Amrita Vishwa Vidyapeetham, Coimbatore, India**  
---

  

