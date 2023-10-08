#include<Servo.h>
Servo servo;
byte recognizer;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.write(0xAA);
Serial.write(0x37);
delay(1500);
Serial.write(0xAA);
Serial.write(0x21);
servo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()){
  recognizer = Serial.read();
  switch(recognizer){
    case 0x11:
    servo.write(110);
    break;
    case 0x12:
    servo.write(30);
    break;

  }
}
}
