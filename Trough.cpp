#include "Arduino.h"
#include "Trough.h"

Trough::Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {

_output = output_pin;
_serial_activated = false;
_pins = input_pins;
_num_pins = num_pins;
_count = 0;
_filter_results;
filter = new Filter();

memcpy(&_pins,&input_pins,sizeof _pins);

}

void Trough::serial_activate() {
_serial_activated = true;
}

uint8_t Trough::inventory() {

for(int i = 0; i < _num_pins; ++i) {
//uint8_t pin = *_pins;
if(filter[i].detect_edge(_pins[i],15) == false) {
Serial.println("test");
} 
//Serial.println(_pins[i]);
//Serial.println("test");

//if(_input_filter != false) {
    //if(filter.edge_status(_input_filter) == true) {
    //_count++;
    //_stack[i] = true;
    //Serial.println("test");
    //} else {
    //Serial.println("test1");
    //_stack[i] = false;
    //}
}
//*_pins++;


//}

//for(int i = 0; i < _num_pins; ++i) {
//if(_stack[i] == true) { 
// _count++;
//}
//}
//Serial.println(_count);
return _count;
}

//solenoid.on_pwm_reduce_esp32(0,255,15,2000);
//solenoid.on_pwm(0,255);
//solenoid.on(_output);
//} else {
//solenoid.off_pwm_esp32(0);
//solenoid.off(_output);
//}

//if(_serial_activated == true) {
    //if(filter.edge_status(_input_filter) == true) {
    //Serial.print("test");
    //}
//}

//}
