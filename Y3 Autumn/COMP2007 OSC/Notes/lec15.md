# lec15: Memory Management 2

>   **Overview**
>
>   -   Code **relocation** and **protection**
>   -   **Dynamic partitioning & segmentation** 
>   -   Managing **free/occupied** memory
>       -   Bitmap
>       -   Linked list

## Relocation and Protection

>   ```C
>   #include <stdio.h>
>   #include <unistd.h>
>   
>   int iVar = 0;
>   int main() {
>       while (iVar++ < 10) {
>           printf("Addr: %p; Val: %d\n", &iVar, iVar);
>           sleep(1);
>       }
>       return 0;
>   }
>   ```
>
>   -   If this programm is runned twice, different addresses may be displayed for Mac since it uses **Address Space Layout Randomization**

<img src="assets/Screenshot 2023-11-06 at 15.13.06.png" alt="Screenshot 2023-11-06 at 15.13.06" style="zoom: 33%;" />

### Definition

-   **Relocation**: One does not know **at compile time** which **partition/addresses** a process will occupy
    -   **Compiler** assumes the process that it will **run at 0** 
    -   **Mapping** takes place once it is known where in physical memory the process resides 
    -   **Relocation** must be used in any operating system that allows processes to run at changing locations in physical memory
-   **Protection**: once you can have **multiple processes** in memory at the same time, protection must be enforced

**Address Types**

-   A **logical address** is a memory address **seen by the process**
    -   Relative to the **start of the program** 
    -   Assigned by the **compiler** 
    -   **Independent** of the current location in physical memory
-   The **physical address** refers to an **actual location in main memory** 
-   The logical address space must be mapped onto the machine’s physical address space

### Approaches

-   **Static “relocation” at compile time**: 
    -   a process has to be located at the same location every single time (impractical) 

-   **Dynamic relocation at runtime**
    -   An **offset** is added to every logical address to account for its **physical location** in memory 
    -   Slows down the loading of a process 
    -   Does not account for **swapping**
-   Dynamic relocation **at runtime** with hardware support



**At Runtime: Base and Bound Registers**

-   Two special purpose registers are maintained in the **MMU**

    -   **base register**: stores the **start address** of the partition 
    -   **bound register**: holds the **size** of the partition

-   **At runtime**
    -   **physiclal address** is generated by adding **logical address** to **base register**
    -   **the resulting address** is compared with **bound register** added with **base register** 
    

## Dynamic Partitioning

>   **内部碎片**：一个进程只占8KB，但是OS给了10KB，中间的这2KB就是内部碎片
>
>   **外部碎片**：内存里的0-8KB给了进程1，10KB-20KB给了进程2，中间这2KB没法填上，就成了外部碎片

**Context**

-   **Fixed partitioning**
    -   results in **internal fragmentation**
    -   an exact match for the process may not always be available
    -   the partition may not be used completely
-   **Dynamic partitioning**
    -   a **variable number** of partitions
    -   a process is allocated the **exact amount** of contiguous memory
    -   reduces internal fragmentation

<img src="assets/Screenshot 2024-01-06 at 23.48.14.png" alt="Screenshot 2024-01-06 at 23.48.14" style="zoom:50%;" />

**Swapping**

-   Swapping moves processes between the **drive and main memory**
-   Reasons:
    -   Some processes only run **occasionally**
    -   The total amount of memory required **exceeds available memory**
    -   Memory requirements **change**
    -   We have **more processes than partitions**
-   Processes can be reloaded into a different memory location

<img src="assets/Screenshot 2024-01-06 at 23.57.37.png" alt="Screenshot 2024-01-06 at 23.57.37" style="zoom:50%;" />

**Shortcomings**

-   **External fragmentation**
    -   Swapping a process out of memory creates a *hole*
    -   A new process may not use the entile hole, leaving a small **unused block**
-   A new process may be too **large** for a given hole
-   The **overhead** of memory compaction to recover holes can be prohibitive and requires **dynamic relocation**

<img src="assets/Screenshot 2024-01-07 at 00.11.16.png" alt="Screenshot 2024-01-07 at 00.11.16" style="zoom:80%;" />

| Advantages                     | Disadvantages                                        |
| ------------------------------ | ---------------------------------------------------- |
| Reduces internal fragmentation | External fragmentation (swapping creates a **hole**) |
| Improve CPU utilisation        | Extra overhead for memory management                 |

## Segmentation

**Fine Grained Dynamic Partitioning**

-   **Dynamic partitioning** loads the **entire logical address space** into (**contiguous**) physical memory
    -   Uses a single **base and bounds pair** per process 
    -   Results in **external fragmentation** 
    -   **Unused space** between stack and heap takes up physical memory
-   **Segmentation** loads only the **relevant sections** into memory
    -   Splits the logical address space into **separate contiguous segments (code, data, heap, stack)** 
    -   Each segment is **loaded separately** in (contiguous) memory 
    -   Each segment has a **different base and bound pair** 
    -   The base and bound pair are stored in a the **segmentation table** 
    -   Part of the logical address is used as an **index** into the segmentation table

<img src="assets/Screenshot 2024-01-07 at 00.13.00.png" alt="Screenshot 2024-01-07 at 00.13.00" style="zoom:80%;" />

**Segmentation Table**

-   Segments can:
    -   Have protection bits associated with them
    -   Be shared between processes (e.g. code segments)
-   **MMU** must use the correct base/bound
-   OS remains responsible for finding a sufficiently **large contiguous range of physical memory** for each segment

## Managing Free Space

### Allocation Structures: Bitmaps

-   The **simplest** date structure
-   Memory is **split** into blocks of 4KB size
    -   `0`: memory block is free
    -   `1`: memory block is used
-   The size of bitmap depends on the size of the memory and the size of the **allocation unit**
-   A **trade-off** exists between the size of the bitmap and the size of blocks exists
    -   The size of bitmaps can become prohibitive for small blocks and may make searching the bitmap slower
    -   Larger blocks may increase internal fragmentation

-   Bitmaps are **rarely used** for this reason

### Allocation Structures: Linked List

-   A linked llist 
    -   consists of a number of entries (links)
    -   each link contains data items (start of memory block, size, free/allocated flag)
    -   each link contains a pointer to the next 

<img src="assets/Screenshot 2024-01-07 at 00.25.12.png" alt="Screenshot 2024-01-07 at 00.25.12" style="zoom:50%;" />


