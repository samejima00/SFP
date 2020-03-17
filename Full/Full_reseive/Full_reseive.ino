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
int s = 0;
int count = 0;
void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) { // データの受信を確認
    int check = int(Serial.read());
    Serial.println(check);
    if (check == 1) {
    s=s+1;
    Serial.println(s);
    delay(20);
    }
    if (check == 2) {
     s=0;
     count=0;
     delay(20);
    }
    while(digitalRead(2)==LOW) {}
  }
  if (s==1){
    bas.write(180,30);
  }
  if (s==2) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
  }
  if (s==3) {
    if (count==0){
      digitalWrite(12, LOW);
    delay(2500);
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    count = 1;
    }
    delay(100);
  }
  if (s==4){
    bas.write(90,30);
  }
  if (s==5){
    rot.write(90,30);
  }
}
