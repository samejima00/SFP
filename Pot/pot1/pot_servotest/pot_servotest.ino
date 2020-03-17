#include <VarSpeedServo.h>  //ライブラリ<Servo.h>を組み込む

VarSpeedServo rot; //Servoオブジェクト“sv”を作成する
VarSpeedServo bas;

void setup() {
  // put your setup code here, to run once:
  rot.attach(7);
  bas.attach(8);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  Serial.begin(9600);
  rot.write(0);
  bas.write(0);
}
void loop() {
  // put your main code here, to run repeatedly:
  bas.write(90,30);
  delay(1000);
  bas.write(180,30);
  delay(1000);
  bas.write(90,30);
  delay(500);
  rot.write(90,30);
  delay(1000);
  bas.write(0,30);
  delay(1000);
}
