// Faça um sistema com 2 LEDs e 2 botões.
// Ao pressionar qualquer dos botões, o LED 13 deve ligar.
// Ao pressionar os dois botões juntos, os dois LEDs devem ligar.

const int botao1 = 2;   
const int botao2 = 3;   
const int led1 = 13;
const int led2 = 12;

void setup() {
    pinMode(botao1, INPUT);  
    pinMode(botao2, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    // Lendo os botões
    bool estadoBotao1 = digitalRead(botao1) == HIGH;
    bool estadoBotao2 = digitalRead(botao2) == HIGH;

    if (estadoBotao1 && estadoBotao2) {
        // Se os dois botões estiverem pressionados, acende os dois LEDs
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
    } 
    else if (estadoBotao1 || estadoBotao2) {
        // Se apenas um dos botões estiver pressionado, acende apenas o LED 13
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    } 
    else {
        // Se nenhum botão estiver pressionado, apaga os dois LEDs
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }
}
