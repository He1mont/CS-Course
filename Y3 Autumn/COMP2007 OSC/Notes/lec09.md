# lec09: Concurrency 2

>   **Overview**
>
>   -   Peterson's Solution (*software approach*)
>       -   Mutual exclusion requirement
>       -   Progress requirement
>       -   Fairness/bounded waiting requirement
>   -   Atomic Instructions (*hardware approach*)
>       -   Mutal exclusion
>
>   -   Mutexes (*OS approach*)
>
>   Reference: [Youtube](https://www.youtube.com/watch?v=gYCiTtgGR5Q&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=59), *MOS 2.3.3-4*

## Peterson's Solution (Software approach)

-   Peterson's solution is a **software based solution** which worked well on **older machines**
-   Two **shared vairables**
    -   `turn`: indicates which process is the next to enter its critical section
    -   `bool flag[2]`: indicates that if a process is ready to enter its critical section
-   Can be **generalised to multiple processes**
-   Structure of process Pi

```C
do {
    // Pi wants to enter the critical section
    flag [i] = true;
    turn = j;
    while (flag [j] && turn == j);	// busy waiting
    
    // critical section
    
    flag [i] = false;
    
    // remainder section
} while (TRUE);
```

<img src="assets/Screenshot 2023-10-24 at 02.45.06.png" alt="Screenshot 2023-10-24 at 02.45.06" style="zoom:50%;" />

**Mutual exclusion requirement**

-   The variable turn can have **at most one** value at a time

    -    Both `flag[i]` and `flag[j]` are `true` when they wanna enter their critical section

    -   Turn is a **singular variable** that can store only **one value**

    -   Hence at most one of `while(flag[i] && turn == i)`or  `while(flag[j] && turn == j)` is `true` and at most **one process can enter its critical section**



**Progress requirement**

-   **Progress**: any process must be able to enter its critical section at some time

    -   processes/threads in the **"remaining code" do not influence** access to critical sections


    -   If process `j` does **not want to enter** its critical section
    
        => `flag[j] == false`
    
        => `while(flag[j] && turn == j)` will terminate for process i
    
        => i enters critical section




**Fairness/bounded waiting requirement**

-   Processes cannot be made to wait **indefinitely**

-   If Pi and Pj both want to enter their critical section

    => `flag[i] == flag[j] = true`

    =>  `turn` is either i or j 

    => assuming that `turn == i`

    => `while(flag[j] && turn == j)` terminates and i enters section

    => i finishes critical section

    => `flag[i] = false` 

    => `while(flag[i] && turn == i)` terminates and j enters critical section. 

    Even if it loops back round again, it will set `turn = j`, letting the other thread in first.

## Atomic Instructions (Hardware approach)

>   Reference: [Youtube](https://www.youtube.com/watch?v=5oZYS5dTrmk&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=59)

-   Implement `test_and_set()` and `swap_and_compare()` instructions as a **set of atomic (uniterruptible) intructions**
    -   Reading and setting the variables appears as **a single instruction**
    -   If both of them are called **simultaneously**, they will be **executed sequentially**

**Test and Set Lock**

-   There is a shared lock variable which can take either 0 or 1
-   Before entering into the critical section, a process **inquires** about the lock
    -   if locked, wait till it becomes fress
    -   if not locked, takes the lock and executes the critical section

```C
bool TestAndSet(bool *target) {
    bool rv = *target;
    *target = true;
    return rv;
}

do {
    while (TestAndSet(&lock));	// busy waiting

    // Critical Section
    
    lock = false;
    
    // remainder section
} while(true);
```

**Compare and Swap**

```C
int compare_and_swap(int* iIsLocked, int expected, int new_value) { 
    int const old_value = *iIsLocked;
    if (old_value == expected) 
        *iIsLocked = new_value; 
    return old_value; 
}

do {
	while (compare_and_swap(&iIsLocked, 0, 1)); 
    // Lock was false, now true

    // Critical Section

    iIsLocked = 0;
    
	// remainder section 
} while (...);
```

**Mutual Exclusion**

-   Both are rather low level and require busy waiting
-   The OS may use these hardware instructions to implement higher level mechanisms for mutual exclusion, i.e. **mutexes and semaphores**
-   Does NOT satisfy **bounded waiting**

## Mutex (OS approaches)

-   **Mutexes** are an abstraction for providing **mut**ual **ex**clusion
-   It provides an interface with two functions
    -   `acquire(&mutex)`: called **before entering** a critical section, returns when nobody else is in the critical section
    -   `release(&mutex)`: called **after exiting** the critical section, allows other threads to acquire the mutex. Should only be called after matching a acquire
-   Implementation detail
    -   Under naive assumption, we could use Peterson's algorithm
    -   We could use atomic hardware operations and busy waiting
    -   The OS could block threads that are trying to acquire a mutex that is not available

```C
int counter = 0; 
pthread_mutex_t lock; 

void * calc(void * param) {
    int const iterations = 50000000;
    for(int i = 0; i < iterations; i++) {
        pthread_mutex_lock(&lock);	// acquire
        counter++;
        pthread_mutex_unlock(&lock);// release
    }
    return 0;
} 

int main() {
    pthread_t tid1 = 0, tid2 = 0;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&tid1, NULL, calc, 0);
    pthread_create(&tid2, NULL, calc, 0);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("The value of counter is: %d\n", counter);
}
```





