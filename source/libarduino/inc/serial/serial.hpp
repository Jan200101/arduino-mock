#ifndef SERIAL_SERIAL_HPP
#define SERIAL_SERIAL_HPP

#include <cstdint>
#include <cstdlib>
#include "serial/config.hpp"
#include "utils/types.hpp"

class C_Serial
{
   private:
    int baud;

   public:
    C_Serial();

    operator bool()
    {
        return true;
    }

    bool available()
    {
        return *this;
    }

    bool availableForWrite()
    {
        return *this;
    }
    void begin(int, CONFIG = SERIAL_8N1);

    // size_t print(const String&); TODO no String implementation
    size_t print(const char*);
    size_t print(char);
    size_t print(uint8_t, BASEX = DEC);
    size_t print(int, BASEX = DEC);
    size_t print(unsigned int, BASEX = DEC);
    size_t print(long, BASEX = DEC);
    size_t print(unsigned long, BASEX = DEC);
    size_t print(double, int = 2);
    // size_t print(const Printable&); TODO no Printable implementation

    // size_t println(const String& s); TODO no String implementation
    size_t println(const char*);
    size_t println(char);
    size_t println(uint8_t, BASEX = DEC);
    size_t println(int, BASEX = DEC);
    size_t println(unsigned int, BASEX = DEC);
    size_t println(long, BASEX = DEC);
    size_t println(unsigned long, BASEX = DEC);
    size_t println(double, int = 2);
    // size_t println(const Printable&); TODO TODO no Printable implementation
    size_t println(void);
};

#ifndef SERIAL_NODEFINE
C_Serial Serial;
#endif

#endif
