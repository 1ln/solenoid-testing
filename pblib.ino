#include "pblib.h"

uint8_t inputs_pullup[] = { 7,6,5,4,3,2};
uint8_t outputs[] = { 12,11 };

PinConfig pins;

//uint8_t tr_switches[] = { 7,6,5 };
uint8_t dt_switches[] = { 7,6,5 };

Flipper flipper_left(4,12);
//Trough trough(tr_switches,3,21,26,5);
DropTarget drop_target(dt_switches,3,11);
//Kicker kicker(16,18);

void setup() {

Serial.begin(115200);

pins.set_pins_input_pullup(inputs_pullup,6);
pins.set_pins_pwm(outputs,2);

flipper_left.hold_config(245,125,2500);
drop_target.pwm_value(245);
//kicker.pwm_value(245);
//kicker.millis_config(2500,500);

//sys.set_wifi_sta_on();
//Serial.println(sys.get_node_mac());

}

void loop() {

flipper_left.coil_active();
//Serial.println(trough.inv_count());
//kicker.coil_active();
Serial.println(drop_target.inv_targets_activated());
}
