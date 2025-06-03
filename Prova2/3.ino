//Controle de ângulo com dois botões:
//Monte um sistema com um servo motor e dois botões. Um botão deve aumentar o ângulo do servo, enquanto o outro botão deve diminuir esse ângulo.

#include <Servo.h>  // Inclui biblioteca para controle do servo

Servo meuServo;  // Cria objeto para o servo motor

const int botaoAumenta = 2;  // Botão de aumentar ângulo no pino D2
const int botaoDiminui = 3;  // Botão de diminuir ângulo no pino D3

int angulo = 90;  // Servo começa no meio, em 90°
bool estadoAnteriorAumenta = LOW;  // Estado anterior do botão de aumentar
bool estadoAnteriorDiminui = LOW;  // Estado anterior do botão de diminuir

void setup() {
  meuServo.attach(9);  // Servo conectado no pino D9
  meuServo.write(angulo);  // Move servo para a posição inicial (90°)

  pinMode(botaoAumenta, INPUT);  // Configura botão de aumentar como entrada
  pinMode(botaoDiminui, INPUT);  // Configura botão de diminuir como entrada

  Serial.begin(9600);  // Inicia comunicação serial
}

void loop() {
  // Lê estados atuais dos botões
  bool estadoAtualAumenta = digitalRead(botaoAumenta);
  bool estadoAtualDiminui = digitalRead(botaoDiminui);

  // Se botão de aumentar foi pressionado (borda de LOW para HIGH)
  if (estadoAnteriorAumenta == LOW && estadoAtualAumenta == HIGH) {
    if (angulo < 180) {  // Garante que o ângulo não passe de 180°
      angulo += 10;  // Aumenta o ângulo em 10°
      meuServo.write(angulo);  // Move o servo para o novo ângulo
      Serial.print("Ângulo aumentado para: ");
      Serial.println(angulo);
    }
  }

  // Se botão de diminuir foi pressionado (borda de LOW para HIGH)
  if (estadoAnteriorDiminui == LOW && estadoAtualDiminui == HIGH) {
    if (angulo > 0) {  // Garante que o ângulo não fique abaixo de 0°
      angulo -= 10;  // Diminui o ângulo em 10°
      meuServo.write(angulo);  // Move o servo para o novo ângulo
      Serial.print("Ângulo diminuído para: ");
      Serial.println(angulo);
    }
  }

  // Atualiza os estados anteriores para a próxima leitura
  estadoAnteriorAumenta = estadoAtualAumenta;
  estadoAnteriorDiminui = estadoAtualDiminui;

  delay(50);  // Pequeno delay para debounce
}
