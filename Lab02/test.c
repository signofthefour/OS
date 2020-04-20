#include "findsubstr.h"
#include <stdio.h>

const int BUFFER_SIZE = 100;

int main (int argc, char** argv) {
    stdin = fopen(argv[1], "r");
    char line[BUFFER_SIZE];
   
    while (fgets(line, BUFFER_SIZE, stdin)) {
        if (!feof(stdin)) printf("%s", line);
    }
    fclose(stdin);
    return 0;
}