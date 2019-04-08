#include "./lib/WifiConnect.h"
#include "./lib/simpleGps.h"

WifiConnect wifi = WifiConnect("Ankur", "youCANhack1");

void setup()
{
    Serial.begin(115200);
    wifi.Connect();
}

void loop()
{
}