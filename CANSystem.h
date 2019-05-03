#ifndef CANSystem_H
#define CANSystem_H

#include "Arduino.h"
#include "DelayState.h"
#include "CAN.h"

class CANSystem {

public:

CANSystem();

void begin(long kbps);
void send_packet(int packet_id,const char * packet,uint8_t num_chars);
void rec_packet();

private:

char * _packet_rec;
char _packets[];
const char * _packet;
int _num_chars;
int _packet_size;
int _packet_id; 
long _kbps;

};

#endif
