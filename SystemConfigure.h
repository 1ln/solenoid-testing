#ifndef SystemConfigure_H
#define SystemConfigure_H

#include "Arduino.h"

class SystemConfigure {

public:

SystemConfigure();

void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_output(uint8_t *pins,uint8_t num_pins);

};

#endif
