#include <Arduino.h>

#include "Cherry.h"

Bariere::Bariere(uint8_t pin, int iFrom = 0, int iTo = 90)
{
    from = iFrom;
    to = iTo;
    pinMode(pin, OUTPUT);
    servo.attach(pin);
    move();
}

void Bariere::open()
{
    servo.write(to);
}

void Bariere::close()
{
    servo.write(from);
}

void Bariere::move()
{
    if (state)
        open();
    else
        close();
}

void Bariere::move(bool iState)
{
    if (state == iState)
        return;
    state = iState;
    move();
}

void Bariere::toggle()
{
    state = !state;
    move();
}