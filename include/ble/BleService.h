#ifndef BLESERVICE_H
#define BLESERVICE_H
#include <Arduino.h>
#include <NimBLEDevice.h>
// Callback imports
#include <ble/ServerCallbacks.h> //serverCallbacks
#include <ble/CharacteristicCallbacks.h> //chrCallbacks
#include <ble/DescriptorCallbacks.h> //dscCallbacks
#define BLE_SERVICE_NAME "AstroTurret"

class BleService
{
    public:
    static NimBLEServer *pBleServer;
    bool IsRunning;
    void Start();
    void Stop();
    void InitBleService(std::string);
    BleService();
} bleService;


#endif