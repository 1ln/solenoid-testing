#ifndef PopBumper_H
#define PopBumper_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"

class PopBumper {

public:

PopBumper(uint8_t input,uint8_t output);

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