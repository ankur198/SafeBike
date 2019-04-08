#include <SoftwareSerial.h>

class simpleGps
{
private:
    SoftwareSerial ss = SoftwareSerial(10,11);
    static const uint32_t GPSBaud = 9600;
public:
    simpleGps(int RXPin,int TXPin);
    simpleGps(){};
    ~simpleGps();
};

simpleGps::simpleGps(int RXPin,int TXPin)
{
    ss =  SoftwareSerial(RXPin,TXPin);
    ss.begin(GPSBaud);
}

simpleGps::~simpleGps()
{
    Serial.println();
    Serial.println("Gps destroyed");
}
