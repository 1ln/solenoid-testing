#include "solenoid.h"

uint8_t inputs_pullup[] = { 7,6,5};
uint8_t outputs[] = { 12 };

PinConfig pins;

uint8_t switches[] = { 7,6,5 };

Solenoid coil_device(switches,3,12);

void setup() {

Serial.begin(115200);

pins.set_pins_input_pullup(inputs_pullup,6);
pins.set_pins_pwm(outputs,1);

coil_device.pwm_value(245);


}

void loop() {

Serial.println(drop_target.inv_targets_activated());
}
