#include "pblib.h"

uint8_t inputs_pullup[] = { 16,5,34 };
uint8_t outputs[] = { 18,22 };

System sys;

//const int tr_switches[5] = { 25,26,27,A2,A3 };

Flipper flipper_left(16,18);

void setup() {

Serial.begin(115200);
//pinMode(18,OUTPUT);
//sys.set_pin_pwm_esp32(18,0,5000,8);
//sys.set_pin_input_pullup(16);

flipper_left.serial_activate();
sys.set_pins_input_pullup(inputs_pullup,3);
sys.set_pins_pwm_esp32(outputs,2,0,5000,8);

//config.startup_wait(1000);

}

void loop() {

flipper_left.activate();

}
