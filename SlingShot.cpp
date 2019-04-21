#include "Arduino.h"
#include "SlingShot.h"

SlingShot::SlingShot(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;
_input_filter = false;
_serial_activated = false;

}

void SlingShot::serial_activate() {
_serial_activated = true;
}

void SlingShot::activate() {

_input_filter = filter.detect_edge(_input,12);

if(_input_filter == true) {
solenoid.on_pwm_esp32(0,225);
} else {
solenoid.off_pwm_esp32(0);
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    //Serial.print("test");
    }
}

}
