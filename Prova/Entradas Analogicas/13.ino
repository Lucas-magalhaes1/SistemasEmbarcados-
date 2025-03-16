//Faça um sistema com dois leds, sendo que cada um deles representará qual de duas entradas analógicas está maior.

const int entrada1 = A0; 
const int entrada2 = A1;
const int led1 = 13;
const int led2 = 12;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    int valor1 = analogRead(entrada1); 
    int valor2 = analogRead(entrada2);

    if (valor1 > valor2) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);  // Garante que o outro LED fique apagado
    } 
    else if (valor2 > valor1) {
        digitalWrite(led1, LOW);  // Garante que o outro LED fique apagado
        digitalWrite(led2, HIGH);
    } 
    else {  // Se forem iguais, ambos os LEDs ficam apagados
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }
}