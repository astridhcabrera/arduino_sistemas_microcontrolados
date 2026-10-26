const int pinPot = A0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int valorADC = analogRead(pinPot);
  float voltaje = (valorADC / 1023.0) * 5.0;

  Serial.print("ADC: ");
  Serial.print(valorADC);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje);
  Serial.println(" V");

  delay(500);
}
