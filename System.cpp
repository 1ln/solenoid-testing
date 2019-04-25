#include "Arduino.h"
#include "System.h"

System::System() {

_channel = 0;
_freq = 5000;
_res = 8;

}

void System::set_wifi_sta_on() {
#ifdef PBLIB_ESP32
WiFi.mode(WIFI_MODE_STA);
#endif
}

String System::get_node_mac(void) {
#ifdef ESP32
return String(WiFi.macAddress());
#else 
return String("wifi esp32 undefined");
#endif
}

void System::set_esp32_pwm_config(uint8_t channel,double freq,uint8_t res) {
_channel = channel;
_freq = freq;
_res = res;
}

void System::set_pins_pwm(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
ledcSetup(_channel,_freq,_res);
ledcAttachPin(*pins,_channel);
//pinMode(*pins,OUTPUT);
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
pinMode(*pins,INPUT);
pins++;
}

}
