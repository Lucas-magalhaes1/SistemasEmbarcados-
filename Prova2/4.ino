//Controle de servo com sensor LDR:
//Utilize um LDR e um servo motor. O ângulo do servo deve ser controlado pela intensidade de luz detectada pelo LDR.

#include <Servo.h>

Servo meuServo;

const int pinoLDR = A0;   // LDR conectado à entrada analógica A0
const int pinoServo = 9;  // Servo conectado ao pino digital 9

void setup() {
  meuServo.attach(pinoServo);
  meuServo.write(0);      // Inicializa servo na posição 0°
  Serial.begin(9600);
}

void loop() {
  int valorLDR = analogRead(pinoLDR);  // Lê o valor do LDR (0 a 1023)

  // Mapeia o valor do LDR para ângulo do servo (0° a 180°)
  int angulo = map(valorLDR, 0, 1023, 0, 180);

  meuServo.write(angulo);  // Define o ângulo do servo

  Serial.print("Valor LDR: ");
  Serial.print(valorLDR);
  Serial.print(" - Angulo Servo: ");
  Serial.println(angulo);

  delay(100);  // Pequeno delay para estabilidade
}
