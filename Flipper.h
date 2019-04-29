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

void pwm(uint8_t pwm);
void pwm_hold(uint8_t pwm_hold);
void serial_print(const char * serial_print);
void failsafe(bool failsafe);
void activate();

private:

uint8_t _input;
uint8_t _output;

bool _serial_print;
char const * _serial_message;

bool _failsafe;

uint8_t _pwm = pwm;
uint8_t _pwm_hold = _pwm_hold;

bool _input_filter;

};

#endif
