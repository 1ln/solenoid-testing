#include "Arduino.h"
#include "Target.h"

Target::Target(uint8_t input_pin,const Configure &set_config) {

_input = input_pin;
_input_filter = false;

_onboard_address = set_config.onboard_address;
_serial_print = set_config.serial_print;
_serial_message = set_config.serial_message;

}

void Target::serial_print(bool serial_print) {
_serial_print = serial_print;
}

void Target::onboard_address(uint16_t onboard_address) {
_onboard_address = onboard_address;
}

void Target::switch_active() {

_input_filter = filter.detect_edge(_input);

if(_serial_print == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_serial_message);
    }
}

}