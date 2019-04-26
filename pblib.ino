#include "pblib.h"

uint8_t inputs_pullup[] = { 22,14,23,26,5,16};
uint8_t outputs[] = { 18,21 };

System sys;

//uint8_t tr_switches[] = { 22,14,23 };
//uint8_t dt_switches[] = { 22,14,23 };
const Configure flipper_config = { 2,true,false };

Flipper flipper_left(16,18,flipper_config);
//Trough trough(tr_switches,3,21,26,5);
//DropTarget drop_target(dt_switches,3,18);
//Kicker kicker(22,18);

void setup() {

Serial.begin(115200);

//sys.set_esp32_pwm_config(0,5000,8);
sys.set_pins_input_pullup(inputs_pullup,6);
sys.set_pins_pwm(outputs,2);

//sys.set_wifi_sta_on();
//Serial.println(sys.get_node_mac());
}

void loop() {

flipper_left.activate();
//Serial.println(trough.inv_count());
//kicker.coil_active();
//Serial.println(drop_target.inv_targets_activated());
}
