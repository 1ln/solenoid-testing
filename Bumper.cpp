#include "Arduino.h"
#include "Bumper.h"

Bumper::Bumper(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;
_input_filter = false;
_serial_activated = false;
_pwm = 0;

}

void Bumper::serial_activate() {
_serial_activated = true;
}

void Bumper::message(const char * message) {
_message = message;
} 

void Bumper::pwm(uint8_t pwm) {
_pwm = pwm;
}

void Bumper::coil_activate() {

_input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
solenoid.on_pwm(_output,_pwm);
} else {
solenoid.off_pwm(_output);
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_message);
    }
}

}
