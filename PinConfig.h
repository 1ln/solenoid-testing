#ifndef PinConfig_H
#define PinConfig_H

#include "Arduino.h"

class PinConfig {

public:

PinConfig();

void set_pin_input_pullup(uint8_t pin);
void set_pin_pwm(uint8_t pin);
void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_pwm(uint8_t *pins,uint8_t num_pins);

private:


};

#endif
