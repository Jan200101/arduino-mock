#define EEPROM_NODEFINE
#include "EEPROM/EEPROM.hpp"
#include <cstdio>

#if defined(ARDUINO_UNO)
#define EEPROM_SIZE 1000
#elif defined(ARDUINO_MEGA)
#define EEPROM_SIZE 4000
#else
#error Unknown Arduino type
#endif

C_EEPROM::C_EEPROM()
{
    this->memory = new byte[EEPROM_SIZE];
    FILE* file = fopen("EEPROM", "rb");

    if (file != nullptr)
    {
        fclose(file);
        this->readFile();
    }
    else
    {
        this->clear();
        this->writeFile();
    }
}
C_EEPROM::~C_EEPROM()
{
    this->writeFile();
    delete[] this->memory;
}

void C_EEPROM::writeFile()
{
    FILE* file = fopen("EEPROM", "wb");
    fwrite(this->memory, sizeof(byte), EEPROM_SIZE, file);
    fclose(file);
}

void C_EEPROM::readFile()
{
    FILE* file = fopen("EEPROM", "rb");
    fread(this->memory, sizeof(byte), EEPROM_SIZE, file);
    fclose(file);
}

void C_EEPROM::clear()
{
    for (int i = 0; i < EEPROM_SIZE; ++i)
        this->memory[i] = 0xFF;

    this->writeFile();
}

byte C_EEPROM::read(int adress)
{
    this->readFile();
    return adress < EEPROM_SIZE ? this->memory[adress] : 0;
}

void C_EEPROM::write(int adress, byte value)
{
    if (adress < EEPROM_SIZE) this->memory[adress] = value;
    this->writeFile();
}

void C_EEPROM::update(int adress, byte value)
{
    if (this->memory[adress] != value)
        this->write(adress, value);
}

int C_EEPROM::length()
{
    return EEPROM_SIZE;
}