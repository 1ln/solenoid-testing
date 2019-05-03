#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

_reduce_pwm = false;
_channel = 0;
_pin = 0;

}

void Solenoid::on_pwm(uint32_t pwm) {

analogWrite(_channel,pwm);

}

void Solenoid::off_pwm() {

analogWrite(_channel,0);
_reduce_pwm = false;

}

void Solenoid::set_pin(uint8_t pin) {

_pin = pin;

}

void Solenoid::set_channel(uint8_t channel) {

_channel = channel;

}

void Solenoid::on_pwm_reduce(uint32_t pwm,uint32_t pwm_reduce,unsigned long millis_hold) {

if(delay_state.wait_interval(millis_hold) == true) {
_reduce_pwm = true;
}

if(_reduce_pwm == true) {
analogWrite(_channel,pwm_reduce);
} else {
analogWrite(_channel,pwm);
}

}
