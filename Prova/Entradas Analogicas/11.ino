//Faça um sistema que leia o valor da porta analógica e quando um botão for pressionado o valor da 
//porta analógica deve ser mostrada uma única vez no monitor serial.

const int entrada1 = A0;
const int botao = 2;
bool botaoAnterior = LOW;  // Armazena o estado anterior do botão

void setup() {
    Serial.begin(9600);
    pinMode(botao, INPUT);
}

void loop() {
    bool botaoPressionado = digitalRead(botao) == HIGH;
    int valor1 = analogRead(entrada1);

    // Só imprime quando o botão for pressionado pela primeira vez (transição LOW -> HIGH)
    if (botaoPressionado && botaoAnterior == LOW) {
        Serial.print("Entrada 1: ");
        Serial.println(valor1);
    }

    // Atualiza o estado anterior do botão
    botaoAnterior = botaoPressionado;
}
