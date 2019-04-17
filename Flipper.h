#ifndef "Flipper.h"
#define "Flipper.h"

#define "Filter.h"
#define "Solenoid.h"
//#define "SerialMessage.h"

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
