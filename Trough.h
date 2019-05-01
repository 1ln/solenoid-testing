#ifndef Trough_H
#define Trough_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

class Trough {

public:

Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output,uint8_t kickout_ir_pin,uint8_t jam_ir_pin);

Filter *filter;
Filter *ir_filter;
Filter jam_filter;
Filter kickout_filter;
SerialTransfer serial;
Solenoid solenoid;

uint8_t inv_count();
void serial_activate();
void loop_active();
bool jam_ir_active();
void activate_solenoid();
bool kickout_ir_active();
void pwm_value(uint32_t pwm_value);

private:

uint8_t _count;

uint8_t _num_pins;
uint8_t *_pins;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];

uint8_t _jam_ir_pin;
bool _jam;

bool _filter_kickout_ir;
uint8_t _kickout_ir_pin;
bool _kickout;

uint32_t _pwm;
};

#endif
