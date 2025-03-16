// Dois leds terão o brilho controlado por um único potenciômetro. Porem enquanto um led aumentará o seu brilho, 
//um segundo led deverá diminuir o brilho. (gangorra)

const int potenciometro = A0; // Entrada analógica
const int led1 = 11; // LED que aumenta o brilho
const int led2 = 12; // LED que diminui o brilho

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    int valorAnalogico = analogRead(potenciometro); // Lê o potenciômetro (0 a 1023)

    int brilhoLed1 = map(valorAnalogico, 0, 1023, 0, 255); // Brilho normal
    int brilhoLed2 = map(valorAnalogico, 0, 1023, 255, 0); // Brilho invertido

    analogWrite(led1, brilhoLed1);
    analogWrite(led2, brilhoLed2);
}
