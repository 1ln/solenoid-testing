#include "Arduino.h"
#include "Flipper.h"

Flipper::Flipper(uint8_t input_pin,uint8_t output_pin) {

_input = input_pin;
_output = output_pin;

}

//void set_serial_comm(bool active,char * str) {
//_str = str;
//_serial_active = active;
//}

void Flipper::activate() {

if(debounce.detect_edge(_input,12) == true) {
coil.on_pwm_reduce(_output,245,215,50);
} else {
coil.off_pwm(_output);
}

}

