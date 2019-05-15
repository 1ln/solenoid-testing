#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {

_output = output_pin;
_serial_activated = false;
_num_pins = num_pins;
_filter_results[_num_pins];

filter_group = new Filter();

_count = 0;
_pwm = 0;
_millis_rec = 0;
_reduced_modulation = false;

memcpy(&_pins,&input_pins,sizeof _pins);

}

_serial_activated = true;
}

void Solenoid::activateOnceOnInputsLow() {

    if(numberOfInputsLow() >= _num_pins) {
    analogWrite(_output,_pwm);
    } else {
    analogWrite(_output,0);
    }
    
}

void Solenoid::reducePwmAfterDelay(uint32_t pwm_reduce,unsigned long millis_hold) {
   
    _input_filter = filter.detect_edge(_input);

if(_input_filter == true) {

    if(delay_state.wait_interval(millis_hold) == true) {
    _reduced_modulation = true;
    }

    if(_reduced_modulation == true) {
    analogWrite(_input_pin,pwm_reduce);
    } else {
    analogWrite(_input_pin,_pwm);
    }

} else {

analogWrite(_input_pin,0);

}
 
}



void Solenoid::activateOnceAfterDelay(unsigned long millis_wait,unsigned long millis_coil_on) {

_input_filter = filter.detect_edge(_input);

if(filter.edge_status(_input_filter == true)) {
_millis_rec = millis(); 
} 

if(millis() <= millis_wait + _millis_rec) {

    if(millis() >= ((millis_wait + _millis_rec) - millis_coil_on)) {
    analogWrite(_output,_pwm);
    }

} else {
analogWrite(_output,0);
}

if(_serial_activated == true) {
    if(filter.edge_status(_input_filter) == true) {
    serial.transmit(_message);
    }
}

}

uint8_t Solenoid::numberOfInputsLow() {

_count = 0;

for(int i = 0; i < _num_pins; ++i) {

_filter_results[i] = filter[i].detect_edge(_pins[i]);

if(_filter_results[i] == true) {
_count++;
}
}

return _count;

}

void Solenoid::pwmValue(uint32_t pwm_value) {
_pwm = pwm_value;
}
