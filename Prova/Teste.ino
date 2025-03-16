void setup() {
    // Configuração dos LEDs como saída
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);

    // Configuração dos botões como entrada com pull-up interno
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);

    // Inicializa a comunicação serial para depuração
    Serial.begin(9600);
}

void loop() {
    Serial.println("=== TESTE INICIADO ===");

    // Teste dos LEDs - Acender e apagar um por um
    Serial.println("Testando LEDs...");
    for (int i = 11; i <= 13; i++) {
        digitalWrite(i, HIGH);
        delay(500);
        digitalWrite(i, LOW);
    }

    // Teste dos botões - Verifica se estão sendo pressionados
    Serial.println("Testando Botões...");
    int botao1 = digitalRead(2);
    int botao2 = digitalRead(3);

    if (botao1 == LOW) Serial.println("Botão 1 pressionado!");
    else Serial.println("Botão 1 solto.");

    if (botao2 == LOW) Serial.println("Botão 2 pressionado!");
    else Serial.println("Botão 2 solto.");

    // Teste dos potenciômetros - Lê os valores e mostra no serial
    int pot1 = analogRead(A0);
    int pot2 = analogRead(A1);

    Serial.print("Potenciômetro 1: ");
    Serial.println(pot1);
    Serial.print("Potenciômetro 2: ");
    Serial.println(pot2);

    Serial.println("=====================");
    delay(1000); // Aguarda 1 segundo antes do próximo teste
}
