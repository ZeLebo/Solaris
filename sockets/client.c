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
        server = socket(AF_UNIX, SOCK_STREAM, 0);
        if (server == -1){
                perror("Not able to make socket");
                exit(-1);
        }
        memset(&addr, 0, sizeof(addr));
        addr.sun_family = AF_UNIX;
        strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
        if (connect(server, (struct sockaddr*)&addr, sizeof(addr)) == -1){
                perror("Not able to connect");
                exit(-1);
        }

        char* line = "Load up on guns";
        write(server, line, sizeof(line));

        printf("Client shutdown\n");
        exit(0);
}