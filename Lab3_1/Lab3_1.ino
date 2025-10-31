void setup() {
  /*
  ````
    As three different methods are in use to change the PORTB state
    I commented two of them as only one of them should work at a time.
  ````
  */
  Serial.begin(9600);
  DDRB |= (1 << PB5);


}

void loop() {

// With direct memory mapping
  PORTB = 0b00100000;
  delay(500);
  PORTB = 0x0;
  delay(500);

  //Using bitwise shift with or and and
  /*
  PORTB |= (1 << PB5);
  delay(100);
  PORTB &= ~(1 << PB5);
  delay(100);
  
  */
  

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
