//Faça um sistema onde um potenciômetro controla o brilho de um led. (lembre de usar as portas apropriadas)

const int entrada1 = A0; // Primeiro potenciômetro ou sensor analógico
const int led1 = 11; // usei a porta 11 por ela ter o pwm onde o analogWrite()ó funciona em pinos PWM, que são:
// 3, 5, 6, 9, 10 e 11 (em um Arduino Uno, por exemplo).


void setup() {
	pinMode(led1, OUTPUT);
}

void loop() {
    int valor1 = analogRead(entrada1); // Lê o valor da entrada A0
   
    int brilhoLed = map(valor1, 0, 1023, 0, 255); //// Converte para escala PWM
	analogWrite(led1, brilhoLed);
}