#include "Arduino.h"
#include "PinConfig.h"

PinConfig::PinConfig() {


}

void PinConfig::set_pins_pwm(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
//ledcSetup(_channel,_freq,_res);
//ledcAttachPin(*pins,_channel);
pinMode(*pins,OUTPUT);
pins++;
} 
}

void PinConfig::set_pins_input_pullup(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}

void PinConfig::set_pins_input(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT);
pins++;
}

}
