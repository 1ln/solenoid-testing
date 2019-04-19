#include "Arduino.h"
#include "System.h"

System::System() {

}

void System::set_pin_pwm_esp32(uint8_t pin,uint8_t channel,double freq,uint8_t res) {
ledcSetup(channel,freq,res);
ledcAttachPin(pin,channel);
}

void System::set_pin_input_pullup(uint8_t pin) {
pinMode(pin,INPUT_PULLUP);
}

void System::set_pins_pwm_esp32(uint8_t *pins,uint8_t num_pins,uint8_t channel,double freq,uint8_t res) {

for(int i = 0; i < num_pins; ++i) {
ledcSetup(channel,freq,res);
ledcAttachPin(*pins,channel);
pins++;
}

}

void System::set_pins_input_pullup(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}

void System::set_pins_input(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}
