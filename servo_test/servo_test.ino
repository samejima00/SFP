#include <Servo.h>
Servo myServo; // create a servo object

void setup() {
myServo.attach(9); // attaches the servo on pin 9 to the servo object
Serial.begin(9600); // open a serial connection to your computer
}
 
void loop() {
myServo.write(0);
delay(1000);
myServo.write(90);
delay(1000);
}
