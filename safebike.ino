#include <LiquidCrystal.h>
#include <VirtualWire.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int bikeMotor = 7;
const int dataPin = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String data;

void readyStartBike();
void stopBike();

void setup()
{
  lcd.begin(16, 2);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(dataPin);
  vw_setup(2000);
  vw_rx_start();
  pinMode(bikeMotor, OUTPUT);

  lcd.print("Connecting..");
  readData();
}

void loop()
{

  lcd.clear();
  lcd.print("hello, biker!");
  lcd.setCursor(0, 1);

  readData();
  if (data == "1")
  {
    readyStartBike();
  }

  else
  {
    stopBike();
  }
  delay(1000);
}

void readyStartBike()
{
  lcd.print("lets go");
  digitalWrite(bikeMotor, HIGH);
}

void stopBike()
{
  lcd.print("helmet please!");
  digitalWrite(bikeMotor, LOW);
}

void readData()
{
  while (true)
  {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      data = (char *)buf;
      break;
    }
  }
}
