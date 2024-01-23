# lec20: File System 1

>   **Overview**
>
>   -   Rotational Hard Drives
>       -   Construction
>       -   Organisation
>       -   Access Time
>   -   Disk scheduling
>       -   FCFS
>       -   SSTF
>       -   SCANs
>   -   SSD Drives

## Rotational Hard Drives

### **Construction**

-   Rotational hard drives are made of aluminium/glass **platters** covered with **magnetisable material**
    -   Read/write heads fly just above the surface (0.2 – 0.07mm) and are connected to a single **disk arm** controlled by a single **actuator** 
    -   **Data** is stored on both sides 
    -   Common **diameters** range from 1.8 to 3.5 inches 
    -   They **rotate** at a **constant speed** (speed near the spindle is less than on the outside)
-   A **disk controller** abstracts the low level interface 
-   **Rotational hard drives** are approx. 4 orders of magnitude slower than main memory

<img src="assets/Screenshot 2024-01-10 at 21.08.20.png" alt="Screenshot 2024-01-10 at 21.08.20" style="zoom:50%;" />

**Low Level Format**

-   Disks are organised in:
    -   **Cylinders**: all tracks in the same position relative to the spindle
    -   **Tracks**: a concentric circle on a single platter side 
    -   **Sectors**: segments of a track
-   Sectors usually have an **equlal number of bytes** in them
-   The **number of sectors increases** from the inner side of the disk to the outside

<img src="assets/Screenshot 2024-01-10 at 21.12.45.png" alt="Screenshot 2024-01-10 at 21.12.45" style="zoom:50%;" />

### Organisation

-   **Cylinder skew** is an **offset** that is added to the sectors in adjacent tracks to account for the seek time
-   In the past, consecutive **disk sectors were interleaved** to account for transfer time
-   **Disk capacity** is reduced due to **low level formatting**

### Access Times

**Access time** = seek time + rotational delay + transfer time

-   **Seek time**: time needed to move the arm to the cylinder (dominant)
-   **Rotational latency**: time before the sector appears under the head
-   **Transfer time**: time to transfer the data

<img src="assets/Screenshot 2024-01-10 at 21.17.39.png" alt="Screenshot 2024-01-10 at 21.17.39" style="zoom:40%;" />

-   Multiple requests may be happening at the same time (concurrently). Thus, access time may be increased by a **queueing time**
-   Dominance of seek time leaves room for **optimisation** by carefully considering the order of read operations

<img src="assets/Screenshot 2024-01-10 at 21.24.18.png" alt="Screenshot 2024-01-10 at 21.24.18" style="zoom:40%;" />

-   The **esimated seek time** $T_s$ to move the arm from one track to another is approx.:

$$
T_s = n \times m + s
$$

-   where:
    -   `n`: the number of tracks to be crossed
    -   `m`: the crossing time per track
    -   `s`: any additional startup delay 

-   Assume a disk that rotates at `3600rpm`,
    -   one rotation takes approx: 16.7ms (60,000 / 3,600)
    -   the average **rotational latency** $T_r$ is **half a rotation** on average 8.3ms (16.7 / 2)
-   Let `b` denote the **number of bytes transferred**, `N` the **number of bytes per track**, and `rpm` the **rotation speed** in revolution per minute
-   The **transfer time** $T_t$ is given by

$$
T_t = \frac{b}{N} \times ms \ per \ revolution
$$

-   where
    -   `N` bytes takes 1 revolution (16.7ms)
    -   `b` contiguous bytes takes b/N revolutions

### An Example

-   To read a file of **size 256 sectors** with: Ts = 20ms (avg seek time) and 32 sectors
-   If the file is stored **contiguously**
    -   **The first track**: 20 + 8.3 + 16.7 = 45ms (seek + rotational delay + transfer time)
    -   **The remaining track**: 8.3 + 16.7 = 25ms (rotational delay + transfer time)
        -   assuming no cylinder skew and negligible seeks time between neighbouring tracks
-   The total time is then 45 + 7 * 25 = 220ms
-   In case the access is not sequential but **at random for the sectors**, we have:
    -   Time per sector = Ts + Tr + Tt = 20 + 16.7/2 + 16.7/32 = 28.8ms
    -   Total time for 256 sectors = 256 * 28.8ms = 7.37s
-   Observation: **sectors** must be positioned carefully and avoid **disk fragmentation**

## Disk Scheduling

**Concepts**

-   The  OS/hardware must:
    -   **Position/organise** files and sectors strategically
    -   Optimise **disk requests** to **minimise overhead** from seek time and rotational delays
-   **I/O requests happen over time** and  go through a **system calls** and are queued:
    -   They are kept in a **table of requested sectors per cylinder**
    -   This allows the operating system to **intercept** and **re-sequence** them
-   **Disk scheduling algorithms** determine the order in which disk requests are processed to **minimise overhead**
    -   They commonly use **heuristic approaches**
    -   That is, none of the algorithms discussed here are optimal algorithms

>   ### Example
>
>   -   Assume a disk with 36 cylinders, numbered 1 to 36
>
>   -   Consider the following sequence of disk requests (cylinder locations)
>
>       `11, 1, 36, 16, 34, 9, 12`

### FCFS

-   **First come first served**: process the requests in the order that they arrive
-   Order: `11, 1, 36, 16, 34, 9, 12`
-   Total length: 10 + 35 + 20 + 18 + 25 + 3 = 111

<img src="assets/Screenshot 2024-01-10 at 21.58.37.png" alt="Screenshot 2024-01-10 at 21.58.37" style="zoom:50%;" />

### Shortest Seek Time First

-   **Shortest seek time first**: selects the request that is closest to the current head position
-   Order: `11, 12, 9, 16, 1, 34, 36`
-   Total length: 1 + 3 + 7 + 15 + 33 + 2 = 61

<img src="assets/Screenshot 2024-01-10 at 21.59.09.png" alt="Screenshot 2024-01-10 at 21.59.09" style="zoom:50%;" />

-   SSTF could result in **starvation**

>   An Example for **Stavation** caused by SSTF
>
>   假设一个磁盘的当前磁头位置在轨道100，系统收到了一系列磁盘读写请求，它们分别位于不同的轨道：
>
>   -   请求1：轨道95
>   -   请求2：轨道180
>   -   请求3：轨道105
>   -   请求4：轨道110
>   -   请求5：轨道190
>
>   按照SSTF算法，系统会选择距离当前磁头位置最近的请求进行服务。因此，处理请求的顺序将如下：
>
>   1.  **首先处理轨道105的请求3**（距离为5，是最近的）
>   2.  **接着处理轨道110的请求4**（距离为5）
>   3.  **然后处理轨道95的请求1**（距离为15）
>   4.  **处理轨道180的请求2**（距离为85）
>   5.  **最后处理轨道190的请求5**（距离为10）

### SCAN

-   **Lift algorithm SCAN**: keep moving in the same direction until end is reached
    -   It continues in the current diraction, servicing all pending requests as it passes over them
    -   When it gets to the last cylinder, it **reverse direction** and services all the pedning requests
-   Evaluation:
    -   The upper limit on the "waiting time" is 2 * number of cylinders
    -   The **middle cylinder are favoured** if the disk is heavily used
-   Order: `11, 12, 16, 34, 36, 9, 1`
-   Length: 1 + 4 + 18 + 2 + 27 + 8  = 60

<img src="assets/Screenshot 2024-01-10 at 22.09.41.png" alt="Screenshot 2024-01-10 at 22.09.41" style="zoom:50%;" />

### Look-SCAN and N-step SCAN

-   **Look-SCAN** moves to the cylinder containing the **first/last request**
    -   Seeks are **cylinder by cylinder** and one cylinder contains multiple tracks
    -   The arm can stick to a cylinder
-   **N-step SCAN** only services N requests every single sweep

### C-SCAN

-   Once the outer/inner side of the disk is reached, the **requests at the other end of the disk have been waiting longest** 
-   SCAN can be improved by using a **circular scan** approach => C-SCAN
    -   The disk arm moves in **one direction** servicing requests until the **last cylinder** is reached 
    -   It **reverses direction** but does **not service requests** when returning 
    -   Once it gets back to the **first cylinder** it reverses direction and **services requests** 
    -   It is **fairer** and **equalises response times** across a disk

-   Order: `11, 12, 16, 34, 36, 1, 9`
-   Length: 1 + 4 + 18 + 2 + 35 + 8 = 68

### Disk Scheduling in Linux

-   In Linux, we can modify the disk scheduler by modifying the file: 
    -   `/sys/block/sda/queue/scheduler` 
-   We have got three policies:
    -   `noop`: this is FCFS 
    -   `deadline`: N-step-SCAN 
    -   `cfq`: Complete Fairness Queueing from Linux.

### Driver Caching

-   For most current drives, the time required to seek a new cylinder is more than the **rotational time** (remember pre-paging in this context!)
-   It makes sense, therefore, to **read more sectors than actually required**
    -   Read sectors during the rotational delay (i.e. that accidentally pass by) 
    -   Modern controllers read multiple sectors when asked for the data from one sector: track-at-a-time caching

## SSD Drives

-   **Solid State Drives (SSDs)**
    -   Have no moving parts, store data using **single level** (SLC), **multiple level** (MLC), **triple level** (TLC) electrical circuits, and suffer from **wear out** and **disturbance**
    -   Are organised into **banks**, **blocks, pages** and have some **volatile cache memory** (buffering, mapping tables) 
    -   Often use multiple **banks in parallel** to improve performance

<img src="assets/Screenshot 2024-01-10 at 22.19.59.png" alt="Screenshot 2024-01-10 at 22.19.59" style="zoom:50%;" />

<img src="assets/Screenshot 2024-01-10 at 22.19.47.png" alt="Screenshot 2024-01-10 at 22.19.47" style="zoom:50%;" />

**Reads/Writes**

-   The **Flash Translation Layer** that maps **logical blocks onto physical pages**
-   The following operations are supported:
    -   **Read**: uniformly fast random access to any **page** to any location (10s of microseconds) 
    -   **Erase**: entire **blocks** containing multiple pages (milliseconds magnitude) 
    -   **Program**: write a **page** (100s of microseconds, block must be erased first)

**Direct Mapping**

-   **Logical pages** (seen by the OS) are **directly mapped** on to **physical pages**
    -   Read the entire block for the given page 
    -   Erase the entire block
    -    Write the new page and remaining old pages back
-   Write performance is bad (write amplification) and wear is increased (some blocks are used more than others) ⇒ a different log structured approach is needed

<img src="assets/Screenshot 2024-01-10 at 22.24.37.png" alt="Screenshot 2024-01-10 at 22.24.37" style="zoom:50%;" />





