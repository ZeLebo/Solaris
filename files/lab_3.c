#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	FILE *file;
	uid_t uid;
	
	printf("%u\n%u\n", getuid(), geteuid());

	if ((file = fopen("test.txt", "r")) == NULL) {
		perror("Access denied\n");
		exit(1);
	} else {
		printf("Access allowed\n");
		fclose(file);
	}

	setuid(uid = getuid());


	printf("%u\n%u\n", getuid(), geteuid());
	file = fopen("test.txt", "r");

	if (file == NULL) {
		perror("Access denied\n");
		exit(1);
	} else {
		printf("Access allowed\n");
		fclose(file);
		exit(0);
	}	
	
	return 0;
}