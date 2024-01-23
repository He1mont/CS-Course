# lec18: Memory Management 5

>   **Overview**
>
>   -   **Page tables: multi-level page tables, inverted** and performance
>   -   Several **key decisions** have to be made when using virtual memory
>       -   When are page fetched
>       -   What pages are removed from memory

## Multi-level Page Tables

-   **Memory organisation** of multi-level page tables:
    -   The root page table is always maintained in memory 
    -    Page tables themselves are maintained in **virtual memory** due to their size
-   Assume that a **fetch** from main memory takes T nano seconds 
    -   With a **single page** table level, access is 2 × T （先访问页表，在访问实际的物理地址）
    -   With **two page** table levels, access is 3 × T ...
-   With two levels, every memory reference already becomes **3 times slower**:
    -   Assuming that the second level page table is **already in main memory** 
    -   Memory access already forms a **bottleneck** under normal circumstances

### **Translation Lookaside Buffers** (TLBs)

-   TLBs are usually located inside the **MMU**
    -   They **cache the most frequently** used page table entries
    -   They can be searched in parallel
-   The principle behind TLBs is similar to other types of caching in OS
-   Remember: **locality** states that processes make a large number of references to a small number of pages

<img src="assets/Screenshot 2024-01-09 at 23.04.21.png" alt="Screenshot 2024-01-09 at 23.04.21" style="zoom:50%;" />

-   Memory access with TLBs:

    -   Assume a single-level page table, 
    -   Assume 20ns associative TLB **lookup**, 100ns **memory access time** 
    -   **TLB Hit** => 20 + 100 = 120ns
    -   **TLB Miss** => 20 + 100 + 100 = 200ns

-   Performance evaluation of TLBs:

    -   For an 80% hit rate, the estimated access time is:

        120 * 0.8 + 220 * (1 - 0.8) = 140ns (40% slowdown)

    -   For a 98% hit rate, the estimated access time is:

        120 * 0.98 + 220 * (1 - 0.98) = 122ns (22% slowdown)

-   Note that **page tables** can be held in virtual memory => further slowdown due to page fault

## Inverted Page Table

**Definition**

-   A “normal” page table’s size is proportional to **the number of pages** in the virtual address space (prohibitive for modern machines) 
-   An “inverted” page table’s size is proportional to **the size of main memory**
    -   Contains one entry for every frame (i.e. not for every page) 
    -   Is indexed by **frame number/hash code** (not by page number) 
    -   When a process references a page, the OS must search the (entire) inverted page table for the corresponding entry (i.e. page and process id) ⇒ this could be too slow.
-   Solution: Use a **hash function** that transforms page number (n bits) into an index in the inverted page table (hash table)

**Inverted Page Table Entries**

-   PID: the process that owns this page
-   Page nnumber: logical address space
-   Protection bits: (Read/Write/Execution)
-   Link pointer: field pointer toward the next entry

**Address translation example**

<img src="assets/Screenshot 2024-01-09 at 23.56.53.png" alt="Screenshot 2024-01-09 at 23.56.53" style="zoom:50%;" />

**Evaluation**

-   Pros
    -   The OS maintains a single inverted page table for all processes
    -   **Saves space** (especially when virtual memory is much larger than physical memory)
-   Cons
    -   Logical-to-Physical address translation becomes harder/slower
    -   **Collisions** have to be handled and will slow down address translation
        -   Hash tables eliminates searching the whole inverted table
        -   TLBs help to improve performance
-   Commonly used on 64-bit machines **(e.g. WIndows 10)**

## Page Loading/Replacement

-   Two key decisions have to be made using virtual memory
    -   What pages are loaded and when => predictions can be made
    -   What pages are **removed** from memory and when => **page replacement algorithms**
-   Pages are shutlled between primary and secondary memory

### Demand Paging （按需分页）

-   **Demand paging** starts the process with **no pages in memory**
    -   The first instruction will immediately cause a **page fault** 
    -   More page faults will follow, but they will **stabilise over time** until moving to the next locality 
    -   <u>The set of pages that is **currently being used** is called its **working set** (⇔ resident set)</u>
-   Pages are only **loaded when needed**, i.e. following page faults

-   **Processing page faults**

    1.   Trap the OS

    -   Save the registers and state of the current process
    -   identify page fault
    -   validate page reference and frame location
    -   Interruption for Disk IO: queueing, seek, transfer

    2.   Context switching
    3.   Interruption after IO completion

    -   Save the registers and state of the current process
    -   identify interrupt
    -   Load frame into page table

    4.   Context switch to original process

### Pre-Paging

-   When the process is started, all pages expected to be used (i.e. the working set) could be **brought into memory at once**
    -   This can drastically reduce the page fault rate 
    -   Retrieving multiple (**contiguously stored**) pages **reduces transfer times** (seek time, rotational latency, etc.)
-   **Pre-paging** loads pages (as much as possible) **before page faults are generated** 
    (a similar mechanism is used when processes are **swapped out/in**)

|              | Demand Paging                    | Pre-Paging          |
| ------------ | -------------------------------- | ------------------- |
| Advantage    | Save the memory                  | Reduce page fault   |
| Disadvantage | more page fault in the beginning | Low CPU utilisation |

### Implementation Details

-   Avoiding **unnecessary pages** and **page replacement** is important

-   Note that here we do not consider **TLBs**

-   Variables:

    -   `ma` denote the memory access time (multiple times for multi-level page table)
    -   `p` denote the page fault rate
    -   `pft` denote the page fault time

-   The effective access time is then given by

$$
T_{a} = (1 - p) \times ma + pft \times p
$$

**Demand Paging**

-   For a single-level page table:
    -   ma = 100ns
    -   Two memory accesses required (200ns)
    -   pft = 8ms

$$
T_{a} = (1 - p) \times 200 + pft \times 8000000
$$

-   The effective access time is proportional to **page fault rate**

    -   Ideally, all pages would have to be loaded without demanding paging

