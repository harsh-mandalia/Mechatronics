#include <Servo.h>

Servo s1, s2, s3, s4;

int temp = 90;

void setup() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
}

void loop() {
//  servo_move(temp, temp, temp, temp);
//  delay(500);
 int a1 = rand() % 180;
 int a2 = rand() % 180;
 int a3 = rand() % 180;
  int a4 = rand() % 180;
  servo_move(a1, a2, a3, a4);
  delay(500);
}

void servo_move(int a1, int a2, int a3, int a4)
{
  s1.write(a1);
  s2.write(a2);
  s3.write(a3);
  s4.write(a4);
}
