# lec24: File System 5

>   **Overview**
>
>   -   File system recovery
>       -   Scandisk
>       -   FSCK
>   -   Defragmenting Disks
>   -   File systems in Linux

## File System Consistency

-   **Journaling** heavily reduces the probability of having inconsistencies in a file system. In case of crash, the log stores what operations were not run. 
-   However, it can still be possible to get some inconsistencies (e.g. data blocks weren’t flushed to the drive, typical case on USB drives!).
-   This can be problematic, in particular for structural blocks such as i-nodes, directories, and free lists 
-   **System utilities** are available to restore file systems, e.g.: Scandisk, FSCK
-   There are two main consistency checks: **block and directory.**

### Checking Block Consistency

-   Block consistency checks whether blocks are **assigned/used** the correct way
-   Block consistency is checked by building **two tables**:
    -   Table one counts how often a **block is present in a file** (based on the i-nodes) 
    -   Table two counts how often a **block is present in the free list**
-   A consistent file system has a 1 in **either** of the tables for each block 
-   Typically, this is a **very slow process**, taking even hours (and running with the partition unmounted)

-   An example
    -   a: Consistent
    -   b: Missing block
    -   c: Duplicate block in free list
    -   d: Duplicate data

<img src="assets/Screenshot 2024-01-12 at 02.49.00.png" alt="Screenshot 2024-01-12 at 02.49.00" style="zoom:50%;" />

### **Restoring Block Consistency**

-   **Missing block**: 
    -   it does not exist in any of the tables => add to the free list
-   **Double counted block in the free list**: 
    -   re-built the free list
-   A block is present in **two or more files**
    -   Removing one file results in the adding the block to the free list 
    -   Removing both files will result in a double entry in the free list 
    -   Solution: use new free block and copy the content (the file is still likely to be damaged)

**FSCK Algorithm**

1.   Iterate through all the i-nodes

     - retrieve the blocks


     - increment the counters

2.   Iterate through the free list

     - increment counters for free blocks

>   **An example**
>
>   假设你在使用Linux操作系统的计算机上工作，突然发生电源故障导致计算机意外关闭。当你重新启动计算机时，Linux系统自动运行`fsck`来检查根文件系统的一致性。
>
>   **fsck的具体步骤和动作：**
>
>   1.  **启动检查**：
>       -   你的计算机启动时，`fsck`自动启动来检查文件系统。
>       -   假设根文件系统是ext4格式。
>   2.  **第一阶段：检查inode**：
>       -   `fsck`开始检查文件系统的每个inode。它发现了一个问题：inode #24576应该是一个空闲inode，但实际上被错误地标记为已使用。
>       -   `fsck`将此inode标记为未使用并更新inode表。
>   3.  **第二阶段：检查目录的一致性**：
>       -   在检查目录结构时，`fsck`发现“/home/user/docs”目录中的一个文件条目指向了不存在的inode #33792。
>       -   `fsck`删除这个无效的文件条目，防止出现“死链接”。
>   4.  **第三阶段：检查数据块的一致性**：
>       -   `fsck`检查数据块的分配情况。它发现了一些数据块既没被任何inode引用，也没有被标记为空闲。
>       -   `fsck`将这些数据块重新标记为未使用，释放这部分空间。
>   5.  **第四阶段：检查inode引用计数**：
>       -   `fsck`检测到一个文件的引用计数（指示有多少目录条目指向这个文件）不正确。
>       -   假设文件“/home/user/note.txt”的引用计数比实际引用次数多1。`fsck`修正这个计数。
>   6.  **第五阶段：修复**：
>       -   `fsck`完成所有检查后，进行必要的修复操作，确保文件系统的一致性。
>       -   系统记录了`fsck`的修改，并在修复后正常启动

### Restoring I-node Consistency

-   I-node counter is **higher** than the number of directories containing the file
    -   Removing the file will reduce the i-node counter by 1 
    -   Since the counter will remain larger than 1, the i-node / disk space will not be released for future use
-   I-node counter is **less** than the number of directories containing the file
    -   Removing the file will (eventually) set the i-node counter to 0 whilst the file is still referenced 
    -   The file / i-node will be released, even though the file was still in use

## File System Defragmentation

-   At the beginning, all free disk space is in a single contiguous unit.
-   After a while, creating and removing files, a disk may end up badly fragmented (holes and file all over the place).
-   **Defrag utilities** make file blocks contiguous (very slow operation), and free space in **one or more large contiguous region**s on the disk. 
-   Windows users should run this regularly, except on SSDs.
-   **Linux (ext2/3) suffers less from fragmentation.**
-   Defragmentating SSD is counter-productive (No gain in performance and SSDs wear out).

## File Systems

-   **Minix file system**: the maximum file size was 64MB and file names were limited to 14 characters 
-   The “**extended file system**” (extfs): file names were 255 characters and the maximum file size was 2 GB 
-   The “**ext2**” file system: larger files, larger file names, better performance 
    -   Most popular

-   The “**ext3-4**” file system: journaling etc.

**Standard Unix File System vs. Ext2 File System**

<img src="assets/Screenshot 2024-01-12 at 03.23.51.png" alt="Screenshot 2024-01-12 at 03.23.51" style="zoom:50%;" />

<img src="assets/Screenshot 2024-01-12 at 03.24.29.png" alt="Screenshot 2024-01-12 at 03.24.29" style="zoom:50%;" />

-   **Directory Entries**
    -   The **superblock** contains file system information (e.g. the number of i-nodes, disk blocks) 
    -   The **group descriptor** contains bitmap locations, the number of free blocks, i-nodes and directories 
    -   A **data block bitmap and i-node bitmap**, used to keep track of free disk blocks and i-nodes (Unix uses lists) 
    -   A **table of i-nodes** containing file and disk block information 
    -   **Data blocks** containing file and directory blocks

