  float pot;
  float volt;

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    pot=analogRead(A0);
    volt=map(pot,0,1023,0,50);

    for(int i=0;i<volt;i++){
      Serial.print(" ");
    }
    Serial.println("*");
  }
