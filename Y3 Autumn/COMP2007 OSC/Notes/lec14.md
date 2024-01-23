# lec14: Memory Management 1

>   **Overview**
>
>   -   **Introduction** to memory management
>   -   **Modelling** of multi-programming
>   -   Memory management based on **fixed partitioning**

## Memory Management

**Memory Hierarchies**

-   Computers typically have memory hierarchies:
    -   Registers, L1/L2/L3 cache 
    -   Main memory (RAM) 
    -   Disks
-   -   "Higher memory" is faster, more expensive and volatile, 
    -   "lower memory" is slower, cheaper, and non-volatile 
-   The operating system provides a **memory abstraction** 
-   Memory can be seen as one **linear array** of bytes/words



**OS reponsibilities**

-   **Allocate/deallocate** memory when requested by processes 
-   Keep track of **used/unused** memory 
-   **Distribute memory** between processes and simulate an "**infinitely large"** memory space 
-   **Control access** when multiprogramming is applied 
-   **Transparently** move data from memory to disk and vice versa

## Models

-   **Contiguous** memory management models:
    -   allocate memory in **one single block** without any holes or gaps 
-   **Non-contiguous** memory management models:
    -   Allocate memory in multiple **blocks, or segments**
    -   May be placed anywhere in physical memory (i.e., not necessarily next to each other)

<img src="assets/Screenshot 2023-11-02 at 14.37.36.png" alt="Screenshot 2023-11-02 at 14.37.36" style="zoom:30%;" />

<img src="assets/Screenshot 2023-11-02 at 14.38.00.png" alt="Screenshot 2023-11-02 at 14.38.00" style="zoom:30%;" />



##### Parititioning (for contiguous approach)

-   **Mono-programming**: one single partition for user processes 
-   **Multi-programming** with **fixed partitions**
    -   Fixed **equal** sized partitions 
    -   Fixed **non-equal** sized partitions
-   **Multi-programming** with **dynamic partitions**

### Mono-Programming (NO Memory Abstraction)

-   Only **one single user process** is in memory/executed at any point in time (**no multi-programming**)
-   Divide main memory into **Kernel space** and **user space**.
-   This process has **direct access** to **physical memory** (i.e. **no address translation** takes place)

<img src="assets/Screenshot 2023-11-02 at 14.43.37.png" alt="Screenshot 2023-11-02 at 14.43.37" style="zoom:40%;" />

**Properties**

-   Every process is allocated **contiguous block of memory**
-   **Only one process** is allocated the **entire memory space** 
-   The process is **always located in the same address space** 
-   **No protection** between different user processes required (one process) 
-   **Overlays** enable the programmer to use more memory than available (burden on programmer)

**Shortcomes**

-   It may have access to **OS memory** since a process has direct access to the physical memory
-   **Low utilisation** of hardware resources (CPU, I/O devices, etc.)
-   **Direct memory access** and **mono-programming** are common in basic **embedded systems** and modern consumer electronics, e.g. washing machines, microwaves

| Advantages                                       | Disadvantages                    |
| ------------------------------------------------ | -------------------------------- |
| One process is allocated the entire memory space | Direct access to physical memory |
| No need for protection between processes         | Low utilisation of CPU           |

### Multi-Programming

**A Probabilistic Model**

-   There are n **processes in memory**
-   A process spends `p` percent of its time **waiting for I/O** 
-   **CPU Utilisation** is calculated as `1 - p`
-   The probability that **all n processes are waiting for I/O** is `p^n`
-   The CPU utilisation is given by `1 - p^n`

<img src="assets/Screenshot 2023-11-02 at 14.59.04.png" alt="Screenshot 2023-11-02 at 14.59.04" style="zoom:50%;" />

>   Therefore, **Multi-programming** does enable to **improve resource utilisation**

**Caveats**

-   This model assumes that all processes are **independent**, this is not true
-   More complex models could be built using **queueing theory**, but we can still use this simplistic model to make **approximate predictions**

## Parititioning

### Fixed Partitions of equal size

-   Divide memory into **static, contiguous and equal sized partitions** that have a **fixed size** and **fixed location**

    -   Any process can take any (large enough) partition 

    -   Allocation of fixed equal sized partitions to processes is trivial 

    -   Very **little overhead** and **simple implementation** 

    -   The OS keeps a track of which partitions are being **used** and which are **free**

-   **Disadvantages** 
    -   **Low memory utilisation** and **internal fragmentation**: partition may be unnecessarily large 
    -   **Overlays** must be used if a program does not fit into a partition (burden on programmer)

| Advantages            | Disadvantages                                                |
| --------------------- | ------------------------------------------------------------ |
| Simple implementation | Low memory utilisation and internal fragmentation (parition too large) |
|                       | Program may not fit into a partition (partition too small)   |

### Fixed Partitions of non-equal size

-   Divide memory into **static and non-equal sized** partitions that have a **fixed size** and **fixed location**
    -   Reduces **internal fragmentation** 
    -   The allocation of processes to partitions must be **carefully considered**

<img src="assets/Screenshot 2023-11-02 at 15.17.44.png" alt="Screenshot 2023-11-02 at 15.17.44" style="zoom:40%;" />

-   One **private queue** per paritition
    -   assigns each process to the **smallest partition** that it would fit in
    -   reduces internal fragmentation
    -   can reduce memory utilisation and result in starvation (lots of small jobs result in unused large partition)
-   A single **shared queue **for all partitions
    -   allocate small processes to large partitions
    -   results in increased **internal fragmentation**

| Advantages                    | Disadvantages                                                |
| ----------------------------- | ------------------------------------------------------------ |
| Reduce internal fragmentation | Low memory utilisation or starvation <br />(e.g. lots of small jobs result in unused large partitions) |



