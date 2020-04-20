#include "readline.h"
#include "findsubstr.h"
#include <stdio.h>

const int BUFFER_SIZE = 100;
int read_line(char* str) {
    char line[BUFFER_SIZE];
    fgets(line, BUFFER_SIZE, stdin);
    if (find_sub_string(str, line) == 1) {
        printf("%s\n", line);
    }
    int res = 0;
    while (*(line + res) != '\0') {
        str[res] = line[res];
        res++;
    }
    str[res] = '\0';
    if (feof(stdin)) return -1;
    else return res - 1;
}