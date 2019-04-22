#include "pblib.h"

uint8_t inputs_pullup[] = { 16,22,14,23 };
uint8_t outputs[] = { 18,21 };

uint8_t jam_pin = 5;

System sys;

uint8_t tr_switches[] = { 22,23,14 };

Flipper flipper_left(16,18);
Trough trough(tr_switches,3,21,jam_pin);

void setup() {

Serial.begin(115200);

//sys.set_pin_pwm_esp32(18,0,5000,8);
//sys.set_pin_input_pullup(16);
//flipper_left.serial_activate();
sys.set_pins_input_pullup(inputs_pullup,4);
sys.set_pins_pwm_esp32(outputs,2,0,5000,8);

//sys.set_wifi_sta_on();
//Serial.println(sys.get_node_mac());
}

void loop() {

flipper_left.activate();
Serial.println(trough.inv_count());

}
