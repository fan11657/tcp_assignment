typedef unsigned char Byte;

typedef struct Packet
{
    int seqNum;
    int len;
    Byte *body;
} Packet;

Packet *createPacket(int seqNum, int len, Byte *body);