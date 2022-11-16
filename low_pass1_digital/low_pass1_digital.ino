float vin=0;
float voA=0;
float vok=0;
float vokk=0;
int t1=millis();
int t2=millis();
float dt=0;
float w=77.3;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  vin=analogRead(A0)*5/1023.0;
  voA=analogRead(A1)*5/1023.0;
  t2=micros();
  dt=(t2-t1)/1000000.0;
  vokk=((-dt*w+1)*vok+dt*w*vin);
  t1=micros();
  Serial.print(vokk);
  Serial.print(" ");
  Serial.print(voA);
  Serial.print(" ");
  Serial.println(vin);
  vok=vokk;
//  delay(1);/
}
