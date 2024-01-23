#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_PROCESSES 4

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end);
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end);

int main() {
    int i, pid;
    struct timeval startTime, currentTime;
    gettimeofday(&startTime, NULL); 
    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        pid = fork();
        if (pid < 0) {
            printf("fork() error!\n");
            exit(1);
        } else if (pid > 0) {
            gettimeofday(&currentTime,NULL); 
            printf("Hello from the child process %d with PID %d at time %ld\n", 
                i, getpid(), getDifferenceInMicroSeconds(startTime, currentTime));
            return 0;
        }
    }
}

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end) { 
    int seconds = end.tv_sec - start.tv_sec;
    int useconds = end.tv_usec - start.tv_usec; 
    int mtime = (seconds * 1000 + useconds / 1000.0); 
    return mtime; 
}
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end) { 
    int seconds = end.tv_sec - start.tv_sec; 
    int useconds = end.tv_usec - start.tv_usec; 
    int mtime = (seconds * 1000000 + useconds); 
    return mtime; 
}