#include <Arduino.h>
#include <ble/DescriptorCallbacks.h>

void DescriptorCallbacks::onWrite(NimBLEDescriptor *pDescriptor, NimBLEConnInfo &connInfo)
{
    std::string dscVal = pDescriptor->getValue();
    Serial0.printf("Descriptor written value: %s\n", dscVal.c_str());
}

void DescriptorCallbacks::onRead(NimBLEDescriptor *pDescriptor, NimBLEConnInfo &connInfo)
{
    Serial0.printf("%s Descriptor read\n", pDescriptor->getUUID().toString().c_str());
}