#include<stdio.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define IP "142.250.76.163" /* www.google.com */
#define PORT 80 /* http */

int main() {
    int s; // file descriptor for socket
    struct sockaddr_in sock; // This is were we put our IP addresses (structural type)
    char buf[512];
    char *data = "HEAD / HTTP/1.0\n\n";

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        printf("socket() error \n");
        return -1;
    }

    sock.sin_addr.s_addr = inet_addr(IP);
    sock.sin_port = htons(PORT);
    sock.sin_family = AF_INET;

    if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) != 0) {
        printf("connect() error \n");
        close(s);
        return -1;
    } 

    write(s, data, strlen(data));
    int n = read(s, buf, 511);
    buf[n] = '\0';
    close(s);

    printf("\n%s\n", buf);

    return 0;
}