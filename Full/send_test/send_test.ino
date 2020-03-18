int LED = 13;
String sendstr = "arduino";

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Start writeing.");
}

void loop(){
  
  Serial.write("t");
  delay(500);
  Serial.write("b");
  delay(500);
}
