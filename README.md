
# Automatic Door Opener Using Servo and Sensor

This project demonstrates how to automatically open and close a door using a servo motor controlled by a sensor (e.g., motion sensor or proximity sensor). When the sensor detects an object, the door opens and automatically closes after a set delay. This setup is useful in automated systems like entrance doors, gates, or smart home applications.

## Table of Contents
- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Code Explanation](#code-explanation)
- [How to Use](#how-to-use)


## Introduction

The automatic door opener system uses a sensor to detect the presence of an object (such as a person approaching the door). When the sensor is triggered, the servo motor opens the door. The door remains open for 2 seconds before closing. This project is ideal for creating hands-free door systems.

## Hardware Requirements
- Arduino Uno or any other compatible microcontroller board
- Servo motor (SG90 or similar)
- Motion or proximity sensor (e.g., PIR sensor or ultrasonic sensor)
- Jumper wires
- Breadboard
- Power supply for servo (if needed)

## Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- Servo library (included with the Arduino IDE)

## Code Explanation

```cpp
#include <Servo.h>

Servo tap_servo;          // Create a Servo object to control the door
int sensor_pin = 4;       // Pin connected to the sensor
int tap_servo_pin = 5;    // Pin connected to the servo
int val;                  // Variable to store the sensor reading
bool isServoOpened = false; // Tracks whether the door is open or closed

void setup() {
  pinMode(sensor_pin, INPUT);   // Set sensor pin as input
  tap_servo.attach(tap_servo_pin); // Attach servo to pin 5
  Serial.begin(9600);           // Start serial communication for debugging
}

void loop() {
  val = digitalRead(sensor_pin);   // Read sensor input
  Serial.println(val);             // Print the sensor value to the Serial Monitor

  if (val == 0) {  // Sensor is activated (detecting an object)
    if (!isServoOpened) { // Open the door if it's not already open
      tap_servo.write(0);  // Open the door (0 degrees)
      isServoOpened = true;  // Mark the door as opened
      delay(2000);  // Wait for 2 seconds before allowing it to close
    }
  } else {  // No object detected by the sensor
    if (isServoOpened) { // Close the door if it's currently open
      tap_servo.write(180); // Close the door (180 degrees)
      isServoOpened = false; // Mark the door as closed
    }
  }
}
```

### How It Works:
- **Sensor Input**: The sensor pin reads a digital signal. If an object is detected (`val == 0`), the door (servo) opens.
- **Servo Control**: The `isServoOpened` boolean variable tracks the state of the door to prevent repeated open/close commands.
- **Timed Operation**: The door opens for 2 seconds before it is allowed to close once the sensor no longer detects an object.

## How to Use
1. **Assemble the Circuit**: Follow the circuit diagram to connect the sensor and servo motor to the Arduino.
2. **Upload the Code**: Use the Arduino IDE to upload the provided code to your board.
3. **Test the System**: Power the Arduino and place your hand (or any object) near the sensor. The door should automatically open and close after 2 seconds.

