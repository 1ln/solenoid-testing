#include "Arduino.h"
#include "CANSystem.h"

CANSystem::CANSystem() {

_packet_size = 0;
_packet_rec = NULL;
_num_chars = 0;
_packet = NULL;
_packets[8] = NULL;

}

//500E3
void CANSystem::begin(long kbps) {

_kbps = kbps;

if(!CAN.begin(_kbps)) {
Serial.println("CAN Init Error");
while(1);
}

}

void CANSystem::send_packet(int packet_id,const char * packet,uint8_t num_chars) {

_packet_id;
_packet = packet;
_num_chars = num_chars;

if(_num_chars > 8) {
Serial.println("Limit, 8 bytes");

} else {

strcpy(_packets,_packet);

CAN.beginPacket(_packet_id);

    for(int i = 0; i <= _num_chars; ++i) {
    CAN.write(_packets[i]);
    }

CAN.endPacket();
}

} 

void CANSystem::rec_packet() {

_packet_size = CAN.parsePacket();

if(_packet_size != false) {

    if(CAN.packetRtr() == true) {

    } else {

    while(CAN.available()) {
    //_packet_rec = CAN.read(); 
    Serial.println(CAN.read());
    }
} 
}
} 

