// Sockets in C
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {
    // client side application
    int socketID = socket(AF_INET, SOCK_STREAM, 0);
    // domain, type(tcp here), protocol
    // 0 means that we want the IP layer to be used.
    // The above function returns a integer (socket file descriptor) which if it is not negative means that the socket has been created successfully.

    struct sockaddr_in address;
    address.sin_port = 2000;
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = IN

    connect(socketID, &address, sizeof(address));
    return 0;
}