//O brilho de um led deve aumentar a cada pulso de um botão. Após o led atingir o brilho máximo, no próximo pulsoo led deve apagar.

const int botao = 2;  // Botão ligado na porta digital 2
const int led = 11;   // LED ligado na porta PWM 11

int brilho = 0;   // Nível de brilho do LED
bool ultimoEstadoBotao = LOW;  // Armazena o estado anterior do botão

void setup() {
    pinMode(botao, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    bool estadoBotao = digitalRead(botao); // Lê o estado do botão

    // Detecta quando o botão é pressionado (transição de LOW para HIGH)
    if (estadoBotao == HIGH && ultimoEstadoBotao == LOW) {
        if (brilho < 255) {
            brilho += 51; // Aumenta o brilho (255/5 = 51, para 5 passos)
        } else {
            brilho = 0; // Se já estiver no máximo, apaga o LED
        }
        analogWrite(led, brilho); // Atualiza o brilho do LED
    }

    ultimoEstadoBotao = estadoBotao; // Atualiza o estado do botão
}
