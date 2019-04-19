#ifndef Trough_H
#define Trough_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
//#include "SerialMessage.h"

class Trough {

public:

Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter filter;
Solenoid solenoid;

bool inventory();
void serial_activate();
//void activate();

private:

bool _stack[];
uint8_t _num_pins;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _input_filter;

};

#endif
