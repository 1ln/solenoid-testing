#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

_reduce_pwm = false;
_channel = 0;
_pwm = 235;
_pwm_reduce = 50;
_millis_hold = 1500;
_pin = 0;

}

void Solenoid::on_pwm() {

//#ifdef PBLIB_ESP32
ledcWrite(_channel,_pwm);
//#else
//analogWrite(_pin,_pwm);
//#endif
}

void Solenoid::off_pwm() {
//#ifdef PBLIB_ESP32
ledcWrite(_channel,0);
_reduce_pwm = false;
//#else
//analogWrite(_pin,0);
//#endif
}

void Solenoid::set_pin(uint8_t pin) {
_pin = pin;
}

void Solenoid::set_channel(uint8_t channel) {
_channel = channel;
}

void Solenoid::set_pwm(uint32_t pwm) {
_pwm = pwm;
}

void Solenoid::set_pwm_reduction(uint8_t pwm_reduce) {
_pwm_reduce = _pwm_reduce;
}

void Solenoid::set_hold(unsigned long millis_hold) {
_millis_hold = millis_hold;
}

//void Solenoid::on(uint8_t pin) {
//digitalWrite(pin,LOW);
//}

//void Solenoid::off(uint8_t pin) {
//digitalWrite(pin,HIGH);
//}

void Solenoid::on_pwm_reduce() {

if(delay_state.wait_interval(_millis_hold) == true) {
_reduce_pwm = true;
}

if(_reduce_pwm == true) {
//#ifdef PBLIB_ESP32
ledcWrite(_channel,_pwm_reduce);
//#else
//analogWrite(_pin,_pwm_reduce);
//#endif
} else {
//#ifdef PBLIB_ESP32
ledcWrite(_channel,_pwm);
//#else
//analogWrite(_pin,_pwm);
//#endif
}

}
