
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

byte S_Mode[] = {B00111, B01100, B11000, B11000, B11000, B11000, B01100, B00111};

byte O_Lock[] = {B01110, B10001, B10001, B00001, B11111, B11011, B11011, B11111};

byte wrong[] = {B00000, B10001, B11011, B01110, B01110, B11011, B10001, B00000};

byte Check[] = {B00000, B00001, B00011, B10110, B11100, B01000, B00000, B00000};

void setup()
{

  lcd.begin(16, 2);
  lcd.createChar(0, S_Mode);
  lcd.createChar(1, O_Lock);
  lcd.createChar(2, wrong);
  lcd.createChar(3, Check);
}

void loop()
{
  lcd_stdby();
  delay(1500);
  lcd_wrg();
  delay(1500);
  lcd_chk();
  delay(1500);
  lcd_olock();
  delay(1500);
}

void lcd_stdby()
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Stand_By");             //Return to standby mode it's the message do display when waiting
  lcd.setCursor(12, 0);
  lcd.write(0);
}

void  lcd_wrg()
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Wrong Code");
  lcd.setCursor(8, 1);
  lcd.write(2);
}

void  lcd_chk()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Code Changed !");
  lcd.setCursor(8, 1);
  lcd.write(3);
}

void  lcd_olock()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Welcome Back");
  lcd.setCursor(8, 1);
  lcd.write(1);
}
