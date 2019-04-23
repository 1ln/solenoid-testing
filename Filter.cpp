#include "Arduino.h"
#include "Filter.h"

Filter::Filter() {

_last_edge_status = false;
_edge_value = false;
_edge_status = false;

_current_edge = HIGH;
_last_edge = HIGH;
_input = HIGH;
_debounce_clock = 0;
_count = 0;
_edge_detected = false;

_ir_input = 0;
_ir_value = 0;
_bit_value = 0;
_value_ir_compare = 0;

}

bool Filter::edge_status(bool edge) {

_edge_value = edge;

if(_edge_value != _last_edge_status) {

    if(_edge_value == true) {
    _edge_status = true;
    }

} else {
    _edge_status = false;
}

_last_edge_status = _edge_value;
return _edge_status;

}

bool Filter::detect_edge(uint8_t pin,unsigned long range_millis) {

_input = digitalRead(pin);

//if(_input == LOW) {
//Serial.println("test");
//}

//reset debounce clock to current millis
if(_input != _last_edge) {
_debounce_clock = millis();
}

if((millis() - _debounce_clock) > range_millis) {

     if(_input != _current_edge) {
     _current_edge = _input;

         if(_input == LOW) {
         //Serial.println("test");
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

void Filter::set_ir_compare_value(uint16_t compare_value) {
_value_ir_compare = compare_value;
} 

void Filter::set_ir_bit_value(bool bit_value) {

_bit_value = bit_value;

}

bool Filter::ir_read(uint8_t pin) {

_ir_input = analogRead(pin);

if(_ir_input < _value_ir_compare) {
_ir_value = true;
} else {
_ir_value = false;
}

return _ir_value;

}

bool Filter::ir_digital_read(uint8_t pin) {

_ir_input = digitalRead(pin);

if(_ir_input > _bit_value) {
_ir_value = true;
} else {
_ir_value = false;
}
return _ir_value;
}

int Filter::get_count() {
return _count;
}

void Filter::reset_count() {
_count = 0;
}
