#include "./lib/WifiConnect.h"
#include "./lib/simpleGps.h"
#include "./lib/Mqtt.h"
#include "./lib/motion.h"

WifiConnect wifi = WifiConnect("Pawan", "pawangoyal725");
simpleGps gps;
Mqtt MqttServer;
motion motion(19);

void setup()
{
    Serial.begin(115200);
    wifi.Connect();
    motion.init();
}

void loop()
{
    if (motion.isMotion())
    {
        Serial.println("Hila");
        String loc = gps.GetLocation();
        Serial.println(loc);
        MqttServer.SendData(loc);
    }
}