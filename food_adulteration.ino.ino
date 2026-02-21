#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PH 34
#define GAS 35

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Food Quality");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");
  delay(2000);
  lcd.clear();
}

void loop() {
  int phRaw = analogRead(PH);
  int gasRaw = analogRead(GAS);

  float phVal = map(phRaw, 0, 4095, 0, 14);
  int gasVal = map(gasRaw, 0, 4095, 0, 3000);

  lcd.setCursor(0,0);
  lcd.print("pH:");
  lcd.print(phVal,1);
  lcd.print(" Gas:");
  lcd.print(gasVal);

  lcd.setCursor(0,1);

  if(phVal < 6.5 || phVal > 7.5 || gasVal > 1500) {
    lcd.print("ADULTERATED ");
  } else {
    lcd.print("PURE FOOD   ");
  }

  delay(1000);
}
