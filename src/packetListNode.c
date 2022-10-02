#include <stdlib.h>
#include "packetListNode.h"

PacketListNode *createPacketListNode(Packet *packet, PacketListNode *next)
{
    PacketListNode *node = (PacketListNode *) malloc(sizeof(PacketListNode));
    node->packet = packet;
    node->next = next;
    return node;
}