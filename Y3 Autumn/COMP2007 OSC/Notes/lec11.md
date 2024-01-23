# lec11: Concurrency 4

>   **Overview**
>
>   -   Producer-Consumer Problem (bounded buffer problem)
>   -   The dining philosophers problem
>
>   *References: MOS 2.3.4 2.5.1*

## Producer-Consumer Problem

-   A different variant of the problem has n consumers, m producers, and a fixed buffer size N. The solution is based on **3 semaphores**:
    -   `sync`: used to enforce mutual exclusion for the buffer
    -   `empty`: keeps track of the number of empty buffers, initialised to N
    -   `full`: keeps track of the number of full buffers, initialised to 0 


```C
void* producer(void* a) {
    while(1) {
        sem_wait(&empty);
        sem_wait(&sync);
        items++;
        printf("Producer: %d\n", items);
        sem_post(&sync);
        sem_post(&full);
    }
}
void* consumer(void* a) {
    while(1) {
        sem_wait(&full);
        sem_wait(&sync);
        items--;
        printf("Consumer: %d\n", items);
        sem_post(&sync);
        sem_post(&empty);
    }
}
```

## The Dining Philosophers Problem

<img src="assets/Screenshot 2023-11-02 at 17.16.53.png" alt="Screenshot 2023-11-02 at 17.16.53" style="zoom:30%;" />

-   The problem is defined as:
    -   Five philosophers are sitting on a round table 
    -   Each one has one has a plate of spaghetti 
    -   The spaghetti is too slippery, and each philosopher needs 2 forks to be able to eat 
    -   When hungry (in between thinking), the philosopher tries to acquire the forks on their left and right
-   Note that this reflects the general problem of sharing a **limited set of resources** (forks) between **a number of processes** (philosophers)

### Solution 1: Naive will Deadlock

-   Forks are represented by **semaphores (initialised to 1)**
    -   `1` if the fork is **available**: the philosopher can **continue** 
    -   `0` if the fork is **not available**: the philosopher goes to sleep if trying to acquire it
-   First approach: Every philosopher **picks up one fork** and waits for the second one to become available (**without putting the first one down**)
-   **Deadlocks** can be prevented by 
    -   putting the forks down and waiting a random time
    -   putting one additional fork on the table
    -   one **global mutex** set by a philosopher when they want to eat
        -   only one can eat at a time
        -   not result in maximum parallelism

```C
#define N 5 
sem_t forks[N];

void * philosopher(void * id) {
    int i = *((int*)id);
    int left = (i + N - 1) % N;
    int right = i % N; 
    while(1) {
        printf("%d is thinking\n", i); 
        printf("%d is hungry\n", i); 
        sem_wait(&forks[left]); 
        sem_wait(&forks[right]); 
        printf("%d is eating\n", i); 
        sem_post(&forks[left]); 
        sem_post(&forks[right]);
    }
}
```

### Solution 2: Global Mutex/Semaphore

```C
sem_t eating;

void* philosopher(void* id) { 
    int i = (int) id;
    int left = (i + N - 1) % N;
    int right = i % N; 
    while(1) {
		printf("%d is thinking\n", i); 
        printf("%d is hungry\n", i); 
        sem_wait(&eating); 
        sem_wait(&forks[left]); 
        sem_wait(&forks[right]); 
        printf("%d is eating\n", i); 
        sem_post(&forks[left]); 
        sem_post(&forks[right]); 
        sem_post(&eating); 
    }
}
```

-   Can we create maximum parallelism by initialising the value of `eating` to `2` 

### Solution 3: Maximum Parallelism

>   A philosopher can only start eating if his/her **neighbours are not eating**

-   A more **sophisticated solution** is necessary to allow **maximum parallelism** 
-   The solution uses:
    -   `state[N]`: one **state variable**, (THINKING, HUNGRY, EATING) 
    -   `phil[N]`: one **semaphore per philosopher** (i.e., not forks, initialised to 0)
        -   The philosopher **goes to sleep** if one of his/her neighbours are eating
        -   **The neighbours wake up the philosopher** if they have ﬁnished eating
    -   `sync`: one **semaphore/mutex** to enforce **mutual exclusion** of the critical section (while updating the states)

```C
#define N 5 
#define THINKING 1 
#define HUNGRY 2 
#define EATING 3

int state[N] = {THINKING, THINKING, THINKING, THINKING, THINKING}; 
sem_t phil[N]; // sends philosopher to sleep 
sem_t sync;

void* philosopher(void* id) {
    int i = *((int*)id); 
    while(1) { 
        printf("%d is thinking\n", i); 
        take_forks(i); 
        printf("%d is eating\n", i); 
        put_forks(i); 
    }
}
void take_forks(int i) { 
    sem_wait(&sync); 
    state[i] = HUNGRY; 
    test(i); 
    sem_post(&sync); 
    sem_wait(&phil[i]); 
}
void put_forks(int i) {
    int left = (i + N - 1) % N; 
    int right = (i + 1) % N; 
    sem_wait(&sync); 
    state[i] = THINKING; 
    test(left); 
    test(right); 
    sem_post(&sync);
}
void test(int i) { 
    int left = (i + N - 1) % N; 
    int right = (i + 1) % N; 
    if(state[i] == HUNGRY && state[left] != EATING && state[right] != EATING) { 
        state[i] = EATING; 
        sem_post(&phil[i]); 
    } 
}
```









