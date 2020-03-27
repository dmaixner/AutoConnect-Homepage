#include "SetupPortal.h"

SetupPortal::SetupPortal() : _portal(_httpServer)
{
}

SetupPortal::~SetupPortal()
{
}

void SetupPortal::setupPortal()
{
    ESP8266HTTPUpdateServer httpUpdate;
    AutoConnectAux update("/update", AUTOCONNECT_MENULABEL_UPDATE);

    httpUpdate.setup(&_httpServer);
    _portal.load(FPSTR(L_PORTAL_PAGES_P));
    _portal.join({update});

    AutoConnectConfig config;
    config.homeUri = "/";
    config.bootUri = AC_ONBOOTURI_HOME;
    config.apip = IPAddress(10, 0, 0, 1);
    config.gateway = IPAddress(10, 0, 0, 1);
    config.apid = "WT-" + String(ESP.getChipId());
    config.title = config.apid;

    config.immediateStart = true;
    config.portalTimeout = 120000;
    config.autoReconnect = false;
    config.ticker = false;
    _portal.config(config);
    if (_portal.begin())
    {
        Serial.println("client used portal, connection successful");
    }

    int count = 0;
    while (count < 60 && WiFi.softAPgetStationNum() > 0)
    {
        count++;
        Serial.println("handling client, closing in " + String(60 - count));
        _portal.handleClient();
        delay(1000);
    }

    Serial.println("closing portal");
    _portal.end();
    delay(1000);
    WiFi.mode(WIFI_STA);
}
