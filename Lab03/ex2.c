#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("process %d have created process %d\n", getppid(), getpid());
    }
    pid = fork();
    if (pid == 0) {
        printf("process %d have created process %d\n", getppid(), getpid());
    }
    pid = fork();
    if (pid == 0) {
        printf("process %d have created process %d\n", getppid(), getpid());
    }
    return 0;
}