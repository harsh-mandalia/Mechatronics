#include <Wire.h>
#define slave 7
#define led 3
int x;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(slave);
  Wire.onReceive(receiveEvent);
  pinMode(led,OUTPUT);

  Serial.begin(9600);
  Serial.println("chalu");
}

void loop() {
  delay(100);
}

 
void receiveEvent() {
 
  // Read while data received
  while (0 < Wire.available()) {
    x = Wire.read();
    analogWrite(led,x);
  }
  
  // Print to Serial Monitor
  Serial.print("Receive event ");
  Serial.println(x);
}
