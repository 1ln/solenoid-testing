#include "Arduino.h"
#include "Trough.h"

Trough::Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin,uint8_t jam_pin) {

_output = output_pin;

_serial_activated = false;

_pins = input_pins;
_num_pins = num_pins;
_count = 0;
_filter_results[num_pins];
filter = new Filter();

_jam_pin = jam_pin;

memcpy(&_pins,&input_pins,sizeof _pins);

}

void Trough::serial_activate() {

_serial_activated = true;

}

uint8_t Trough::inv_count() {

_count = 0;

for(int i = 0; i < _num_pins; ++i) {

_filter_results[i] = filter[i].detect_edge(_pins[i],15);

    if(_filter_results[i] == true) {
    _count++;
    }

}

return _count;
}

void Trough::loop_activate() {

if((inv_count() >= _num_pins) && _jam != true) {
solenoid.on_pwm_esp32(0,255);
} else {
solenoid.off_pwm_esp32(0);
}

}

bool Trough::jam_activated() {

if(jam_filter.detect_edge(_jam_pin,15) == true) {
_jam = true;
} else {
_jam = false;
}
return _jam;
}

void Trough::activate_solenoid() {

solenoid.on_pwm_esp32(0,255);
solenoid.off_pwm_esp32(0);

}
