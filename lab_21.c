#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


int cnt = 0;
void function(int signal) {
	if (signal == SIGQUIT) {
		printf("\nYou tried to quit the stuff for %d times\n", cnt);
		exit(1);
	}
    else if (signal == SIGINT) {
        printf("%c", '\07');
        cnt++;
    }
     printf("%c", '\07');
        cnt++;
}

int main() {
	sigset(SIGINT, function);
	sigset(SIGQUIT, function);
	while(1) {
		pause();
	}
}
