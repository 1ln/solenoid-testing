#ifndef "Configure.h"
#define "Configure.h"

class Configure {

public:

void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_output(uint8_t *pins,uint8_t num_pins);

};

#endif
