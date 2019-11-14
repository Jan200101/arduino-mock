#include "io/io.hpp"
#include <ctime>
#include "io/pin.hpp"
#include "utils/defs.hpp"

#if defined(ARDUINO_UNO)
#define MAX_AD_BITS 1024
#else
#error Unknown Arduino type
#endif

Pin DPINS[DPINCOUNT];
Pin APINS[APINCOUNT];

VALUE digitalRead(PIN pin)
{
    if (pin > DPINCOUNT - 1) return 0;
    return DPINS[pin].getValue();
}

void digitalWrite(PIN pin, VALUE value)
{
    if (pin > DPINCOUNT - 1) return;
    DPINS[pin].setValue(value);
}

void pinMode(PIN pin, MODE mode)
{
    if (pin > DPINCOUNT - 1) return;
    DPINS[pin].setMode(mode);
}

ANALOGVALUE analogRead(PIN pin)
{
    if (pin > APINCOUNT - 1) return 0;
    ANALOGVALUE val = APINS[pin].getAnalogValue();
    if (val > MAX_AD_BITS - 1) val = MAX_AD_BITS - 1; // val > 2^10
    return val;
}

void analogWrite(PIN pin, PWMVALUE value)
{
    STUB;
}

void delay(float ms)
{
    time_t now = time(nullptr);
    ms = ms / 1000;

    while ((time(nullptr) - now) < ms)
    {
    }
}