//Leds ligados nas portas 13, 12 e 11. Botões ligados nas portas 2 e 3. Potênciometros ligados nas portas A0 e A1.
// Faça um sistema com dois botões e três leds, o primeiro deve aumentar a quantidade de leds acesos e o segundo deve diminuir a quantidade de leds acesos.

const int led1 = 13;  // LED 1 (vermelho)
const int led2 = 12;  // LED 2 (amarelo)
const int led3 = 11;  // LED 3 (azul)

const int botaoAumentar = 2;
const int botaoDiminuir = 3;

int ledsAtivos = 0;

void setup() {
  // Configuração dos LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Configuração dos botões
  pinMode(botaoAumentar, INPUT_PULLUP);  // Usando pull-up interno
  pinMode(botaoDiminuir, INPUT_PULLUP);  // Usando pull-up interno
  
  // Inicializa os LEDs apagados
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  // Verifica se o botão de aumentar foi pressionado
  if (digitalRead(botaoAumentar) == LOW) {  // Botão conectado ao GND, então verificamos LOW
    if (ledsAtivos < 3) {
      ledsAtivos++;  // Aumenta a quantidade de LEDs acesos
      acionarLeds();
      delay(300);  // Delay para evitar múltiplos acionamentos rápidos
    }
  }

  // Verifica se o botão de diminuir foi pressionado
  if (digitalRead(botaoDiminuir) == LOW) {  // Botão conectado ao GND, então verificamos LOW
    if (ledsAtivos > 0) {
      ledsAtivos--;  // Diminui a quantidade de LEDs acesos
      acionarLeds();
      delay(300);  // Delay para evitar múltiplos acionamentos rápidos
    }
  }
}

// Função para acionar os LEDs de acordo com a quantidade de LEDs ativos
void acionarLeds() {
  // Desliga todos os LEDs antes de acionar os que devem estar acesos
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  // Aciona os LEDs conforme a quantidade de LEDs ativos
  if (ledsAtivos >= 1) {
    digitalWrite(led1, HIGH);  // Acende o primeiro LED
  }
  if (ledsAtivos >= 2) {
    digitalWrite(led2, HIGH);  // Acende o segundo LED
  }
  if (ledsAtivos >= 3) {
    digitalWrite(led3, HIGH);  // Acende o terceiro LED
  }
}
