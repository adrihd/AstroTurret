#include "astroturret_config.h"
#include "tilter.h"

Tilter::Tilter() {

    _PIN_TILT_FORWARD = CFG_TILT_PIN_FORWARD;
    _PIN_TILT_BACKWARD = CFG_TILT_PIN_BACKWARD;

    _TILT_SPEED = CFG_TILT_SPEED;

}

// Calibration
void Tilter::CalibrateLevel() {

}

// Tilt Angle
float Tilter::GetAngleFromHorizon()
{

}

// Tilt Speed
int Tilter::Speed() {
    return _TILT_SPEED;
}

void Tilter::SetSpeed(int speed){
    if (speed <= CFG_TILT_MAX_SPEED || speed >= CFG_TILT_MIN_SPEED)
    {
        _TILT_SPEED = speed;    
    }
}

//Tilt Action

void Tilter::TiltForwardByDegrees(float angle) {
    
}

void Tilter::TiltBackwardByDegrees(float angle) {
    
}

