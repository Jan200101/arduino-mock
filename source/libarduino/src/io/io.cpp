#include "io/io.hpp"
#include <cerrno>
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

int delay(int ms)
{
    struct timespec ts;
    int ret;

    if (ms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;

    do
    {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);

    return ret;
}