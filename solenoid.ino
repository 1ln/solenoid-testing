#include "solenoid.h"

uint8_t inputs_pullup[] = {5,9,11};
const uint8_t inp = 6;
const uint8_t out = 12;

Solenoid coil_device;

void setup() {

Serial.begin(115200);

coil_device.pinConfigInputsPullup(inputs_pullup,3); 
coil_device.pinConfigInputPullup(inp);
coil_device.pinConfigOutput(out);

coil_device.pwmValue(245);

}

void loop() {

//coil_device.activateOnceAfterDelay(2500,150);
//coil_device.reducePwmAfterDelay(50,1500);
//coil_device.numberOfInputsLow();
//coil_device.activateOnceOnInputsLow();
Serial.println(coil_device.numberOfInputsLow());
}
