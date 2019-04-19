#ifndef DelayState_H
#define DelayState_H

#include "Arduino.h"

class DelayState {

public:

DelayState();

bool wait_interval(unsigned long interval);

private:

bool _limit_reached;
unsigned long _limit;

};

#endif
