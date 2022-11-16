#define pot A1
int i=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.write(analogRead(pot));
//  i=i+10;
//  if(i>255)
//  {
//    i=0;
//  }
  delay(10);
}
