//O funcionamento dos leds deve ser parecido com o do exercício acima (17), porem o controle do brilho se dara por dois botões.

const int potenciometro = A0; // Entrada analógica
const int led1 = 11; // LED que aumenta o brilho
const int led2 = 12; // LED que diminui o brilho
const int botao1 = 2;
const int botao2 = 3;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}

void loop() {
  	bool estadoBotao = digitalRead(botao1);
  	bool estadoBotao2 = digitalRead(botao2);
    int valorAnalogico = analogRead(potenciometro); // Lê o potenciômetro (0 a 1023)
	
  if (estadoBotao == HIGH){
    int brilhoLed1 = map(valorAnalogico, 0, 1023, 0, 255); // Brilho normal
  	analogWrite(led1, brilhoLed1);
  }
  
  if (estadoBotao2 == HIGH){
    int brilhoLed2 = map(valorAnalogico, 0, 1023, 255, 0); // Brilho invertido
  	analogWrite(led2, brilhoLed2);
  } 
}