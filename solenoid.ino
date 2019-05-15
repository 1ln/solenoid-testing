#include "solenoid.h"

uint8_t inputs_pullup[] = { 11,10,9};
//uint8_t outputs[] = { 12 };

PinConfig pins;

Solenoid coil_device(inputs_pullup,3,12);

void setup() {

Serial.begin(115200);

pins.set_pins_input_pullup(inputs_pullup,3);
//pins.set_pins_pwm(outputs,1);

coil_device.pwmValue(245);


}

void loop() {

Serial.println(coil_device.numberOfInputsLow());
}
