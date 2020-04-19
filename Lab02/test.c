#include "findsubstr.h"
#include <stdio.h>

int main (int argv, char** args) {
    printf("%d",find_sub_string(args[0], args[1]));
    return 0;
}