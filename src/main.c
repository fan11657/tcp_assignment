#include <stdio.h>
#include <stdlib.h>
#include "packetListNode.h"
#include "tcpClient.h"

int parseBigEndianNum(Byte bytes[], int len)
{
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num += bytes[i] << ((len - 1 - i) * 8);
    }
    return num;
}

Packet *getPacket(TcpClient *tcp_client)
{
    // TODO: talk about head
    Byte head[6];
    int head_response_len = tcpRecieve(tcp_client, head, sizeof(head));
    if (head_response_len == 0)
    {
        return NULL;
    }
        
    int seqNum = parseBigEndianNum(head, 4);
    int len = parseBigEndianNum(head + 4, 2);
    
    int body_size = len * sizeof(Byte);
    Byte *body = (Byte *) malloc(body_size);
    int body_reponse_len = 0;
    while (body_reponse_len < len)
    {
        int body_request_size = body_size - (body_reponse_len * sizeof(Byte));
        Byte *buffer = body + body_reponse_len;
        body_reponse_len += tcpRecieve(tcp_client, buffer, body_request_size);
    }
    return createPacket(seqNum, len, body);
}

void sortPackets(PacketListNode *node, Packet *sorted_packets[])
{
    // sort packet by seq number
    // with counting sort
    while (node != NULL)
    {
        sorted_packets[node->packet->seqNum] = node->packet;
        
        // free node
        PacketListNode *temp_node = node->next;
        free(node);
        node = temp_node;
    }
}

void dump_to_file(char *file_name, Packet *packets[], int len)
{
    FILE *file = fopen(file_name, "wb");
    for (int i = 0; i < len; i++)
    {
        Packet *packet = packets[i];
        fwrite(packet->body, sizeof(Byte), packet->len, file);
        free(packet->body);
        free(packet);
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    char *domain = argv[1];
    int port = atoi(argv[2]);
    char *file_name = argc >= 4 ? argv[3] : "download";

    TcpClient *tcp_client = createTcpClient(domain, port);
    tcpConnect(tcp_client);
    
    // create dummy head of linked list
    PacketListNode *packet_list_head = createPacketListNode(NULL, NULL);
    PacketListNode *packet_list_node = packet_list_head;
    
    // get all packets
    int packet_count = 0;
    Packet *packet = NULL;
    while ((packet = getPacket(tcp_client)) != NULL)
    {
        packet_list_node->next = createPacketListNode(packet, NULL);
        packet_list_node = packet_list_node->next;
        packet_count++;
    }
    
    #ifdef DEBUG
    printf("packet count: %d\n", packet_count);
    #endif
    
    // sort packets
    Packet *sorted_packets[packet_count];
    sortPackets(packet_list_head->next, sorted_packets);
    free(packet_list_head);
    
    // dump to file
    dump_to_file(file_name, sorted_packets, packet_count);
    
    return 0;
}