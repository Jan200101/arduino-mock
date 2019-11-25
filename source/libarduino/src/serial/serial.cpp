#define SERIAL_NODEFINE
#include "serial/serial.hpp"
#include <cstdio>

#define SERIAL_STR_PRINT(format, arg)           \
    if (this->baud) return printf(format, arg); \
    return 0

#define SERIAL_PRINT SERIAL_STR_PRINT // TODO implement proper print for non str functions

C_Serial::C_Serial()
{
    this->baud = 0;
}

void C_Serial::begin(int baud, CONFIG config)
{
    this->baud = baud;
}

size_t C_Serial::print(const char* text) { SERIAL_STR_PRINT("%s", text); }
size_t C_Serial::print(char text) { SERIAL_STR_PRINT("%c", text); }
size_t C_Serial::print(uint8_t val, BASEX) { SERIAL_PRINT("%i", val); }
size_t C_Serial::print(int val, BASEX) { SERIAL_PRINT("%i", val); }
size_t C_Serial::print(unsigned int val, BASEX) { SERIAL_PRINT("%u", val); }
size_t C_Serial::print(long val, BASEX) { SERIAL_PRINT("%li", val); }
size_t C_Serial::print(unsigned long val, BASEX) { SERIAL_PRINT("%lu", val); }
size_t C_Serial::print(double val, int) { SERIAL_PRINT("%.2f", val); }

size_t C_Serial::println(const char* text) { SERIAL_STR_PRINT("%s\n", text); }
size_t C_Serial::println(char text) { SERIAL_STR_PRINT("%c\n", text); }
size_t C_Serial::println(uint8_t val, BASEX) { SERIAL_PRINT("%i\n", val); }
size_t C_Serial::println(int val, BASEX) { SERIAL_PRINT("%i\n", val); }
size_t C_Serial::println(unsigned int val, BASEX) { SERIAL_PRINT("%u\n", val); }
size_t C_Serial::println(long val, BASEX) { SERIAL_PRINT("%li\n", val); }
size_t C_Serial::println(unsigned long val, BASEX) { SERIAL_PRINT("%lu\n", val); }
size_t C_Serial::println(double val, int) { SERIAL_PRINT("%.2f\n", val); }
size_t C_Serial::println(void) { SERIAL_STR_PRINT("\n", ""); }
