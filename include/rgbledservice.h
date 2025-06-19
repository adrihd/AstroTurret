#ifndef RGBLEDSERVICE_H
#define RGBLEDSERVICE_H
#include <Arduino.h>
#include <FastLED.h>

#define RGBLED_NUM_LEDS     1
#define RGBLED_DATA_PIN     48
// CRGB leds[RGBLED_NUM_LEDS];

class RGBLEDService
{
private:
    /* data */
    CRGB leds[RGBLED_NUM_LEDS];
public:
    RGBLEDService();
    void ShowLEDColor(CRGB);
};


#endif //RGBLEDSERVICE_H