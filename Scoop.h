#ifndef Scoop_H
#define Scoop_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"

class Scoop {

public:

Scoop(uint8_t input,uint8_t output);

Filter filter;
Solenoid solenoid;

void serial_activate();
void coil_active();

private:

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _input_filter;
unsigned long _millis_receive;
unsigned long _millis_wait;
unsigned long _millis_coil_on;

};

#endif
