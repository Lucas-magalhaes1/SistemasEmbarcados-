float pot;  // variável para armazenar o valor da leitura
float voltage;  // variável para armazenar a tensão
float temperatureC;  // variável para armazenar a temperatura em Celsius
int ledPin = 9;  // pino digital onde o LED está conectado

void setup() {
  Serial.begin(9600);  // inicializa a comunicação serial
  pinMode(ledPin, OUTPUT);  // configura o pino do LED como saída
}

void loop() {
  pot = analogRead(A1);  // lê o valor analógico do LM35
  
  // Converte o valor lido para uma tensão (considerando a referência de 5V)
  voltage = pot * (5.0 / 1023.0);
  
  // Converte a tensão para temperatura em Celsius
  temperatureC = voltage * 100.0;  // 10mV por grau Celsius, então multiplicamos por 100
  
  // Imprime a temperatura em Celsius
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // Controle do LED baseado na temperatura
  if (temperatureC > 25.0) {
    digitalWrite(ledPin, HIGH);  // Acende o LED se a temperatura for maior que 25°C
  } else if (temperatureC <= 25.0) {
    digitalWrite(ledPin, LOW);  // Apaga o LED se a temperatura for 24°C ou menor
  }
  
  delay(1000);  // Aguarda 1 segundo antes de fazer a próxima leitura
}
