#include "Arduino.h"
#include "Filter.h"

Filter::Filter() {

_current_edge = HIGH;
_last_edge = HIGH;
_input = HIGH;
_debounce_clock = 0;
_count = 0;
_edge_detected = false;

}

bool Filter::detect_edge(uint8_t pin,unsigned long range_millis) {

_input = digitalRead(pin);

//reset debounce clock to current millis
if(_input != _last_edge) {
debounce_clock = millis();
}

if((millis() - debounce_clock) > range_millis) {

     if(_input != current_edge) {
     current_edge = _input;

         if(_input == LOW) {
         _edge_detected = true;
         _count++;
         } else {
         _edge_detected = false;
         } 

     } 

}

_last_edge = _input;
return _edge_detected;

}

int Filter::get_count() {
return _count;
}

void Filter::reset_count() {
_count = 0;
}
