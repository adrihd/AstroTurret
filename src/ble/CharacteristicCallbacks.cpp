#include <Arduino.h>
#include <ble/CharacteristicCallbacks.h>

void CharacteristicCallbacks::onRead(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo)
{
    Serial0.printf("%s : onRead(), value: %s\n",
                   pCharacteristic->getUUID().toString().c_str(),
                   pCharacteristic->getValue().c_str());
}

void CharacteristicCallbacks::onWrite(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo)
{
    Serial0.printf("%s : onWrite(), value: %s\n",
                   pCharacteristic->getUUID().toString().c_str(),
                   pCharacteristic->getValue().c_str());
}

/**
 *  The value returned in code is the NimBLE host return code.
 */
void CharacteristicCallbacks::onStatus(NimBLECharacteristic *pCharacteristic, int code)
{
    Serial0.printf("Notification/Indication return code: %d, %s\n", code, NimBLEUtils::returnCodeToString(code));
}

/** Peer subscribed to notifications/indications */
void CharacteristicCallbacks::onSubscribe(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo, uint16_t subValue)
{
    std::string str = "Client ID: ";
    str += connInfo.getConnHandle();
    str += " Address: ";
    str += connInfo.getAddress().toString();
    if (subValue == 0)
    {
        str += " Unsubscribed to ";
    }
    else if (subValue == 1)
    {
        str += " Subscribed to notifications for ";
    }
    else if (subValue == 2)
    {
        str += " Subscribed to indications for ";
    }
    else if (subValue == 3)
    {
        str += " Subscribed to notifications and indications for ";
    }
    str += std::string(pCharacteristic->getUUID());

    Serial0.printf("%s\n", str.c_str());
}
