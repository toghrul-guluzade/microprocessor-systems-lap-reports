int8_t result;

void setup() {
  Serial.begin(9600);

  asm volatile(
    "LDI R16, 0 \n\t" //accumulator
    "LDI R17, 10 \n\t" //limit for our loop
    "LDI R18, 0 \n\t" // SUM

    "LOOP: \n\t"
    " INC R16 \n\t" //Increment accumulator
    " ADD R18, R16 \n\t" //add operation
    " CP R16, R17 \n\t" //compare accumulator with max limit
    " BRLT LOOP \n\t" //loop back if it hasn't reach to the limit yet
    "MOV %0, R18 \n\t"
    : "=r"(result)


  );

}

void loop() {
  // print
  Serial.print(result);
  delay(3000);

}
