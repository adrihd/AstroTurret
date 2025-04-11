#ifndef PANNER_H
#define PANNER_H

#include <Arduino.h>
#include <Stepper.h>

class Panner
{
public:

    enum PannerSpeed {
        SP_FASTEST = 20,
        SP_FASTER = 18,
        SP_FAST = 15,
        SP_MED = 12,
        SP_LOW = 9,
        SP_LOWER = 6,
        SP_LOWEST = 3   
    };

    Panner();
    Stepper *stepper;
    void SetSpeed(PannerSpeed);
    void PanBy(int);



private:

    int PAN1;
    int PAN2;
    int PAN3;
    int PAN4;
    int SPR;
    int PanSpeed;
};

#endif