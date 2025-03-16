//Faça um sistema em que um potenciômetro controle o brilho de um led utilizando um potenciômetro, 
//porém o brilho do led só deve ser atualizado quando um botão for pressionado.

const int entrada1 = A0;
const int botao = 2;
const int led1 = 13;


void setup() {
	pinMode(led1, OUTPUT);
  	pinMode(botao, INPUT);	
}

void loop() {
  
    bool botaoPressionado = digitalRead(botao) == HIGH; 
    int valor1 = analogRead(entrada1);
  
  if (botaoPressionado) {
    int brilhoLed = map(valor1, 0, 1023, 0, 255); 
	analogWrite(led1, brilhoLed);
  }
}