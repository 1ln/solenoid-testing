#include "Arduino.h"
#include "Solenoid.h"

//Solenoid::Solenoid(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {
Solenoid::Solenoid() {

//_output = 0;
//_input = 0;
_serial_activated = false;
//_num_pins = num_pins;
//_filter_results[_num_pins];

filter_group = new Filter();

_count = 0;

_pwm = 0;

_millis_rec = 0;
_millis_hold = 0;
_millis_wait = 0;
_millis_coil_on = 0;

_reduced_modulation = false;

//memcpy(&_pins,&input_pins,sizeof _pins);

_serial_activated = true;

}

void Solenoid::pinConfigInputsPullup(uint8_t *pins, uint8_t num_pins) {

_num_pins = num_pins;
memcpy(&_pins,&pins,sizeof _pins);

for(int i = 0; i < _num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;

}
}

void Solenoid::pinConfigInputPullup(uint8_t pin) {
_input = pin;
pinMode(_input,INPUT_PULLUP);
}

void Solenoid::pinConfigOutput(uint8_t pin) {
_output = pin;
pinMode(_output,OUTPUT);
}

void Solenoid::activateOnceOnInputsLow() {

    if(numberOfInputsLow() >= _num_pins) {
    analogWrite(_output,_pwm);
    } else {
    analogWrite(_output,0);
    }
    
}

void Solenoid::reducePwmAfterDelay(uint8_t pwm_reduce,unsigned long millis_hold) {
   
    _input_filter = filter.detect_edge(_input);

if(_input_filter == true) {
    if(delay_state.wait_interval(millis_hold) == true) {
    _reduced_modulation = true;
    }

    if(_reduced_modulation == true) {
    analogWrite(_input,pwm_reduce);
    } else {
    analogWrite(_input,_pwm);
    }

} else {

analogWrite(_input,0);

}
 
}



void Solenoid::activateOnceAfterDelay(unsigned long millis_wait,unsigned long millis_coil_on) {

_input_filter = filter.detect_edge(_input);

if(filter.edge_status(_input_filter == true)) {
_millis_rec = millis();
Serial.println("test");
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

_filter_results[i] = filter_group[i].detect_edge(_pins[i]);

if(_filter_results[i] == true) {
_count++;
}
}

return _count;

}

void Solenoid::pwmValue(uint8_t pwm_value) {
_pwm = pwm_value;
}
