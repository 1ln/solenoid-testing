#include "pblib.h"

//const int inputs_pullup[4] = { 22,25,26,27 };
//const int inputs[2] = { A2,A3 };
//const int outputs[2] = { 12,11 };

SystemConfigure config;

//const int tr_switches[5] = { 25,26,27,A2,A3 };

Flipper flipper_left(16,2);

void setup() {

Serial.begin(115200);

config.set_pin_pwm_esp32(2,0,5000,8);
config.set_pin_input_pullup(16);

flipper_left.serial_activate();
//config.set_pins_input_pullup(inputs_pullup,6);
//config.set_pins_input(inputs,2);
//config.set_pins_output(outputs,4);

//config.startup_wait(1000);

}

void loop() {

flipper_left.activate();

}
