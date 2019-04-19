#include "Arduino.h"
#include "Trough.h"

Trough::Trough(uint8_t *input_pins,uint8_t num_pins,uint8_t output_pin) {

//_input = input_pin;
_output = output_pin;
_input_filter = false;
_serial_activated = false;
_stack[num_pins] = { 0 };
_num_pins = num_pins;


}

void Trough::serial_activate() {
_serial_activated = true;
}

bool Trough::inventory() {

//bool items[num_pins] = { 0 };

for(int i = 0; i < _num_pins; ++i) {
_input_filter = filter.detect_edge(*input_pins,12);

    if(_input_filter == true) {
    _stack[i] = true;
    } else {
    _stack[i] = false;
    }

}
return stack;
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
