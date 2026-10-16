#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte run1[8] = {0b00110,0b00110,0b00100,0b01110,0b10101,0b00100,0b01010,0b10001};
byte run2[8] = {0b00110,0b00110,0b00100,0b01110,0b00100,0b00100,0b01010,0b01010};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, run1);
  lcd.createChar(1, run2);
  lcd.setCursor(0, 1);
  lcd.print("Hello");
}

void loop() {
  for (int x = 0; x < 16; x++) {
    if (x > 0) { lcd.setCursor(x - 1, 0); lcd.print(" "); }  // erase old spot
    lcd.setCursor(x, 0);
    lcd.write(x % 2);          // alternate the two frames
    delay(150);
  }
  lcd.setCursor(15, 0);
  lcd.print(" ");
}