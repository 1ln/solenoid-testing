#ifndef Trough_H
#define Trough_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
//#include "SerialMessage.h"

class Trough {

public:

Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output,uint8_t jam_pin);

//Filter filter;
Filter *filter;
Filter jam_filter;
Solenoid solenoid;

uint8_t inv_count();
void serial_activate();
void loop_activate();
bool jam_activated();
void activate_solenoid();

private:

uint8_t _count;

uint8_t _num_pins;
uint8_t *_pins;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];

uint8_t _jam_pin;
bool _jam;

};

#endif
