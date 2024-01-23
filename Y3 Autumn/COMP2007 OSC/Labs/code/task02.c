#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_PROCESSES 4


int main() {
    int i;
    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        pid_t id = fork();

        if (id < 0) {
            printf("fork() error.\n");
            exit(1);
        } else if (id == 0) {       // child process
            printf("Hello from child %d with pid %d\n", i + 1, getpid());
            execl("/bin/ps", "ps", "l", 0);
            exit(0);
        } else {                    // parent process

        }
    }
}
