#include "Arduino.h"
#include "Kicker.h"

Kicker::Kicker(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;

_input_filter = false;
_millis_rec = 0;

_ir = false;

_pwm = 0;
_serial_activated = false;
_millis_wait = 2500;
_millis_coil_on = 500;

}

void Kicker::serial_activate() {
_serial_activated = true;
}

void Kicker::pwm_value(uint32_t pwm_value) { 
_pwm = pwm_value;
}

void Kicker::millis_config(unsigned long millis_wait_amt,unsigned long millis_coil_on_amt) {

_millis_wait = millis_wait_amt;
_millis_coil_on = millis_coil_on_amt;

}

void Kicker::ir_device(bool infrared) {
_ir = infrared;
}

void Kicker::message(const char * message) {
_message = message;
}

void Kicker::coil_active() {

if(_ir == true) {

_input_filter = filter.edge_status(_input);

    if(_input_filter == true) {
    _millis_rec = millis();
    } 

} else {
_input_filter = filter.detect_edge(_input);

    if(filter.edge_status(_input_filter == true)) {
    _millis_rec = millis();
    }

}

if(millis() <= _millis_wait + _millis_rec) {

    if(millis() >= ((_millis_wait + _millis_rec) - _millis_coil_on)) {
    solenoid.on_pwm(_pwm);
    }

} else {
solenoid.off_pwm();
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_message);
    }
}

}
