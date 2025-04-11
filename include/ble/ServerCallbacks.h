#ifndef SERVERCALLBACKS_H
#define SERVERCALLBACKS_H

#include <Arduino.h>
#include <NimBLEDevice.h>

class ServerCallbacks : public NimBLEServerCallbacks
{
  void onConnect(NimBLEServer *pServer, NimBLEConnInfo &connInfo) override;

  void onDisconnect(NimBLEServer *pServer, NimBLEConnInfo &connInfo, int reason) override;

  void onMTUChange(uint16_t MTU, NimBLEConnInfo &connInfo) override;

  /********************* Security handled here *********************/
  uint32_t onPassKeyDisplay() override;
  
  void onConfirmPassKey(NimBLEConnInfo &connInfo, uint32_t pass_key) override;

  void onAuthenticationComplete(NimBLEConnInfo &connInfo) override;
  
} serverCallbacks;

#endif