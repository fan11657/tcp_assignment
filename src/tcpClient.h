typedef struct tcpClient
{
    int socket_id;
    char *host_name;
    int port;
} TcpClient;

TcpClient *createTcpClient(char *host_name, int port);

int tcpConnect(TcpClient *tcp_client);

int tcpRecieve(TcpClient *tcp_client, void *buffer, size_t len);