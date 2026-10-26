#define LED_PIN 13
void setup() {
 pinMode(LED_PIN, OUTPUT); // Configurar pin como salida
}
void loop() {
 digitalWrite(LED_PIN, HIGH); // Encender LED
 delay(1000); // Esperar 1 segundo
 digitalWrite(LED_PIN, LOW); // Apagar LED
 delay(1000); // Esperar 1 segundo
}
