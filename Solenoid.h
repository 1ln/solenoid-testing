#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"
#include "PinConfig.h"

class Solenoid {

public:

Solenoid();

void on_pwm(uint8_t pin,uint8_t pwm);
void off_pwm(uint8_t pin);
void on_pwm_reduce(uint8_t pin,uint8_t pwm, uint8_t pwm_hold, unsigned long millis_hold);

DelayState delay_state;

private:

bool _reduce_pwm;

};

#endif
