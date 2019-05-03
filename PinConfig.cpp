#include "Arduino.h"
#include "PinConfig.h"

PinConfig::PinConfig() {

_channel = 0;
_freq = 5000;
_res = 8;

_pin = 0;

}

void PinConfig::set_esp32_pwm_config(uint8_t channel,double freq,uint8_t res) {
_channel = channel;
_freq = freq;
_res = res;
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
