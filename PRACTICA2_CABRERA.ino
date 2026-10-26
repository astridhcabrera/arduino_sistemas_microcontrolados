int BOTON = 8;
int LED2  = 12;
unsigned long tiempoAnterior = 0;
unsigned long tiempoActual;
const unsigned long intervalo = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lectura de boton iniciada");
  pinMode(BOTON, INPUT);
}
// the loop function runs over and over again forever
void loop() {
  tiempoActual = millis();
 if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Cambia estado
  }
 
  int lectura = digitalRead(BOTON);
  if (lectura == LOW) {        // Botón presionado (pull-up)
    digitalWrite(LED2, HIGH);    // LED encendido
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED2, LOW);     // LED apagado
    Serial.println("LED APAGADO");
  }
}

