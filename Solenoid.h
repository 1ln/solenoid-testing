#ifndef Solenoid_H
#define Solenoid_H

#include "Arduino.h"
#include "DelayState.h"
#include "Filter.h"
#include "SerialTransfer.h"

class Solenoid {

public:

Solenoid();
//Solenoid(uint8_t *input_pins,uint8_t num_pins,uint8_t output);

Filter *filter_group;
Filter filter;
SerialTransfer serial;
DelayState delay_state;

void pinConfigInputsPullup(uint8_t *pins,uint8_t num_pins);
void pinConfigInputPullup(uint8_t pin);
void pinConfigOutput(uint8_t pin);

void reducePwmAfterDelay(uint8_t pwm_reduce,unsigned long millis_hold); 
void activateOnceAfterDelay(unsigned long millis_wait,unsigned long millis_coil_on);
void activateOnceOnInputsLow();

void serialActive();
void pwmValue(uint8_t pwm_value); 

uint8_t numberOfInputsLow();

private:

uint8_t _num_pins;
uint8_t *_pins;
uint8_t _count;

uint8_t _input;
uint8_t _output;

bool _serial_activated;
bool _filter_results[];
bool _input_filter;
bool _reduced_modulation;

const char * _message;

unsigned long _millis_rec;
unsigned long _millis_wait;
unsigned long _millis_hold;
unsigned long _millis_coil_on;

uint8_t _pwm;

};

#endif
