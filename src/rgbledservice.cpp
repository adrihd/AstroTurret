#include "rgbledservice.h"

RGBLEDService::RGBLEDService() {
    FastLED.addLeds<NEOPIXEL, RGBLED_DATA_PIN>(leds, RGBLED_NUM_LEDS);
}

void RGBLEDService::ShowLEDColor(CRGB color) {
    this->leds[0] = color;
    FastLED.show();
}
