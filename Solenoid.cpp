#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

}

void Solenoid::on_pwm(uint8_t pin,uint8_t pwm) {

analogWrite(pin,pwm);

}

void Solenoid::off_pwm(uint8_t pin) {

analogWrite(pin,0);
_reduce_pwm = false;

}

void Solenoid::on_pwm_reduce(uint8_t pin,uint8_t pwm,uint8_t pwm_hold,unsigned long millis_hold) {

if(delay_state.wait_interval(millis_hold) == true) {
_reduce_pwm = true;
}

if(_reduce_pwm == true) {
analogWrite(pin,pwm_hold);
} else {
analogWrite(pin,pwm);
}

}
