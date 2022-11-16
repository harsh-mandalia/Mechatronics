#include <Encoder.h>

Encoder myEnc(18, 19);

#define EN 2
#define INA 3
#define INB 4
#define PWM 5
#define M A0

String read1;

float curr = 0;
float curr_read = 0;
float pwm = 0;
int cap = 40;
int fade = 1;

int t1=micros();
int t2=t1;

float dt=0;
float w=100;
float currk=0;
float currkk=0;
float curr_d=0;

float angle1=0;
float angle2=0;
float angled=0;

float w1=10;
float speed1=0;
float speedd=0;
float speedk=0;
float speedkk=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(EN, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(M, INPUT);

  digitalWrite(EN,1);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    read1 = Serial.readString();
    speedd=read1.toFloat();
    Serial.println(speedd);
  }
  speedd = 2000*sin(0.0002*PI*1*millis()*millis()/1000.0);
//  curr_d = 0.5;
  
  curr_read=analogRead(M)*5/1023.0;
  curr = (curr_read - 2.5)/0.185;

  angle2 = myEnc.read()/2400.0*360;

  t2=micros();
  dt=(t2-t1)/1000000.0;
  speed1 = (angle2-angle1)/dt;
  
  speedkk=((-dt*w1+1)*speedk+dt*w1*speed1);
  speedk=speedkk;

  
  currkk=((-dt*w+1)*currk+dt*w*curr);
  currk=currkk;
  
  angle1 = angle2;
  
  curr_d=0.004*(speedd-speedk);
  pwm=100*(curr_d-currk);
  
  
  t1=micros();

  
//  pwm=25;

  

//  pwm=pwm+fade;
//  if(pwm<=0 | pwm>=255)
//  {
//    fade=-fade;
//  }

  if(pwm>=0)
  {
    digitalWrite(INA,0);
    digitalWrite(INB,1);
    if(pwm>cap)
    {
      analogWrite(PWM, cap);
    }
    else
    {
      analogWrite(PWM, (int)pwm);
    }
  }
  else
  {
    digitalWrite(INA,1);
    digitalWrite(INB,0);
    if(pwm<-cap)
    {
      analogWrite(PWM, cap);
    }
    else
    {
      analogWrite(PWM, (int)abs(pwm));
    }
  }
  Serial.print(speedk);
  Serial.print(", ");
  Serial.println(speedd);
//  Serial.print(", ");0

//  Serial.print(currkk);
//  Serial.print(", ");
//  Serial.println(curr_d);
  

}
