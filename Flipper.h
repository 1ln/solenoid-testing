#ifndef Flipper_H
#define Flipper_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

class Flipper {

public:

Flipper(uint8_t input,uint8_t output);

Filter filter;
Solenoid solenoid;
SerialTransfer serial;

void pwm_value(uint32_t pwm_value);
void pwm_hold(uint32_t pwm_hold);
void initial_voltage_millis(unsigned long initial_voltage_millis );
bool serial_active(bool active);
void message(const char * message);
void coil_active();

private:

uint8_t _input;
uint8_t _output;

bool _serial_active;
char const * _message;

uint32_t _pwm;
uint32_t _pwm_hold;

unsigned long _millis;

bool _input_filter;

};

#endif
