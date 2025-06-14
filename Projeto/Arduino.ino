#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

/* ---------- LCD ---------- */
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* ---------- Keypad 4×4 ---------- */
const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};   // linhas
byte colPins[COLS] = {5, 4, 3, 2};   // colunas
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* ---------- Estados ---------- */
enum State { SHOW_DECISION, ENTER_VALUE, SELECT_CURR, WAIT_RESULT, RESULT_MENU };
State state = SHOW_DECISION;

/* ---------- Variáveis ---------- */
String valorTxt, moeda, lastL1, lastL2;
uint8_t cotacoesMostradas = 0;
bool digitando = false;

/* ---------- Utilidades de Tela ---------- */
void showDecision() {
  lcd.clear();
  lcd.print("A=Repetir");
  lcd.setCursor(0,1);
  lcd.print("B=Converter");
  state = SHOW_DECISION;
}

void askValue() {
  lcd.clear();
  lcd.print("Valor em reais:");
  lcd.setCursor(0,1);
  lcd.print("Confirme com A");
  digitando = false;
}

void askCurrency() {
  lcd.clear();
  lcd.print("Moeda:");
  lcd.setCursor(0,1);
  lcd.print("A:USD B:EUR C:BTC");
}

void resultMenu() {
  lcd.clear();
  lcd.print("A=Conv de novo");
  lcd.setCursor(0,1);
  lcd.print("B=Mostrar");
  state = RESULT_MENU;
}

/* ---------- Setup ---------- */
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Aguardando API...");
}

/* ---------- Loop ---------- */
void loop() {
  /* ---- 1. Ler Serial -------------------------------- */
  static String sIn = "";
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {

      /* 1A. Mensagens @CMD só no menu inicial --------- */
      if (sIn.startsWith("@CMD") && state == SHOW_DECISION) {
        String msg = sIn.substring(4);
        lcd.clear();
        lcd.print(msg.substring(0,16));
        if (msg.length() > 16) {
          lcd.setCursor(0,1);
          lcd.print(msg.substring(16,32));
        }

        /* Contar USD/EUR/BTC para mostrar menu A/B */
        if (msg.indexOf("USD:")!=-1 || msg.indexOf("EUR:")!=-1 ||
            msg.indexOf("BTC:")!=-1) {
          cotacoesMostradas++;
          if (cotacoesMostradas == 3) {
            delay(4000);            // ← agora 4 s antes do menu
            showDecision();
            cotacoesMostradas = 0;
          }
        }
      }

      /* 1B. Resultado da conversão -------------------- */
      else {
        int p1 = sIn.indexOf(','),
            p2 = (p1!=-1) ? sIn.indexOf(',', p1+1) : -1;
        if (p1!=-1 && p2!=-1) {
          lastL1 = "R$" + sIn.substring(0,p1);
          lastL2 = sIn.substring(p1+1,p2) + ": " + sIn.substring(p2+1);

          lcd.clear(); lcd.print(lastL1);
          lcd.setCursor(0,1); lcd.print(lastL2);

          delay(5000);              // 5 s visível
          resultMenu();
        }
      }
      sIn = "";
    } else sIn += c;
  }

  /* ---- 2. Teclado ----------------------------------- */
  char key = kpd.getKey();
  if (!key) return;

  switch (state) {
    /* ---- menu A/B ---------------------------------- */
    case SHOW_DECISION:
      if (key == 'A')              Serial.println("REQ_QUOTES");
      else if (key == 'B')         { askValue(); valorTxt=""; state=ENTER_VALUE; }
      break;

    /* ---- digitar valor ----------------------------- */
    case ENTER_VALUE:
      if (key>='0' && key<='9') {
        if (!digitando) {
          lcd.setCursor(0,1); lcd.print("                ");
          lcd.setCursor(0,1); digitando = true;
        }
        valorTxt += key; lcd.print(key);
      }
      else if (key=='*' && valorTxt.indexOf('.')==-1) {
        if (!digitando) {
          lcd.setCursor(0,1); lcd.print("                ");
          lcd.setCursor(0,1); digitando = true;
        }
        valorTxt += '.'; lcd.print('.');
      }
      else if (key=='A' && valorTxt.length()) { askCurrency(); state=SELECT_CURR; }
      else if (key=='D') showDecision();
      break;

    /* ---- selecionar moeda -------------------------- */
    case SELECT_CURR:
      if (key=='A'||key=='B'||key=='C') {
        moeda = (key=='A')?"USD":(key=='B')?"EUR":"BTC";
        Serial.println(valorTxt + "," + moeda);
        lcd.clear(); lcd.print("Aguardando...");
        state = WAIT_RESULT;
      } else if (key=='D') showDecision();
      break;

    /* ---- aguardando PC ----------------------------- */
    case WAIT_RESULT:
      /* nada a fazer */
      break;

    /* ---- menu pós resultado ------------------------ */
    case RESULT_MENU:
      if (key=='A') showDecision();
      else if (key=='B') {
        lcd.clear(); lcd.print(lastL1);
        lcd.setCursor(0,1); lcd.print(lastL2);
        delay(5000);
        resultMenu();
      }
      break;
  }
}
