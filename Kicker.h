#ifndef Kicker_H
#define Kicker_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"

class Kicker {

public:

Kicker(uint8_t input,uint8_t output);

Filter filter;
Solenoid solenoid;

void serial_activate();
void activate();

private:

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _input_filter;

};

#endif
