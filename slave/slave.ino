#define led 3

int a=0;
String read1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    read1 = Serial.read();
    a=read1.toInt();
//    Serial.println(read1);
    analogWrite(led,a);
  }
  

}
