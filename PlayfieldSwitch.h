#ifndef PlayfieldSwitch_H
#define PlayfieldSwitch_H

#include "Arduino.h"
#include "Filter.h"
#include "SerialTransfer.h"

#include "Configure.h"

class PlayfieldSwitch {

public:

PlayfieldSwitch(uint8_t input,const Configure &set_config);

Filter filter;
SerialTransfer serial;

void serial_print(bool serial_print);
void onboard_address(uint16_t onboard_address);

void switch_active();

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
