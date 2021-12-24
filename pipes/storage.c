#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char input[256];
    int s = 0;
    while ((s = read(0, input, 14)) > 0) {
        for (int i = 0; i < s; i++) {
            input[i] = toupper(input[i]);
            printf("%c", input[i]);
        }
    }
    exit(0);
}
