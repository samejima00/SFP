char buff[255];
int counter = 0;
int LED = 13;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Start reading.");
}

void loop(){
  while(Serial.available()){
    char inChar = char(Serial.read());
      Serial.println(inChar);}
}
