#define SERIAL_NODEFINE
#include "serial/serial.hpp"
#include <cstdio>
#include <cstring>

constexpr char fltfmt[] = "%.";

#define SERIAL_STR_PRINT(format, arg)                    \
    if (this->baud) return fprintf(stderr, format, arg); \
    return 0

#define SERIAL_FLOAT_PRINT(decimal, val, newline) \
    char str[sizeof(val) * 8 + 4];                \
    snprintf(str, sizeof(val) * 8 + 4,            \
             "%s%if", fltfmt, decimal);           \
    if (newline) strcat(str, "\n");               \
    SERIAL_PRINT(str, val);

#define SERIAL_PRINT SERIAL_STR_PRINT

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
size_t C_Serial::print(double val, int decimal) { SERIAL_FLOAT_PRINT(decimal, val, false); }

size_t C_Serial::println(const char* text) { SERIAL_STR_PRINT("%s\n", text); }
size_t C_Serial::println(char text) { SERIAL_STR_PRINT("%c\n", text); }
size_t C_Serial::println(uint8_t val, BASEX) { SERIAL_PRINT("%i\n", val); }
size_t C_Serial::println(int val, BASEX) { SERIAL_PRINT("%i\n", val); }
size_t C_Serial::println(unsigned int val, BASEX) { SERIAL_PRINT("%u\n", val); }
size_t C_Serial::println(long val, BASEX) { SERIAL_PRINT("%li\n", val); }
size_t C_Serial::println(unsigned long val, BASEX) { SERIAL_PRINT("%lu\n", val); }
size_t C_Serial::println(double val, int decimal) { SERIAL_FLOAT_PRINT(decimal, val, true); }
size_t C_Serial::println(void) { SERIAL_STR_PRINT("%s", "\n"); }
