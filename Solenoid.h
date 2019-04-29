#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"
#include "System.h"

class Solenoid {

public:

Solenoid();

void on_pwm_reduce(uint32_t pwm, uint32_t pwm_hold, unsigned long millis_hold);
void set_channel(uint8_t channel);
void set_pin(uint8_t pin);

DelayState delay_state;

private:

bool _reduce_pwm;
uint8_t _pin;
uint8_t _channel;

};

#endif
