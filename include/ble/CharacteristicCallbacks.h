#ifndef CHARACTERISTICSCALLBACKS_H
#define CHARACTERISTICSCALLBACKS_H

#include <Arduino.h>
#include <NimBLEDevice.h>

class CharacteristicCallbacks : public NimBLECharacteristicCallbacks
{
  void onRead(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo) override;

  void onWrite(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo) override;

  /**
   *  The value returned in code is the NimBLE host return code.
   */
  void onStatus(NimBLECharacteristic *pCharacteristic, int code) override;

  /** Peer subscribed to notifications/indications */
  void onSubscribe(NimBLECharacteristic *pCharacteristic, NimBLEConnInfo &connInfo, uint16_t subValue) override;

} chrCallbacks;

#endif