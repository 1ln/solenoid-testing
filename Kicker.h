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
