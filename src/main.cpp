#include <Arduino.h>
#include <Elog.h>

#include "astroturret_config.h"
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <WiFi.h>
#include "otaservice.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "string.h"
#include "nvs.h"
#include "nvs_flash.h"
#include <sys/socket.h>

#include "esp_wifi.h"
#include <Stepper.h>
#include "panner.h"
#include "RGBLEDService.h"
#include "utilities.h"

const char *WIFI_SSID = CFG_WIFI_SSID;
const char *WIFI_PASSWORD = CFG_WIFI_PWD;
const char *WIFI_HOSTNAME = CFG_WIFI_HOSTNAME;

Panner *panner;
OTAService *otaservice;
RGBLEDService *rgbLedService;

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting");
  rgbLedService = new RGBLEDService();
  rgbLedService->ShowLEDColor(CRGB::Orange);
  WiFi.mode(WIFI_STA);
  WiFi.setHostname(WIFI_HOSTNAME);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    rgbLedService->ShowLEDColor(CRGB::Red);
    Serial.println("WIFI: Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  rgbLedService->ShowLEDColor(CRGB::Blue);
  Serial.println("WIFI: Connected: " + WiFi.localIP().toString());
  
  panner = new Panner();
  
  otaservice = new OTAService();
  otaservice->Start();

  rgbLedService->ShowLEDColor(CRGB::Green);

}

void loop()
{

}
