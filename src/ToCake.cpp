#include <Arduino.h>

#include "Cherry.h"

ToCake::ToCake(uint8_t iPin1, uint8_t iPin2, int iFrom1 = 0, int iFrom2 = 0, int iTo1 = 90, int iTo2 = 90)
{
    from1 = iFrom1;
    to1 = iTo1;
    from1 = iFrom1;
    to2 = iTo2;
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void ToCake::setup()
{
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo1.write(from1);
    servo2.write(to2);
}

void ToCake::open()
{
    servo2.write(from2);
    servo1.write(to1);
    delay(500);
    servo1.write(from1);
    delay(500);
    servo2.write(to2);
}
