#include <Arduino.h>

#include "Cherry.h"

Costume::Costume(uint8_t iPin, int iTo = 180)
{
    to = iTo;
    pin = iPin;
    pinMode(pin, OUTPUT);
}

void Costume::setup()
{
    servo.attach(pin);
}

void Costume::deploy()
{
    servo.write(to);
}