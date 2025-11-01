// TCP server
#include<stdio.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

# define PORT 8181

int main() {
    int s, c;
    socklen_t addrlen; // unassigned int type
    struct sockaddr_in srv, cli;
    char buf[512];
    char *data;

    addrlen = 0;
    memset(&srv, 0, sizeof(srv));
    memset(&cli, 0, sizeof(cli));
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        printf("socket() error \n");
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0;
    srv.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr *)&srv, sizeof(srv))) {
        printf("bind() error \n");
        close(s);
        return -1;
    }

    if (listen(s, 5)) {
        printf("listen() error \n");
        close(s);
        return -1;
    }
    printf("Server listening on port 0.0.0.0:%d\n", PORT);

    c = accept(s, (struct sockaddr *)&srv, &addrlen); // new socket file descriptor from the client.
    if (c < 0) {
        printf("accept() failed \n");
        close(s);
        return -1;
    }

    printf("Client connected \n");
    read(c, buf, 511);
    printf("Received from client: %s\n", buf);
    data = "You are connected successfully.. \n";
    sleep(5);
    write(c, buf, strlen(buf));
    write(c, data, strlen(data));
    close(c);
    close(s);

    return 0;
}