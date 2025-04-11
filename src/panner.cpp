#include "panner.h"

// #define PAN1 4
// #define PAN2 5
// #define PAN3 6
// #define PAN4 7
// #define stepsPerRevolution 2038

Panner::Panner() {

    // Coil Pins
    PAN1 = 4;
    PAN2 = 5;
    PAN3 = 6;
    PAN4 = 7;
    
    // Steps Per Rev
    // SPR = 2038;
    SPR = 2038;
    PanSpeed = 20;

    stepper = new Stepper(SPR, PAN1, PAN3, PAN2, PAN4);
    stepper->setSpeed(PanSpeed);
}

void Panner::SetSpeed(PannerSpeed speed) {
    stepper->setSpeed(speed);
    
}

void Panner::PanBy(int steps) {
    stepper->step(steps);
}
