//Faça um sistema com 2 leds e 2 botões.Ao pressionar qualquer dos botões, o LED 13 deve ligar.Ao pressionar os dois botões juntos, os dois leds devem ligar.

const int led1 = 13;  // LED 1
const int led2 = 12;  // LED 2

const int botaoAumentar = 2;  // Botão Aumentar
const int botaoDiminuir = 3;  // Botão Diminuir

void setup() {
  // Configuração dos LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Configuração dos botões com resistência de pull-down externa (botões conectados diretamente aos pinos)
  pinMode(botaoAumentar, INPUT);  
  pinMode(botaoDiminuir, INPUT);  
  
  // Inicializa os LEDs apagados
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  // Verifica se ambos os botões foram pressionados
  if (digitalRead(botaoAumentar) == LOW && digitalRead(botaoDiminuir) == LOW) {
    // Se ambos os botões foram pressionados, acende ambos os LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  // Verifica se qualquer um dos botões foi pressionado
  else if (digitalRead(botaoAumentar) == LOW || digitalRead(botaoDiminuir) == LOW) {
    // Se apenas um dos botões foi pressionado, acende o LED 13 (led1)
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);  // Garante que o LED 2 está apagado
  } 
  else {
    // Se nenhum botão foi pressionado, apaga ambos os LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
