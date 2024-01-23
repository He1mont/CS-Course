#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_EXPERIMENT_DURATION 0

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end);
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end);

int main() {
    int status;
    pid_t pid;
    struct timeval startTime, currentTime;
    gettimeofday(&startTime, NULL); 

    while (1) {
        pid = fork();
        if (pid < 0) {
            printf("fork() error!\n");
            exit(1);
        } else if (pid == 0) {
            gettimeofday(&currentTime,NULL); 
            printf("PID: %d, time %ld\n", 
                getpid(), getDifferenceInMicroSeconds(startTime, currentTime));
            return 0;
        }
        waitpid(pid, &status, WUNTRACED);
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