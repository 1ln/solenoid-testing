#ifndef SystemConfigure_H
#define SystemConfigure_H

#include "Arduino.h"

class SystemConfigure {

public:

SystemConfigure();

void set_pin_input_pullup(uint8_t pin);
void set_pin_pwm_esp32(uint8_t pin,uint8_t channel,double freq,uint8_t res);
void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_output(uint8_t *pins,uint8_t num_pins);

};

#endif
