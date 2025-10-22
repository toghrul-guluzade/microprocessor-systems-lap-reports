int8_t result;

void setup() {
  Serial.begin(9600);

  asm volatile(
    "LDI R16, 0 \n\t" //accumulator
    "LDI R17, 10 \n\t" //limit for our loop
    "LDI R18, 0 \n\t" // SUM

    "LOOP: \n\t"
    " INC R16 \n\t"
    " ADD R18, R16 \n\t"
    " CP R16, R17 \n\t"
    " BRLT LOOP \n\t"
    "MOV %0, R18 \n\t"
    : "=r"(result)


  );

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(result);
  delay(3000);

}
