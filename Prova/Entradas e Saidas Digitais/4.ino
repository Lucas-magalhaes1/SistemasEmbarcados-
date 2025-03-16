//Faça um sistema com um led e três botões. Um led deve iniciar piscando com um intervalo de 1s. Esse intervalo pode ser alterado por dois botões, 
// sendo um deles para aumentar o intervalo em 100ms e o outro para diminuir esse intervalo em 100ms. Ao pressionar o terceiro botão o intervalo deve ser reiniciado para 1s.

const int botao1 = 2;   
const int botao2 = 3;  
const int botao3 = 4;
const int led1 = 13;

int intervaloPiscar = 1000; // Começa piscando a cada 1s

void setup() {
    pinMode(botao1, INPUT);  
    pinMode(botao2, INPUT);
    pinMode(botao3, INPUT);
    pinMode(led1, OUTPUT);
}

void loop() {
  // Lê o estado dos botões
  bool botao1Pressionado = digitalRead(botao1) == HIGH;
  bool botao2Pressionado = digitalRead(botao2) == HIGH;
  bool botao3Pressionado = digitalRead(botao3) == HIGH;

  // Aumenta o intervalo em 100ms
  if (botao1Pressionado) {
    intervaloPiscar += 100;
    delay(200); // Pequeno delay para evitar múltiplas contagens rápidas
  }

  // Diminui o intervalo em 100ms (mínimo 100ms para evitar valores muito baixos)
  if (botao2Pressionado) {
    if (intervaloPiscar > 100) {
      intervaloPiscar -= 100;
    }
    delay(200); 
  }

  // Reseta o intervalo para 1 segundo
  if (botao3Pressionado) {
    intervaloPiscar = 1000;
    delay(200);
  }

  // Faz o LED piscar com o intervalo ajustado
  digitalWrite(led1, HIGH);
  delay(intervaloPiscar);
  digitalWrite(led1, LOW);
  delay(intervaloPiscar);
}


  
  
  