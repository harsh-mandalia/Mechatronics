// current LED state
byte state = B00000000;

// the setup function runs once when you press reset or power the board
void setup() {
  
  // setting up output on LED pin
  DDRD = B10000000;
  PORTD =B00000000;

  //setting up timer to CTC mode
  TCCR1A=B00000000;
  TCCR1B=B00001100;

  //initialise timer to 0
  TCNT1 = 0;
  OCR1A = 31250; //setting comperator value(setting intrupt time)

  //setting intrupt on A
  TIMSK1 = B00000010;

  //enable globle intrupts
  sei();
}

// the loop function runs over and over again forever
void loop() {
//  PORTD = B10000000;   // turn the LED on (HIGH is the voltage level)
//  delay(500);                       // wait for a second
//  PORTD = B00000000;    // turn the LED off by making the voltage LOW
//  delay(500);                       // wait for a second
}

ISR(TIMER1_COMPA_vect)
{
//  TCNT1 = 0;
  state = ~state;
  PORTD = B10000000 & state;
  
}
