#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <WiFi.h>

#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883 // use 8883 for SSL
#define AIO_USERNAME "pawangoyal725"
#define AIO_KEY "e2e231f28fe545458013e0306bc95bba"

class Mqtt
{
  private:
  public:
    Mqtt(/* args */);
    ~Mqtt();

    void SendData(String data)
    {
        WiFiClient client;

        Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

        Adafruit_MQTT_Publish accident = Adafruit_MQTT_Publish(&mqtt,  AIO_USERNAME "/feeds/college.accident");
        Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt,  AIO_USERNAME "/feeds/college.bike");

        int8_t ret;

        // Stop if already connected.
        if (mqtt.connected())
        {
            //return;
        }
        else
        {
            Serial.print("Connecting to MQTT... ");

            uint8_t retries = 3;
            while ((ret = mqtt.connect()) != 0)
            { // connect will return 0 for connected
                Serial.println(mqtt.connectErrorString(ret));
                Serial.println("Retrying MQTT connection in 5 seconds...");
                mqtt.disconnect();
                delay(5000); // wait 5 seconds
                retries--;
                if (retries == 0)
                {
                    // basically die and wait for WDT to reset me
                    while (1)
                        ;
                }
            }
            Serial.println("MQTT Connected!");
        }

        char dataArray[data.length()];
        data.toCharArray(dataArray, data.length());

        if (!photocell.publish(dataArray))
        { 
            Serial.println(F("Failed"));
        }
        else
        {
            accident.publish(100);
            delay(10000);
            accident.publish(0);

            Serial.println(F("OK!"));
        }
    }
};

Mqtt::Mqtt(/* args */)
{
    Serial.println("");
    Serial.println("MQTT started");
}

Mqtt::~Mqtt()
{
}
