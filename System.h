#ifndef System_H
#define System_H

#include "Arduino.h"
#include "WiFi.h"

class System {

public:

System();

void set_wifi_sta_on();
String get_node_mac();

void set_pin_input_pullup(uint8_t pin);
void set_pin_pwm_esp32(uint8_t pin,uint8_t channel,double freq,uint8_t res);
void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_pwm_esp32(uint8_t *pins,uint8_t num_pins,uint8_t channel,double freq,uint8_t res);

};

#endif
