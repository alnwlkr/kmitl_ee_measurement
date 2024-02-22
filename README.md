
# Distance Measurement with Arduino

## Project Description
This project is applying knowledge from INSTRUMENT AND MEASUREMENT subject at KMITL with Arduino Microcontroller together by using knowledge about how to measure distance using electronics device.

## How to run this project

### List of electronics device you need
First of all, you need a electronics component listed here.
- Arduino UNO R3
- 20x4 LCD with backlight of the LCD screen with I2C Interface
- HC-SR04 Ultrasonic Sensor
Additional component to run the project with full function.
- 9V Battery Supply
- Voltage Sensor Module (DC)
- Buzzer Module MH-FMD (Active Type)
- KY-016 RGB LED Module

### Connect each component together

As 
|     LCD 20x4   I2C    |     Arduino   UNO R3    |
|-----------------------|-------------------------|
|     GND               |     GND                 |
|     VCC               |     5V                  |
|     SDA               |     A4                  |
|     SCL               |     A5                  |


|     HC-SR04    |     Arduino   UNO R3    |
|----------------|-------------------------|
|     GND        |     GND                 |
|     ECHO       |     7                   |
|     TRIG       |     6                   |
|     VCC        |     5V                  |

|     Voltage   Meter Sensor    |     Arduino   UNO R3    |     9V  Battery  |
|-------------------------------|-------------------------|------------------|
|     S                         |     A0                  |                  |
|     -                         |     GND                 |                  |
|     VCC                       |                         |     +            |
|     GND                       |                         |     -            |

|     Buzzer   Module    |     Arduino   UNO R3    |
|------------------------|-------------------------|
|     GND                |     GND                 |
|     I/O                |     2                   |
|     VCC                |     5V                  |

## Installation

After connect all component together as above. You can simply plug in Arduino UNO R3 to your computer and upload 
```Milo_Dist.ino``` to your UNO R3 using Arduino IDE.
    
## Features

- Animated text on LCD when starting up.
- Distance Measurement up to 4 m.
- Custom Beeping Sound when Distance Value Is less than 5 cm or more than 100 cm.
- Light Indicator if distance is too far or too close from the sensor.
- Battery Measurement (Implement for 9V Battery Supply and cut off at 6V)
