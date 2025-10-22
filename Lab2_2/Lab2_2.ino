
  uint8_t result;
void setup() {
  Serial.begin(9600);
  asm volatile(
    "LDI R17, 5 \n\t"
    "LDI R18, 8 \n\t"
    "ADD R18, R17 \n\t"
    "mov %0, R18 \n\t"
    : "=r" (result)

  );
  Serial.print(result);
  
}

void loop() {
  
}
