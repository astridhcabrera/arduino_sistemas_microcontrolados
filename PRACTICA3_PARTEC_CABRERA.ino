const int pinLM35 = A1;
const int pinLED = 13;
float umbral = 30.0; // °C
unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 500;
void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Alarma de temperatura con millis()");
}

void loop() {
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    int valorADC = analogRead(pinLM35);
    float voltaje = (valorADC / 1023.0) * 5.0;
    float temperatura = voltaje / 0.01;

    Serial.print("T: ");
    Serial.print(temperatura);
    Serial.print(" °C | ");

    if (temperatura > umbral) {
      digitalWrite(pinLED, HIGH);
      Serial.println("ALARMA: LED ENCENDIDO");
    } else {
      digitalWrite(pinLED, LOW);
      Serial.println("Normal");
    }
  }
}
