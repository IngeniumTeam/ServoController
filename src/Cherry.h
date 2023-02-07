#include <Arduino.h>
#include <Servo.h>

class ToCake
{
    public:
        ToCake(uint8_t pin1, uint8_t pin2, int iFrom1 = 0, int iFrom2 = 0, int iTo1 = 90, int iTo2 = 90);
        void setup();
        void open();
    private:
        Servo servo1;
        Servo servo2;
        uint8_t from1;
        uint8_t to1;
        uint8_t from2;
        uint8_t to2;
        uint8_t pin1;
        uint8_t pin2;
};

class ToBasket
{
    public:
        ToBasket(uint8_t pin, int iFrom = 0, int iTo = 90);
        void setup();
        void open();
        void close();
        void move(bool iState);
        void move();
        void toggle();
    private:
        Servo servo;
        uint8_t from;
        uint8_t to;
        uint8_t pin;
        bool state = false;
};

class Barrier
{
    public:
        Barrier(uint8_t pin, int iFrom = 0, int iTo = 90);
        void setup();
        void open();
        void close();
        void move(bool iState);
        void move();
        void toggle();
    private:
        Servo servo;
        uint8_t from;
        uint8_t to;
        uint8_t pin;
        bool state = false;
};

class Costume
{
    public:
        Costume(uint8_t iPin, int iTo = 180);
        void setup();
        void deploy();
    private:
        Servo servo;
        uint8_t to;
        uint8_t pin;
};

class Grabber
{
    public:
        Grabber(uint8_t iPin1, uint8_t iPin2);
        Grabber(uint8_t iPin1, uint8_t iPin2, int iPulseMin1, int iPulseMax1);
        Grabber(uint8_t iPin1, uint8_t iPin2, int iPulseMin1, int iPulseMax1, int iPulseMin2, int iPulseMax2);
        void setup();
        void grab();
        void open();
        void close();
        void up();
    private:
        Servo servo1;
        Servo servo2;
        uint8_t pin1;
        uint8_t pin2;
        int pulseMin1 = 0;
        int pulseMax1 = 0;
        int pulseMin2 = 0;
        int pulseMax2 = 0;
};  