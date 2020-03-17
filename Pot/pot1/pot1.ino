void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
}
int s = 0;
void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(2)==LOW) {
    s=s+1;
    if(s>2)
     s=0;
    delay(20);
    while(digitalRead(2)==LOW) {}
  }
  if (s==1) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
  }
  if (s==2) {
    digitalWrite(12, LOW);
    delay(2500);
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    s = 0;
  }
}
