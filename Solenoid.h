#ifndef "Solenoid.h"
#define "Solenoid.h"

#define "DelayState.h"

class Solenoid {

public:

void on_pwm(uint8_t pin, uint16_t pwm_value);
void off_pwm(uint8_t pin);
void on(uint8_t pin);
void off(uint8_t pin);
void on_pwm_hold(uint8_t pin,uint8_t pwm_value,unsigned long hold_millis);

DelayState delay;

};

#endif
