#include <VirtualWire.h>

const int ATAD =12; //rf
const int helment = 8; //btn

char* data;

bool isHelmentWere();

void setup()
{
    Serial.begin(9600);

    Serial.print("Sending");
    vw_set_ptt_inverted(true);
    vw_set_tx_pin(ATAD);
    vw_setup(2000);
    pinMode(helment,INPUT);
    data = "-1";
    sendData();

    Serial.print("Sent");
}

void sendData()
{
    Serial.println(data);
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
}

void loop()
{
    if(isHelmentWere())
    {
        data="1";
    }
    else
    {
        data="0";
    }
    sendData();

    delay(100);
}

bool isHelmentWere()
{
    return digitalRead(helment);
}
