// Definição dos pinos
const int botao1 = 2;
const int botao2 = 3;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11; // LED com controle de brilho (PWM)
const int potenciometro1 = A0;
const int potenciometro2 = A1;

void setup() {
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Leitura dos botões
    int estadoBotao1 = digitalRead(botao1);
    int estadoBotao2 = digitalRead(botao2);

    // Controle dos LEDs com os botões
    if (estadoBotao1 == LOW) {
        digitalWrite(led1, HIGH);
    } else {
        digitalWrite(led1, LOW);
    }

    if (estadoBotao2 == LOW) {
        digitalWrite(led2, HIGH);
    } else {
        digitalWrite(led2, LOW);
    }

    // Leitura dos potenciômetros
    int valorPot1 = analogRead(potenciometro1);
    int valorPot2 = analogRead(potenciometro2);

    // Converte os valores dos potenciômetros para PWM (0-255)
    int brilhoLed3 = map(valorPot1, 0, 1023, 0, 255);
    int reducaoBrilho = map(valorPot2, 0, 1023, 0, 255);

    // Aplica o brilho ajustado no LED3
    int brilhoFinal = brilhoLed3 - reducaoBrilho;
    brilhoFinal = constrain(brilhoFinal, 0, 255); // Mantém dentro do intervalo 0-255

    analogWrite(led3, brilhoFinal);

    // Exibe no monitor serial
    Serial.print("Botao 1: ");
    Serial.print(estadoBotao1 == LOW ? "Pressionado" : "Solto");
    Serial.print(" | Botao 2: ");
    Serial.print(estadoBotao2 == LOW ? "Pressionado" : "Solto");
    Serial.print(" | Pot1: ");
    Serial.print(valorPot1);
    Serial.print(" | Pot2: ");
    Serial.print(valorPot2);
    Serial.print(" | Brilho LED3: ");
    Serial.println(brilhoFinal);

    delay(100); // Pequeno atraso para facilitar a leitura
}
