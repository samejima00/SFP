#include <Servo.h>  //ライブラリ<Servo.h>を組み込む

Servo sv; //Servoオブジェクト“sv”を作成する
int DIN_PIN = 3;

void setup() {
 sv.attach(6); //svの出力をD6番ピンに割り当てる
 pinMode( DIN_PIN, INPUT_PULLUP );
    Serial.begin( 9600 );
}

void loop() {      
  sv.write( 10 ); //D6番ピンに“0度”を出力する
         delay( 2000 ); //そのままで1000ミリ秒待機する
         sv.write( 110 ); //D6番ピンに“90度”を出力する
         delay( 2000 ); //そのままで1000ミリ秒待機する
 /*        
 sv.write( 180 ); //D6番ピンに“180度”を出力する
 delay( 1000 ); //そのままで1000ミリ秒待機する
 sv.write( 90 ); //D6番ピンに“90度”を出力する
 delay( 1000 ); //そのままで1000ミリ秒待機する
 */
}
