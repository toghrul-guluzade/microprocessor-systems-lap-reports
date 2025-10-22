void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  DDRB |= (1 << PB4);
  DDRB &= ~(1 << PB0);
  PORTB |= (1 << PB0);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(!(PINB & (1<<PB0))){
    PORTB |= (1<<PB4);
  } else {
    PORTB &= ~(1<<PB4);
  }
}
