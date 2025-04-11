#include <Arduino.h>
#include <ble/BleService.h>
#include <NimBLEDevice.h>

void BleService::Stop() {

}

void BleService::Start() {

}

void BleService::InitBleService(std::string ServiceName)
{
    if (this->IsRunning)
        return;   

    NimBLEDevice::init(ServiceName);
    NimBLEDevice::setSecurityAuth(BLE_SM_PAIR_AUTHREQ_SC);
    pBleServer = NimBLEDevice::createServer();
    pBleServer->setCallbacks(&serverCallbacks);

    NimBLEService *pDeadService = pBleServer->createService("DEAD");
    NimBLECharacteristic *pBeefCharacteristic =
        pDeadService->createCharacteristic("BEEF",
                                           NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE |
                                               /** Require a secure connection for read and write access */
                                               NIMBLE_PROPERTY::READ_ENC | // only allow reading if paired / encrypted
                                               NIMBLE_PROPERTY::WRITE_ENC  // only allow writing if paired / encrypted
        );
    pBeefCharacteristic->setValue("Burger");
    pBeefCharacteristic->setCallbacks(&chrCallbacks);

    NimBLE2904 *pBeef2904 = pBeefCharacteristic->create2904();
    pBeef2904->setFormat(NimBLE2904::FORMAT_UTF8);
    pBeef2904->setCallbacks(&dscCallbacks);

    NimBLEService *pBaadService = pBleServer->createService("BAAD");
    NimBLECharacteristic *pFoodCharacteristic =
        pBaadService->createCharacteristic("F00D", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY);

    pFoodCharacteristic->setValue("Fries");
    pFoodCharacteristic->setCallbacks(&chrCallbacks);

    NimBLEDescriptor *pC01Ddsc =
        pFoodCharacteristic->createDescriptor("C01D",
                                              NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::WRITE_ENC,
                                              20);
    pC01Ddsc->setValue("Send it back!");
    pC01Ddsc->setCallbacks(&dscCallbacks);

    /** Start the services when finished creating all Characteristics and Descriptors */
    pDeadService->start();
    pBaadService->start();

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->setName("NimBLE-Server");
    pAdvertising->addServiceUUID(pDeadService->getUUID());
    pAdvertising->addServiceUUID(pBaadService->getUUID());
  
    pAdvertising->enableScanResponse(true);
    pAdvertising->start();
}

BleService::BleService() {
    IsRunning = false;
}