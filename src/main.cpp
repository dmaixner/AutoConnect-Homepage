#include <Arduino.h>
#include "SetupPortal.h"

SetupPortal setupPortal;

void setup()
{
    Serial.begin(9600);
    delay(2000);

    setupPortal.setupPortal();
}

void loop()
{
    if (!WiFi.isConnected())
    {
        Serial.println("WiFi disconnected");
    }

    delay(1000);
}
