#include "pblib.h"

//uint8_t inputs_pullup[] = { 22,14,23,26,5};
//uint8_t inputs[] = { 26,5 };
//uint8_t outputs[] = { 18,21 };


System sys;

//uint8_t tr_switches[] = { 22,14,23 };
uint8_t dt_switches[] = { 22,14,23 };

//Flipper flipper_left(16,18);
//Trough trough(tr_switches,3,21,26,5);
DropTarget drop_target(dt_switches,3,18);

void setup() {

Serial.begin(115200);

pinMode(22,INPUT_PULLUP);
pinMode(14,INPUT_PULLUP);
pinMode(23,INPUT_PULLUP);
//sys.set_pins_input(inputs,2);
sys.set_esp32_pwm_config(0,5000,8);
//sys.set_pins_input_pullup(inputs_pullup,5);
//sys.set_pins_pwm(outputs,2);
sys.set_pin_pwm(18);
//delay(2000);
//sys.set_wifi_sta_on();
//Serial.println(sys.get_node_mac());
}

void loop() {

//flipper_left.activate();
//Serial.println(trough.inv_count());
//Serial.println(trough.kickout_ir_active());
Serial.println(drop_target.inv_targets_activated());
//trough.kickout_ir_active();
}
