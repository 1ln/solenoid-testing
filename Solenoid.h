#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"

class Solenoid {

public:

Solenoid();

//void on_pwm_esp32(uint8_t channel, uint32_t pwm_value);
//void off_pwm_esp32(uint8_t channel);
void on_pwm();
void off_pwm();
//void on(uint8_t pin);
//void off(uint8_t pin);
//void on_pwm_reduce_esp32(uint8_t channel,uint32_t pwm_value,uint32_t pwm_reduce_value,unsigned long hold_millis);
void on_pwm_reduce();
void set_hold(unsigned long millis_hold);
void set_pwm(uint32_t pwm);
void set_pwm_reduction(uint8_t pwm_reduce);
void set_channel(uint8_t channel);
void set_pin(uint8_t pin);

DelayState delay_state;

private:

bool _reduce_pwm;
uint8_t _pin;
uint8_t _pwm;
uint8_t _pwm_reduce;
uint8_t _channel;
unsigned long _millis_hold;

};

#endif
