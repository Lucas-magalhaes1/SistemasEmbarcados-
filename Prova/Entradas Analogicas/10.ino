//Faça um led que piscará com um intervalo correspondente a leitura de uma porta analógica. 
//map(valor, minimo_entrada, maximo_entrada, minimo_saida, maximo_saida)

const int entrada1 = A0; // Potenciômetro
const int led1 = 13;     // LED

void setup() {
    pinMode(led1, OUTPUT);
}

void loop() {
    int valorAnalogico = analogRead(entrada1); // Lê o potenciômetro
    int intervalo = map(valorAnalogico, 0, 1023, 100, 2000); // Mapeia o valor para o intervalo de piscar

    digitalWrite(led1, HIGH); // Liga o LED
    delay(intervalo);         // Espera conforme o valor lido
    digitalWrite(led1, LOW);  // Desliga o LED
    delay(intervalo);         // Espera novamente para completar o ciclo
}
