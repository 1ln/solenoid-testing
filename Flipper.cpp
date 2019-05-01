#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;

_input_filter = false;

_pwm = 255;
_pwm_hold = 235;

}

void Flipper::message(const char * message) {
_message = message;
} 

bool Flipper::serial_active(bool active) {
_serial_active = active;
return _serial_active;
}

void Flipper::hold_config(uint32_t pwm_value, uint32_t pwm_hold,unsigned long initial_voltage_millis) {
_pwm = pwm_value;
_pwm_hold = pwm_hold;
_millis = initial_voltage_millis;
}

void Flipper::coil_active() {

_input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
solenoid.on_pwm_reduce(_pwm,_pwm_hold,_millis);
} else {
solenoid.off_pwm();
}

if(_serial_active == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_message);
    }
}

}
