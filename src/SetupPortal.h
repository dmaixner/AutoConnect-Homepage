#ifndef _SETUPPORTAL_H_
#define _SETUPPORTAL_H_

#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <AutoConnect.h>
#include "Labels.h"

class SetupPortal
{
public:
    SetupPortal();
    ~SetupPortal();
    void setupPortal();

private:
    ESP8266WebServer _httpServer;
    AutoConnect _portal;
};

#endif