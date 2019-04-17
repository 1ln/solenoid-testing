#include "Arduino.h"
#include "Configure.h"

Configure::Configure() {

}

void Configure::set_pins_output(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,OUTPUT);
digitalWrite(*pins,HIGH);
pins++;
}

}

void Configure::set_pins_input(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT);
pins++;
}

}

void Configure::set_pins_input_pullup(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}
