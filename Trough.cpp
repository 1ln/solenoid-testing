#include "Arduino.h"
#include "Trough.h"

Trough::Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin,uint8_t kickout_ir_pin,uint8_t jam_ir_pin) {

_output = output_pin;

_serial_activated = false;

//_pins = input_pins;
_num_pins = num_pins;
_count = 0;
_filter_results[_num_pins];
filter = new Filter();
_filter_kickout_ir = false;

_kickout_ir_pin = kickout_ir_pin;
_jam_ir_pin = jam_ir_pin;

memcpy(&_pins,&input_pins,sizeof _pins);

}

void Trough::serial_activate() {

_serial_activated = true;

}

bool Trough::kickout_ir_active() {

_filter_kickout_ir = kickout_filter.ir_digital_read(_kickout_ir_pin);
if(_filter_kickout_ir == true) {
_kickout = true;
Serial.println("test");
} else {
_kickout = false;
}
return _kickout;
}

uint8_t Trough::inv_count() {

if(kickout_ir_active() == true) {
_count = 1;
} else {
_count = 0;
}

for(int i = 0; i < _num_pins; ++i) {

_filter_results[i] = filter[i].detect_edge(_pins[i]);

    if(_filter_results[i] == true) {
    _count++;
    }
}

return _count;
}

void Trough::pwm_value(uint32_t pwm_value) {
_pwm = pwm_value;
}

void Trough::loop_active() {

if((inv_count() >= _num_pins) && _jam != true) {
solenoid.on_pwm(_pwm);
} else {
solenoid.off_pwm();
}

}

bool Trough::jam_ir_active() {

if(jam_filter.ir_digital_read(_jam_ir_pin) == true) {
_jam = true;
} else {
_jam = false;
}
return _jam;
}

void Trough::activate_solenoid() {

solenoid.on_pwm(_pwm);
solenoid.off_pwm();

}
