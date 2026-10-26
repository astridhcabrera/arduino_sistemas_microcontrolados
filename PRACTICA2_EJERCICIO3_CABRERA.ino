int BOTON = 8;
int LED2 = 12;
int LED3 = 11; // Nuevo LED

unsigned long tiempoAnterior = 0;
unsigned long tiempoAnterior2 = 0;
unsigned long tiempoActual;

const unsigned long intervalo = 1000;
const unsigned long intervalo2 = 2000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
  Serial.println("Lectura de boton iniciada");

  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {
  tiempoActual = millis();

  // Primer LED: parpadea cada 1 segundo
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  // Segundo LED parpadeante: cada 2 segundos
  if (tiempoActual - tiempoAnterior2 >= intervalo2) {
    tiempoAnterior2 = tiempoActual;
    digitalWrite(LED3, !digitalRead(LED3));
  }

  // LED controlado por el botón
  int lectura = digitalRead(BOTON);

  if (lectura == LOW) {
    digitalWrite(LED2, HIGH);
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED2, LOW);
    Serial.println("LED APAGADO");
  }
}