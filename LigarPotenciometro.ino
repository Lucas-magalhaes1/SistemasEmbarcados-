int pot;        //Ligar Potenciometro com 3 leds e ligar e dislar eles conforme gira ele 

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  pot=analogRead(A0);
  Serial.println(pot);

  if(pot>=0 and pot<255){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }

  if(pot>=255 and pot<512){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }

  if(pot>=512 and pot<767){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
  }
 
  if(pot>=767){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
  }

}
