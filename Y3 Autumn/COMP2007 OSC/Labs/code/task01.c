#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_PROCESSES 10

int main() {
    int i;
    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        pid_t id = fork();

        if (id < 0) {
            printf("Unsuccessful fork.");
            exit(1);
        } else if (id == 0) {       // child process
            printf("Hello from child %d with pid %d\n", i + 1, getpid());
            exit(0);
        } else {                    // parent process
            // printf("Hello I'm father!\n");
        }
    }
}
