//Faça um sistema com um led que deve ligar toda a vez que um botão for pressionado. Esse led 
//deverá desligar quando a leitura de uma porta analógica seja menor que 10. 

const int botao = 2;  // Botão ligado na porta digital 2
const int led = 13;    // LED ligado na porta digital 13
const int entradaAnalogica = A0; // Entrada analógica para leitura

void setup() {
    pinMode(botao, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    bool botaoPressionado = digitalRead(botao) == HIGH; 
    int valorAnalogico = analogRead(entradaAnalogica); 

    if (botaoPressionado) {
        digitalWrite(led, HIGH); // Liga o LED quando o botão for pressionado
    }

    if (valorAnalogico < 10) {
        digitalWrite(led, LOW); // Desliga o LED se a leitura analógica for menor que 10
    }
}