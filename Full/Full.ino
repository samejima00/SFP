/*
  simpleMovements.ino

 This  sketch simpleMovements shows how they move each servo motor of Braccio

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;
Servo sv; //Servoオブジェクト“sv”を作成する

void setup() {
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
   sv.attach(2);
  Braccio.begin();
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
  int s=0;
  int n=13;
for(;;) {
  if(digitalRead(4)==LOW) {
    s=s+1;
    delay(20);
    Serial.write(s);
    if(s>n){
     s=0;
    delay(20);
    }
    while(digitalRead(4)==LOW) {}
  }
  /*
  if(s==0){
    digitalWrite(8,LOW);
    //(step delay, M1, M2, M3, M4, M5, M6);
    sv.write(10);
    Braccio.ServoMovement(30,           100,  15, 79, 98, 0,  73);  //初期配置。茶碗に茶筅を持たれかけさせる
  //delay(5000);
  }
 
  if(s==0){
   Braccio.ServoMovement(30,           100,  15, 150, 98 , 0,  73); //茶碗から持ち上げる
  sv.write(180);
  //delay(5000); 
  }
  */
  if(s==0){
    sv.write(180);
    Braccio.ServoMovement(30,           130,  15, 72, 5, 0,  73);  //配置時。茶筅が上を向く
  //delay(10000);
  }
  else if(s==7){
    Braccio.ServoMovement(30,           130,  54, 150, 26 , 0,  73); //茶碗から持ち上げる
  sv.write(30);
  //delay(1000);
  }
  else if(s==8){
    Braccio.ServoMovement(30,           95,  54, 150, 26 , 0,  73); //茶碗から持ち上げる
  sv.write(30);
  //delay(1000);
  }
  else if(s==9){
    Braccio.ServoMovement(30,           95,  32, 90, 15, 0,  73);
    sv.write(20);
  //delay(1000);
  }
  else if(s==10){
    digitalWrite(7, LOW);
    analogWrite(8, 153);
  }
  else if(s==11){
    Braccio.ServoMovement(0,           90,  32, 90, 15, 0,  73);
    Braccio.ServoMovement(0,           100,  32, 90, 15, 0,  73);
  }
  if(s==12){
    Braccio.ServoMovement(30,           95,  54, 150, 26 , 0,  73);
  }
 
  //Wait 1 second
  }
}
