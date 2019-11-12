#ifndef SERIAL_CONFIG_HPP
#define SERIAL_CONFIG_HPP

#include <stdint.h>

typedef uint8_t CONFIG;
enum : CONFIG
{
    SERIAL_5N1,
    SERIAL_6N1,
    SERIAL_7N1,
    SERIAL_8N1, // Default
    SERIAL_5N2,
    SERIAL_6N2,
    SERIAL_7N2,
    SERIAL_8N2,
    SERIAL_5E1, // even parity
    SERIAL_6E1,
    SERIAL_7E1,
    SERIAL_8E1,
    SERIAL_5E2,
    SERIAL_6E2,
    SERIAL_7E2,
    SERIAL_8E2,
    SERIAL_5O1, // odd parity
    SERIAL_6O1,
    SERIAL_7O1,
    SERIAL_8O1,
    SERIAL_5O2,
    SERIAL_6O2,
    SERIAL_7O2,
    SERIAL_8O2
};

#endif