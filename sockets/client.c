#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

char* socket_path = "ZhoRa";

int main(){
        char buff[BUFSIZ];
        int server;
        struct sockaddr_un addr;
        memset(&addr, 0, sizeof(addr));
        addr.sun_family = AF_UNIX;
        strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

        server = socket(AF_UNIX, SOCK_STREAM, 0);
        if (server == -1){
                perror("Not able to make socket");
                exit(-1);
        }

        if (connect(server, (struct sockaddr*)&addr, sizeof(addr)) == -1){
                perror("Not able to connect");
                exit(-1);
        }

        printf("Sending the message to server...\n");

        char* line = "Load up on guns\nBring your friends...\nIt's fun to lose and to pretend\n";
        write(server, line, strlen(line));

        printf("Client shutdown\n");
        exit(0);
}