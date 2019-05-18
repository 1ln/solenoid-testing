#include "solenoid.h"

uint8_t inputs_pullup[] = {11,10,9};
//uint8_t outputs[] = { 12 };
const uint8_t inp = 6;
const uint8_t out = 12;

//Solenoid coil_device(inputs_pullup,4,out);
Solenoid coil_device;

void setup() {

Serial.begin(115200);
coil_device.pinConfigInputPullup(inp);
coil_device.pinConfigOutput(out);

coil_device.pwmValue(245);


}

void loop() {
coil_device.activateOnceAfterDelay(2500,150);
//Serial.println(coil_device.numberOfInputsLow());
}
