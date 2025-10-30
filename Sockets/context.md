In the sockets.c file,
It is the implementation of a simple HTTP client that connects to Google's web server, sends a HTTP HEAD request asking for metadata about the root page (/) and receives the server's response. It then prints the response to the terminal.

The header files:-
sys/socket.h is used for socket() and connect()
netinet/in.h used for struct sockaddr_in and AF_INET
arpa/inet.h used for inet_addr() and htons()
sys/types.h is used for the data types of sockets
unistd.h is used for close(), read(), write()

SOCKET CREATION
s = socket(AF_INET, SOCK_STREAM, 0);
AF_INET: IPv4 address family, specifies that we are using the IPv4 protocol.
~~~ "Create a socket that uses IPv4 addresses for communication."
SOCK_STREAM: It is for TCP connection.
->Connection-oriented: Must establish connection before sending data
->Reliable: Guarantees data delivery, no packet loss
->Ordered: Data arrives in the same order it was sent
->Byte stream: Data flows continuously like a stream, no message boundaries.
->Error checked: Automatic retransmission, if packets are lost.

0: Default protocol (TCP in our case)

SERVER ADDRESS
struct sockaddr_in is a structure that holds an IPv4 socket address

struct sockaddr_in {
    sa_family_t sin_family // Address family (AF_INET for IPv4)
    in_port_t sin_port // Port number
    struct in_addr sin_addr // IPv4 address
    char sin_zero[8] // padding to match sockaddr
};

inet_addr(IP): Converts dotted-decimal string -> 32 bit binary IP
htons(PORT): Converts port from host byte order -> network byte order
Computers store multi-byte numbers in two ways
1. Big Endian (Network Byte Order) -> Most Significant byte to first
2. Little Endian (Most AMD/Intel CPUs) -> Least Significant byte first
Network always uses Big Endian form.