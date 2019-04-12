#include <WiFi.h>

class WifiConnect
{
  private:
    char *ssid;
    char *password;

  public:
    WifiConnect(char *SSID, char *Password);
    ~WifiConnect();

    bool isConnected()
    {
        return WiFi.status() == WL_CONNECTED;
    }
    void Connect();
};

WifiConnect::WifiConnect(char *SSID, char *Password)
{
    ssid = SSID;
    password = Password;
}

WifiConnect::~WifiConnect()
{
    Serial.println();
    Serial.println("Wifi closed...");
}

void WifiConnect::Connect()
{
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}