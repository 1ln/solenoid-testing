#ifndef "Filter.h"
#define "Filter.h"

class Filter {

public:

bool debounce(uint8_t pin,unsigned long range_millis);
int get_edge_count();
void reset_edge_count();

private:

bool _edge_detected;
uint8_t _input;
uint8_t _current_edge;
uint8_t _last_edge;
unsigned long debounce_clock;
unsigned int count; 

};

#endif
