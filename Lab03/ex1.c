#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int MAX_LENGTH = 1000;

int main(int argv, char* argc[]) {
    FILE* fileIn = fopen(argc[1], "r");
    stdin = fileIn;
    int* temp = (int*)malloc(MAX_LENGTH * sizeof(int));
    int pos = 0;
    while (!feof(fileIn)) {
        scanf("%d", temp + pos*sizeof(int));
        pos++;
    }
    int* arr = (int*)malloc((pos + 1) * sizeof(int));
    for (int i = 0; i < pos; i++) {
        *(arr + i * sizeof(int)) = *(temp + i * sizeof(int));
    }
    free(temp);
    pid_t pid;

    if ((pid = fork()) == 0) { // child process
        int count = 0;
        for (int i  = 0; i < pos; i++) {
            if (!(*(arr + i * sizeof(int))%3)) count++;
        }
        wait(NULL);
        printf("%d\n", count);
    } else { // parent process
        int count = 0;
        for (int i  = 0; i < pos; i++) {
            if (!(*(arr + i * sizeof(int))%2)) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}