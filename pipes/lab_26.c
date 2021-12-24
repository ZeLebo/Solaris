#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    FILE* input = popen("./testing", "w");
    char* line = "Load up on guns\n";
    fputs(line, input);
    pclose(input);
    return 0;
}
