void setup() {
    pinMode(2,INPUT); 
    pinMode(13,OUTPUT);
  }
  
  void loop() {
    if(digitalRead(2)==HIGH){  
      digitalWrite(13,HIGH);
    }
    if(digitalRead(2)==LOW){  
      digitalWrite(13,LOW);
    }
  
    //delay(3000); Se usar delay com codigo de botão tem que segurar o botão se possivel nao usar com botão 
  }