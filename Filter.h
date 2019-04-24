#ifndef Filter_h
#define Filter_h

#include "Arduino.h"

class Filter {

public:

Filter();

bool edge_status(bool edge);
bool detect_edge(uint8_t pin);
int get_count();
void set_edge_millis(unsigned long range_millis);
void reset_count();
bool ir_digital_read(uint8_t pin);
bool ir_read(uint8_t pin);
void set_ir_compare_value(uint16_t compare_value);
void set_ir_bit_value(bool bit_value);

private:

bool _edge_status;
bool _last_edge_status;
bool _edge_value;

bool _edge_detected;
uint8_t _input;
uint8_t _current_edge;
uint8_t _last_edge;
unsigned long _debounce_clock;
unsigned int _count;
unsigned long _range_millis;

bool _ir_value;
bool _ir_input;
bool _bit_value;
bool _value_ir_compare;

};

#endif
