#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"
#include "Filter.h"
#include "SerialTransfer.h"

class Solenoid {

public:

Solenoid(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter *filter;
SerialTransfer serial;
DelayState delay_state;
 
//void activateOnInput();
void activateOnInputReducePWM(uint32_t pwm_reduce,unsigned long millis_hold); 
void activateOnInputWait(unsigned long millis_wait,unsigned long millis_coil_on);
void activateOnInputs();

void setSerialActive();
void setPwmValue(uint32_t pwm_value); 

uint8_t numberOfInputsLow();

private:

uint8_t _num_pins;
uint8_t *_pins;
uint8_t _count;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];

unsigned long _millis_rec;

uint32_t _pwm;

};

#endif
