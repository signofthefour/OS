#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    std::cout << "Checking fork()\n";
    std::cout << pid << '\n';

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);
    }
    else {
        wait(NULL);
        printf("Child complete\n");
    }
    return 0;
}