#include "Arduino.h"
#include "Scoop.h"

Scoop::Scoop(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;
_input_filter = false;
_serial_activated = false;
_millis_wait = 2500;
_millis_coil_on = 500;
_millis_receive = 0;
}

void Scoop::serial_activate() {
_serial_activated = true;
}

void Scoop::coil_active() {

_input_filter = filter.edge_status(_input);

if(_input_filter == true) {
_millis_receive = millis();
} 


if(millis() <= _millis_wait + _millis_receive) {

    if(millis() >= ((_millis_wait + _millis_receive) - _millis_coil_on)) {
    solenoid.on_pwm();
    }

} else {
solenoid.off_pwm();
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    }
}

}
