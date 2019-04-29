#ifndef Bumper_H
#define Bumper_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

class Bumper {

public:

Bumper(uint8_t input,uint8_t output);

Filter filter;
Solenoid solenoid;
SerialTransfer serial; 

void serial_activate();
void coil_activate();
void message(const char * message);
void pwm(uint32_t pwm);

private:

uint8_t _input;
uint8_t _output;

uint32_t _pwm;

const char * _message;

bool _serial_activated;
bool _input_filter;

};

#endif
