#include "Arduino.h"
#include "SystemConfigure.h"

SystemConfigure::SystemConfigure() {

}

void SystemConfigure::set_pin_pwm_esp32(uint8_t pin,uint8_t channel,double freq,uint8_t res) {
ledcSetup(pin,freq,res);
ledcAttachPin(pin,channel);
}

void SystemConfigure::set_pin_input_pullup(uint8_t pin) {
pinMode(pin,INPUT_PULLUP);
}

void SystemConfigure::set_pins_output(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,OUTPUT);
digitalWrite(*pins,HIGH);
pins++;
}

}

void SystemConfigure::set_pins_input(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT);
pins++;
}

}

void SystemConfigure::set_pins_input_pullup(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}
