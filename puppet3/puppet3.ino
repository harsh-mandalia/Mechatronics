#include <Servo.h>

#define dirPin 7
#define stepPin 9

Servo s1, s2, s3;

int temp = 0;
int servo_dir = 1;
String read1;
int a1,a2,a3;
//int dir, dely;


// 1.15cm pully outer dia

void setup() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
//  if (Serial.available() > 0)
//  {
//    read1 = Serial.readString();
////    dir = read1.toInt();
//    a1=read1.substring(0,3).toInt();
//    a2=read1.substring(4,7).toInt();
//    a3=read1.substring(8,11).toInt();
//    Serial.println(a1);
//    Serial.println(a2);
//    Serial.println(a3);
//  }
  for (int i=0;i<4;i++)
  {
  moveall(120, 180, 60, -2,20);
  delay(100);
  moveall(180, 90, 0, -2,20);
  delay(100);
  }
  for (int i=0;i<4;i++)
  {
  moveall(60, 90, 120, 2,20);
  delay(100);
  moveall(0, 180, 180, 2,20);
  delay(100);
  }
  
}

void moveall(int a1, int a2, int a3, int dist, int dely)
{
  s1.write(a1);
  s2.write(a2);
  s3.write(a3);

  int steps = dist*6400/(PI*1.15);

  if (dist>0)
  {
    digitalWrite(dirPin, 1);
  }
  else
  {
    digitalWrite(dirPin, 0);
  }
  for (int i=0;i<abs(steps);i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(dely);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(dely);
//    Serial.println(i);
  }
//  delay(1000);
}

void stepper(int dir, int dely)
{
  digitalWrite(dirPin, dir);
  
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(dely);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(dely);
}

void left_up()
{
  
}
