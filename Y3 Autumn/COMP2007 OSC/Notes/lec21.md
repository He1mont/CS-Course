# lec21: File System 2

>   **Overview**
>
>   -   Disk Layout
>   -   File System
>   -   Files
>   -   Directories
>   -   Free Space Management

## Disk Layout

**Boot Sector and Partitions**

-   **Drive** is a **collection of sectors** (0 - N) 
-   **Boot record** is located at start of the drive:
    -   Used to boot the computer (BIOS reads and executes boot sector) 
    -   Contains **partition table** at its end with **active partition** 
    -   One partition is listed as **active** containing a **boot block** to **load the operating system**
-   The drive is commonly split into **multiple partitions**: 
    -   A different file/operating system may exist on each partition (occasionally none)

<img src="assets/Screenshot 2024-01-11 at 01.20.17.png" alt="Screenshot 2024-01-11 at 01.20.17" style="zoom:50%;" />

>   **An example**
>
>   假设你的硬盘有两个分区：一个安装了Windows系统，另一个安装了Linux系统。Boot Record中的分区表将包含这两个分区的信息。当你开机时，Boot Record中的代码将被执行，它通过查看分区表来确定哪个分区是活动分区（即包含需要启动的操作系统）。如果活动分区设置为Windows分区，Boot Record的代码将引导电脑加载Windows操作系统；如果设置为Linux分区，则加载Linux操作系统。

**Partition Layout**

-   **Boot block** containing code to **boot the operating system** (for every partition irrespective containing an OS) 
-   **Super block** containing **stats about the partition** (partition size, number of FCBs, location of free list, . . . ) 
-   **Free space management** contains data structures to indicate free FCBs or data blocks 
-   **Meta data** or **File Control Blocks** (e.g. i-nodes) 
-   **Data blocks**, including the root directory (the top of the file-system tree)

<img src="assets/Screenshot 2024-01-11 at 01.20.00.png" alt="Screenshot 2024-01-11 at 01.20.00" style="zoom:50%;" />

## File Systems

File systems allow data to be stored, located, and retrieved easily and efficiently.

-   **File system abstraction**: the logical file system is mapped onto the physical one (abstraction from the physical level) 
-   **Abstraction from the device**: uniform view of very different underlying storage mechanism

**OS Abstractions**

-   A **user view** that defines a file system in terms of the abstractions (system calls) that the operating system provides (files and directories)
-   An **implementation view** that defines the file system in terms of its **low level implementation**

**Logical Layers**

-   Shared layers:
    -   **I/O control** interacts with the **device controller**/registers (device drivers, interrupt handlers) 
    -   **Basic file system** instructs device drivers “blocks” , **schedules** I/O, and manages **buffers** and **caches** for (meta-)data
-   File system specific layers:
    -   **File organisation** models **logical blocks** for files and free space 
    -   **Logical file system** manages **file control blocks**, directory structures, and **protection**
-   **Application programs** define the structure of the files

<img src="assets/Screenshot 2024-01-11 at 01.28.39.png" alt="Screenshot 2024-01-11 at 01.28.39" style="zoom:50%;" />

## Files

**Types**

-   Both Windows and Unix (including OS X) have **regular files** and **directories**:
    -   **Regular files** contain user data in **ASCII** or **binary** (well defined) format 
    -   **Directories** group files together (but are files on an implementation level)
-   Unix also has **character** and **block special files**:
    -   **Character special files** are used to model serial I/O devices (e.g. keyboards, printers) 
    -   **Block special files** are used to model, e.g. hard drives
-   Files are **sequential, random (direct) access, indexed access**

**File Control Blocks**

-   **File control blocks** (FCBs) are **kernel** data structures
    -   Allowing user applications to access them directly could **compromise their integrity**
    -   **System calls** enable a **user application** to ask the operating system to carry out an action on its behalf (in kernel mode)
-   FCBs are kept in the **per process** and system wide open file table (array) indexed using a process specific file handle

<img src="assets/Screenshot 2024-01-11 at 01.41.46.png" alt="Screenshot 2024-01-11 at 01.41.46" style="zoom:50%;" />

**File Tables**

-   The **per process file table** contains **process specific information**, e.g.:
    -   **All files** currently open to the process 
    -   Read/write/current **pointers** 
    -   A **reference** to the relevant entry in the system wide file table
-   The **system wide file table** contains **general information**, e.g.:
    -   One entry per open file 
    -   Location on disk 
    -   Access times 
    -   **Reference count**



<img src="assets/Screenshot 2024-01-11 at 01.42.00.png" alt="Screenshot 2024-01-11 at 01.42.00" style="zoom:50%;" />

**System Calls**

-   **System calls** for file manipulation include: `create()`, `open()`, `close()`, `read()`, `write()`
-   The `open()` system call:
    -   Maps the **logical name** onto the **low level name** identifying the **file control block** 
    -   **Retrieves** the “FCB” (from the drive) 
    -   Adds it to the process/system open file table (increments the reference count) 
    -   Returns a process specific file handle (index into the table)
-   The `close()` system call:
    -   Decrements the reference count
    -   **Synchronise FCB** with disk 
    -   **Removes FCB** from process/system file tables (when reference count = 0)

## Directories

**Implementations**

-   **Directories are special files** that group files together and of which the structure is defined by the file system
    -   A **bit is set** to indicate that they are directories 
    -   They map human readable “logical” names onto unique identifiers for file control blocks that detail physical locations and file attributes
-   **Two approaches** exist:
    -   All attributes are **stored in the directory file** (e.g. file name, disk address – Windows) 
    -   **A pointer** to the data structure (e.g. i-node) that contains the file attributes (Unix)

<img src="assets/Screenshot 2024-01-11 at 01.53.20.png" alt="Screenshot 2024-01-11 at 01.53.20" style="zoom:40%;" />

<img src="assets/Screenshot 2024-01-11 at 01.58.35.png" alt="Screenshot 2024-01-11 at 01.58.35" style="zoom:50%;" />

-   Directories enable to build **directed acyclic graphs**
    -   Generalisation of a tree structure

<img src="assets/Screenshot 2024-01-11 at 01.59.53.png" alt="Screenshot 2024-01-11 at 01.59.53" style="zoom:40%;" />

**System Calls**

-   Similar to files, directories are manipulated using **system calls** 
    -   `create/delete`: a new directory is created/deleted 
    -   `opendir, closedir`: add/free directory to/from internal tables
    -   `readdir`, return the next entry in the directory file 
    -   Others: `rename, link, unlink, list, update`

-   Retrieving a file comes down to **searching a directory file** as fast as possible 
-   A **simple random order of directory** entries might be insufficient (search time is linear as a function of the number of entries) 
-   **Indexes** or **hash tables** can be used for large directories

## Free Space Management

-   Similar to memory management, **bitmaps** and **linked lists** can be used for free space management 
-   **Bitmaps** represent each block by a single bit in a map
    -   The **size of the bitmap** grows with the size of the disk but is constant for a given disk 
    -   Bitmaps take **comparably less space** than linked lists

-   **Linked List** of list free groupings
    -   Use **free blocks** to hold the **locations of the free blocks** (hence, they are no longer free) 
    -   The size of the list **grows with the size of the disk** and **shrinks with the size of the blocks**
        -   E.g., with a 1KB block a 32-bit/4 byte disk block number, each block will hold 255 free blocks (one for the pointer to the next block) 
        -   Since the free list shrinks when the disk becomes full, this is not wasted space
    -   **Blocks are linked together**, i.e., multiple blocks list the free blocks
-   Linked lists can be modified by **keeping track of the number of consecutive free blocks** for each entry (known as Counting)

**Comparison**

-   **Bitmaps**:
    -   Require extra space. 
        e.g: If block size = 2^12 bytes (4KB) and disk size = 2^30 bytes (1 GB) 
        => bitmap size: 2^30 / 2^12 = 2^18 (32KB) 
    -   Keeping it in main memory is possible only for small disks.
-   **Linked lists:**
    -   **Grows** with the number of empty blocks 
    -   **No waste** of disk space (uses empty space) 
    -   We only need to keep in memory **one block of pointers** (load a new block when need).

<img src="assets/Screenshot 2024-01-11 at 02.08.40.png" alt="Screenshot 2024-01-11 at 02.08.40" style="zoom:50%;" />
