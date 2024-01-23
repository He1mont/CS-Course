# lec23: File System 4

>   **Overview**
>
>   -   File system **paradigms**:
>       -   Logs: store everything as close as possible 
>       -   Journaling: apply the transaction principle
>   -   VFS: apply good software design (polymorphism)

## Log Structured File System

**Context**

-   Consider the creation of a **new file** on a Unix system:

    -   Allocate, initialise and write the i-node for the file

        i-nodes are usually located at the start of the disk

    -   **Update and write the directory** entry for the file 

    -   **Write the data** to the disk

-   The corresponding blocks are not necessarily in **adjacent locations**

-   Also in linked lists/FAT file systems blocks can be **distributed across the disk**

-   Device characteristics:
    -   Due to seek and rotational delays, **hard disks are slow** 
    -   **SSDs** suffer from **write amplification** (block must be erased), **write disturbance**, and **wear out**

>   **An example of Write Amplification**
>
>   SSD（固态硬盘）中的“写入放大效应”（Write Amplification）是指实际写入到SSD芯片上的数据量大于原始数据量的现象。这主要是因为SSD的底层存储和管理机制导致的。
>
>   写入放大效应的原因：
>
>   1.  **固定大小的擦除块**：SSD中的数据是以固定大小的擦除块（Erase Blocks）进行存储的。当需要修改存储在一个擦除块中的数据时，整个块必须先被擦除，然后重新写入包含新数据的整个块。
>   2.  **数据移动和重写**：如果只是修改了块中的一小部分数据，整个块的其他数据也需要被移动到另一个位置并重写。这导致实际写入的数据量大于原始修改的数据量。

-   A log **structured file system** copes better with inherent **device characteristics**:
    -   Aims to improve speed of a file system on a traditional hard disk by **minimising head movements** and **rotational delays**
    -   Reduces **write amplification**, **disturbance** and **wear out**

**Concept**

-   A **log** is a data structure that is **written to at the end** and treated as a **circular buffer** 
-   Log structured file systems **buffer read and write operations** (i-nodes, data, etc.) in memory 
    -   Enables to write “larger volumes” 
-   Once the buffer is full it is “flushed” to the disk and written as one contiguous segment at the end of “a log”
    -   **i-nodes and data** are all written to the same “segment” 
    -   Finding i-nodes (traditionally located at the start of the partition) becomes more **difficult**
-   An **i-node** map is maintained in memory to quickly find the address of i-nodes on the disk

<img src="assets/Screenshot 2024-01-12 at 00.19.09.png" alt="Screenshot 2024-01-12 at 00.19.09" style="zoom:50%;" />

>   **An example**
>
>   **传统Unix文件系统的操作和外部碎片问题：**
>
>   假设在传统的Unix文件系统中，文件被存储在磁盘的不同区域：
>
>   1.  **初始存储**：
>       -   当文件A、B、C依次创建时，它们被放置在磁盘的连续块中。
>       -   磁盘布局可能如下：`[File A][File B][File C]`
>   2.  **文件删除和添加**：
>       -   如果文件B被删除，它释放的空间成为一个“空洞”。
>       -   新创建的文件D可能比原先的文件B大，不能完全放入这个空洞中。
>       -   磁盘布局可能变为：`[File A][空洞][File C][File D的部分][File D的剩余部分]`
>       -   这就造成了外部碎片：磁盘空间被小的、不连续的“空洞”填满，使得存储大文件变得困难。
>
>   **LFS的操作和碎片避免：**
>
>   现在，假设同样的操作在一个LFS上进行：
>
>   1.  **连续写入**：
>       -   在LFS中，所有文件更新都以连续的日志形式写入磁盘。文件A、B、C连续地追加到日志中。
>       -   初始磁盘布局：`[File A][File B][File C]`
>   2.  **文件删除和添加**：
>       -   当文件B被删除，LFS不会立即在磁盘上清除它，而是在日志中记录这一删除操作。
>       -   新文件D直接追加到日志末尾，而不是放入旧文件B的位置。
>       -   磁盘布局：`[File A][File B][File C][删除B的记录][File D]`
>   3.  **垃圾回收**：
>       -   LFS定期进行垃圾回收，重新组织磁盘上的数据，清除无效或过时的记录（如已删除的文件B），并压缩剩余数据。
>       -   这个过程有效地整理了磁盘空间，减少了外部碎片。

**External Fragmentation**

-   A **cleaner thread** (for deleted files) is running in the background and spends its time scanning the log circularly and **compacting** it
-   **Deleted** files are marked as free segments and **files being used** right now are written at the end of the log

**Evaluation**

-   It greatly **increases disk performance** on writes, file creates, deletes but the **cleaner thread** takes additional CPU time 
-   Writes are **more robust** as they are done as a single operation (multiple small writes are more likely to expose the file system to serious inconsistency) 
-   Less frequently used for **regular file systems** (because it is highly incompatible with existing file systems), more frequently used for **SSDs**

>   **An example of how LFS reduces write amplification**
>
>   传统文件系统操作：
>
>   1.  **文件编辑**：
>       -   假设你打开了一个包含三行文本的文件`file.txt`，它存储在SSD的一个擦除块中。
>       -   现在，你修改了文件中的第二行。
>   2.  **写入过程**：
>       -   在传统文件系统中，这种修改首先需要读取整个擦除块到内存。
>       -   然后擦除整个块，并将包含修改后的第二行和未更改的其他两行文本的新数据写回到一个新的擦除块中。
>   3.  **结果**：
>       -   因为SSD不能只修改擦除块中的一部分数据，所以整个擦除块的内容都需要被重写，即使只更改了一小部分。
>
>   LFS操作：
>
>   1.  **文件编辑**：
>       -   同样，你在LFS上修改了`file.txt`中的第二行。
>   2.  **写入过程**：
>       -   在LFS中，这种修改被视为一个新的日志条目。LFS不会去修改原始擦除块中的数据，而是将包含修改的新数据作为一个新条目追加到日志的末尾。
>       -   由于LFS总是顺序写入，所以它只是在日志的末尾添加了修改的部分，而不需要重写整个文件。
>   3.  **结果**：
>       -   LFS减少了写入量，因为它只写入了实际更改的数据，而不是整个文件的数据。这减少了对擦除块的擦除和重写操作，从而减少了写入放大效应。

## Journaling File Systems

**Example**

-   Deleting a file consists of the following actions:
    -   **Remove** the file's directory entry
    -   Add the file's **inode** to the **pool of free inodes**
    -   Add the file's **disk blocks** to the **free list**
-   It can **go wrong**, for instance
    -   **Directory** entry has been deleted and a crash occurs ⇒ i-nodes and disk blocks become inaccessible 
    -   The **directory** entry and **i-node** have been released and a crash occurs ⇒ disk blocks become inaccessible
-   **Changing the order** of the events does not necessarily resolve the issues
-   Journaling file systems aim at **increasing the resilience** of file systems against **crashes** by recording each update to the file system as a transaction

**Concept**

-   The key idea behind a **journaling file system** is to log all events (transactions) before they take place
    -   Write the actions that should be undertaken to a log file 
    -   Carry them out 
    -   Remove/commit the entries once completed
-   If a **crash** happens in the middle of an action the **entry in the log file will remain present** 
-   The **log is examined** after the crash and used to restore the consistency 
-   NTFS, ext3, and ext4 and are examples of journaling file systems

## Virtual File System

**Concept**

-   Multiple file systems usually co-exist (e.g., NTFS and ISO9660 for a CD-ROM, NFS) 
-   File systems are **seamlessly integrated** by the operating system’s **virtual file systems** (VFS) 
-   VFS relies on **standard object oriented principles** (or manual implementations thereof), e.g. polymorphism

-   Consider some code that you are writing, **reading “data records”** (DataObject) from a file 
-   These records can be stored in **CSV file**, or **XML File** 
-   How would you make your code resilient against **changes in the underlying data structure**?
    -   hide the **implementation** behind **interfaces** using **Data Access Objects** (DAOs)

-   We can define a generic interface, e.g. `DataReader`, containing a method 
    `public DataObject readData();`
    -   In the case of file systems, this would be the **POSIX interface** containing reads, writes, close, etc.
-   You would hide the CSV and XML code in **specific implementations** of the `DataReader` interface, e.g. `CSVDataReader` and `XMLDataReader`
    -   In the case of file systems this would be the file system implementations

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
String type = br.readLine(); 
br.close();

DataReader reader = null; 
if (type.equals("CSV")) {
	reader = new CSVDataReader(); 
} else if (type.equals("XML")) {
	reader = new XMLDataReader(); 
}
if (reader != null) 
    System.out.println(reader.readData());
```

<img src="assets/Screenshot 2024-01-12 at 01.07.10.png" alt="Screenshot 2024-01-12 at 01.07.10" style="zoom:50%;" />

>   **An example**
>
>   **示例情景：使用不同文件系统的操作系统**
>
>   假设你的电脑上安装了一个操作系统，这个操作系统支持多种文件系统，比如NTFS（通常用于Windows）、ext4（Linux的标准文件系统）和FAT32（一个广泛兼容的老旧文件系统）。你的电脑有三个分区，每个分区使用不同的文件系统：
>
>   1.  **分区1**：使用NTFS。
>   2.  **分区2**：使用ext4。
>   3.  **分区3**：使用FAT32。
>
>   **文件访问过程**
>
>   现在，假设你在这个操作系统上运行一个文本编辑器应用程序，你想打开位于这三个分区上的不同文本文件。
>
>   1.  **打开NTFS分区上的文件**：
>       -   当你尝试通过文本编辑器打开分区1（NTFS）上的文件时，你的操作系统通过VFS发送一个通用的“打开文件”请求。
>       -   VFS识别这个文件位于NTFS分区，并利用NTFS驱动程序来实际处理文件的打开操作。
>   2.  **打开ext4分区上的文件**：
>       -   接着，当你尝试打开分区2（ext4）上的文件时，VFS再次接收到一个“打开文件”的请求。
>       -   这一次，VFS使用ext4驱动程序来处理请求，因为文件位于ext4分区。
>   3.  **打开FAT32分区上的文件**：
>       -   最后，当你尝试打开分区3（FAT32）上的文件时，VFS又一次处理了相同的请求。
>       -   在这种情况下，VFS调用FAT32驱动程序来访问文件。

-   The VFS interface commonly contains the **POSIX system calls** (open, close, read, write ..) 
-   Each file system that meets the VFS requirements **provides an implementation** for the system calls contained in the interface 
-   Note that implementations can be for **remote file systems** (e.g. sshfs), i.e. the file can be stored on a different machine

