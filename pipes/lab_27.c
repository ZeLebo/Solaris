#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    char line[BUFSIZ];

    input = fopen("test.txt", "r");
    if (input == (FILE*) NULL) {
        perror("Smells like something's gone wrong");
        exit(1);
    }
    
    output = popen("wc -l", "w");
    int cnt = 0;
    while (fgets(line, BUFSIZ, input) != (char *) NULL) {
        if (line[0] == '\n') {
            fputs(line, output);
        }
    }
    fclose(input);
    pclose(output);
    return 0;
}
