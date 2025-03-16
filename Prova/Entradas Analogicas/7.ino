//Faça um sistema com dois potenciômetros, em que cada um deles controle o brilho de um led diferente. 

const int entrada1 = A0; // Primeiro potenciômetro ou sensor analógico
const int entrada2 = A1;// Segundo potenciômetro ou sensor analógico
const int led1 = 13;
const int led2 = 12;

void setup() {
	pinMode(led1, OUTPUT);
  	pinMode(led2, OUTPUT);
}

void loop() {
    
    int valor1 = analogRead(entrada1); // Lê o valor da entrada A0
    int valor2 = analogRead(entrada2); // Lê o valor da entrada A1

    int brilhoLed = map(valor1, 0, 1023, 0, 255); //// Converte para escala PWM
	analogWrite(led1, brilhoLed);
  
  	int brilhoLed2 = map(valor2, 0, 1023, 0, 255); 
	analogWrite(led2, brilhoLed2);
}