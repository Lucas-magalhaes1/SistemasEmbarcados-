//- Ao pressionar: 
//- botão 2 os leds devem "correr" em um sentido.
//- botão 3 os leds devem "correr em sentido contrario.

const int botao1 = 2;   
const int botao2 = 3;   
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

void setup() {
    pinMode(botao1, INPUT);  
    pinMode(botao2, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}

void loop() {
  bool botao1Pressionado = digitalRead(botao1) == HIGH;
  bool botao2Pressionado = digitalRead(botao2) == HIGH;

  if (botao1Pressionado) {
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(200);
    digitalWrite(led3, LOW);
  } 

  else if (botao2Pressionado) {
    digitalWrite(led3, HIGH);
    delay(200);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
  }
}
