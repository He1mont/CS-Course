# lec10: Concurrency 3

>   **Overview**
>
>   -   Semaphore
>   -   Producer-Consumer Problem (Unbounded buffer)
>
>   *Reference: MOS 2.3.4-2.3.5, [Youtube](https://www.youtube.com/watch?v=XDIOC2EY5JE)*

## Semaphores

-   **Semaphores** are another abstraction for **mutual exclusion** and **process synchronisation**, often provided by the OS
    -   They have a **capacity**, either a positive number or infinity.
-   Semaphore is simply a non-negative variable that is shared **between threads**. 
    -   to solve the critical section problem
    -   to achieve process synchronization in the multiprocessing environment

-   Two types: 
    -   **binary** (2 valued), in some system known as the **mutex lock**
    -   **counting semaphores** (N-valued or unbounded), used to control access to a resource that has multiple instances

-   Two functions are used to **manipulate semaphores** 
    -   `wait()` is called when a resource is **acquired**, the capacity is **decremented** 
    -   `signal()` or `/post()` is called when a resource is **released**, the capacity is **incremented**.
-   The semaphore can only be acquired when its **currently capacity is strictly positive**
-   A thread calling `post` does NOT have to have previous called `wait`

**Conceptural definition of a semaphore**

```C
typedef struct {
    int value;
    struct process * list;
} semaphore;
```

**Conceptual implementation of a `wait()`**

```C
void wait(semaphore* S) {
    S->count--;
    if (S->count < 0) {
        // add process to S->list
        block();	// system call
    }
}
```

**Conceptual implementation of `post()`**

```C
void post(semaphore* S {
    S->count++;
    if (S->count <= 0) {
        // remove process P from S->list
        wakeup(P);
    }
}
```

**Implementation**

<img src="assets/Screenshot 2023-10-26 at 13.50.36.png" alt="Screenshot 2023-10-26 at 13.50.36" style="zoom:40%;" />

-   Calling `wait()` will **block** the process when the internal **counter is not positive**
    -   The process **joins the a queue blocking on the semaphore** 
    -   The **process state** is changed from **running** to **blocked** 
    -   Control is transferred to the **process scheduler**
-   Calling `post()` removes a process from the **blocked queue** if available:
    -   The process state is changed from **blocked** to **ready** 
    -   Different queueing strategies can be employed to **remove processes** - so avoid unjustified assumptions in your code.
-   Notably
    -   The queue length is the number of processes waiting on the semaphore. 
    -   `block()` and `wakeup()` are **system calls** provided by the OS. 
    -   `post()` and `wait()` must be **atomic**

```C
void post(semaphore* S) {
    lock(&mutex);
    S->count++;
    if (S->count <= 0) {
        // remove process P from queue
        wakeup(P);
    }
    unlock(&mutex);
}
```

`Counter++` revisited

-   Semaphores within the **same process** can be declared as variables of the type `sem_t`
    -   `sem_init()` initialises the value of the semaphore 
    -   `sem_wait()` decrements the value of the semaphore 
    -   `sem_post()` increments the values of the semaphore
-   An **explanation** of any of these functions can be found in the **man pages**, 
    -   e.g. by typing `man sem_init` on the Linux command line

**POSIX Semaphores**

```C
sem_t s; 
int sum = 0; 
void * calc(void * arg) { 
    int const iterations = 50000000;
    for(int i = 0; i < iterations;i++) {
        sem_wait(&s);
        sum++;
        sem_post(&s);
    } 
    return 0;
} 

int main() {
	pthread_t tid1,tid2; 
    sem_init(&s,0,1);
    pthread_create(&tid1, NULL, calc, 0);
    pthread_create(&tid2, NULL, calc, 0);
    pthread_join(tid1,NULL); 
    pthread_join(tid2,NULL);
    printf("The value of sum is: %d\n", sum);
}
```

**Efficiency**

-   Synchronising code does result in a **performance penalty**
    -   Synchronise **only when nessary**
    -   Synchronise **as few instruction** as possible
-   Carefully consider how to synchronise

```C
void * calc(void * increments) {
    int number_of_iterations = 50000000; 
    int total = 0; 
    for(int i = 0; i < number_of_iterations; i++) {
        total++;	// Pretend this is non-trivial to work out
    } 
    sem_wait(&s); 
    sum += total; 
    sem_post(&s); 
    return 0;
}
```

**Caveats**

-   **Starvation**: poorly designed **queueing approaches** (e.g. LIFO) may result in fairness violations 
-   **Deadlocks**: two or more processes are **waiting indefinitely** for an event that can be **caused only by one of the waiting processes**
    -   I.e., every process in a set is waiting for an event that can only be caused by another process in the same set 
    -   E.g., consider the following sequence of instructions on semaphores

<img src="assets/Screenshot 2023-10-26 at 18.24.03.png" alt="Screenshot 2023-10-26 at 18.24.03" style="zoom:50%;" />


## The Producer/Consumer Problem

**Problem Description**

-   Producers and consumers share a **buffer** of values, e.g. a printer queue
    -   The buffer can be **bounded** or **unbounded**
    -   There can be any number of **producers** and **consumers**
-   A producer attempts to add items and **blocks if the buffer is full**
-   A consumer attempts to remove items and **blocks if the buffer is empty**

**The simplest version**

-   One producer, one consumer and a buffer of **unbounded size**
-   A counter variable keeps track of the number of **items in the buffer**
-   It uses two **binary semaphores**
    -   `sync` - synchronises access to the buffer, initialise to 1
    -   `delay_consumer` - ensures that the consumer blocks when there are no items available, initialised to 0

```C
void* consumer(void* p) {
    sem_wait(&delay_consumer);
    while(1) {
        sem_wait(&sync);
        items--;
        printf("%d\n", items);
        sem_post(&sync);
        if (items == 0)
            sem_wait(&delay_consumer);
    }
}
void* producer(void* p) {
    while(1) {
        sem_wait(&sync);
        items++;
        printf("%d\n", items);
        if (items == 1)
            sem_post(&delay_consumer);
        sem_post(&sync);
    }
}
```

**Race conditions** still exist:

-   When the consumer has exhausted the buffer, should have blocked, but the producer increments items before the consumer checks it
-   Use a **temporary variable**
    -   Copies the value of `items` inside the critical section
    -   Decrements the `delay_consumer` semaphore to make it consistent

```C
void* consumer(void* p) {
    sem_wait(&delay_consumer);
    while(1) {
        sem_wait(&sync);
        items--;
        temp = items;
        printf("%d\n", items);
        sem_post(&sync);
        if (temp == 0)
            sem_wait(&delay_consumer);
    }
}
void* producer(void* p) {
    while(1) {
        sem_wait(&sync);
        items++;
        printf("%d\n", items);
        if (items == 1)
            sem_post(&delay_consumer);
        sem_post(&sync);
    }
}
```





