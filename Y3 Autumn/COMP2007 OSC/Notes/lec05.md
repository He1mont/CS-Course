# lec05: Process 2 - Scheduling

>   **Overview**
>
>   -   Introduction to **process scheduling**
>   -   Types of **process schedulers**
>       -   Classification by Time Horizon
>       -   Classification by Approach
>   -   **Evaluation criteria** for scheduling algorithms
>-   Typical **process scheduling algorithms**
>   
>   *Reference: MOS Chapter 2.4*

## Process scheduling

**Context**

-   The OS Is responsible for **managing** and **scheduling processes**
    -   decide when to **admit** processes to the system (new -> ready)
    -   decide which process to **run** next (ready -> run)
    -   decide when and which processes to **interrupt** (running -> ready)
-   It relies on the **scheduler** to decide using a **scheduling algorithm**
    -   the type of algorithm is influenced by the **type of OS**

-   Two types
    -   **CPU-bound** or compute-bound
    -   **I/O-Bound**

<img src="assets/Screenshot 2023-10-19 at 02.20.45.png" alt="Screenshot 2023-10-19 at 02.20.45" style="zoom:33%;" />

### Process schedulers

**Classification by Time Horizon**

-   **Long term**: 
    -   applies to **new processes** and controls the degree of multiprogramming by deciding which processes to admit to the system when
    -   A good **mix of CPU and I/O bound processes** is favourable to keep all resources as busy as possible
    -   usually absent in popular modern OS
-   **Medium term**
    -   controls swapping and the degree of multi-programming
-   **Short term**
    -   manages the **ready queue**
    -   invoked very frequently, hence must be fast
    -   usually called in response to **clock interrupts**, **I/O interrupts**, or **blocking system calls**

<img src="assets/Screenshot 2023-10-19 at 02.06.14.png" alt="Screenshot 2023-10-19 at 02.06.14" style="zoom:40%;" />

**Classification by Approach**

-   **Non-preemptive**: processes are only interrupted **voluntarily**
-   **Preemptive**: processes can be interrupted **forcefully or voluntarily**
    -   Typically driven **by interrupts from a system clock**
    -   Requires additional context switches which generate **overhead**
    -   Prevents processes from **monopolising the CPU**
    -   Most popular modern operating systems are preemptive

## Performance Assessment

-   **User oriented criteria:**
    -   **response time**: minimise the time between creating the job and its first execution
    -   **turnaround time**: minimise the time between job creation and completion
    -   **predictability**: minimise the variance in processing times
-   **System oriented criteria**
    -   **Throughput**: maximise **the number of jobs processed** per hour
    -   **Fairness**
        -   Are processing power/waiting time equally distributed?
        -   Are some processes kept waiting excessively long? (**starvation**)

-   Evaluation criteria can be **conflicting**
    -   improving the response time may require more context switches
    -   hence worsen the throughput and increase the turnaround time

## Scheduling Algorithms

-   Algorithms considered 
    -   First Come First Served (FCFS) / FIFO => **non-interactive system**
    -   Shortest job first => **non-interactive system**
    -   Round robin => **interactive system**
    -   Priority queues => **interactive system**
-   Performance measures used
    -   **Average response time**: avg time taken for all the processes to *start*
    -   **Average turnaound time**: avg time taken for all the processes to *finish*

### First Come First Served (FCFS)

>   A more detailed explanation could be found [here](https://www.youtube.com/watch?v=7DoP1L9nAAs&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=40)

-   **Concept**: a **non-preemtive algorithm** that operates as a **strict queueing mechanism** and schedules the processes in the same order that they were added to the queue
-   **Advantages**: 
    -   **positional fairness** and easy to implement using a **FIFO queue**

-   **Disadvantages**
    -   **Favours long processes** over short ones
    -   Could **compromise resource utilisation**
-   An example
    -   Average response time = 0 + 7 + 9 + 15 = 31/4 = 7.75
    -   Average turn-around time = 7 + 9 + 15 + 20 = 51 4 = 12.75

<img src="assets/Screenshot 2023-10-19 at 02.46.01.png" alt="Screenshot 2023-10-19 at 02.46.01" style="zoom:40%;" />

### Shortest Job First

>   A more detailed explanation could be found [here](https://www.youtube.com/watch?v=t0g9b3SJECg&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=43)

-   **Concept**: a **non-preemtive algorithm** that starts processes in order of **ascending processing time** using a provided/known estimate of the processing
-   **Advantages**: 
    -   always result in the **optimal turn around time**

-   **Disadvantages**:
    -   **starvation** might occur
    -   **fairness** and **predictability** are compromised
    -   **processing times** have to be known beforehand
-   An example
    -   Average response time = 0 + 2 + 7 + 13 = 22/4 = 5.5
    -   Average turn around time = 2 + 7 + 13 + 20 = 42/4 = 10.5

<img src="assets/Screenshot 2023-10-19 at 02.49.42.png" alt="Screenshot 2023-10-19 at 02.49.42" style="zoom:40%;" />

### Round Robin

>   A more detailed explanation could be found [here](https://www.youtube.com/watch?v=7TpxxTNrcTg&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=50)

-   **Concept**: **a preemptive version of FCFS** that forces context switches at **periodic intervals or time slices**
    -   Processes run in the order that they were added to the queue 
    -   Processes are forcefully **interrupted by the timer**
-   **Advantages:**

    -   Each process is allocated CPU time to response more efficiently

    -   Improved **response time** 
    
    -   Effective for general purpose **interactive/time sharing systems**
-   **Disadvantages:**

    -   Increased **context switching** and thus **overhead** 
    -   Favours **CPU-bound** processes (which usually run long) over **I/O** processes (which do not run long)
    -   Can **reduce to FCFS**
-   Core of this alg. => **the length of time slice**

    -   assume a multi-programming system with preemptive scheduling and a context switch time of `1ms`
        -   a **good response time** is achieved with a **small** time slice
        -   a **high throughput** is achieved with a **large** time slice
    -   time slice too short => too much context switch => less efficiency in CPU
    -   time slice too long => longer response time
-   An example

    -   Average response time = 0 + 1 + 2 + 3 = 6/4 = 1.5
    -   Average turn-around time = 6 + 17 + 19 + 20 = 62/4 = 15.5

<img src="assets/Screenshot 2023-10-19 at 02.54.48.png" alt="Screenshot 2023-10-19 at 02.54.48" style="zoom:40%;" />

### Priority Queues

>   A more detailed explanation could be found [here](https://www.youtube.com/watch?v=yKD3pcFvGmY&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=46)

-   **Concept**: A **preemptive algorithm** that schedules processes by priority (high → low)
    -   A round robin is used within the same priority levels 
    -   The process priority is saved in the **process control block**
-   **Advantages**: can prioritise I/O-bound jobs
-   **Disadvantages**: low priority processes may suffer from **starvation** (when priorities are static)
-   An example:
    -   Average response time = 0 + 1 + 11 + 13 = 25/4 = 6.25
    -   Average turn around time = 10 + 11 + 13 + 20 = 54/4 = 13.5

<img src="assets/Screenshot 2023-10-19 at 02.59.15.png" alt="Screenshot 2023-10-19 at 02.59.15" style="zoom:40%;" />

### Summary

|                  | FCFS                                           | SJF                                                     | Round Robin                                                  | PriorityQueue                                     |
| ---------------- | ---------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------- |
| CPU or I/O bound | CPU                                            | CPU                                                     | CPU                                                          | I/O                                               |
| suitable system  | non-interactive                                | non-interactive                                         | interactive                                                  | interactive                                       |
| preemptive?      | non-preemptive                                 | non-preemptive                                          | preemptive                                                   | preemptive                                        |
| concepts         | schedules process in the order of arrival time | schedules process in the order of processing time       | preemptive version of FCFS, forces context switch at periodic time interval | preemptive alg that schedules process by priority |
| pros             | positional fairness, easy to implement         | optimal turnaround time                                 | each process is allocated with CPU time, prevent starvation, improve response time | prioritise I/O bound jobs                         |
| cons             | compromise resource utilisation                | starvation, processing times should be known beforehand | increased context switching and overheads                    | starvation for low prioirty processes             |

## Quiz

1.  **On a Non-Preemptive Operating System, What Can a Process Do Without Volunteering to Cede the CPU?**

-   CPU-Bound Tasks
-   Executing Instructions
-   Processing Data in Memory

2.  **Using the Non-Preemptive Shortest Job First Scheduler, Does the Shortest Job Run on the CPU Until Completed?**

-   Yes. Since it will not be interrupted and it would be run first for it is the shortest job.
