#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin,const Configure &set_config) {

_input = input_pin;
_output = output_pin;
_input_filter = false;
_onboard_address = set_config.onboard_address;
_serial_print = set_config.serial_print;
_serial_message = set_config.serial_message;
_failsafe = set_config.failsafe;

}

void Flipper::serial_print(bool serial_print) {
_serial_print = serial_print;
}

void Flipper::onboard_address(uint16_t onboard_address) {
_onboard_address = onboard_address;
}

void Flipper::failsafe(bool failsafe) {
_failsafe = failsafe;
}


void Flipper::activate() {

_input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
solenoid.on_pwm_reduce();
} else {
solenoid.off_pwm();
}

if(_serial_print == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_serial_message);
    }
}

}
