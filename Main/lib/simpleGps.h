#include <TinyGPS++.h>
class simpleGps
{
  private:
    HardwareSerial ss = HardwareSerial(2);

    static const int RXPin = 16, TXPin = 17;
    static const uint32_t GPSBaud = 9600;
    TinyGPSPlus gps;

    String displayInfo()
    {
        String res = "Location:";
        if (gps.location.isValid())
        {
            res += gps.location.lat();
            res += ",";
            res += gps.location.lng();
        }
        else
        {
            res += "INVALID";
        }
        res += " Time:";
        if (gps.time.isValid())
        {
            if (gps.time.hour() < 10)
                res += "0";
            res += gps.time.hour();
            res += ":";
            if (gps.time.minute() < 10)
                res += "0";
            res += gps.time.minute();
            res += ":";
            if (gps.time.second() < 10)
                res += "0";
            res += gps.time.second();
            res += ".";
        }
        else
        {
            res += "INVALID";
        }
        return res;
    }

  public:
    simpleGps();
    ~simpleGps();
    String GetLocation();
};

String simpleGps::GetLocation()
{
    String res = "";

    while (res == "")
    {
        //to really clear buffer
        for (int i = 0; i < 3; i++)
        {
            // to clear buffer
            while (ss.available() > 0)
            {
                ss.read();
            }
            delay(10);
        }

        delay(100); //to get latest values

        // start reading values
        while (ss.available() > 0)
            if (gps.encode(ss.read()))
                res = displayInfo();
    }

    return res;
}

simpleGps::simpleGps()
{
    Serial.println("");
    Serial.println("Gps Started");

    ss = HardwareSerial(2);
    ss.begin(GPSBaud);
}

simpleGps::~simpleGps()
{
    Serial.println();
    Serial.println("Gps destroyed");
}
