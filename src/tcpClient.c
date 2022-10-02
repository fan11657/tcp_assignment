#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include "tcpClient.h"

TcpClient *createTcpClient(char *host_name, int port)
{
    TcpClient *tcp_client = (TcpClient *) malloc(sizeof(TcpClient));
    tcp_client->socket_id = socket(AF_INET, SOCK_STREAM, 0);
    tcp_client->host_name = host_name;
    tcp_client->port = port;
    return tcp_client;
}

int tcpConnect(TcpClient *tcp_client)
{
    // resolve hostname with dns
    struct hostent *host_entry = gethostbyname(tcp_client->host_name);
    
    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = *((unsigned long *)host_entry->h_addr_list[0]);
    socket_address.sin_port = htons(tcp_client->port);
    return connect(tcp_client->socket_id, (struct sockaddr *)&socket_address, sizeof(struct sockaddr));
}

int tcpRecieve(TcpClient *tcp_client, void *buffer, size_t len)
{
    recv(tcp_client->socket_id, buffer, len, 0);
}