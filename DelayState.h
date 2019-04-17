#ifndef DelayState_H
#define DelayState_H

#include "Arduino.h"

class DelayState {

public:

DelayState();

bool wait_until(unsigned long interval);

private:

bool _limit_reached = true;
unsigned long _limit = 0;

};

#endif
