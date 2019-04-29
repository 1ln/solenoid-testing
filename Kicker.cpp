#include "Arduino.h"
#include "Kicker.h"

Kicker::Kicker(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;

_input_filter = false;
_millis_receive = 0;

_ir = ir;

_pwm = 0;
_serial_activated = false;
_millis_wait_amt = 2500;
_millis_coil_on = 500;

}

void Kicker::serial_activate() {
_serial_activated = true;
}

void Kicker::pwm(uint32_t pwm) { 
_pwm = pwm;
}

void Kicker::millis_config(unsigned long millis_wait_amt,unsigned long millis_coil_on_amt) {

_millis_wait_amt = millis_wait_amt;
_millis_coil_on_amt = millis_coil_on_amt;

}

void Kicker::ir_device(bool ir) {
_ir = ir;
}

void Kicker::message(const char * message) {
_message = message;
}

void Kicker::coil_active() {

if(_ir == true) {

_input_filter = filter.edge_status(_input);

    if(_input_filter == true) {
    _millis_receive = millis();
    } 

} else {
_input_filter = filter.detect_edge(_input);

    if(filter.edge_status(_input_filter == true)) {
    _millis_receive = millis();
    }

}

if(millis() <= _millis_wait_amt + _millis_receive) {

    if(millis() >= ((_millis_wait_amt + _millis_receive) - _millis_coil_on_amt)) {
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
