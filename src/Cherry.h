#include <Arduino.h>
#include <Servo.h>

class ToCake
{
    public:
        ToCake(uint8_t pin1, uint8_t pin2, int iFrom1 = 0, int iFrom2 = 0, int iTo1 = 90, int iTo2 = 90);
        Servo servo1;
        Servo servo2;
        void open();
        uint8_t from1;
        uint8_t to1;
        uint8_t from2;
        uint8_t to2;
};

class ToBasket
{
    public:
        ToBasket(uint8_t pin, int iFrom = 0, int iTo = 90);
        Servo servo;
        void open();
        void close();
        void move(bool iState);
        void move();
        void toggle();
        uint8_t from;
        uint8_t to;
        bool state = false;
};

class Bariere
{
    public:
        Bariere(uint8_t pin, int iFrom = 0, int iTo = 90);
        Servo servo;
        void open();
        void close();
        void move(bool iState);
        void move();
        void toggle();
        uint8_t from;
        uint8_t to;
        bool state = false;
};