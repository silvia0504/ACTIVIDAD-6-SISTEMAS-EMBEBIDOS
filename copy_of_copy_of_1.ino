// Code C++
//
// Definición de los pines de los LEDs y botón
const int led1 = 5;   // LED conectado al pin 5
const int led2 = 3;   // LED conectado al pin 3
const int led3 = 4;   // LED conectado al pin 4
const int button = 2; // Botón conectado al pin 2

// Variable para indicar si el botón está presionado
volatile bool buttonPressed = false; 

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT_PULLUP); // Configurar el pin del botón (Pulsador)
  
  // Configurar interrupción en el botón
  attachInterrupt(digitalPinToInterrupt(button), buttonInterrupt, FALLING); 
}

void loop() {
  if (buttonPressed) {
    parpadeo(1000); // Parpadeo con una duración de 2 segundo (total 2 segundos)
    buttonPressed = false; 
  }
}

// Función de interrupción
void buttonInterrupt() {
  // Actualizar la variable buttonPressed a true cuando el botón es presionado
  buttonPressed = true;
}

// Función para el parpadeo del LED
void parpadeo(int duration) {
  digitalWrite(led1, HIGH); // Encender el LED1
  digitalWrite(led2, HIGH); // Encender el LED2
  digitalWrite(led3, HIGH); // Encender el LED3
  delay(duration);          // Esperar la duración especificada
  digitalWrite(led1, LOW);  // Apagar el LED1
  digitalWrite(led2, LOW);  // Apagar el LED2
  digitalWrite(led3, LOW);  // Apagar el LED3
  delay(duration);          // Esperar la duración especificada
}
