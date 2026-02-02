#include <Servo.h>

const int x = A0;
const int y = A1;

const int servoPin = 8;

const int ledCCW = 2;   // Red
const int ledCW  = 3;   // Green
const int ledCenter = 4; // Optional (blue)

Servo servo;

// Deadzone around joystick center
const int deadLow  = 300;
const int deadHigh = 500;

void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);

  pinMode(ledCCW, OUTPUT);
  pinMode(ledCW, OUTPUT);
  pinMode(ledCenter, OUTPUT);

  servo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
  int yval = analogRead(y);

  // Map joystick Y to servo angle
  int angle = map(yval, 0, 1023, 0, 180);
  servo.write(angle);

  // Direction indication
  if (yval < deadLow) {
    // CCW
    digitalWrite(ledCCW, HIGH);
    digitalWrite(ledCW, LOW);
    digitalWrite(ledCenter, LOW);
  }
  else if (yval > deadHigh) {
    // CW
    digitalWrite(ledCW, HIGH);
    digitalWrite(ledCCW, LOW);
    digitalWrite(ledCenter, LOW);
  }
  else {
    // Center / stopped
    digitalWrite(ledCenter, HIGH);
    digitalWrite(ledCCW, LOW);
    digitalWrite(ledCW, LOW);
  }

  Serial.println(yval);
  delay(10);
}
