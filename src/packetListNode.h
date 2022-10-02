#include "packet.h"

typedef struct PacketListNode
{
	struct PacketListNode *next;
    Packet *packet;
} PacketListNode;

PacketListNode *createPacketListNode(Packet *packet, PacketListNode *next);