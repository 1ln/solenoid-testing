#ifndef System_H
#define System_H

#include "Arduino.h"
#include "WiFi.h"
#include "BLEDevice.h"
#include "BLEUtils.h"
#include "BLEServer.h"

#define PBLIB_ESP32

#define SERVICE_UUID ""
#define CHARACTERISTIC_UUID ""

class System {

public:

System();

void bluetooth_connect();
int read_hall_sensor();
void set_wifi_sta_on();
String get_node_mac();

void set_pin_input_pullup(uint8_t pin);
void set_pin_pwm(uint8_t pin);
void set_esp32_pwm_config(uint8_t channel,double freq,uint8_t res);
void set_pins_input(uint8_t *pins,uint8_t num_pins);
void set_pins_input_pullup(uint8_t *pins,uint8_t num_pins);
void set_pins_pwm(uint8_t *pins,uint8_t num_pins);

uint8_t set_system_button(uint8_t pin);

private:

uint8_t _channel;
double _freq;
uint8_t _res;
int _hall_value;

uint8_t _pin;

};

#endif
