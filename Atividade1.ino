void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(400);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(400);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  delay(400);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(400);
}

//Liguei 2 LEDS e dei instruções de LIGADO/DESLIGADO
