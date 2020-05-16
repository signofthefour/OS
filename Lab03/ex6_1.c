#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        value += 15;
        return 0;
    }
    else if (pid > 0) {
        wait(NULL);
        printf("PARENT: value = %d\n", value); // print: PARENT: value = 5
        return 0;
    }
}

// 2> Only shared memmory segments is shared between parent and child process when
//     parent create child process.
//    Stack and Heap are copied to new process.