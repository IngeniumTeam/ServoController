#include <Arduino.h>

#include "Cherry.h"

ToCake::ToCake(uint8_t pin1, uint8_t pin2, int iFrom1 = 0, int iFrom2 = 0, int iTo1 = 90, int iTo2 = 90)
{
    from1 = iFrom1;
    to1 = iTo1;
    from1 = iFrom1;
    to2 = iTo2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
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
