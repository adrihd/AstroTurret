#include "otaservice.h"
#include <SPIFFS.h>

OTAService::OTAService()
{
    _running = false;
    otaserver = new AsyncWebServer(CFG_OTASERVICE_PORT);
    Serial.println("OTASERVICE: Initializing...");
}

void CustomOnStart(NSPrettyOTA::UPDATE_MODE updateMode) {
    if(updateMode == NSPrettyOTA::UPDATE_MODE::FILESYSTEM)
    {
        // Unmount SPIFFS filesystem here
        SPIFFS.end();
    }
}

void OTAService::Start()
{
    if (!_running)
    {
        OTAUpdates.Begin(otaserver, CFG_OTASERVICE_USERNAME, CFG_OTASERVICE_PWD);
        OTAUpdates.SetHardwareID(CFG_OTASERVICE_HWID);
        OTAUpdates.SetAppVersion(CFG_BUILD_VERSION);
        OTAUpdates.SetAppBuildTimeAndDate(CFG_BUILD_TIME, CFG_BUILD_DATE);
        OTAUpdates.OnStart(CustomOnStart);
        otaserver->begin();
        Serial.println("OTASERVICE: Running...");
        _running = true;
    }
}

void OTAService::Stop()
{
    if (_running)
    {
        otaserver->end();
        _running = false;
        Serial.println("OTASERVICE: Stopped...");

    }
}
