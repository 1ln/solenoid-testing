#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

_reduce_pwm = false;
_channel = 0;
_pwm = 235;
_pwm_reduce = 50;
_millis_hold = 1500;

}

void Solenoid::on_pwm_esp32(uint8_t channel, uint32_t pwm_value) {
//analogWrite(pin,pwm_value);
ledcWrite(channel,pwm_value);
}

void Solenoid::off_pwm_esp32(uint8_t channel) {
//analogWrite(pin,0);
ledcWrite(channel,0);
_reduce_pwm = false;
}

void Solenoid::set_channel(uint8_t channel) {
_channel = channel;
}

void Solenoid::set_pwm(uint8_t pwm) {
_pwm = pwm;
}

void Solenoid::set_pwm_reduction(uint8_t pwm_reduce) {
_pwm_reduce = _pwm_reduce;
}

void Solenoid::set_hold(unsigned long millis_hold) {
_millis_hold = millis_hold;
}

void Solenoid::on(uint8_t pin) {
digitalWrite(pin,LOW);
}

void Solenoid::off(uint8_t pin) {
digitalWrite(pin,HIGH);
}

void Solenoid::on_pwm_reduce_esp32(uint8_t channel, uint32_t pwm_value, uint32_t pwm_reduce_value, unsigned long millis_hold) {

if(delay_state.wait_interval(millis_hold) == true) {
_reduce_pwm = true;
}

if(_reduce_pwm == true) {
//analogWrite(pin,pwm_reduce_value);
ledcWrite(channel,pwm_reduce_value);
} else {
//Serial.println("reduced");
//analogWrite(pin,pwm_value);
ledcWrite(channel,pwm_value);
}

}
