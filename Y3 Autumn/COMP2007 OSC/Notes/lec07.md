# lec07: Process 4 - Further Scheduling

>   **Overview**
>
>   -   **Multi-level feedback queues**
>   -   Scheduling in **Windows 7**
>   -   Scheduling in **Linux**
>   -   Scheduling **related processes/threads**
>
>   *Reference: MOS Chapter 2.4, 8.1.4*

## Multi-level feedback queues

-   Different **scheduling algorithms** can be used for the individual queues
-   **Feedback queues** allow **priorities to change dynamically**. Jobs can move between queues
    -   move to lower priority queue, if too much CPU time is used (prioritise I/O and interactive processes)
    -   move to higher priority queue, to prevent **starvation** and avoid **inversion of control**
    -   Here is an illustration of inversion of Control

<img src="assets/Screenshot 2023-10-16 at 15.18.16.png" alt="Screenshot 2023-10-16 at 15.18.16" style="zoom:40%;" />

-   Defining characteristis of feedback queue include:
    -   The **number of queues**
    -   The **scheduling algorithms** used for the individual queues
    -   **Migration policy** between queues
    -   Initial access to the queue
-   Feedback queues are highly **configurable** and offer significant flexibility

>   ### Example
>
>   **具体例子**
>
>   假设系统有三个队列，优先级从高到低分别为 Q1、Q2、Q3，时间片分别为10ms、20ms、40ms。
>
>   -   **场景**：
>       -   有三个进程P1、P2、P3，初始时都在最高优先级队列Q1。
>   -   **进程行为**：
>       -   P1是I/O密集型进程，经常在使用完部分时间片后进行I/O操作。
>       -   P2是CPU密集型，经常耗尽整个时间片。
>       -   P3初期是CPU密集型，但随后转为I/O密集型。
>   -   **调度过程**：
>       -   由于P2经常耗尽时间片，它被移动到优先级较低的队列Q2。
>       -   P1由于频繁的I/O等待，保持在高优先级队列Q1。
>       -   P3开始时在Q1，但由于行为的改变，后来被移动到Q2，最终在I/O频繁后又回到Q1。

>   ### Exam 13-14
>
>   **Explain how you would prevent starvation in a priority queue algorithm**
>
>   1.  **老化（Aging）**：如果进程在队列中等待太久，则增加其优先级。随着时间的推移，进程的优先级逐渐提高，确保它最终能够被执行。
>   2.  **优先级上限（Priority Ceiling）**：设置一个限制，限制进程可以被更高优先级进程抢占的时间长度。一旦达到这个限制，进程要么被执行，要么其优先级被提高。
>   3.  **公平共享调度（Fair Share Scheduling）**：根据分配给每个进程的系统资源份额分配CPU时间。这确保即使优先级较低的进程也能获得合理的CPU时间。
>   4.  **优先级内的轮转调度（Round-Robin within Priority Levels）**：将优先级调度与轮转调度结合起来。具有相同优先级的进程以轮转方式调度，以确保它们之间均等分配时间。
>   5.  **随机选择（Random Selection）**：偶尔随机选择一个进程执行，不考虑其优先级，以确保所有进程都有机会被执行。

## Scheduling in Windows 7

-   An interactive system using r
-   Two priority classes with 16 different priority levels exist
    -   "**Real time**" processes/threads have a **fixed priority level**
    -   "**Variable**" processes/threads can have their priorities **boosted temporarily**
-   A **round robin algorithm** is used within the queues

<img src="assets/Screenshot 2023-10-23 at 01.30.31.png" alt="Screenshot 2023-10-23 at 01.30.31" style="zoom:40%;" />

-   Priorities are based on the **process base priority** (between 0-15) and **thread based priority** 
-   A thread's **priority dynamically changes** during execution between its base priority and the maximum priority within its class
    -   **Interactive I/O bound processes** receive a **larger boost**
    -   Boosting priorities prevents starvation and priority inversion

**An example**

-   P1 and P2 have initial priority 1 (higher) but P3 has priority 2 (lower)
-   ==yellow block==: The scheduler concludes P3 is being starved of CPU time.
-   Process P3 has it’s priority temporarily promoted to prevent starvation.

<img src="assets/Screenshot 2023-10-23 at 01.40.50.png" alt="Screenshot 2023-10-23 at 01.40.50" style="zoom:50%;" />

## Scheduling in Linux

**The completely fair scheduler**

-   Process sheduling has **evolved** over different versions of LInux to make efficient use of multiple processors/cores
-   Linux distinguishes between **two types** of tasks for scheduling
    -   **Real time tasks** (to be POSIX compliant), divided into
        -   real time FIFO Tasks
        -   real time Round Robin tasks
    -   **Time sharing tasks** using a **preemptive** approach which are similar to **variable** in Windows
-   The most recent scheduling algorithm in Linux for time sharing tasks is the **completely fair scheduler(CFS)**



**Real-time tasks**

-   **Real-time FIFO** tasks have the **highest priority** and are scheduled using a **FCFS approach**, using **preemption** if a higher priority job shows up
-   **Real-time round Robin** tasks are preemptable by **clock interrupts** and have a **time slice** associated with them
-   Both approaches **cannot guarantee hard deadlines**



### Completely Fair Scheduler (CFS)

we imagine a hypothetical ideal scenario:

-   Our CPU allows all N current tasks to be run simultaneously, with each receiving 1/N of the CPU power
-   For example, with 5 tasks wanting to run, each gets 20% of the available computational power
-   Unfortunately, real CPUs cannot run an arbitrary number of tasks in parallel in this way - but can we approximate this ideal



**Deciding how to divide up the CPU time**

-   We choose a **target latency**
    -   this is the amount of time before every task gets access to the CPU.
    -   The target latency also bounds how far we will drift from being fair

-   To hit this target latency, for N tasks, each task is allowed to run for 1/N of the target latency
-   To avoid excessive context switching when N is large, we also choose a **minimum granularity**
    -   <u>a minimum amount of time we will allow a task to run on the CPU</u> before being considered for replacement


**Approximating Fairness**

-   We record a **virtual time** that each task has had on the CPU, and order tasks by their virtual CPU time
-   Tasks are ordered in **ascending order of virtual time used** - implemented using a red-black tree
-   The task with the lowest virtual time on the CPU is considered to have been **treated least fairly**, and will be the next one chosen to run on the CPU
-   After that task has had 1/N of the target latency in virtual time, we replace it with the next task with lowest virtual run time
-   Note - system calls may lead to a quicker CPU time

**Accounting for priorities**

-   A **weighting scheme** is used to take different priorities into account

    -   <u>we will assume that the weight is literally the task priority - a simplification</u>

-   The recorded virtual time on the CPU is the really time on the CPU scaled up by the weight. After 100ms of actual computation time:
    -   A priority 1 (higher priority) process is considered to have used 100ms of virtual time.

        A priority 2 (lower priority) process is considered to have used 200ms of virtual time.
-   **Virtual time runs at different speeds for different priority processes**

>   **Example Question**
>
>   Assume three tasks T1, T2, and T3, with priorities 1,2 and 3 respectively, and target latency is 300ms. Write T(v,r) to indicate task T has had v units of virtual run time, and r units of real time. The state after each 100ms of virtual time is:
>
>   -   CPU: T1(0,0), queue: T2(0,0), T3(0,0)
>   -   CPU: T2(0,0), queue: T3(0,0), T1(100,100)
>   -   CPU: T3(0,0), queue: T1(100,100), T2(100,50)
>   -   CPU: T1(100,100), queue: T2(100,50), T3(100,33)
>   -   CPU: T2(100,50), queue: T3(100,33), T1(200,200)
>   -   ...

**Further enhancements**

To avoid potential pathological behaviours

-   New tasks have their virtual run time set to the **current minimum virtual run time**
    -   think about how unfairly advantaged they might be if this was set to zero
-   Blocked tasks have their virtual run time set to the greater of:
    -   the **current minimum virtual run time, minus a small offset** - to ensure it gets to run
    -   its old virtual run time - in this case it is already getting a good share of the CPU

## Multi-processor Scheduling

**Shared Queue**

-   A **single or multi level queue shared** between all CPUs
-   Advantage: automatic **load balancing**
-   Disadvantage: 
    -   **Contention** for the queues
    -   Does not take advantage of the current state of the CPU's
        -   **Cache** becomes invalid when moving to a different CPU
        -   Translation look aside buffers become invalid

**Private Queues**

-   Each CPU has a **private queue** or queues
-   Advantages:
    -   Often can reuse existing CPU state such as cache and TLB
    -   **Contention** for shared queue is minimised
-   Disadvantage: less **loading balancing**
-   To mitigate the lact of load balancing **migration** between CPUs is possible

**Thread Types**

-   **Related**: multiple threads that communicate with one another and ideally run togerther
-   **Unrelated**: e.g. processes threads that are **independent**, possibly started by different users running different programs

**Working Together**

-   Process A has thread A0 and A1

    Process B has thread B0 and B1

-   The scheduler selects A0 and B1 to run first, then A1 and B0, run on different CPUs

<img src="assets/Screenshot 2023-10-23 at 13.09.16.png" alt="Screenshot 2023-10-23 at 13.09.16" style="zoom:50%;" />



-   The aim is to get collaborating threads running as much as possible , at the same time across multiple CPUs
-   Approaches include:
    -   Space sharing
    -   Gang scheduling

**Space Sharing**

-   N related threads, typically from a single process, are allocated to N dedicated CPUs when enough CPUs are available
-   M related threads, typically from another process, are kept waiting until M CPUs are available
-   At any point in time the available CPUs are partitioned into blcoks of related threads
-   As thread complete, their dedicated CPUs are returned to the collection of available CPUs
-   The CPUs are not multiprogrammed to keep related threads running together. This means blockign calls result in idle CPUs

**Gang scheduling**

-   Space sharing scheduling shares work by space (CPU)
    -   Keeps related threads running together
    -   Lack of multiprogramming avoids context switching overhead, but leads to wasted CPU cycles
    -   Gang scheduling is an attempt to schedule "in both time and space" to avoid this waste of CPU time
-   The scheduler groups related threads together into gangs to run simultaneously on different CPUs
-   This is a preemptive algorithm, with time slices synchronised across all CPUs
-   Blocking threads result in idle CPUs
    -   if a thread blocks the rest of the time slice will be unused, due to the time slice synchronisation across all CPUs







