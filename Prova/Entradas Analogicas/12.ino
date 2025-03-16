//Um led que deverá piscar quando um botão for pressionado, a quantidade de vezes conforme o 
//valor lido em uma porta analógica (0 a 1023). 

const int entradaAnalogica = A0;
const int botao = 2;
const int led = 13;
bool botaoAnterior = LOW;  // Armazena o estado anterior do botão

void setup() {
    pinMode(led, OUTPUT);
    pinMode(botao, INPUT);
}

void loop() {
    bool botaoPressionado = digitalRead(botao) == HIGH;
    int valorAnalogico = analogRead(entradaAnalogica);

    // Converte o valor da entrada analógica para um número de piscadas (ex: 0 a 10)
    int qtdPiscadas = map(valorAnalogico, 0, 1023, 0, 10);

    // Quando o botão for pressionado pela primeira vez, pisca o LED
    if (botaoPressionado && botaoAnterior == LOW) {
        for (int i = 0; i < qtdPiscadas; i++) {
            digitalWrite(led, HIGH);
            delay(300);
            digitalWrite(led, LOW);
            delay(300);
        }
    }

    // Atualiza o estado do botão
    botaoAnterior = botaoPressionado;
}
