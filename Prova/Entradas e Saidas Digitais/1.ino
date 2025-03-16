// Faça um sistema com dois botões e três leds, 
//o primeiro deve aumentar a quantidade de leds acesos 
//e  segundo deve diminuir a quantidade de leds acesos. 

// Definição dos pinos
const int botao1 = 2;   // Aumenta LEDs acesos
const int botao2 = 3;   // Diminui LEDs acesos
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

int qtdLedsAcesos = 0; // Começa com nenhum LED aceso

void setup() {
    pinMode(botao1, INPUT);  
    pinMode(botao2, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}

void loop() {
    // Leitura dos botões
    bool botao1Pressionado = digitalRead(botao1) == HIGH;
    bool botao2Pressionado = digitalRead(botao2) == HIGH;

    // Se o botão 1 for pressionado, aumenta a quantidade de LEDs acesos
    if (botao1Pressionado && qtdLedsAcesos < 3) {
        qtdLedsAcesos++;
        delay(200); // Pequeno atraso para evitar múltiplos aumentos rápidos
    }

    // Se o botão 2 for pressionado, diminui a quantidade de LEDs acesos
    if (botao2Pressionado && qtdLedsAcesos > 0) {
        qtdLedsAcesos--;
        delay(200); // Pequeno atraso para evitar múltiplas reduções rápidas
    }

    // Atualiza os LEDs com base na quantidade que deve estar acesa
    if (qtdLedsAcesos >= 1) {
        digitalWrite(led1, HIGH);
    } else {
        digitalWrite(led1, LOW);
    }

    if (qtdLedsAcesos >= 2) {
        digitalWrite(led2, HIGH);
    } else {
        digitalWrite(led2, LOW);
    }

    if (qtdLedsAcesos == 3) {
        digitalWrite(led3, HIGH);
    } else {
        digitalWrite(led3, LOW);
    }
}  