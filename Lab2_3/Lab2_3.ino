int8_t result;
uint8_t SREG_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  asm volatile(
    "LDI R17, 200 \n\t"
    "LDI R18, 50 \n\t"
    "SUB R18, R17 \n\t"
    "MOV %0, R18 \n\t"
    : "=r" (result)

  );

  asm volatile(
    "IN R20, __SREG__ \n\t"
    "MOV %0, R20 \n\t"
    : "=r" (SREG_value)
  );


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nResult: ");
  Serial.print(result);
  Serial.print("\nZERO Flag: ");
  Serial.print((SREG_value >> 1) & 1);
  Serial.print("\nCARY Flag: ");
  Serial.print((SREG_value) & 1);
  delay(5000);

}
