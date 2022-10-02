#include <stdlib.h>
#include "packet.h"

Packet *createPacket(int seqNum, int len, Byte *body)
{
    Packet *packet = (Packet *) malloc(sizeof(Packet));
    packet->seqNum = seqNum;
    packet->len = len;
    packet->body = body;
    return packet;
}