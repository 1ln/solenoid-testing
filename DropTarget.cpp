#include "Arduino.h"
#include "DropTarget.h"

DropTarget::DropTarget(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {

_output = output_pin;
_serial_activated = false;
_num_pins = num_pins;
_filter_results[_num_pins];
filter = new Filter();
_count = 0;
_pwm = 0;

memcpy(&_pins,&input_pins,sizeof _pins);

}

void DropTarget::serial_activate() {
_serial_activated = true;
}

void DropTarget::coil_active() {

    if(inv_targets_activated() >= _num_pins) {
    solenoid.on_pwm(_pwm);
    } else {
    solenoid.off_pwm();
    }
    
}

uint8_t DropTarget::inv_targets_activated() {

_count = 0;

for(int i = 0; i < _num_pins; ++i) {

_filter_results[i] = filter[i].detect_edge(_pins[i]);

if(_filter_results[i] == true) {
_count++;
}
}

return _count;

}

void DropTarget::pwm_value(uint32_t pwm_value) {
_pwm = pwm_value;
}
