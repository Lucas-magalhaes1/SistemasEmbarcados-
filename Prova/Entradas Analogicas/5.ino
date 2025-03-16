// Faça um sistema que leia o valor de uma porta analógica e ligue ou desligue um led conforme a 
//tensão lida, sendo menor que 2,5V desliga o led e maior ou igual a 2,5V ligue o led. 

const int potenciometro = A0; // Entrada analógica (A0)
const int led = 13; // LED na porta 13

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    int valorLido = analogRead(potenciometro); // Lê o valor do potenciômetro (0 a 1023)

    if (valorLido >= 512) { // Se for maior ou igual a 2,5V (meio da escala)
        digitalWrite(led, HIGH); // Liga o LED
    } else {  
        digitalWrite(led, LOW); // Desliga o LED
    }
}

