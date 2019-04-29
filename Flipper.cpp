#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;

_input_filter = false;

_pwm = 255;
_pwm_hold = 235;

}

void Flipper::serial_print(bool serial_print) {
_serial_print = serial_print;
}

void Flipper::failsafe(bool failsafe) {
_failsafe = failsafe;
}

void Flipper::pwm(uint8_t pwm) {
_pwm = pwm;
} 

void Flipper::pwm_hold(uint8_t pwm_hold) {
_pwm_hold = pwm_hold;
}

void Flipper::activate() {

_input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
solenoid.on_pwm_reduce(_pwm,_pwm_hold);
} else {
solenoid.off_pwm();
}

if(_serial_print == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_serial_message);
    }
}

}
