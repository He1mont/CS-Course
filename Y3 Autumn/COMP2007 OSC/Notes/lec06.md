# lec06: Process3 - Threads

>   **Overview:**
>
>   -   Threads
>       -   Threads from an OS Perspective
>       -   Why we use threads
>   -   Different thread implementations
>       -   User Thread
>       -   Kernel Thread
>       -   Comparison
>       -   Hybrid Implementation
>   -   POSIX Threads
>       -   Thread Management
>       -   Overview
>       -   Example
>
>   *Reference: MOS Chapter 2.2, [Youtube](https://www.youtube.com/watch?v=HW2Wcx-ktsc&t=5s)*

## Threads

### What is Thread

-   A process consists of two **fundamental units**

    -   **Resources**, all related resources are grouped together
        -   a logical address space containing the proecess image (program, data, heap, stack)
        -   Files, I/O devices, I/O channels ...

    -   **Execution trace**, i.e. an entity that gets executed

-   A program can **share its resources** between **multiple execution traces**

<img src="assets/Screenshot 2023-10-12 at 16.40.30.png" alt="Screenshot 2023-10-12 at 16.40.30" style="zoom:40%;" />

-   Every thread has its own **execution context** (PC, stack, register)
-   All threads have **access** to the process **shared resources**
    -   <u>e.g. one thread opens a file, all threads of the same process can access the file</u>
    -   global variables, memory, etc. (synchronisation)
-   Similar to processes, threads have:
    -   States and transitions (running, blocked, ready)
    -   A **thread control block (TCB)**

<img src="assets/Screenshot 2023-10-19 at 14.11.36.png" alt="Screenshot 2023-10-19 at 14.11.36" style="zoom:50%;" />

### **Advantages**

-   Threads incur **less overhead** to create/terminate/switch, easier to create and destroy
    -   address space remains **the same for threads of the same process**
-   **Inter-thread communication** is easier/faster than **inter-process** communications
    -   threads share memory by default
-   Some CPUs have direct **hardware support** for **multi-threading**
    -   typically offer up to 8 hardware threads per core


-   **No protection boundaries** are required in the address space
    -   不同的进程会来自不同的用户，它们彼此之间可能有敌意
    -   不同的线程来自同个用户，它们之间应该合作而不是彼此间争斗
-   **Synchronisation** has to be considered carefully



**Why we use threads**

>   The PPT version

-   Multiple related activites apply to the same resources, these resources should be accessible/shared
-   Process will often contain multiple **blocking tasks**
    -   I/O operations (thread blocks, interrupt)
    -   Memory access: pages faults are result in blocking
-   Such activities should be carried out in **parallel/concurrently**
-   Application examples: webservers, make program

>   The Textbook version

-   Threads have the ability for the parallel entities to **share an address space** and all of its data among themselves.
-   Threads are **easier (i.e., faster) to create and destroy** than processes.
-   Threads allows CPU-bound and I/O-bound to work in concurrency, thus speeding up the application
-   An example : writing a book, into three threads
    -   one to interact with the user
    -   one to reformat the document when told to
    -   one to write the contents of RAM to disk periodically.

## Different thread implementations

>   Reference video can be found [here](https://www.youtube.com/watch?v=HW2Wcx-ktsc&t=5s)

**OS implementations of Threads**

-   User threads
-   Kernel threads
-   Hybrid implementation

### User threads (Many-to-One)

>   Example: Java Thread

-   **Thread management** is carried out in **user space** with the help of a **user library**
-   The process maintains a **thread table** managed by the **runtime system** without the **kernel's knowledge**
    -   similar to **process table**
    -   used for **thread switching**
    -   track thread related information
-   **Advantages**
    -   threads are in user space (**no mode switches**) so it is **efficient**
    -   **Full control** over the thread schedule
    -   **OS independent** (threads can run on OS that do not support them)
-   **DIsadvantages**
    -   The entire process will block if a thread makes a **blocking system calls**
    -   **No true parallelism** since only **one thread can access the kernel** at a time
    -   **Clock interrupts** are non-existent (user threads are **non-preemptive**)
    -   **Page faults** result in blocking the process

### Kernel Threads (One to one)

>   Example: Linux thread

-   The **kernel** manages the threads. User app accesses threads throught **API and system calls**
    -   **Thread table** is in the kernel, containing TCB
    -   If a **thread blocks**, the kernel chooses thread from same or different process
-   Advantages:
    -   **True parallelism** by allowing another thread to run when a thread makes a blocking system call
    -   Allows multiple threads to run **in parallel on multiprocessors**
    -   No run-time system needed
-   Disadvantages:
    -   Creating a user thread requires creating the corresponding kernel thread
    -    Frequent **mode switches** take place, resulting in lower performance

<img src="assets/Screenshot 2023-10-19 at 15.12.21.png" alt="Screenshot 2023-10-19 at 15.12.21" style="zoom:40%;" />



**Comparison** 

-   Null fork: the overhead in creating, scheduling, running and terminating a null process/thread
-   Signal wait: overhead in synchronising threads

<img src="assets/Screenshot 2023-10-19 at 15.04.20.png" alt="Screenshot 2023-10-19 at 15.04.20" style="zoom:50%;" />

### Hybrid Implementations (Many to many)

-   User threads are multiplexed onto smaller numbers of kernel threads
-   Kernel sees and schedules the kernel threads
-   User application sees user threads and create/schedules these

<img src="assets/Screenshot 2023-10-19 at 15.05.41.png" alt="Screenshot 2023-10-19 at 15.05.41" style="zoom:40%;" />

<img src="assets/Screenshot 2024-01-13 at 03.06.14.png" alt="Screenshot 2024-01-13 at 03.06.14" style="zoom:50%;" />

>   ### Exam 13-14
>
>   **In which situations would you favour user level threads? In which situation would you definitely favour kernel level threads?**
>
>   -   User-level threads are favored in 
>       -   single-processor systems
>       -   efficiency: easy to manage, no mode switches
>       -   portability: OS independent
>   -   Kernel-level threads are preferred in 
>       -   multi-core systems 
>       -   true parallelism
>       -   preemptive scheduling
>       -   resource utilization: Allows multiple threads to run in parallel on multiprocessors

## POSIX's PThreads

**Thread Management**

-   Thread libraries provide an **API for managing threads** like `POSIX's PThreads`
-   Thread libraries can be implemented:
    -   entirely in **user space** (i.e. user threads)
    -   bases on **system calls** (i.e. reply on the kernel)

**Overview**

-   POSIX threads are a specification that "anyone" can implement

    -   i.e. it defines a set of APIs

-   Core functions of PThreads include:

    <img src="assets/Screenshot 2023-10-19 at 15.37.28.png" alt="Screenshot 2023-10-19 at 15.37.28" style="zoom:50%;" />

**Example**

```C
#include <pthread.h> 
#include <stdio.h>

void* hello(void * arg) {
    printf("Hello from thread %d\n", * ((int * )arg));
    return 0;
}

int main() {
    int const THREADS = 10;
    int args[THREADS] = { 0 };
    pthread_t threads[THREADS];
    for(int i = 0; i < THREADS; i++) {
        args[i] = i;
        if(pthread_create(threads + i, NULL, hello, args + i)) {
            printf("Creating thread %d failed\n", i);
            return -1;
        }
    }
    for(int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);
}
```

## Quiz

1.   **If the threads in a process share the same memory, why do they have independent stacks?**

-   Each thread has its own execution sequence and local variables. 
-   The stack is to store local variables, return addresses, and the execution state
-   Independent stacks allow for such thread-specific data management.

2.   **Is it always necessary to call pthread_exit when ending a thread?** 

-   调用 `pthread_exit` 是明确退出线程的一种方式，但并非总是必要。如果线程中的 `main` 函数返回，或者线程的启动例程返回，线程将自动退出。

3.   **What is the minimum number of threads a process can have?**

-   1

4.   **Can user threads make good use of concurrent hardware?**

-   Normally NO, since user threads are mapped to a single kernel thread
