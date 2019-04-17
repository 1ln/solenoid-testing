#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin) {

_input = _input_pin;
_output = _output_pin;

}

//void set_serial_comm(bool active,char * str) {
//_str = str;
//_serial_active = active;
//}

void Flipper::activate() {

if(debounce.detect_edge(_input) == true) {
coil.on_pwm_reduce(_output,245,215,50);
} else {
coil.off_pwm();
}

}

