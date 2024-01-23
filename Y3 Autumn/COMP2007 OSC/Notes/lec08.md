# lec08: Concurrrency 1

>   **Overview**
>
>   -   Process Synchronization
>       -   Example 1: Incrementing a counter
>       -   Example 2: Shared procedures
>       -   Example 3: Bounded buffers
>   -   Race Conditions
>   -   Critical Sections
>       -   Approaches
>       -   Busy waiting
>
>   -   Deadlocks
>
>   *Reference: MOS Chapter 2.3.1, 2.3.2, [Youtube](https://www.youtube.com/watch?v=ph2awKa8r5Y&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=56)*

### Process Synchronization 

>   Reference: *[Youtube](https://www.youtube.com/watch?v=ph2awKa8r5Y&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=56)*

-   A **cooperating process** is one that can affect or be affected by other processes executing in the system. They can either,
    -   directly share a logical address space
    -   be allowed to share data only through files or messages
-   Concurrent access to shared data may result in **data inconsistency**
    -   one famous example is the **Producer-Consumer-Problem** (*MOS 2.3.4*)

>   Reference: *MOS 2.3.1*

**Three main problems** (the last two problems also works for *Threads*)

-   how one process can **pass information** to another
-   how to make sure two or more processes **do not get in each other's way**
    -   e.g. last seat on a train in a booking system
-   how to **proper sequencing** when dependencies are present
    -   e.g. if process A produces data and process B prints them
    -   B has to wait until A has produced

### **Example 1: Incrementing a counter**

```C
#include <stdio.h> 
#include <pthread.h>

int counter = 0; 
void* calc(void* param) { 
    int const iterations = 50000000;
	for(int i = 0; i < iterations; i++)
        counter++;
    return 0;
}

int main() {
    pthread_t tid1 = 0,tid2 = 0;
    pthread_create(&tid1, NULL, calc, 0);
    pthread_create(&tid2, NULL, calc, 0);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("The value of counter is: %d\n", counter);
}
```

-   `counter++` consistws of three separate actions:
    -   `read` the value and store it in a register
    -   `add` one value to the register
    -   `store` the value of the register in **counter** in memory

<img src="assets/Screenshot 2023-10-18 at 09.14.30.png" alt="Screenshot 2023-10-18 at 09.14.30" style="zoom:40%;" />

<img src="assets/Screenshot 2023-10-18 at 09.15.01.png" alt="Screenshot 2023-10-18 at 09.15.01" style="zoom:40%;" />

### Example 2: Shared procedures

-   Consider the following **code shared** between threads/processes
-   `chin` and `chout` shared global variables

```C
void print () {
    chin = getchar();
    chout = chin;
    putchar(chout);
}
```

-   Consider that two processes/threads **DO NOT** interact

<img src="assets/Screenshot 2023-10-18 at 09.19.50.png" alt="Screenshot 2023-10-18 at 09.19.50" style="zoom:40%;" />

-   Consider that two processes/threads **DO** interact

<img src="assets/Screenshot 2023-10-18 at 09.21.03.png" alt="Screenshot 2023-10-18 at 09.21.03" style="zoom:40%;" />

### Example 3: Bounded Buffers

-   Two kinds of buffers
    -   **Bounded buffer**: a fixed buffer size
    -   **Unbounded buffer**: no practical limit on size

-   a **counter** is maintained to count the number of items currently in the buffer
    -   incremented when an item is added
    -   decremented when an item is removed
-   Similar **concurrency problems** as with calculation of sums happen when multiple threads read and write to the bounded buffer.

```C
// producer
while (true) {
    while (count == BUFFER SIZE);
    buffer[in] = new_item;
    in = [in + 1] % BUFFER_SIZE;
    counter++;
}
// consumer
while (true) { 
    while (counter == 0);
	consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE; 
    counter--; 
}
```

## Race Conditions

**Definition**

-   Code has a **race condition** if its behaviour is dependent on the time of when computation is performed
-   <u>A race condition typically occurs when multiple threads **access shared data**</u> and the result is dependent on **the order in which the instructions are interleaved**

**Concurrency within the OS**

-   Kernels are **preemptive** these days
    -   **Multiple threads** are running in the kernel
    -   Kernel code can be **interrupted at any point**
-   The kernel maintains **data structures** such as process tables and open file lists
    -   There data structures may be accessed **concurrently**
    -   These can be subject to **concurrency issues**

>    **An example from MOS 2.3.1**
>
>   -   Process A reads `in` and stores the value 7 in a local variable called `next_free_slot`.
>   -   A clock interrupt occurs and the CPU switches to process B.
>   -   Process B also reads `in` and also stores the value 7 in a local variable called `next_free_slot`.  And it stores the nmae of its file in slot 7 and update `in` to be 8.
>   -   A clock interrupt occurs and the CPU switches to process A.
>   -   Process A also writes its file name in slot 7, erasing the name that Process B just put there
>
>   <img src="assets/Screenshot 2023-10-23 at 14.35.09.png" alt="Screenshot 2023-10-23 at 14.35.09" style="zoom:50%;" />

## Critical Sections, Mutual Exclusion

-   <u>A **critical section** is a segment of code of a process to access shared data</u> or do other critical things that can lead to races
-   A solution to the critical section problem should satisfy the following requirements
    -   **Mutual exclusion**: only one process can be in its critical section at any one point in time
    -   **Progress**: any process must be able to enter its critical section at some point in time
    -   **Fairness/bounded waiting**: processes cannot be made to wait indefinitely

```C
do { 
    ...
	// ENTRY to critical section 
    critical section, e.g.counter++; 
    // EXIT critical section 
    // remaining code 
    ...
} while (...);
```

**Approaches**

-   A standard approach to enforcing mutual exclusion is via locks known as **mutexes**. These can be implemented in various ways
    -   software based: Peterson's solution
    -   Hardware based: `test_and_set()`, `swap_and_compare()`
    -   O/S based: the OS blocks processes waiting for the lock

-   Unfortunately, mutexes and other concurrency primitives such as **semaphore** introduce a new problem - **deadlocks**

## Deadlocks

>   **A set of threads is deadlocked if each thread in the set is waiting for an event that only the other thread in the set can cause**

**An example**

-   Assume that X and Y are **mutexes**

-   Thread A and B need to acquire both mutexes and requests them in opposite orders

-   The following sequence of events could occur in a multi-programmed system

<img src="assets/Screenshot 2023-10-24 at 01.53.21.png" alt="Screenshot 2023-10-24 at 01.53.21" style="zoom:50%;" />

**4 Minimum Conditions (Coffman's conditions)**

-   **Mutual exclusion**: a resource can be assigned to at most one process at time
-   **Hold and wait condition**: a resource can be held whilst requesting new resources
-   **No preemption**: resources cannot be forcefully taken away from a process
-   **Circular wait**: there is a circular chain of two or more processes, waiting for a resource held by the other processes

>   -   **互斥条件**：资源不能被共享，只能由一个进程在任一时刻使用
>   -   **请求和保持条件**：已经得到某些资源的进程可以请求新的资源
>   -   **非抢占条件**：资源不能被强制从一个进程中抢占。只有当拥有资源的进程自愿释放资源后，其他进程才能使用
>   -   **循环等待条件**：存在一种进程资源的循环等待链，链中的每一个进程已获得的资源同时被下一个进程所请求。

