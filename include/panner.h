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

    //Calibration

    void CalibrateMagneticNorth();
    void CalibrateTrueNorth();

    // Pan Speed
    void SetSpeed(int);
    int Speed();

    // Pan Action
    void PanBy(int);



private:

    int _PIN_PAN_IN1;
    int _PIN_PAN_IN2;
    int _PIN_PAN_IN3;
    int _PIN_PAN_IN4;
    int _STEPS_PER_REV;
    int PanSpeed;
};

#endif