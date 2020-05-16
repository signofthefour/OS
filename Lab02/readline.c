#include "readline.h"
#include <stdio.h>

int read_line(char* str) {
    fgets(str, 100, stdin);
    int res = 0;
    while (*(str + res) != '\0') {
        res++;
    }
    if (feof(stdin)) return -1;
    return res - 1;
}