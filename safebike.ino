#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int helmentWereBtn = 6, bikeMotor = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool checkHelmentWere();
void readyStartBike();
void stopBike();

void setup()
{
  lcd.begin(16, 2);

  pinMode(helmentWereBtn, INPUT);
  pinMode(bikeMotor,OUTPUT);
}

void loop()
{

  lcd.clear();
  lcd.print("hello, biker!");
  lcd.setCursor(0, 1);

  if (checkHelmentWere())
  {
    readyStartBike();
  }

  else
  {
    stopBike();
  }
  delay(1000);
}

bool checkHelmentWere()
{
  return digitalRead(helmentWereBtn);
}

void readyStartBike()
{
  lcd.print("lets go");
  digitalWrite(bikeMotor,HIGH);
}

void stopBike()
{
  lcd.print("helmet please!");
  digitalWrite(bikeMotor,LOW);
}
