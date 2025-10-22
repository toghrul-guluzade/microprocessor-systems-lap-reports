void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB |= (1 << PB5);


}

void loop() {

// With direct memory mapping
  PORTB |= 0b00100000;
  delay(500);
  PORTB &= 0x0;
  delay(500);

  // Togling with exclusive or
  /*
  PORTB ^= (1 << PB5);
  delay(100);
  */

  //Using bitwise shift with or and and
  /*
  PORTB |= (1 << PB5);
  delay(100);
  PORTB &= ~(1 << PB5);
  delay(100);
  
  */
  

}
