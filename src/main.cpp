#include <Arduino.h>
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
#include "utilities.h"

const char *WIFI_SSID = CFG_WIFI_SSID;
const char *WIFI_PASSWORD = CFG_WIFI_PWD;
const char *WIFI_HOSTNAME = CFG_WIFI_HOSTNAME;

Panner *panner;
OTAService *otaservice;

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting XXX");

  WiFi.mode(WIFI_STA);
  WiFi.setHostname(WIFI_HOSTNAME);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WIFI: Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  
  Serial.println("WIFI: Connected: " + WiFi.localIP().toString());
  
  panner = new Panner();
  
  otaservice = new OTAService();
  otaservice->Start();

}

// BLE OTA Removed
// vTask: BLE Polling
// #define TASK_POLL_BLE_STACK_SIZE  2048
// TaskHandle_t poll_ble_task_handle = NULL;
// void task_poll_ble(void *pvParameters)
// {
//   vTaskDelay(2000 / portTICK_PERIOD_MS);
//   if (pServer->getConnectedCount())
//   {
//     NimBLEService *pSvc = pServer->getServiceByUUID("BAAD");
//     if (pSvc)
//     {
//       NimBLECharacteristic *pChr = pSvc->getCharacteristic("F00D");
//       if (pChr)
//       {
//         pChr->notify();
//       }
//     }
//   }
// }
// BLE OTA Removed

void loop()
{

  // BLE OTA Removed
  // if (!poll_ble_task_handle) {
  //   xTaskCreate(task_poll_ble, "task_poll_ble", TASK_POLL_BLE_STACK_SIZE, NULL, tskIDLE_PRIORITY, &poll_ble_task_handle);
  // }
  // BLE OTA Removed
}
