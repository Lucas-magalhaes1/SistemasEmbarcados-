#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String entrada = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pronto para uso");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      if (entrada.startsWith("@CMD")) {
        String msg = entrada.substring(4);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(msg.substring(0, 16));
        if (msg.length() > 16) {
          lcd.setCursor(0, 1);
          lcd.print(msg.substring(16, 32));
        }
      } else {
        int pos1 = entrada.indexOf(',');
        int pos2 = entrada.indexOf(',', pos1 + 1);
        if (pos1 > 0 && pos2 > pos1) {
          String reais = entrada.substring(0, pos1);
          String tipo = entrada.substring(pos1 + 1, pos2);
          String convertido = entrada.substring(pos2 + 1);

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("R$" + reais);
          lcd.setCursor(0, 1);
          lcd.print(tipo + ": " + convertido);
        }
      }
      entrada = "";
    } else {
      entrada += c;
    }
  }
}
