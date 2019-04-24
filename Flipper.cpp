#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;
_input_filter = false;
_serial_activated = false;

}

void Flipper::serial_activate() {
_serial_activated = true;
}

void Flipper::activate() {

_input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
solenoid.on_pwm_reduce();
} else {
solenoid.off_pwm();
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    //Serial.print("test");
    }
}

}
