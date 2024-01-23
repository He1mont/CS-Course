# lec19: Memory Management 6

>   -   Page Replacement Algorithms
>       -   Optimal
>       -   FIFO (second-chance, clock)
>       -   NRU
>       -   LRU
>   -   Resident Set & Working Set
>   -   Paging Daemon
>   -   Thrashing

## Page Replacement

### **Concepts**

-   When the main memory is full, the OS must choose a page to remove when a **new one is loaded**
-   This choice is made by **page replacement algorithms** and takes into account
    -   When the page is **last used/expected** to be used again
    -   Whether the page has been **modifed**
-   Replacement choices have to be **made intelligently** to save time/avoid **thrashing**

**Algorithms**

-   Optimal page replacement
-   FIFO page replacement
    -   Second chance replacement
    -   Clock replacement
-   Not recently used (NRU)
-   Least recently used (LRU)

### Optimal Page Replacement

-   In an **ideal/optimal** world
    -   Each page is labeled with the number of instructions that will be executed and length of time before it is used again 
    -   <u>The page which is not going to be not referenced for the **longest time** is the **optimal one** to remove</u>
-   The **optimal approach** is not possible to implement
    -   It can be used for **post-execution analysis** => what would have been the minimum number of page faults
    -   It provide a **lowerbound** on the numebr of the page faults (used for comparison with other algorithms)

### First-in, First-Out (FIFO)

-   FIFO maintains **a linked list** and **new pages** are added at the end of the list 
-   The **oldest page** at the **head of the list** is evicted when a page fault occurs 
-   The **(dis-)advantages** of FIFO include:
    -   It is easy to understand/implement 
    -   It **performs poorly** ⇒ heavily used pages are just as likely to be evicted as a lightly used pages

<img src="assets/Screenshot 2024-01-10 at 02.10.00.png" alt="Screenshot 2024-01-10 at 02.10.00" style="zoom:50%;" />

**Second-Chance FIFO**

-   Second-Chance FIFO
    -   If a page at the front of the list has not been referenced, it is evicted
    -   If the **reference bit** is set, the page is placed at the end of list and its reference bit reset
-   Second chance FIFO **works better** than FIFO but is **costly to implement** (list changes constantly) and **can degrade to FIFO** if all pages were initially referenced

>   **Example** 
>
>   假设我们有一个容量为3个页面的内存，并且页面访问顺序如下：1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5。
>
>   1.  初始时，内存为空。依次将1, 2, 3加载到内存。
>   2.  接下来访问页面4，需要置换一个页面。按FIFO，页面1应被置换，但在Second-Chance算法中，如果页面1最近被访问（即访问位被设置），则给它一个“第二次机会”，暂时不置换它，而将它放到队列末尾，并检查下一个页面（此处为页面2）。
>   3.  页面2和页面3也被访问过，因此也都获得“第二次机会”并移到队列末尾。
>   4.  然后再次到达页面1，这次页面1没有被最近使用（假设其访问位已被清除），所以它被置换出去，页面4被加载到内存。

**The Clock Replacement Algorithm**

-   Second-chance FIFO can be improved by maintaining a **circular list**s
    -   A **pointer** points to the last page "visited"
    -   Slow for long lists
-   The time spent on maintaining the list is **reduced**

<img src="assets/Screenshot 2024-01-10 at 02.41.59.png" alt="Screenshot 2024-01-10 at 02.41.59" style="zoom:33%;" />

### Not Recently Used (NRU)

-   **Referenced** and **modified** bits are kept in the page table
    -   Referenced bits are set to 0 at the start, and **reset periodically**
-   Four different page types
    -   class 0: not referenced and not modified
    -   class 1: not referenced and modified
    -   class 2: referenced and not modified
    -   class 3: referenced and modified
-   Page table entries are inspected upon every **page fault**
-   Implementation
    1.   Find a page from class 0 to be removed
    2.   If step 1 fails, scan again looking for class 1 and **set the reference bit to `0`** for each page visited
    3.   If step 2 fails, start again from step 1 with class 2 and 3
-   The NRU algorithm provides good performance and is easy to understand and implement

### Least-Recently-Used

-   Least recently used evicts the page **that has not been used the longest**
    -   The OS **keeps track** of when a page was **last used** 
    -   Every page table entry contains **a field for the counter** 
    -   **Costly implementation** since it requires **a list of pages** sorted in the order in which they have been used

-   The algorithm can be **implemented in hardware** using a **counter** that is incremented after each instruction

<img src="assets/Screenshot 2024-01-10 at 03.21.14.png" alt="Screenshot 2024-01-10 at 03.21.14" style="zoom:50%;" />

### Summary

-   **Optimal page replacement**: optimal but not practical 
-   **FIFO page replacement**: poor performance but easy to implement
    -   **Second chance** replacement: improved performance but poor implementation 
    -   **Clock replacement**: improved implementation but can still be slow
-   **Not recently used (NRU)**: easy to understand, moderately efficient (approximation of LRU) 
-   **Least recently used (LRU)**: close to optimal but more difficult to implement

## Resident Set & Working Set

### Resident Set

**Size of the Resident Set**

-   How many pages should be allocated to individual processes:
    -   **Small resident sets** enable to store **more processes** in memory ⇒ improved CPU utilisation 
    -   **Small resident sets** may result in more **page faults** 
    -   **Large resident sets** may no longer reduce the page fault rate (diminishing returns)
-   A **trade-off** exists between the **sizes of the resident sets** and **system utilisation**

-   Resident set sizes may be **fixed** or **variable**
-   For **variable sized** resident sets, **replacement policies** can be:
    -   Local: a page of the same process is replaced
    -   Global: a page can be taken away from a different process
-   Variable sized sets require **careful evaluation of their size** when a **local scope** is used (often based on the **working set** or the **page fault frequency**)

>   ### **Example**
>
>   假设有一个简单的操作系统，它管理着一个有16个页面的物理内存，现在运行着三个进程：进程A、进程B和进程C。
>
>   1.  **启动时**：初始状态下，所有页面都是空的。
>   2.  **进程A启动**：进程A开始运行，并且需要4个页面。操作系统分配了页面1, 2, 3, 4给进程A。此时，进程A的Resident Set就是{1, 2, 3, 4}。
>   3.  **进程B启动**：随后，进程B请求运行，它需要3个页面。操作系统分配了页面5, 6, 7给进程B。进程B的Resident Set变成了{5, 6, 7}。
>   4.  **进程C启动**：最后，进程C也请求运行，需要5个页面。操作系统分配了页面8, 9, 10, 11, 12给进程C。进程C的Resident Set是{8, 9, 10, 11, 12}。
>   5.  **页面访问**：假设进程A现在访问页面2，这个页面已经在它的Resident Set中，所以可以直接访问，没有缺页中断。
>   6.  **内存压力**：如果物理内存有压力，操作系统可能决定缩小某个进程的Resident Set。假设操作系统决定从进程A的Resident Set中移除页面4，现在进程A的Resident Set变成了{1, 2, 3}。
>
>   <img src="assets/Screenshot 2024-01-10 at 03.21.14.png" alt="Screenshot 2024-01-10 at 03.21.14" style="zoom:50%;" />
>
>   -   最上面那一行就是Working set
>   -   表格中的每一个竖列都是resident set

**Local vs. Global Replacement**

-   **Global replacement policies** can select frames from the **entire set**, i.e., <u>they can be “taken” from other processes</u>
    -   Frames are **allocated dynamically** to processes 
    -   Processes cannot control their own page fault frequency, i.e., the **PFF** of one process is **influenced by other processes**
    -   May affect process's completeness
-   **Local replacement policies** can only select frames that are allocated to the current process
    -   Every process has a **fixed fraction of memory** 
    -   The locally “**oldest page**” is not necessarily the globally “oldest page”
-   Windows uses a **variable approach** with **local replacement**
-   Page replacements algorithms explained before can use both policies.

### Working Sets

**Defining and Monitoring Working Sets**

-   The **resident set** comprises the set of pages of the process **that are in memory** 
-   The **working set** `W(t, k)` comprises the set referenced pages in the last `t` (= working set window) **virtual time units** for the process 
-   `k` can be defined as “**memory references**” or as “actual process time”
    -   The set of most recently used pages 
    -   The set of pages used within a pre-specified time interval
-   The **working set size** can be used as a guide for the number frames that should be allocated to a process
-   The working set is a function of time `t`:
    -   Processes move between **localities**, hence the pages that are included in the working set **change over time**
    -   Stable intervals alternate with intervals of rapid change
-   |W(t, k)| is a variable in time: 1 ≤ |W(t, k)| ≤ min(k, N)
    -   where N is the total number of pages of the process

>### An Example
>
><img src="assets/Screenshot 2024-01-10 at 05.42.49.png" alt="Screenshot 2024-01-10 at 05.42.49" style="zoom:50%;" />
>
>-   If k = 3:
>    -   At `t1`, W(t1, 3) = {4, 5, 6}
>    -   At `t2`, W(t2, 3) = {4, 7}
>-   If k = 5:
>    -   At `t1`, W(t1, 5) = {2, 3, 4, 5, 6}
>    -   At `t2`, W(t2, 5) = {2, 4, 7}

**Monitoring Working Sets**

-   Choosing the right value for k is paramount
    -   Too small: inaccurate, pages are missing
    -   Too large: too many unused pages present
    -   Infinity: all pages of the process are in the working set
-   Working sets can be used to guide the **size of the resident sets**
    -   Monitor the working set
    -   Remove pages from the resident set that are not in the working set
-   The working set is costly to maintain => **page fault frequency (PFF)** can be used as an approximation
    -   If the PFF is increased => **increase k**
    -   If the PFF is reduced => **decrease k**

## Paging Daemon

-   It is more efficient to proactively keep a number of **free pages** for **future page faults**
    -   If not, we may have to **find a page** to evict and we write it to the drive first when a page fault occurs
-   Many systems have a background process called a **paging daemon**
    -   This process runs at **periodic intervals**
    -   It inspect the state of the frames and, if too few frames are free, it selects pages to evict (using page replacement algs)
-   Paging daemons can be combined with **buffering** (free and modified lists) => write the modified pages **but keep them in main memory** when possible

>   ### Example
>
>   **初始状态：**
>
>   -   物理内存总共有100个页面。
>   -   系统正在运行着三个进程：进程A、进程B和进程C。
>   -   每个进程都有一组它们当前正在使用的页面，也就是它们的工作集。
>   -   物理内存已经很满了，大约90%的页面都在使用中。
>
>   **Paging Daemon的操作流程：**
>
>   1.  **监控内存使用**：
>       -   Paging Daemon周期性地检查内存使用情况。
>       -   它发现物理内存中有90个页面正在被使用，只剩下10个空闲页面。
>   2.  **分析页面活动**：
>       -   Daemon查看每个页面的最后访问时间。
>       -   它发现进程A的某些页面在过去的几分钟内没有被访问过。
>   3.  **决定置换策略**：
>       -   基于LRU算法，Paging Daemon选择了进程A中最久未被访问的页面进行置换。
>   4.  **执行页面置换**：
>       -   假设选中的页面为A1、A2和A3。
>       -   Paging Daemon将这些页面写入磁盘上的交换空间。
>       -   页面的状态在页表中被更新为“不在物理内存中”。
>   5.  **释放物理内存页面**：
>       -   页面A1、A2和A3在物理内存中的位置被标记为可用。
>   6.  **处理缺页中断**：
>       -   此后，如果进程A尝试访问页面A1、A2或A3，将发生缺页中断。
>       -   Paging Daemon响应中断，将页面从磁盘交换空间加载回物理内存。
>       -   如果此时物理内存没有足够空间，Paging Daemon将根据LRU算法再次选择其他页面进行置换。

## Thrashing

**Definition**

-   Assuem **all available pages are in active use** and a new page needs to be loaded:
    -   The page that will be **evicted** will have to be **reloaded soon** afterwards
-   **Thrashing** occurs **when pages are swapped out and loaded again immediately**

>   ### Example
>
>   **背景设定：**
>
>   假设一个操作系统管理着一个有限的物理内存，共有100个页面，以及一个相对较大的磁盘交换空间。系统同时运行了五个进程，每个进程为了正常运行至少需要40个页面。
>
>   **详细的发展过程：**
>
>   1.  **进程启动**：五个进程（进程A，B，C，D，E）启动，每个进程都试图加载它们需要的40个页面到物理内存中。
>   2.  **内存分配**：最初，操作系统尝试满足每个进程的需求。由于物理内存限制（100个页面），不是所有进程的需求都能被完全满足。
>   3.  **首轮页面置换**：
>       -   进程A加载了40个页面，剩下的内存不足以满足其他进程的完整需求。
>       -   当进程B，C，D和E尝试运行时，它们无法找到足够的空闲页面。因此，操作系统开始从磁盘交换空间调入所需的页面。
>       -   为了给进程B腾出空间，操作系统从进程A的页面集中挑选页面置换到磁盘。
>   4.  **频繁置换导致Thrashing**：
>       -   当进程B，C，D和E开始运行并请求访问它们的页面时，发现这些页面不在物理内存中，引发缺页中断。
>       -   操作系统再次尝试置换其他进程的页面，以便将缺失的页面从磁盘交换空间调入。
>       -   由于每个进程都不能保持其工作集完整地驻留在内存中，系统陷入了频繁的页面置换循环。
>   5.  **系统性能急剧下降**：
>       -   大量的CPU时间被用于处理缺页中断和页面置换，而不是执行进程的实际计算任务。
>       -   每个进程的执行速度急剧下降，因为它们经常在等待所需页面被加载。
>       -   系统吞吐量降低，用户体验到显著的性能下降。

-   CPU utilisation is too low 
    => schedular increases degree of multi-programming
    => Frames are allocated to new processes and taken away from existing processes
    => I/O requests are queued up as a consequence of page faults
-   CPU **utilisation drops further** => scheduler increases degree of multi-programming

**Causes and Solutions**

-   **Causes**
    -   The degree of multi-programming is too high
        i.e. the sum of all working set sizes exceeds the available frames
-   **Solution**
    -   Use good **page replacement** policies
    -   Reduce the degree of multi-programming
    -   Add more memory
-   The **PFF** can be used to detect that a system is thrashing
    -   higher PFF => more frequent page fault => more page replacement => thrashing







