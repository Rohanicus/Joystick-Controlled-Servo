Joystick-Controlled Servo with LED Indicators
An Arduino project that uses a joystick's vertical axis to control a positional servo. Three LEDs indicate which range the joystick reading falls into, and the raw reading appears in Serial Monitor.
Parts
- Arduino Uno or compatible board
- Two-axis analog joystick module
- Positional servo (such as an SG90)
- Three LEDs: red, green, and blue
- Three current-limiting resistors (typically 220–330 Ω)
- Breadboard and jumper wires
- A suitable external 5 V servo supply if the servo draws more current than the board can safely provide
Wiring
Component	Connection
Joystick VRy	Arduino A1
Joystick VCC / GND	5 V / GND
Servo signal	Arduino D8
Servo power / ground	Suitable 5 V supply / GND
Red LED anode	Arduino D2 through a current-limiting resistor
Green LED anode	Arduino D3 through a current-limiting resistor
Blue LED anode	Arduino D4 through a current-limiting resistor
All LED cathodes	GND


If the servo uses an external supply, connect its ground to Arduino GND as well. Do not power a high-current servo from an Arduino I/O pin. The sketch defines joystick X on A0 but does not currently read or use it, so connecting VRx is optional.
How it works
The sketch reads the joystick's Y axis (0–1023), maps that reading to a servo position (0–180 degrees), and sends the angle to the servo. It also turns on one LED according to the raw joystick reading:
Y reading	LED
Below 300	Red (ledCCW)
300–500	Blue (ledCenter)
Above 500	Green (ledCW)


The LEDs label ranges of the joystick input. This is a positional servo: the servo.write(angle) command sets its target angle. The code does not detect actual rotation direction or whether the servo is moving. In particular, a centered joystick often reads around 512, which puts it in the green range with the current thresholds.
Run it
1. Open the sketch in Arduino IDE and select your board and port.
2. Upload it to the Arduino.
3. Move the joystick up and down to change the servo position and LED indicator.
4. Open Serial Monitor at 9600 baud to see the raw Y reading.
Possible improvements
- Set the center thresholds around your joystick's actual resting value (for example, 450–570 if it rests near 512).
- Use both joystick axes for a second servo or another control.
- Display the mapped angle alongside the raw reading in Serial Monitor.
