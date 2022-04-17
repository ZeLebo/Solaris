#include <sys/socket.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

char* socket_path = "ZhoRa";

int main(){
        struct sockaddr_un addr;
        int server, client, lines;
        server = socket(AF_UNIX, SOCK_STREAM, 0);
        if (server == -1){
                perror("An error occured while creating the socket");
                exit(-1);
        }
        
        char buff[BUFSIZ];
        printf("Socket was made successfully\n");
        memset(&addr, 0, sizeof(addr));
        addr.sun_family = AF_UNIX;
        strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
        unlink(socket_path);
        if (bind(server, (struct sockaddr*)&addr, sizeof(addr)) == -1)    {
                perror("Not able to bind a socket");
                exit(-1);
        }

        if (listen(server, 1) == -1){
                perror("Not able to listen");
                exit(-1);
        }

        printf("Waiting for client\n");
        client = accept(server, NULL, NULL);
        if (client == -1){
                perror("Not able to get socket");
                close(server);
                exit(-1);
        }

        printf("The output from the client:\n\n");
        while((lines = read(client, buff, BUFSIZ)) != 0) {
                for(int i = 0; i < lines; ++i){
                        printf("%c", toupper(buff[i]));
                }
        }
        
        if (lines == -1) {
                perror("Something went wrong");
                exit(-1);
        }

        close(client); close(server);
        printf("\nShuting down\n");
        exit(0);
}
