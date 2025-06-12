#include "astroturret_config.h"
#include "panner.h"

// #define PAN1 4
// #define PAN2 5
// #define PAN3 6
// #define PAN4 7
// #define stepsPerRevolution 2038

Panner::Panner() {

    // Coil Pins

    _PIN_PAN_IN1 = CFG_PANNER_PIN_IN1;
    _PIN_PAN_IN2 = CFG_PANNER_PIN_IN2;
    _PIN_PAN_IN3 = CFG_PANNER_PIN_IN3;
    _PIN_PAN_IN4 = CFG_PANNER_PIN_IN4;
    
    // Steps Per Rev
    // SPR = 2038;
    _STEPS_PER_REV = CFG_PANNER_STEPS_PER_REV;
    PanSpeed = 20;

    stepper = new Stepper(_STEPS_PER_REV, _PIN_PAN_IN1, _PIN_PAN_IN3, _PIN_PAN_IN2, _PIN_PAN_IN4);
    stepper->setSpeed(PanSpeed);
}

void Panner::SetSpeed(PannerSpeed speed) {
    stepper->setSpeed(speed);
    
}

void Panner::PanBy(int steps) {
    stepper->step(steps);
}
