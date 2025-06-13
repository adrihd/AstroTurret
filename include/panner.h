#ifndef PANNER_H
#define PANNER_H

#include <Arduino.h>
#include <Stepper.h>

class Panner
{
public:

    public:
    Panner();
    Stepper *stepper;

    //Calibration

    void CalibrateMagneticNorth();
    void CalibrateTrueNorth();

    // Pan Speed
    void SetSpeed(int speed);
    int Speed();

    // Pan Action
    void PanBySteps(int steps);
    void PanByAngle(long angle);



private:

    int _PIN_PAN_IN1;
    int _PIN_PAN_IN2;
    int _PIN_PAN_IN3;
    int _PIN_PAN_IN4;
    int _STEPS_PER_REV;
    int PanSpeed;

    int AngleToSteps(long angle);
    float StepsToAngle(int steps);
};

#endif