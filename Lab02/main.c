#include "readline.h"
#include "findsubstr.h"
#include <stdio.h>

const int FILE_LEN = 10000;
const int BUFFER_SIZE = 100;

int main (int argc, char** argv) {
    stdin = fopen(argv[1], "r");
    char str[FILE_LEN];
    char line[BUFFER_SIZE];
    int posInStr = 0;
    int posInLine = 0;
    int newLineLen = 0;
    while (!feof(stdin)) {
        newLineLen = read_line(line);
        if (find_sub_string(str, line) == 1)
            printf("%s", line);
        posInLine = 0;
        while (*(line + posInLine)) {
            str[posInStr + posInLine] = line[posInLine];
            posInLine++; 
        }
        str[posInStr + posInLine + 1] = '\0';
        posInStr += newLineLen + 1;
    }
    fclose(stdin);
    return 0;
}