#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();                      
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("pressCnt: ");
  lcd.setCursor(0,1);
  lcd.print(0);
}
void loop() {
  if (Serial.available()) {
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("pressCnt: ");
    lcd.setCursor(0,1);
    while(Serial.available()){
      char inc = Serial.read();
      if(inc != '\n') lcd.write(inc);
    }
  }

}
