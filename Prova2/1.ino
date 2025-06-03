//Controle de um servo motor com potenciômetro:
//Monte o circuito e escreva a programação para que a posição de um servo motor seja controlada por um potenciômetro.


// Inclui a biblioteca Servo, que facilita o controle de servo motores
#include <Servo.h>

// Cria um objeto servo para controlar o servo motor
Servo meuServo;

// Define a entrada analógica do potenciômetro
const int pinoPotenciometro = A0;

// Define a saída digital do servo motor
const int pinoServo = 9;

// Variável para armazenar o valor lido do potenciômetro
int valorPotenciometro = 0;

void setup() {
  // Inicializa o objeto servo na porta digital 12
  meuServo.attach(pinoServo);

  // Inicializa a comunicação serial (opcional, para depuração)
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do potenciômetro (entre 0 e 1023)
  valorPotenciometro = analogRead(pinoPotenciometro);

  // Mapeia o valor lido para um ângulo de 0 a 180 graus
  int angulo = map(valorPotenciometro, 0, 1023, 0, 180);

  // Move o servo motor para o ângulo calculado
  meuServo.write(angulo);

  // Exibe os valores no monitor serial (opcional, para verificação)
  Serial.print("Valor Potenciômetro: ");
  Serial.print(valorPotenciometro);
  Serial.print(" | Ângulo: ");
  Serial.println(angulo);

  // Aguarda um pequeno tempo para estabilidade
  delay(15);
}
