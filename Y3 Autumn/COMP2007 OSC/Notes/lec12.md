# lec12: Concurrency 5: Readers-Writers Problem

>   **Overview**
>
>   -   Description
>   -   Solution 1: No parallelism
>   -   Solution 2: Readers First
>   -   Solution 3: Writers First
>
>   *References: MOS 2.5.2*

## **Description**

-   Concurrent database processes are readers and/or writers, ﬁles, I/O devices, ...
-   **Reading** a record (variable) can happen **in parallel** without problems, **writing needs synchronisation** (i.e. exclusive access) 
-   Different solutions exist to the readers/writers problem
    -   Solution 1: naive implementation with **limited parallelism** 
    -   Solution 2: **readers receive priority**: no reader is kept waiting (unless a writer already has access, **writers may starve**) 
    -   Solution 3: **writing** is performed as soon as possibly (**readers may starve**)

## Solution 1: No Parallelism

-   Prevents parallel reading

```C
void* reader(void* arg) { 
    while(1) { 
        pthread_mutex_lock(&sync); 
        printf("reading record\n"); 
        pthread_mutex_unlock(&sync); 
    } 
}
void* writer(void* writer) { 
    while(1) { 
        pthread_mutex_lock(&sync); 
        printf("writing\n"); 
        pthread_mutex_unlock(&sync); 
    } 
}
```

## Solution 2: Readers First: allows parallel reading

A correct implementation of this solution requires

-   `iReadCound`: an integer tracking the number of readers
    -   if `iReadCound > 0`: writers are blocked `(sem_wait(rwSync))`
    -   if `iReadCound == 0`: writers are released `(sem_post(rwSync))`
    -   if already writing, readers must wait
-   `sync`: a mutex for mutual exclusion of `iReadCount`
-   `rwSync`: a semaphore that **synchronises the readers and writers**, set by the ﬁrst/last reader

```C
void* reader(void* arg) {
    while(1) {
        sem_wait(&sync);
        iReadCount++;
        if (iReadCount == 1) 
            sem_wait(&rwSync);
        sem_post(&sync);
        
        printf("reading record\n");
        
        sem_wait(&sync);
        iReadCount--;
        if (iReadCount == 0)
            sem_post(&rwSync);
        sem_post(&sync);
    }
}
void* writer(void* writer) {
    while(1) {
        sem_wait(&rwSync);
        printf("writing\n");
        sem_post(&rwSync);
    }
}
```

## Solution 3: Writers First

**Variables**

-   Integers `iReadCount` and 
-   Mutexes `sRead` and to synchronise the **reader’s/writer’s critical section**.
    -   set default by 1

**Comparison with Writers First**

-   `sResource` is mutex, similar to `sync`
-   Add `iWriteCount` and  `sWrite` to keep track of **the number of writers**
-   Add `sReadTry` to stop readers when there is a **writer waiting**
    -   set default by 1

```C
void* reader(void* arg) {
    while (1) {
        sem_wait(&sReadTry);
        sem_wait(&sRead); 
        iReadCount++;
        if (iReadCount == 1)
            sem_wait(&sResource);
        sem_post(&sRead); 
        sem_post(&sReadTry);
        
        printf("reading \n");
        
        sem_wait(&sRead); 
        iReadCount--;
        if (iReadCount == 0)
            sem_post(&sResource);
        sem_post(&sRead);
    }
}
void* writer(void* arg) {
    while (1) {
        sem_wait(&sWrite);
		iWriteCount++;
        if (iWriteCount == 1)
            sem_wait(&sReadTry);
        sem_post(&sWrite); 
        
        sem_wait(&sResource);
        printf("writing\n");
        sem_post(&sResource);
        
        sem_wait(&sWrite);
        iWriteCount--;
        if (iWriteCount == 0)
            sem_post(&sReadTry);
        sem_post(&sWrite);
    }
}
```



