#include "io/pin.hpp"
#include <cstdio>
#include "utils/defs.hpp"

#include <filesystem>
#if __cplusplus < 201703L
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

static uint8_t LAST_PIN = 0;

Pin::Pin() : Pin::Pin(LAST_PIN++) {}

Pin::Pin(PIN number)
{
    this->number = number;
    sprintf(this->file, number > DPINCOUNT ? "PINS/A%i" : "PINS/D%i", number > DPINCOUNT ? this->number - DPINCOUNT : this->number);
    this->mode = NONE;
    this->value = LOW;
    this->analogvalue = 0;

    fs::create_directory("PINS");
    FILE* file = fopen(this->file, "rb");

    if (file != nullptr)
    {
        fclose(file);
        this->readFile();
    }
    else
    {
        this->writeFile();
    }
}

void Pin::readFile()
{
    FILE* file = fopen(this->file, "rb");
    if (this->number > DPINCOUNT)
        fread(&this->analogvalue, sizeof(ANALOGVALUE), 1, file);
    else
        fread(&this->value, sizeof(VALUE), 1, file);
    fclose(file);
}

void Pin::writeFile()
{
    FILE* file = fopen(this->file, "wb");
    if (this->number > DPINCOUNT)
        fwrite(&this->analogvalue, sizeof(ANALOGVALUE), 1, file);
    else
        fwrite(&this->value, sizeof(VALUE), 1, file);
    fclose(file);
}

void Pin::setMode(MODE mode)
{
    this->mode = mode;
}

MODE Pin::getMode()
{
    return this->mode;
}

void Pin::setValue(VALUE value)
{
    if (this->mode == OUTPUT)
    {
        this->value = value;
        this->writeFile();
    }
}

VALUE Pin::getValue()
{
    if (this->mode == INPUT)
    {
        this->readFile();
        return this->value;
    }
    return 0;
}

ANALOGVALUE Pin::getAnalogValue()
{
    this->readFile();
    return this->analogvalue;
}