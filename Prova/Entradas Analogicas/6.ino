//O objeivo deste exercício é criar um programa para Arduino que lê os valores de duas entradas 
//analógicas e exibe o resultado no monitor serial.

const int entrada1 = A0; // Primeiro potenciômetro ou sensor analógico
const int entrada2 = A1; // Segundo potenciômetro ou sensor analógico

void setup() {
    Serial.begin(9600); // Inicia a comunicação serial a 9600 bps
}

void loop() {
    int valor1 = analogRead(entrada1); // Lê o valor da entrada A0
    int valor2 = analogRead(entrada2); // Lê o valor da entrada A1

    Serial.print("Entrada 1: ");
    Serial.print(valor1);
    Serial.print(" | Entrada 2: ");
    Serial.println(valor2); // O println pula para a próxima linha no monitor serial

    delay(500); // Pequeno atraso para facilitar a leitura no serial
}