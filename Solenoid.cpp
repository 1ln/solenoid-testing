#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

_reduce_pwm = false;

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
