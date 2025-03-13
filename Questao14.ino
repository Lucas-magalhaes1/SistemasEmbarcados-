// Definindo o pino do LED e do potenciômetro
const int ledPin = 13;   // LED 13
const int potPin = A0;   // Potenciômetro 1 (controla o brilho do LED 13)

void setup() {
  // Definindo o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Lendo o valor do potenciômetro (A0)
  int potValue = analogRead(potPin);  // Leitura do potenciômetro
  int brightness = map(potValue, 0, 1023, 0, 255); // Mapeando o valor para o intervalo de brilho do LED
  
  // Ajusta o brilho do LED 13
  analogWrite(ledPin, brightness);

  delay(100); // Pequeno delay para garantir leituras estáveis
}
