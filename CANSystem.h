#ifndef CANSystem_H
#define CANSystem_H

#include "Arduino.h"
#include "DelayState.h"

class CANSystem {

public:

CANSystem();

void begin();
void send_packet(int packet_id,constant char * packet,int num_chars);
void rec_packet();

private:

const char _packets[];
const char * _packet;
int num_chars;
int packet_size;
int packet_id;


};

#endif
