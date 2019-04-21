#ifndef DropTarget_H
#define DropTarget_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"

class DropTarget {

public:

DropTarget(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter filter;
Solenoid solenoid;

void activate();
void serial_activate();

private:

uint8_t _num_pins;
uint8_t *_pins;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results;

};

#endif
