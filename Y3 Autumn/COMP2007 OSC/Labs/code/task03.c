#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUMBER_OF_PROCESSES 4

int main() {
    int i, status[NUMBER_OF_PROCESSES];
    pid_t pid[NUMBER_OF_PROCESSES];

    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        printf("Hello from the parent process.\n");
        pid[i] = fork();
        if (pid[i] < 0){
            printf("fork() error\n");
        } else if (pid[i] == 0) {
            sleep(1);
            printf("Hello from child process %d with PID %d\n", i, getpid());
            return 0;
        }
    }
    wait(NULL);     // wait for all child process to finish
    // for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
    //     waitpid(pid[i], &status, WUNTRACED);
    // }
    printf("Bye from the parent.\n");
}