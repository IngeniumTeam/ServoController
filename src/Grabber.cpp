#include <Arduino.h>

#include "Cherry.h"

Grabber::Grabber(uint8_t iPin1, uint8_t iPin2)
{
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

Grabber::Grabber(uint8_t iPin1, uint8_t iPin2, int iPulseMin1, int iPulseMax1)
{
    pulseMin1 = iPulseMin1;
    pulseMax1 = iPulseMax1;
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

Grabber::Grabber(uint8_t iPin1, uint8_t iPin2, int iPulseMin1, int iPulseMax1, int iPulseMin2, int iPulseMax2)
{
    pulseMin1 = iPulseMin1;
    pulseMax1 = iPulseMax1;
    pulseMin2 = iPulseMin2;
    pulseMax2 = iPulseMax2;
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Grabber::setup()
{
    if (pulseMin1 != 0)
        servo1.attach(pin1, pulseMin1, pulseMax1);
    else
        servo1.attach(pin1);
    if (pulseMin2 != 0 && pulseMax2 != 0)
        servo2.attach(pin2, pulseMin2, pulseMax2);
    else
        servo2.attach(pin2);
}

void Grabber::grab()
{
    servo2.write(180);
    servo1.write(0);
    delay(1500);
    servo2.write(130);
    delay(750);
    servo1.write(160);
    delay(1500);
    servo2.write(180);
    servo1.write(0);
}