#ifndef DESCRIPTORCALLBACKS_H
#define DESCRIPTORCALLBACKS_H

#include <Arduino.h>
#include <NimBLEDevice.h>

class DescriptorCallbacks : public NimBLEDescriptorCallbacks
{
  void onWrite(NimBLEDescriptor *pDescriptor, NimBLEConnInfo &connInfo) override;

  void onRead(NimBLEDescriptor *pDescriptor, NimBLEConnInfo &connInfo) override;
  
} dscCallbacks;


#endif