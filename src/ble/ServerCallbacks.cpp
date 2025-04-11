#include <Arduino.h>
#include <ble/ServerCallbacks.h>

void ServerCallbacks::onConnect(NimBLEServer *pServer, NimBLEConnInfo &connInfo)
{
    Serial0.printf("Client address: %s\n", connInfo.getAddress().toString().c_str());

    /**
     *  We can use the connection handle here to ask for different connection parameters.
     *  Args: connection handle, min connection interval, max connection interval
     *  latency, supervision timeout.
     *  Units; Min/Max Intervals: 1.25 millisecond increments.
     *  Latency: number of intervals allowed to skip.
     *  Timeout: 10 millisecond increments.
     */
    pServer->updateConnParams(connInfo.getConnHandle(), 24, 48, 0, 180);
}

void ServerCallbacks::onDisconnect(NimBLEServer *pServer, NimBLEConnInfo &connInfo, int reason)
{
    Serial0.printf("Client disconnected - start advertising\n");
    NimBLEDevice::startAdvertising();
}

void ServerCallbacks::onMTUChange(uint16_t MTU, NimBLEConnInfo &connInfo)
{
    Serial0.printf("MTU updated: %u for connection ID: %u\n", MTU, connInfo.getConnHandle());
}

/********************* Security handled here *********************/
uint32_t ServerCallbacks::onPassKeyDisplay()
{
    Serial0.printf("Server Passkey Display\n");
    /**
     * This should return a random 6 digit number for security
     *  or make your own static passkey as done here.
     */
    return 123456;
}

void ServerCallbacks::onConfirmPassKey(NimBLEConnInfo &connInfo, uint32_t pass_key)
{
    Serial0.printf("The passkey YES/NO number: %" PRIu32 "\n", pass_key);
    /** Inject false if passkeys don't match. */
    NimBLEDevice::injectConfirmPasskey(connInfo, true);
}

void ServerCallbacks::onAuthenticationComplete(NimBLEConnInfo &connInfo)
{
    /** Check that encryption was successful, if not we disconnect the client */
    if (!connInfo.isEncrypted())
    {
        NimBLEDevice::getServer()->disconnect(connInfo.getConnHandle());
        Serial0.printf("Encrypt connection failed - disconnecting client\n");
        return;
    }

    Serial0.printf("Secured connection to: %s\n", connInfo.getAddress().toString().c_str());
}