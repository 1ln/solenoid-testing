#include "Arduino.h"
#include "SerialTransfer.h"

SerialTransfer::SerialTransfer() {

}

void SerialTransfer::transmit(char const * message) {
Serial.println(message);
}
