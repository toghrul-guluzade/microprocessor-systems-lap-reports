  uint8_t value = 0;
  uint8_t value_out;

void setup() {
  Serial.begin(9600);

  DDRB &= ~(1 << PB0); //Setting PB0 as an input
  PORTB |= (1 << PB0); //Pull-up resistor

  EEARL = 0x00; // EPROM ADDRESS

  EECR |= (1 << EERE); //Fetching previous value from address to EEDR
  value = EEDR; //Copying EEDR value into variable

    // while ((EECR & (1 << EEPE)));
    // EEDR = value;
    // EECR |= (1 << EEMPE);
    // EECR |= (1 << EEPE);
  

}

void loop() {

  //Checks if button is pressed and if yes increments the value.
  if(~(PINB) & (1 <<PB0)){ 
    value += 1;
    delay(200); //Short delay for button debounce
  }

  while ((EECR & (1 << EEPE))){
    //Wait until EEPROM write operation is finished
  }
    EEDR = value; // Copying our value into Data Register
    EECR |= (1 << EEMPE); //Changing the Control Register status into write
    EECR |= (1 << EEPE); //Start Writing

  while (EECR & (1 << EEPE)){
    //Wait until EEPROM write operation is finished
  }
  EECR |= (1 << EERE); //Read Enable
  value_out = EEDR; //Store EEDR value into Variable

  //print
  Serial.print(value_out);
  Serial.print("\n");
  delay(200);


}
