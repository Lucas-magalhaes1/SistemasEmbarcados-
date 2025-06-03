// Sistema de cancela com botão e servo motor:
//Monte um sistema utilizando um botão e um servo motor que simule a cancela de um estacionamento. O servo deve iniciar com ângulo em 0°.
// Ao pressionar o botão, o ângulo do servo deve ir para 90°, 
//aguardar 5 segundos e retornar à posição inicial. No monitor serial, deve ser exibida a quantidade de vezes que o servo foi acionado.



#include <Servo.h>  // Inclui a biblioteca para controlar servo motores

Servo meuServo;  // Cria um objeto servo

const int pinoBotao = 2;  // Botão conectado ao pino D2
int contagemAcionamentos = 0;  // Variável para contar quantas vezes a cancela foi acionada
bool estadoAnteriorBotao = LOW;  // Guarda o estado anterior do botão (começa "não pressionado")

void setup() {
  meuServo.attach(9);  // Servo conectado ao pino D9
  pinMode(pinoBotao, INPUT);  // Configura o pino do botão como entrada simples (sem pull-up interno)
  meuServo.write(0);  // Servo inicia fechado, ângulo 0°
  Serial.begin(9600);  // Inicia comunicação serial
}

void loop() {
  // Lê o estado atual do botão (AGORA: HIGH quando pressionado, LOW quando solto)
  bool estadoAtualBotao = digitalRead(pinoBotao);

  // Verifica se houve uma transição de LOW -> HIGH (botão foi pressionado)
  if (estadoAnteriorBotao == LOW && estadoAtualBotao == HIGH) {
    contagemAcionamentos++;  // Incrementa contador

    meuServo.write(90);  // Abre a cancela (servo a 90 graus)
    delay(5000);  // Mantém a cancela aberta por 5 segundos
    meuServo.write(0);  // Fecha a cancela (servo volta a 0 graus)

    // Exibe no monitor serial a quantidade de acionamentos
    Serial.print("Cancela acionada: ");
    Serial.println(contagemAcionamentos);
  }

  // Atualiza o estado anterior do botão para o próximo loop
  estadoAnteriorBotao = estadoAtualBotao;

  delay(50);  // Pequeno delay para evitar bounce (efeito de múltiplos acionamentos)
}
