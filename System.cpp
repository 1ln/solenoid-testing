#include "Arduino.h"
#include "System.h"

System::System() {

_channel = 0;
_freq = 5000;
_res = 8;
_hall_value = 0;

_pin = 0;

}

#ifdef PBLIB_ESP32

void System::set_wifi_sta_on() {
WiFi.mode(WIFI_MODE_STA);
}

String System::get_node_mac(void) {
return String(WiFi.macAddress());
}

int System::read_hall_sensor() {
_hall_value = hallRead();
return _hall_value;
}

void System::set_esp32_pwm_config(uint8_t channel,double freq,uint8_t res) {
_channel = channel;
_freq = freq;
_res = res;
}

void System::bluetooth_connect() {

BLEDevice::init("test");
BLEServer *btServer = BLEDevice::createServer();
BLEService *btService = btServer->createService(SERVICE_UUID);

BLECharacteristic *btCharacteristic = btService->createCharacteristic(

CHARACTERISTIC_UUID,
BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE );

btCharacteristic->setValue("testing!");
btService->start();

BLEAdvertising *btAdvertising = btServer->getAdvertising();
btAdvertising->start();

} 

#endif

void System::set_pins_pwm(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
ledcSetup(_channel,_freq,_res);
ledcAttachPin(*pins,_channel);
//pinMode(*pins,OUTPUT);
pins++;
} 
}

void System::set_pins_input_pullup(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT_PULLUP);
pins++;
}

}

void System::set_pins_input(uint8_t *pins,uint8_t num_pins) {

for(int i = 0; i < num_pins; ++i) {
pinMode(*pins,INPUT);
pins++;
}

}

uint8_t System::set_system_button(uint8_t pin) {
_pin = pin;
pinMode(_pin,INPUT_PULLUP);
return _pin;
}
