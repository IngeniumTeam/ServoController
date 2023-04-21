#include <Arduino.h>
#include <Timino.h>

#include "Cherry.h"

Vacuum::Vacuum(uint8_t iMotorPin, uint8_t iServoPin, int iFrom = 0, int iTo = 90, bool iReversed = false)
{
    from = iFrom;
    to = iTo;
    motorPin = iMotorPin;
    servoPin = iServoPin;
    reversed = iReversed;
    pinMode(motorPin, OUTPUT);
    pinMode(servoPin, OUTPUT);
}

void Vacuum::setup()
{
    servo.attach(servoPin);
    move();
}

void Vacuum::open()
{
    servo.write(to);
}

void Vacuum::close()
{
    servo.write(from);
}

void Vacuum::on()
{
    digitalWrite(motorPin, !reversed);
}

void Vacuum::off()
{
    digitalWrite(motorPin, reversed);
}

void Vacuum::move()
{
    if (state)
        open();
    else
        close();
}

void Vacuum::move(bool iState)
{
    if (state == iState)
        return;
    state = iState;
    move();
}

void Vacuum::toggle()
{
    move(!state);
}