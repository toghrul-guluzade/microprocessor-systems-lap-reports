void setup() {
  Serial.begin(9600);
  DDRB |= (1<<PB5); //Setting Data Direction
}

void loop() {

  PORTB |= (1<<PB5); //5th bit (PIN 13) set high
  delay(100);

  PORTB &= ~(1 << PB5); //5th bit (PIN 13) set low
  delay(100);

}
