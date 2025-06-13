#ifndef WIFIOTA_H
#define WIFIOTA_H
#include <Arduino.h>
#include "astroturret_config.h"
#include <PrettyOTA.h>


#pragma once
class OTAService
{
public:
OTAService();
void Start();
void Stop();
bool IsRunning();

private:
bool _running;
AsyncWebServer *otaserver;
PrettyOTA OTAUpdates;




};

#endif //WIFIOTA_H