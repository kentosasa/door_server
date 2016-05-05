// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 


#include <Servo.h> 
Servo servo;
int sensor = 0;
int past = 0;
int rapid = 0;
int count = 0;
int kick = 0;
boolean flag = true;


void setup() 
{ 
  Serial.begin(9600);
  servo.attach(13);  //D9ピンをサーボの信号線として設定
} 

void loop() 
{ 
  past = sensor;
  sensor = analogRead(A0);
  rapid = sensor - past;
  if (count%100 == 0){
  Serial.println(sensor);
  String str = "kick "+ String(kick)+" count "+ String(count);
  Serial.println(str);
  }
  delay(10);
  if(sensor < 500 && flag) {
    count = 1;
    kick++;
    flag = false;
    Serial.println("flag1");
  } else if(sensor > 600) {
    flag = true;
    count++;
    Serial.println("flag2");
  }
  
  if(kick == 3) {
    kick = 0;
    openDoor();
    flag = true;
  } else if (count%50 == 0){
    kick = 0;
    flag = true;
  }
}

void openDoor(){
  Serial.println("open door");
  servo.write(90);
  delay(3000);
  servo.write(0);
  delay(3000);
  Serial.println("open door end");
}
