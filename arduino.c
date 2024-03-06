#include <Servo.h>

Servo tap_servo;
int sensor_pin = 4;
int tap_servo_pin = 5;
int val;
bool isServoOpened = false; // Tracks the state of the servo

void setup() {
  pinMode(sensor_pin, INPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(sensor_pin);
  Serial.println(val);

  if (val == 0) {
    if (!isServoOpened) { // Check if servo is not already in the open position
      tap_servo.write(0); // Assume 0 as the open position
      isServoOpened = true;
      delay(2000); // Wait for 2 seconds before closing
    }
  } else {
    if (isServoOpened) { // Check if servo is not already in the closed position
      tap_servo.write(180); // Assume 180 as the closed position
      isServoOpened = false;
    }
  }
}
