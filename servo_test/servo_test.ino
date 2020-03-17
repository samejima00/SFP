#include <Servo.h>
Servo myServo; // create a servo object
 
int const potPin = 7; // analog pin used to connect the potentiometer
int potVal; // variable to read the value from the analog pin
int angle; // variable to hold the angle for the servo motor
int count
 
void setup() {
  pinMode(potPin, INPUT_PULLUP );
myServo.attach(9); // attaches the servo on pin 9 to the servo object
Serial.begin(9600); // open a serial connection to your computer
}
 
void loop() {
potVal = digitalRead(potPin); // read the value of the potentiometer
// print out the value to the serial monitor
Serial.print("potVal: ");
Serial.print(potVal);
if(potval){
   count++;
}
// scale the numbers from the pot
if (count%2 == 0){
  angle = map(potVal, 0, 1023, 0, 179);
}
 
// print out the angle for the servo motor
Serial.print(", angle: ");
Serial.println(angle);
 
// set the servo position
myServo.write(angle);
 
// wait for the servo to get there
delay(15);
}
