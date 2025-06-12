#ifndef PANNER_H
#define PANNER_H

#include <Arduino.h>
#include <Stepper.h>

class Tilter
{
public:

    enum TiltSpeed {
        TS_FASTEST = 20,
        TS_FAST = 16,
        TS_MED = 14,
        TS_LOW = 12,
        TS_LOWER = 8,
        TS_SLOWEST = 1,
    };


    Tilter();
    Tilter* tilter;

    // Calibration
    void CalibrateLevel();
    
    // Tilt Angle

    float GetAngleFromHorizon();
    // Tilt Speed
    void SetSpeed(int);
    int Speed();

    // Tilt Actions
    void TiltForwardByDegrees(float);
    void TiltBackwardByDegrees(float);

private:

    int _PIN_TILT_FORWARD;
    int _PIN_TILT_BACKWARD;
    int _TILT_SPEED;
};

#endif