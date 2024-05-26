const int JoystickX = A2;
const int JoystickY = A3;
const int JoystickSW = 12;
int x,y, but;
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
#include <Servo.h>


Servo NS;




void setup() {
NS.attach(9);

NS.write(80);

 Serial.begin(9600);


pinMode(JoystickX,INPUT);
pinMode(JoystickY,INPUT);
pinMode(JoystickSW,INPUT_PULLUP);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
}

void loop() {
  
 x = analogRead(JoystickX);
  y = analogRead(JoystickY);
  but = digitalRead(JoystickSW);

if(y < 450){
rotaceProtismeru();
} else if (y > 600){
 rotacePosmeru();
}
if(x < 450){
NS.write(120);
delay(400);
} else if (x > 600){
NS.write(60);
delay(400);
}



}
void rotaceProtismeru() {
  krok(0, 0, 0, 1);
  krok(0, 0, 1, 0);
  krok(0, 1, 0, 0);
  krok(1, 0, 0, 0);
}




void rotacePosmeru() {
  krok(1, 0, 0, 0);
  krok(0, 1, 0, 0);
  krok(0, 0, 1, 0);
  krok(0, 0, 0, 1);
}



void krok(int a,int b,int c,int d){
digitalWrite(IN1, a);
digitalWrite(IN2, b);
digitalWrite(IN3, c);
digitalWrite(IN4, d);
delay(3);
}
