//float vin = 1023*sin(micro/s()/10000000);

void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
//  Serial.begin(115200);

}

void loop() {
//   put your main c//ode here, to run repeatedly:
//  vin = 255/2+255/2*si/n(micros()/100000.0);
//  analogWrite(7,vin);/1
//  Serial.println(vin);
//  delay(1/0);
////  Serial.println(analogRead(A0));
  digitalWrite(7,1);
  delay(50);
  digitalWrite(7,0);
  delay(50);
//  Serial.println(analogRead(A0));

}
