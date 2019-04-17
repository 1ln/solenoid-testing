#ifndef Flipper_H
#define Flipper_H

#include "Arduino.h"
#include "Filter.h"
#include "Solenoid.h"
//#include "SerialMessage.h"

class Flipper {

public:

Flipper(uint8_t input,uint8_t output);

Filter debounce;
Solenoid coil;

void activate();

private:
uint8_t _input;
uint8_t _output;

};

#endif
