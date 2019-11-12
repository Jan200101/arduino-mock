#ifndef IO_HPP
#define IO_HPP

#define DPINCOUNT 13
#define APINCOUNT 5

#include <stdint.h>

typedef uint8_t PIN;
enum : PIN
{
    A0,
    A1,
    A2,
    A3,
    A4,
    A5
};

typedef uint8_t MODE;
enum : MODE
{
    NONE,
    INPUT,
    INPUT_PULLUP,
    OUTPUT
};

typedef uint8_t VALUE;
enum : VALUE
{
    LOW,
    HIGH
};

typedef uint16_t ANALOGVALUE;
typedef uint8_t PWMVALUE;

typedef uint8_t TYPE;
enum : TYPE
{
    DIGITAL,
    ANALOG
};

typedef void VOLTTYPE;

// Digital I/O
VALUE digitalRead(PIN);
void digitalWrite(PIN, VALUE);
void pinMode(PIN, MODE);

// ANALOG I/O
ANALOGVALUE analogRead(PIN);
void analogReference(VOLTTYPE);
void analogWrite(PIN, PWMVALUE);

// MISC
void delay(int);

#endif