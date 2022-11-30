#include <Servo.h>

#define dirPin 7
#define stepPin 9

Servo s1, s2, s3;

int temp = 0;
int servo_dir = 1;
String read1;
int a1,a2,a3;
int t0=millis();
int t=0;

//int dir, dely;


// 1.15cm pully outer dia

void setup() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  Serial.begin(9600);
  t0=millis();
}

void loop() {
  t=millis()/1000;
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

//  for (int i=0;i<4;i++)
//  {
//  moveall(120, 180, 60, -2,20);
//  delay(100);
//  moveall(180, 90, 0, -2,20);
//  delay(100);
//  }
//  for (int i=0;i<4;i++)
//  {
//  moveall(60, 90, 120, 2,20);
//  delay(100);
//  moveall(0, 180, 180, 2,20);
//  delay(100);
//  }

//  right_move(0,180,10);
//  delay(1000);
//  right_move(180,0,10);
//  delay(1000);
//
//  left_move(0,180,10);
//  delay(1000);
//  left_move(180,0,10); 
//  delay(1000);

//  both_move(0,160,180,0,10);
//  delay(1000);
//  both_move(160,0,0,180,10);
//  delay(1000);

    if(t<36)
    {
      Serial.println(t);
      left_move(0,180,500);
      while(t<35)
      {
        t=(millis()-t0)/1000;
        delay(1000);
        Serial.println("delay");
      }   
    }
    else if(t<48)
    {
      int temp=300;
      int temp1=20;
      left_move(160,80,temp1);
      delay(temp);
      left_move(80,0,temp1);
      delay(temp);
      right_move(0,90,temp1);
      delay(temp);
      right_move(90,180,temp1);
      delay(temp);
      right_move(180,90,temp1);
      delay(temp);
      right_move(90,0,temp1);
      delay(temp);
      left_move(0,80,temp1);
      delay(temp);
      left_move(80,160,temp1);
      delay(temp);  
    }
    else if(t<70)
    {
      int temp=300;
      int temp1=20;
      three_move(0,80,0,0,180,90,temp1);
      delay(temp);
      three_move(80,160,0,0,90,0,temp1);
      delay(temp);
      three_move(160,80,0,0,0,90,temp1);
      delay(temp);
      three_move(80,0,0,0,90,180,temp1);
      delay(temp);
    }
    else if(t<92)
    {
      int temp=80;
      int temp1=20;
      three_move(0,80,0,180,180,90,temp1);
      delay(temp);
      three_move(80,160,180,0,90,0,temp1);
      delay(temp);
      three_move(160,80,0,180,0,90,temp1);
      delay(temp);
      three_move(80,0,180,0,90,180,temp1);
      delay(temp);
    }
    else if(t<120)
    {
      int temp=80;
      int temp1=10;
      three_move(0,80,0,180,180,90,temp1);
      stepper(-4,20);
      three_move(80,160,180,0,90,0,temp1);
      stepper(-4,20);
      delay(temp);
      three_move(160,80,0,180,0,90,temp1);
      stepper(4,20);
      three_move(80,0,180,0,90,180,temp1);
      stepper(4,20);
      delay(temp);
    }
    Serial.println("done");
//    moveall(0,0,0,0,0);/
    

//    three_move(0,80,0,180,180,90,10);
//    stepper(-3,20);
//    three_move(80,160,180,0,90,0,10);
//    stepper(-3,20);
//    delay(80);
//    three_move(160,80,0,180,0,90,10);
//    stepper(3,20);
//    three_move(80,0,180,0,90,180,10);
//    stepper(3,20);
//    delay(80);
  
//  moveall(0,0,0,0,0);
//  delay(1000);
  
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
  }
}

void stepper(int dist, int dely)
{
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
  }
}

void left_move(int x0, int x1, int t)
{
  if(x1>x0)
  {
    for(int i=x0;i<x1;i=i+5)
    {
      moveall(i,0,0,0,0);
      delay(t);
    }
  }
  else
  {
    for(int i=x0;i>x1;i=i-5)
    {
      moveall(i,0,0,0,0);
      Serial.println(i);
      delay(t);
    }
  }
}

void right_move(int x0, int x1, int t)
{
  if(x1>x0)
  {
    for(int i=x0;i<x1;i=i+5)
    {
      moveall(0,0,i,0,0);
      delay(t);
    }
  }
  else
  {
    for(int i=x0;i>x1;i=i-5)
    {
      moveall(0,0,i,0,0);
      Serial.println(i);
      delay(t);
    }
  }
}

void both_move(int x0, int x1, int y0, int y1,int t)
{
  if(x1>x0)
  {
    if(y1>y0)
    {
      int i=x0;
      int j=y0;
      while(i<x1 || j<y1)
      {
        moveall(i,0,j,0,0);
        delay(t);
        if(i<x1)
        {
          i=i+5;
        }
        if(j<y1)
        {
          j=j+5;
        }
      }
    }
    else
    {
      int i=x0;
      int j=y0;
      while(i<x1 || j>y1)
      {
        moveall(i,0,j,0,0);
        delay(t);
        if(i<x1)
        {
          i=i+5;
        }
        if(j>y1)
        {
          j=j-5;
        }
      }
    }
  }
  else
  {
    if(y1>y0)
    {
      int i=x0;
      int j=y0;
      while(i>x1 || j<y1)
      {
        moveall(i,0,j,0,0);
        delay(t);
        if(i>x1)
        {
          i=i-5;
        }
        if(j<y1)
        {
          j=j+5;
        }
      }
    }
    else
    {
      int i=x0;
      int j=y0;
      while(i>x1 || j>y1)
      {
        moveall(i,0,j,0,0);
        delay(t);
        if(i>x1)
        {
          i=i-5;
        }
        if(j>y1)
        {
          j=j-5;
        }
      }
    } 
  }
}

void three_move(int x0, int x1, int z0, int z1, int y0, int y1, int t)
{
  if(z1>z0)
  {
    if(x1>x0)
    {
      if(y1>y0)
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i<x1 || j<y1 || k<z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i<x1)
          {
            i=i+5;
          }
          if(j<y1)
          {
            j=j+5;
          }
          if(k<z1)
          {
            k=k+5;
          }
        }
      }
      else
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i<x1 || j>y1 || k<z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i<x1)
          {
            i=i+5;
          }
          if(j>y1)
          {
            j=j-5;
          }
          if(k<z1)
          {
            k=k+5;
          }
        }
      }
    }
    else
    {
      if(y1>y0)
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i>x1 || j<y1 || k<z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i>x1)
          {
            i=i-5;
          }
          if(j<y1)
          {
            j=j+5;
          }
          if(k<z1)
          {
            k=k+5;
          }
        }
      }
      else
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i>x1 || j>y1 || k<z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i>x1)
          {
            i=i-5;
          }
          if(j>y1)
          {
            j=j-5;
          }
          if(k<z1)
          {
            k=k+5;
          }
        }
      } 
    }
  }
  else
  {
    if(x1>x0)
    {
      if(y1>y0)
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i<x1 || j<y1 || k>z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i<x1)
          {
            i=i+5;
          }
          if(j<y1)
          {
            j=j+5;
          }
          if(k>z1)
          {
            k=k-5;
          }
        }
      }
      else
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i<x1 || j>y1 || k>z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i<x1)
          {
            i=i+5;
          }
          if(j>y1)
          {
            j=j-5;
          }
          if(k>z1)
          {
            k=k-5;
          }
        }
      }
    }
    else
    {
      if(y1>y0)
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i>x1 || j<y1 || k>z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i>x1)
          {
            i=i-5;
          }
          if(j<y1)
          {
            j=j+5;
          }
          if(k>z1)
          {
            k=k-5;
          }
        }
      }
      else
      {
        int i=x0;
        int j=y0;
        int k=z0;
        while(i>x1 || j>y1 || k>z1)
        {
          moveall(i,k,j,0,0);
          delay(t);
          if(i>x1)
          {
            i=i-5;
          }
          if(j>y1)
          {
            j=j-5;
          }
          if(k>z1)
          {
            k=k-5;
          }
        }
      } 
    }
  }
}
