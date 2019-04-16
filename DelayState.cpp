#include "Arduino.h"
#include "DelayState.h"

DelayState()::DelayState() {

}

bool DelayState::wait_until(unsigned long interval) {

    if(millis() - _limit >= interval) {
    _limit = millis();
    _limit_reached = true;
    } else {
    _limit_reached = false;
    }

return _limit_reached;
}

