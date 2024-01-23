#include <sys/time.h>
#include <pthread.h> 
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_EXPERIMENT_DURATION 500
sem_t sem;

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end);
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end);

int main() {
    int status;
    pid_t pid;
    sem_init(&sem, 0, 1);
    struct timeval startTime, currentTime;
    gettimeofday(&startTime, NULL); 

    while (1) {
        pid = fork();
        if (pid < 0) {
            printf("fork() error!\n");
            exit(1);
        } else if (pid == 0) {
            sem_wait(&sem);
            gettimeofday(&currentTime, NULL); 
            printf("PID: %d, time %ld\n", 
                getpid(), getDifferenceInMilliSeconds(startTime, currentTime));
            sem_post(&sem);
            return 0;
        }
        gettimeofday(&currentTime, NULL); 
        if (getDifferenceInMilliSeconds(startTime, currentTime) >= MAX_EXPERIMENT_DURATION) {
            printf("END OF EXPERIMENT!\n");
            break;
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