#include "readline.h"
#include <stdio.h>

const int FILE_LEN = 10000;

int main (int argc, char** argv) {
    stdin = fopen(argv[1], "r");
    char str[FILE_LEN];
    int pos = 0;
    int newLineLen = 0;
    while ((newLineLen = read_line(str + pos)) > -1) {
        pos += newLineLen + 1;   // include '\n' to str
    }
    fclose(stdin);
    return 0;
}