const int pinLM35 = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorADC = analogRead(pinLM35);
  float voltaje = (valorADC / 1023.0) * 5.0;
  float temperatura = voltaje / 0.01; // 10 mV/°C

  Serial.print("ADC: ");
  Serial.print(valorADC);
  Serial.print(" | V: ");
  Serial.print(voltaje);
  Serial.print(" V | T: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(1000);
}
