#include <Servo.h> //サーボモーター用Arduino標準ライブラリを読み込む
Servo myservo; //サーボモータ用のオブジェクトを作成
int val; //サーボの角度を格納
int state = 0; //pinから取得したデータ格納
int pin7 = 7;
int count = 0;

void setup()
{
Serial.begin(9600); //シリアルモニタを使う(カッコ内は通信速度)
myservo.attach(6); //デジタル6番ピンをサーボの角度命令出力ピンとして設定
pinMode(pin7, INPUT); //pin7を入力として使う
}
void loop()
{
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}
