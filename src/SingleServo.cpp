#include <Arduino.h>

#include "Cherry.h"

SingleServo::SingleServo(uint8_t iPin, int iFrom = 0, int iTo = 90)
{
    from = iFrom;
    to = iTo;
    pin = iPin;
    pinMode(pin, OUTPUT);
}

void SingleServo::setup()
{
    servo.attach(pin);
    move();
}

void SingleServo::open()
{
    servo.write(to);
}

void SingleServo::close()
{
    servo.write(from);
}

void SingleServo::move()
{
    if (state)
        open();
    else
        close();
}

void SingleServo::move(bool iState)
{
    if (state == iState)
        return;
    state = iState;
    move();
}

void SingleServo::toggle()
{
    move(!state);
}