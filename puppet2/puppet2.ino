#include <Servo.h>

Servo s1, s2, s3, s4;

int temp = 0;
String read1;
int a1,a2,a3;


void setup() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);

  Serial.begin(9600);
}

void loop() {
//  if (Serial.available() > 0)
//  {
//    read1 = Serial.readString();
//    a1=read1.substring(0,3).toInt();
//    a3=read1.substring(4,7).toInt();
//    a2=read1.substring(8,11).toInt();
//    Serial.println(a1);
//    Serial.println(a2);
//    Serial.println(a3);
//  }
  temp=0;
  
  servo_move(temp, temp, temp, temp);
//  delay(1000);
//  temp=180;
//  servo_move(180, temp, 0, temp);
  
//  delay(1000);

// int a1 = rand() % 180;
// int a2 = rand() % 180;
// int a3 = rand() % 180;
//  int a4 = rand() % 180;
//  servo_move(a1, a2, a3, a4);
}

void servo_move(int a1, int a2, int a3, int a4)
{
  s1.write(a1);
  s2.write(a2);
  s3.write(a3);
  s4.write(a4);
}
