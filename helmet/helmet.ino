#include <VirtualWire.h>

const int ATAD =12;

char* data;

bool isHelmentWere();

void setup()
{
    vw_set_ptt_inverted(true);
    vw_set_tx_pin(12);
    vw_setup(2000);
}

void sendData()
{
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(2000);
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
    sendData()

    delay(100);
}
