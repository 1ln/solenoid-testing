#ifndef DropTarget_H
#define DropTarget_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"

class DropTarget {

public:

DropTarget(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter *filter;
Solenoid solenoid;

void coil_activation_listener();
void serial_activate(); 
uint8_t inv_targets_activated();

private:

uint8_t _num_pins;
uint8_t *_pins;
uint8_t _count;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];

};

#endif
