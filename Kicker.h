#ifndef Kicker_H
#define Kicker_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

class Kicker {

public:

Kicker(uint8_t input,uint8_t output);

Filter filter;
Solenoid solenoid;
SerialTransfer serial;

void serial_activate();
void coil_active();
void pwm(uint32_t pwm);
void millis_config(unsigned long millis_wait_amt,unsigned long millis_coil_on_amt);
void message(const char * message);
void ir_device(bool ir);

private:

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _input_filter;
bool _serial_activated;

bool _ir;
unsigned long _millis_wait_amt;
unsigned long _millis_coil_on_amt;
const char * _message; 
uint32_t _pwm;

};

#endif
