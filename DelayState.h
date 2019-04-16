#ifndef "DelayState_H"
#define "DelayState_H"

class DelayState {

public:

bool wait_until(unsigned long interval);

private:

bool _limit reached = false;
unsigned long _limit = 0;

};

#endif
