//Faça um sistema onde um potenciômetro controla o brilho de um led. Porem a atualização do brilho do led deve ocorrer somente quando 1 botão for pressionado.

const int botao = 2;  // Botão ligado na porta digital 2
const int led = 11;    // LED ligado na porta digital 13
const int entradaAnalogica = A0; // Entrada analógica para leitura

void setup() {
    pinMode(botao, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    bool botaoPressionado = digitalRead(botao) == HIGH; 
    int valorAnalogico = analogRead(entradaAnalogica);
  	 int brilhoLed = map(valorAnalogico, 0, 1023, 0, 255); //// Converte para escala PWM
  
    if (botaoPressionado) {
		analogWrite(led, brilhoLed);
    }
}