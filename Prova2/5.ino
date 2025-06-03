//Controle de dois servos com um potenciômetro:
//Utilize dois servo motores e um potenciômetro. Ambos os servos devem ser controlados pelo mesmo potenciômetro. 
//Ao girar o potenciômetro, apenas o primeiro servo deve aumentar o ângulo até atingir 180°. 
//A partir daí, o segundo servo começa a aumentar seu ângulo.
//No movimento inverso, o segundo servo reduz seu ângulo primeiro; quando atingir 0°, o primeiro servo começa a diminuir seu ângulo.

#include <Servo.h>

Servo servo1;
Servo servo2;

const int pinoPot = A0;  // Potenciômetro conectado em A0
const int pinoServo1 = 9;
const int pinoServo2 = 10;

void setup() {
  servo1.attach(pinoServo1);
  servo2.attach(pinoServo2);

  servo1.write(0);  // Começa com servo1 em 0°
  servo2.write(0);  // Servo2 em 0°

  Serial.begin(9600);
}

void loop() {
  int valorPot = analogRead(pinoPot);  // Lê valor do potenciômetro (0-1023)

  // Mapeia valor do potenciômetro para 0-360 (ângulo total dividido para 2 servos)
  int anguloTotal = map(valorPot, 0, 1023, 0, 360);

  int anguloServo1, anguloServo2;

  if (anguloTotal <= 180) {
    // Servo1 aumenta de 0 a 180
    anguloServo1 = anguloTotal;
    anguloServo2 = 0;
  } else {
    // Servo1 fixo em 180, servo2 começa a aumentar
    anguloServo1 = 180;
    anguloServo2 = anguloTotal - 180;  // Vai de 0 a 180
  }

  servo1.write(anguloServo1);
  servo2.write(anguloServo2);

  Serial.print("Potenciometro: ");
  Serial.print(valorPot);
  Serial.print(" | Servo1: ");
  Serial.print(anguloServo1);
  Serial.print(" | Servo2: ");
  Serial.println(anguloServo2);

  delay(50);
}
