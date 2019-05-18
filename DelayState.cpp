#include "Arduino.h"
#include "DelayState.h"

DelayState::DelayState() {

_limit = 0;
_limit_reached = false;

}

bool DelayState::wait_interval(unsigned long interval) {

    if((millis() - _limit) >= interval) {
    _limit = millis();
    //Serial.println("on");
    _limit_reached = true;
    } else {
    //Serial.println("off");
    _limit_reached = false;
    }

return _limit_reached;
}
