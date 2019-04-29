#include "Arduino.h"
#include "PlayfieldSwitch.h"

PlayfieldSwitch::PlayfieldSwitch(uint8_t input_pin) {

_input = input_pin;

_input_filter = false;

}

void PlayfieldSwitch::message(const char * message) {
_message = message;
}

void PlayfieldSwitch::serial_active(bool activate) {
_serial_activated = activate;
}

void PlayfieldSwitch::switch_active() {

_input_filter = filter.detect_edge(_input);

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_message);
    }
}

}
