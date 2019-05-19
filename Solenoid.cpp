#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid() {

_input_filter = false;
_serial_activated = false;

filter_group = new Filter();

_count = 0;

_pwm = 0;

_millis_rec = 0;
_millis_hold = 0;
_millis_wait = 0;
_millis_coil_on = 0;

_reduced_modulation = false;

_serial_activated = true;

}

//Configuration functions

void Solenoid::pinConfigInputsPullup(uint8_t *pins, uint8_t num_pins) {

_num_pins = num_pins;
memcpy(&_pins,&pins,sizeof _pins);

for(int i = 0; i <= _num_pins-1; ++i) {
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

void Solenoid::serialMessage(const char * message) {
_message = message;
}

//Solenoid functions

void Solenoid::activateOnceOnInputsLow() {

    if(numberOfInputsLow() >= _num_pins) {
    analogWrite(_output,_pwm);
    } else {
    analogWrite(_output,0);
    }
    
}

void Solenoid::reducePwmAfterDelay(uint8_t pwm_reduce,unsigned long millis_hold) {
 
_millis_hold = millis_hold; 

_input_filter = filter.detect_edge(_input);
   
if(filter.edge_status(_input_filter) == true) {
_millis_rec = millis(); 

    if(_serial_activated == true) {
    Serial.println(_message);
    }
} 

if(_input_filter == true) { 

if(millis() >= _millis_rec + _millis_hold ) {
    analogWrite(_output,pwm_reduce);
    } else {
    analogWrite(_output,_pwm);
    }

} else {
analogWrite(_output,0);

}
 
}

void Solenoid::activateOnceAfterDelay(unsigned long millis_wait,unsigned long millis_coil_on) {

_input_filter = filter.detect_edge(_input);

if(filter.edge_status(_input_filter) == true) {
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
    Serial.println(_message);
    }
}

}

uint8_t Solenoid::numberOfInputsLow() {

_count = 0;

for(int i = 0; i <= _num_pins-1; ++i) {

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
