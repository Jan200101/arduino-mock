#ifndef IO_PIN_H
#define IO_PIN_H

#include <stdint.h>
#include "io/io.hpp"

class Pin
{
   private:
    PIN number;
    char file[9];
    MODE mode;
    VALUE value;
    ANALOGVALUE analogvalue;

    void readFile();
    void writeFile();

   public:
    Pin();
    Pin(PIN number);

    MODE getMode();
    void setMode(MODE);
    VALUE getValue();
    void setValue(VALUE);
    ANALOGVALUE getAnalogValue();
};

#endif