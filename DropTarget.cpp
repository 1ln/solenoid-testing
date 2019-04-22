#include "Arduino.h"
#include "DropTarget.h"

DropTarget::DropTarget(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {

_output = output_pin;
_serial_activated = false;
_pins = input_pins;
_num_pins = num_pins;
_filter_results;

memcpy(&_pins,&input_pins,sizeof _pins);

}

void DropTarget::serial_activate() {
_serial_activated = true;
}

void DropTarget::activate() {

for(int i = 0; i < _num_pins; ++i) {

    if(filter.detect_edge(_pins[i],15) == false) {
    solenoid.on_pwm();
    Serial.println("test");
    } else {
    solenoid.off_pwm();
    }
    
}

}
