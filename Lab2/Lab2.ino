
  uint8_t led_state = 0;
  uint8_t previous_state = 1;

void setup() {

  Serial.begin(9600);
  DDRB |= (1 << PB4); // This sets arduino pin 12 as an output
  DDRB &= ~(1 << PB0); // Arduino pin 8 as an input
  PORTB |= (1 << PB0); // PULL UP Resistor


}

void loop() {

  uint8_t current_state = 0; 

  current_state = PINB & (1<<PB0); // Checks Current state

  if(!(current_state) && previous_state){ //Checks if current state is low but previous is high
    led_state ^= 1; //changes the led state variable

    if(led_state){ //changes the led status
      PORTB |= (1<<PB4);
    } else {
        PORTB &= ~(1<<PB4);
    }
      delay(200); // small delay for overcomming button bounce

  } 
    previous_state = current_state; // updating previous state.
  
}
