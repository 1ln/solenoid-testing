#ifndef Flipper_H
#define Flipper_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
#include "SerialTransfer.h"

#include "Configure.h"

class Flipper {

public:

Flipper(uint8_t input,uint8_t output,const Configure &set_config);

Filter filter;
Solenoid solenoid;
SerialTransfer serial;

void serial_print(bool serial_print);
void onboard_address(uint16_t onboard_address);
void failsafe(bool failsafe);
void activate();

private:

uint8_t _input;
uint8_t _output;

uint16_t _onboard_address;
bool _serial_print;
char const * _serial_message;
bool _failsafe;

bool _input_filter;

};

#endif
