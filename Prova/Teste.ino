// Definição das portas analógicas para os potenciômetros
const int entrada1 = A0;
const int entrada2 = A1;

// Definição das portas digitais para os botões
const int botao1 = 2;   
const int botao2 = 3;   

// Definição das portas para os LEDs
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

// Variável para armazenar o último estado do botão 2
bool ultimoEstadoBotao = LOW;

void setup() {
    pinMode(botao1, INPUT);  // Configura botão 1 como entrada
    pinMode(botao2, INPUT);  // Configura botão 2 como entrada
    pinMode(led1, OUTPUT);   // Configura LED 1 como saída
    pinMode(led2, OUTPUT);   // Configura LED 2 como saída
    pinMode(led3, OUTPUT);   // Configura LED 3 como saída
    Serial.begin(9600);      // Inicia a comunicação serial para debug
}

void loop() {
    // Lendo os valores dos potenciômetros
    int valor1 = analogRead(entrada1);
    int valor2 = analogRead(entrada2);

    // Lendo o estado dos botões (pressionado = HIGH, solto = LOW)
    bool estadoBotao1 = digitalRead(botao1) == HIGH;
    bool estadoBotao2 = digitalRead(botao2) == HIGH;

    // Mapeia os valores lidos dos potenciômetros para controle PWM dos LEDs
    int brilhoLed = map(valor1, 0, 1023, 0, 255); 
    analogWrite(led1, brilhoLed);

    int brilhoLed2 = map(valor2, 0, 1023, 0, 255); 
    analogWrite(led2, brilhoLed2);

    // Se o botão 1 for pressionado, acende o LED 3
    if (estadoBotao1 == HIGH) {
        digitalWrite(led3, HIGH);
    } else {
        digitalWrite(led3, LOW);
    }

    // Se o botão 2 for pressionado e antes estava solto, faz o LED 3 piscar 4 vezes
    if (estadoBotao2 == HIGH && ultimoEstadoBotao == LOW) {
        digitalWrite(led3, HIGH);
        delay(200);
        digitalWrite(led3, LOW);
        delay(200);
        digitalWrite(led3, HIGH);
        delay(200);
        digitalWrite(led3, LOW);
        delay(200);
    }

    // Atualiza o estado anterior do botão 2 para detectar futuras mudanças
    ultimoEstadoBotao = estadoBotao2;

    // Exibe informações no Serial Monitor para depuração
    Serial.print("Botao 1: ");
    Serial.print(estadoBotao1 == HIGH ? " Pressionado" : " Solto");
    Serial.println(); 
    
    Serial.print("Botao 2: ");
    Serial.print(estadoBotao2 == HIGH ? " Pressionado" : " Solto");
    Serial.println(); 
    
    Serial.print("Valor Potenciometro1: ");
    Serial.print(valor1);
    Serial.println(); 
    
    Serial.print("Valor Potenciometro2: ");
    Serial.print(valor2);
    Serial.println();
}
