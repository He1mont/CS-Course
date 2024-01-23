#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <sys/shm.h>
#include <pthread.h> 
#include <semaphore.h>
#include <fcntl.h> 

#define MAX_EXPERIMENT_DURATION 500
#define NUMBER_OF_PROCESSES 30
#define SIZE_OF_MEMORY sizeof(int) 
#define SHARED_MEMORY_NAME "sgs0811"

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end) { 
    int seconds = end.tv_sec - start.tv_sec;
    int useconds = end.tv_usec - start.tv_usec; 
    int mtime = (seconds * 1000 + useconds / 1000.0); 
    return mtime; 
}

int main() {
    // initialize variables
    pid_t pid;
    int cnt = 0;
    int status;     // wait for child process
    int *iPtr;      // write in shared memory
    struct timeval startTime, currentTime;
    gettimeofday(&startTime, NULL); 

    // create and open shared memory
    int shm_fd = shm_open(SHARED_MEMORY_NAME, O_RDWR | O_CREAT, 0666); 
    if (shm_fd == -1) {
        printf("failed to open shared memory\n"); 
        exit(1);
    } 
    // set size for shared memory
    if (ftruncate(shm_fd, SIZE_OF_MEMORY) == -1){
        printf("failed to set size of memory\n"); 
        exit(1);
    }

    while (1) {
        cnt += 1;
        pid = fork();
        
        if (pid < 0) {
            printf("fork() error!\n");
            exit(1);
        } else if (pid == 0) {
            srand(getpid()); 
            int rnd = rand() % 501;

            // writes into shared memory
            iPtr = mmap(NULL, SIZE_OF_MEMORY, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
            * iPtr = rnd;
            printf("PID: %d, CHILD writes number: %ld\n", getpid(), rnd);
            munmap(iPtr, SIZE_OF_MEMORY);
            
            return 0;
        }
        // wait for child process
        waitpid(pid, &status, WUNTRACED);

        // read from shared memory
        iPtr = mmap(NULL, SIZE_OF_MEMORY, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("PID: %d, PARENT reads number: %ld\n", pid, *iPtr);
        munmap(iPtr, SIZE_OF_MEMORY);

        // exit parent process
        if (cnt >= NUMBER_OF_PROCESSES) {
            printf("END OF EXPERIMENT!\n");
            break;
        }

        // gettimeofday(&currentTime, NULL); 
        // if (getDifferenceInMilliSeconds(startTime, currentTime) >= MAX_EXPERIMENT_DURATION) {
        //     printf("END OF EXPERIMENT!\n");
        //     break;
        // }
    }
}
