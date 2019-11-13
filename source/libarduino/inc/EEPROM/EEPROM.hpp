#ifndef EEPROM_EPPROM_HPP
#define EEPROM_EPPROM_HPP
#include "utils/types.hpp"

class C_EEPROM
{
   private:
    byte* memory;
    void writeFile();
    void readFile();
    void clear();

   public:
    C_EEPROM();
    ~C_EEPROM();

    byte read(int);
    void write(int, byte);
    void update(int, byte);

    int length();
};

#ifndef EEPROM_NODEFINE
C_EEPROM EEPROM;
#endif

#endif