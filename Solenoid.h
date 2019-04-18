#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"

class Solenoid {

public:

Solenoid();

void on_pwm(uint8_t pin, uint32_t pwm_value);
void off_pwm(uint8_t pin);
void on(uint8_t pin);
void off(uint8_t pin);
void on_pwm_reduce(uint8_t pin,uint32_t pwm_value,uint32_t pwm_reduce_value,unsigned long hold_millis);

DelayState delay_state;

};

#endif
