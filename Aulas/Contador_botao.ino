// Declaração de uma variável inteira chamada 'a', que armazenará o contador
int a;  

void setup() {
  // Inicia a comunicação serial com o computador a uma taxa de 9600 bps
  Serial.begin(9600);  
  
  // Configura o pino 2 como entrada (input)
  pinMode(2, INPUT);   
}

void loop() {
  // Envia o valor da variável 'a' para o monitor serial a cada ciclo de loop
  Serial.println(a);  

  // Verifica se o valor lido no pino 2 é HIGH (geralmente significa que há um sinal de 5V ou 3.3V no pino)
  if (digitalRead(2) == HIGH) {  
    // Se o pino 2 estiver em HIGH, incrementa o valor de 'a' em 1
    a++;  
    
    // Este laço while aguarda até que o pino 2 volte para o estado LOW
    // Ele mantém o Arduino aguardando enquanto o pino 2 permanecer em HIGH
    // A função delay(10) é usada para dar uma pausa de 10 milissegundos antes de continuar a execução
    while (digitalRead(2) == HIGH) { 
      delay(10); // Atraso de 10 milissegundos para evitar múltiplos incrementos por um único pressionamento de botão
    }
  }
}

//Este código incrementa a variável a toda vez que o pino 2 recebe um sinal HIGH (por exemplo, quando um botão é pressionado e o pino 2 é configurado para ser lido como entrada). O código garante que o contador a só seja incrementado uma vez por pressionamento de botão (ao evitar múltiplos incrementos enquanto o pino 2 continuar em HIGH). O valor de a é enviado ao monitor serial a cada ciclo de loop.