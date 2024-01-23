# lec17: Memory Management 4

>   **Overview**
>
>   -   **Address translation** implementation
>   -   Principles behind **virtual memory**
>   -   Complex/large **page tables**

## Address translation implementation

**Memory is a linear array of bytes**

-   N address lines are used to specify $2^N$ addresses
    -   **e.g.: $2^{16}$ for a 16 bit machine**

-   If each memory cell is a byte, we can address up to 64KB

-   The **left most** n bits represent the **page number**
    -   e.g. 4 bits for the page number ⇒ 16 pages 
-   The **right most** m bits represent the **offset** within the page
    -   e.g. 12 bits for the offset ⇒ 4KB pages



**Relocation: Address Translation**

-   Steps
    -   **Extract the page number** from logical address
    -   Use page number as an index to retrieve the frame number in the **page table**
    -   Add the logical offset within the page to the start of the physical frame
-   **Hardware implementation** of address translation
    -   The CPU's MMU intercepts logical addresses
    -   MMU uses a page table as above
    -   The **resulting physical address** is put on the **memory bus**

## Virtual Memory

### Principle of Locality

>   **局部性原则**：程序在执行过程中倾向于重复访问近期访问过的数据（时间局部性）以及邻近的数据（空间局部性）
>
>   -   **时间局部性**
>
>   ```C
>   for (int i = 0; i < 100; i++) {
>       array[0] += i;
>   }
>   ```
>
>   -   **空间局部性**
>
>   ```C
>   for (int i = 0; i < 100; i++) {
>       array[i] = i;
>   }
>   ```

-   **Benefits of paging**
    -   Principle of locality: **code and data references** are usually **clustered**
    
    -   Code execution and data manipulation is usually restricted to a **small subset of pages** at a given point in time
    
-   **Not all pages** have to be loaded in memory at the same time => **virtual memory**
    -   Loading all program/data pages into memory is **wasteful**
    -   Desired blocks could be **loaded on demand**
    
-   **An example**

<img src="assets/Screenshot 2024-01-09 at 03.39.39.png" alt="Screenshot 2024-01-09 at 03.39.39" style="zoom:50%;" />

### Page Faults

-   The resident set refers to the pages that are loaded in main memory
-   A page fault is generated if the processor accesses a page that is **not in memory**
    -   A page fault results in an interrupt (process enters **blocked state**) 
    -   An **I/O operation** is started to bring the missing page into main memory 
    -   A **context switch** (may) take place 
    -   An **interrupt signals** that the I/O operation is complete (process enters **ready state**)



**Processing Page Faults**

1.   Trap operating systems
     -   Save registers/process state
     -   Analyse interrupt (i.e. identify page fault)
     -   Validate page reference, determine frame location
     -   Issue disk I/O: queueing, seek, latency, transfer
2.   Context switch (optional)
3.   Interrupt for I/O completion
     -   Store process state/registers
     -   Analyse interrupt from disk
     -   Update page table (page now in memory)
     -   Wait for original process to be scheduled
4.   Context switch to original process



**Benefits of Virtual memory**

-   Virtual memory improves CPU utilisation
    -   Individual processes take up less memory (only partially loaded)
    -   **More processes** in memory
    -   More **efficient use of memory** (less internal fragmentation, no external fragmentation)
-   The logical address space can be larger than physical address space
    -   N bit machine => $2^N$ logical address

## Complex Page Table

**Contents of a Page Entry**

-   The **present/absent bit** is set if the page/frame is in memory
-   The **modified bit** is set if the page/frame has been modified
    -   Only modified pages have to be written back to disk when evicted
-   The **reference bit** is set if the page is in use
-   **Proctection and sharing bits**: read, write, execute ...

<img src="assets/Screenshot 2024-01-09 at 15.14.17.png" alt="Screenshot 2024-01-09 at 15.14.17" style="zoom:50%;" />

**Multi-level Page Tables**

-   **Size**: how do we deal with the **increasing size** of page tables
    -   Their size prevents them from being **stored in registers**
    -   They have to be stored in (virtual) main memory
        -   **Multi-level** page tables
        -   **Inverted page tables**
-   **Speed**: address translation happens at every memory reference, it has to be fast
    -   Accessing main memory results in memory stalls

-   **Solution**: **Tree-like** structures to hold page tables
-   The **page number** is divided into:
    -   An index to a page table of second level
    -   A page within a second level page table
-   The page table is **not kept entirely in memory**

-   **Memory organisation** of multi-level page tables

    -   The **root page table** is always maintained in memory
    -   Page tables themselves are maintained in virtual memory due to their size




