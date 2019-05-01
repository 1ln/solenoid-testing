#ifndef DropTarget_H
#define DropTarget_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

class DropTarget {

public:

DropTarget(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter *filter;
Solenoid solenoid;
SerialTransfer serial;

void coil_active();
void serial_activate();
void pwm_value(uint32_t pwm_value); 

uint8_t inv_targets_activated();

private:

uint8_t _num_pins;
uint8_t *_pins;
uint8_t _count;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];

uint32_t _pwm;

};

#endif
