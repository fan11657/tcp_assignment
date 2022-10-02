typedef struct tcpClient
{
    int socket_id;
    char *host_name;
    int port;
} TcpClient;

TcpClient *createTcpClient(char *host_name, int port);

// Return 0 if successfully, else -1.
int tcpConnect(TcpClient *tcp_client);

// Return length of the response
int tcpRecieve(TcpClient *tcp_client, void *buffer, size_t len);