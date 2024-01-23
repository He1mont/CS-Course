# lec22: File System 3

>   **Overview**
>
>   -   File system implementations
>       -   Contiguous
>       -   Linked lists
>       -   File Allocation Table (FAT)
>       -   i-nodes (lookups)
>   -   Hard and soft links

## File System Implementation

**File Access**

-   Files will be composed of a number of **blocks**
-   Files are sequential or **random acccess**

### Contiguous Allocation

**Concepts**

-   **Contiguous file systems** are similar to **dynamic partitioning** in memory allocation:
    -   Each file is stored in a single group of **adjacent blocks** on the hard disk
-    Allocation of free space can be done using **first fit, best fit, next fit**, etc

<img src="assets/Screenshot 2024-01-11 at 16.37.55.png" alt="Screenshot 2024-01-11 at 16.37.55" style="zoom:50%;" />

**Advantages**

-   **Easy to implement**:
    -   only location of the first block and the length of the file must be stored in FCB
-   **Optimal read/writei performance**
    -   blocks are co-located in adjacent sectors (seek time is minimised)

**Disadvantages**

-   The **exact size** of a file is not always known beforehand
-   **Allocation algorithms** are needed to decide which free blocks to allocate
-   Deleting a file results in **external fragmentation** which requires de-fragmentation

-   Contiguous allocation used for DVDs

| Advantage         | Disadvantage                                |
| ----------------- | ------------------------------------------- |
| Easy to implement | Dont know the exact file size               |
| Minimal seek time | Delete a file causes external fragmentation |

### Linked Lists

**Concepts**

-   To avoid external fragmentation, files are stored in **separate blocks** (similar to paging) that are **linked to one another**
-   Only the **address of the first** is stored in the FCB 
-   Each block contains a data pointer to the next block (which takes up space)

<img src="assets/Screenshot 2024-01-11 at 16.45.44.png" alt="Screenshot 2024-01-11 at 16.45.44" style="zoom:50%;" />

**Advantages**

-   **Easy to maintain**: only the first block (address) has to be maintained in the directory entry 
-   Files can **grow dynamically**: new blocks/sectors are appended at the end 
-   Similar to paging, there is no **external fragmentation** 
-   **Sequential access** is straightforward, although **more seek operations** may be required (non-contiguous)

**Disadvantages**

-   **Random access** is very **slow** 
-   **Internal fragmentation**: the last half of the block is unused (on average)
    -   Internal fragmentation will reduce for smaller block sizes
-   May result in **random (slow) disk access**
    -   **Larger blocks** (containing multiple sectors) will improve speed (but increase internal fragmentation)
-   The data within a block is **no longer a power of 2** 
-   **Reduced reliability**: if one block is corrupt/lost, access to the rest of the file is lost

| Advantage                             | Disadvantage                                                |
| ------------------------------------- | ----------------------------------------------------------- |
| No external fragmentation             | Slow random access                                          |
| Only the first block has to be stored | Poor reliability: if one block fails, the rest list is lost |

### File Allocation Tables

**Key Concepts**

-   Store the linked-list **pointers** in a **separate index table**, called a **File Allocation Table** (FAT) (loaded in memory)

<img src="assets/Screenshot 2024-01-11 at 16.51.35.png" alt="Screenshot 2024-01-11 at 16.51.35" style="zoom:50%;" />

**Advantages**

-   **Block size remains power of 2**
    -   no space is lost in block due to the pointer
-   Index table can be **kept in memory** allowing fast random access

**Disadvantages**

-   The size of the FAT grows with the number of blocks size
-   **200 million entries** are required for **a 200GB disk** with **a 1KB block** size

| Advantage                            | Disadvantage                                     |
| ------------------------------------ | ------------------------------------------------ |
| No space is lost due to pointer      | Size of FAT grows with the number of block sizes |
| Index table allow fast random access |                                                  |

### i-nodes

**Concept**

-   Each file has a small data structure (on disk) called **i-node** (index-node) that contains its attributes and block pointers.
    -   In contrast to FAT, an i-node is **only loaded when the file is open** (stored in system wide open file table) 
    -   If every i-node consists of n bytes, and at most k files can be open at any point in time, at most n × k bytes of main memory are required

-   i-nodes are composed of **direct block pointers** (usually 10), **indirect block pointers**, or a combination thereof (e.g., similar to **multi-level page tables**)

<img src="assets/Screenshot 2024-01-11 at 22.50.23.png" alt="Screenshot 2024-01-11 at 22.50.23" style="zoom:50%;" />

-   Assuming a block **size of 1KB, and 32-bit** disk address space
-   With **only direct block pointers** the maximum file size is **10KB**
-   With a single indirect block the max file size is (10 + 256) * 1KB = 266KB
-   With a double indirect block 256 blocks containing 256 pointers each
    -   The max file size is (10 + 256 + 256^2) * 1KB = 65802KB
-   If we need files larger than this, we will need a triple indirect blocks for a max file size of
    (10 + 256 + 256^2 + 256^3) * 1KB

**Directories**

-   In UNIX/Linux/MacOS
    -   All **metadata** for a file is stored in an **i-node**
    -   **Directories** are very simple data structures composed of file name and a pointer to the i-node

<img src="assets/Screenshot 2024-01-11 at 22.56.30.png" alt="Screenshot 2024-01-11 at 22.56.30" style="zoom:50%;" />

### Comparison

**Contiguous vs. Linked List vs. i-node**

<img src="assets/Screenshot 2024-01-11 at 22.57.24.png" alt="Screenshot 2024-01-11 at 22.57.24" style="zoom:50%;" />

## i-nodes

**Lookups**

-   **Opening a file** requires the disk blocks to be located
    -   **Absolute file names** are located relative to the root directory 
    -   **Relative file names** are located based on the current working directory

-   Locate the root directory of the file system

    - Its i-node sits on a fixed location at the disk (the directory itself can sit anywhere) 

-   Locate the directory entries specified in the path:
    - Locate the i-node number for the first component (directory) of the path that is provided

    - Use the i-node number to index the i-node table and retrieve the directory file

    - Look up the remaining path directories by repeating the two steps above 

-   Once the file’s directories have been located, locate the file’s i-node and cache it into memory

### **Hard and Soft Links**

There are two approaches to **share a file**, e.g. between directory B and C, where C is the ’real’ owner:

-   **Hard links**: maintain two (or multiple) references to the same i-node in B and C 
    -   the i-node link reference counter will be set to 2 
-   **Symbolic links**:
    -   The owner maintains a reference to the i-node in, e.g., directory C 
    -   The “referencer” maintains a small file (that has its own i-node) that contains the location and name of the shared file in directory C

>   **An example**
>
>   **硬链接 `hard` 指向 `hello.txt`**
>
>   -   当您创建一个硬链接 `hard` 指向文件 `hello.txt` 时，`hard` 和 `hello.txt` 实际上指向文件系统中相同的inode。
>   -   如果您删除了 `hello.txt`，只是移除了 `hello.txt` 这个名称对inode的引用，而 `hard` 仍然保留着对同一个inode的引用。
>   -   由于实际文件数据（存储在inode中）并没有被删除，您可以通过硬链接 `hard` 访问原来 `hello.txt` 里的内容。文件数据会一直保留在磁盘上，直到所有指向该inode的链接都被删除。
>
>   **软链接 `soft` 指向 `hello.txt`**
>
>   -   当您创建一个软链接（或符号链接）`soft` 指向 `hello.txt` 时，`soft` 只是包含了一个指向 `hello.txt` 的路径信息。
>   -   如果 `hello.txt` 被删除，软链接 `soft` 指向的目标（即 `hello.txt` 的路径）就不存在了。
>   -   在这种情况下，您不能通过软链接 `soft` 访问原来 `hello.txt` 里的内容。尝试通过 `soft` 访问文件将导致错误，因为链接的目标文件已经不存在了。

**Hard link**

-   The fastest way of linking files

<img src="assets/Screenshot 2024-01-11 at 23.15.52.png" alt="Screenshot 2024-01-11 at 23.15.52" style="zoom:50%;" />

**Soft link**

-   Advantage:
    -   No problem with deleting the original file
    -   The linked file can be located on a different machine
-   Disadvantage:
    -   results in an **extra file lookup**
    -   requires an **extra inode** for the link file

### File System Examples: Unix vs. Windows

-   The Unix V7 File System:
    -   **Tree structured** file system with links 
    -   Directories contain **file names** and **i-node numbers** 
    -   i-nodes contain **user and system attributes** (e.g. count variable)
    -   One single, double, and triple **indirect blocks** can be used
-   More sophisticated File Systems were developed later (e.g. ext3/4) 
-   Windows:
    -   Up to XP used FAT-16 and FAT-32
    -   From XP moved to NTFS (64 bits) because of file size limitations
        -   NTFS uses File Tables, with bigger i-nodes that can also contain small files and directories
    -   More recently uses ReFS





