#ifndef PlayfieldSwitch_H
#define PlayfieldSwitch_H

#include "Arduino.h"
#include "Filter.h"
#include "SerialTransfer.h"

class PlayfieldSwitch {

public:

PlayfieldSwitch(uint8_t input);

Filter filter;
SerialTransfer serial;

void serial_active(bool activate);
void message(const char * message);
void switch_active();

private:

uint8_t _input;
uint8_t _output;

bool _serial_activated;
char const * _message;

bool _input_filter;

};

#endif
