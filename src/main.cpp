#include <Arduino.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <WiFi.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "esp_http_client.h"
#include "esp_https_ota.h"
#include "string.h"
#include "nvs.h"
#include "nvs_flash.h"
#include <sys/socket.h>

#include "esp_wifi.h"
#include <Stepper.h>
#include "panner.h"
#include "utilities.h"

#include <ble/ServerCallbacks.h>
#include <ble/CharacteristicCallbacks.h>
#include <ble/DescriptorCallbacks.h>


static NimBLEServer *pServer;

const char *WIFI_SSID = "36ED Hyperoptic Fibre Broadband";
const char *WIFI_PASSWORD = "ZEKyWau2LSDw";
const char *WIFI_HOSTNAME = "AstroCam";

Panner *panner;


void setup()
{

  Serial0.begin(115700);
  Serial0.println("Booting");

  WiFi.mode(WIFI_STA);
  WiFi.setHostname(WIFI_HOSTNAME);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial0.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  Serial0.println("HTTP server started");
  panner = new Panner();
  panner->SetSpeed(Panner::PannerSpeed::SP_FAST);

  // NimBLEDevice::init("AstroTurret");
  // NimBLEDevice::setSecurityAuth(BLE_SM_PAIR_AUTHREQ_SC);
  // pServer = NimBLEDevice::createServer();
  // pServer->setCallbacks(&serverCallbacks);
  // NimBLEService *pDeadService = pServer->createService("DEAD");
  // NimBLECharacteristic *pBeefCharacteristic =
  //     pDeadService->createCharacteristic("BEEF",
  //                                        NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE |
  //                                            /** Require a secure connection for read and write access */
  //                                            NIMBLE_PROPERTY::READ_ENC | // only allow reading if paired / encrypted
  //                                            NIMBLE_PROPERTY::WRITE_ENC  // only allow writing if paired / encrypted
  //     );
  // pBeefCharacteristic->setValue("Burger");
  // pBeefCharacteristic->setCallbacks(&chrCallbacks);

  // NimBLE2904 *pBeef2904 = pBeefCharacteristic->create2904();
  // pBeef2904->setFormat(NimBLE2904::FORMAT_UTF8);
  // pBeef2904->setCallbacks(&dscCallbacks);

  // NimBLEService *pBaadService = pServer->createService("BAAD");
  // NimBLECharacteristic *pFoodCharacteristic =
  //     pBaadService->createCharacteristic("F00D", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY);

  // pFoodCharacteristic->setValue("Fries");
  // pFoodCharacteristic->setCallbacks(&chrCallbacks);

  // NimBLEDescriptor *pC01Ddsc =
  //     pFoodCharacteristic->createDescriptor("C01D",
  //                                           NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::WRITE_ENC,
  //                                           20);
  // pC01Ddsc->setValue("Send it back!");
  // pC01Ddsc->setCallbacks(&dscCallbacks);

  // /** Start the services when finished creating all Characteristics and Descriptors */
  // pDeadService->start();
  // pBaadService->start();

  // NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  // pAdvertising->setName("NimBLE-Server");
  // pAdvertising->addServiceUUID(pDeadService->getUUID());
  // pAdvertising->addServiceUUID(pBaadService->getUUID());

  // pAdvertising->enableScanResponse(true);
  // pAdvertising->start();
}

// vTask: BLE Polling
#define TASK_POLL_BLE_STACK_SIZE  2048
TaskHandle_t poll_ble_task_handle = NULL;
void task_poll_ble(void *pvParameters)
{
  vTaskDelay(2000 / portTICK_PERIOD_MS);
  if (pServer->getConnectedCount())
  {
    NimBLEService *pSvc = pServer->getServiceByUUID("BAAD");
    if (pSvc)
    {
      NimBLECharacteristic *pChr = pSvc->getCharacteristic("F00D");
      if (pChr)
      {
        pChr->notify();
      }
    }
  }
}

void loop()
{

  if (!poll_ble_task_handle) {
    xTaskCreate(task_poll_ble, "task_poll_ble", TASK_POLL_BLE_STACK_SIZE, NULL, tskIDLE_PRIORITY, &poll_ble_task_handle);
  }


}
