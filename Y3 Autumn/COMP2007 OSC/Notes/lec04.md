# lec04: Process1

>   **Overview**
>
>   -   Processes
>   -   Process **states** and state **transitions**
>   -   Context Switching
>       -   Process Control Block (PCB)
>       -   Process Implementation
>   -   System calls for process management
>   
>   *Reference: MOS Chapter 2.1*

## Processes

**Definition**

-   **A process is an abstraction of running instance of a program.**
    -   A program is **passive** and "sits" on a disk
    -   A process can be thought of as a program in execution.
    -   A process has **control structures** associated with it, may be **active**, and may have **resources** assigned to it. e.g. I/O devices, memory, processor

-   All the info necessary to administer a process is stored **by the kernel** in a **process control block** (PCB)
-   All the process control blocks are recorded in the **process table**

**Memory Image of Processes**

-   A process memory image contains

    -   the program **code**

    -   a **data segment**, **stack** and **heap**

-   Every process has its own **logical address space**, in which **stack and heap** are placed at **opposite slides** to allow them to grow

<img src="assets/Screenshot 2023-10-16 at 01.12.26.png" alt="Screenshot 2023-10-16 at 01.12.26" style="zoom:33%;" />

## Process States and Transitions

<img src="assets/Screenshot 2023-10-09 at 15.10.35.png" alt="Screenshot 2023-10-09 at 15.10.35" style="zoom:33%;" />

**Process States**

-   **new**:  process has just been created. 
    -   It has a PCB and is waiting to be admitted, although it may not yet be in memory

-   **running**: currently having its instructions executed by the CPU
-   **ready**: waiting for CPU to become available
-   **blocked**: process cannot continue, e.g. waiting for I/O
-   **terminated**: process is no longer executable.
    -   PCB may be temporariliy preserved.

**State transitions include:**

-   **new -> ready**: admit the process and commit to execution
-   **ready -> running**: the process is selected by the **process scheduler**
-   **running -> blocked**: process is waiting for input or carried out a system call
-   **blocked -> ready**: event happens, e.g. I/O operation has finished
-   **running -> ready**: get interrupted by process with higher priority or run out of time slice
-   **running -> exit**: the process has finished, e.g. program ended or exception encountered
-   **Interrupts and system calls drive these transitions**

<img src="assets/Screenshot 2023-10-19 at 00.40.08.png" alt="Screenshot 2023-10-19 at 00.40.08" style="zoom:33%;" />

**One example**

<img src="assets/Screenshot 2023-10-16 at 01.31.02.png" alt="Screenshot 2023-10-16 at 01.31.02" style="zoom:50%;" />

## Context Switching

>   当一个进程停止时，它的寄存器被保存到这个内存位置，通过恢复这些寄存器，OS 可以恢复运行该进程，这被称为**上下文切换 (Context Switch)**.

**Multiprogramming**

-   Assuming a single processor system, the instructions of individual processes are executed **sequentially**

    -   **<u>Control is exchanged between processes via a procedure</u>** known as **context switching**

    -   A **trade-off** exists between the length of the **time-slice** and the **context switch time**

    -   **True parallelism** requires **hardware support**


-   When a **context switch** take place, the system **saves** the state of the old process and **loads** the state of the new process (creates **overhead**)
    -   saved => PCB is updated
    -   started => PCB is read



**Short time slices** result in **good response times** but **low effective utilisation**

-   For example, assume **both** context switches and time slices take `1ms`, then

    -   It will take 99*(1+1) = 198ms for the last of 100 processes to start running


    -   1/(1+1) = 0.5 of the CPU time is doing useful work

<img src="assets/Screenshot 2024-01-12 at 22.55.54.png" alt="Screenshot 2024-01-12 at 22.55.54" style="zoom:50%;" />

**Long time slices** result in **poor response times** but **better effective utilisation**

-   For example, assume context switches take `1ms` and time slices take `100ms`, then

    -   It will take 99*(100+1) = 9999ms for the last of 100 processes to start running


    -   100(1+100) = 0.99 of the CPU time is doing useful work

<img src="assets/Screenshot 2024-01-12 at 22.56.10.png" alt="Screenshot 2024-01-12 at 22.56.10" style="zoom:50%;" />

### **Process Control Block (PCB)**

-   A **process control block** contains **three types of attributes**:
    -   **Process identification** (pid, parent pid, uid)
    -   **Process control information** (process state)
    -   **Process state information** (user registers, program counter, stack pointer, files etc.)
-   **Process control blocks** are **kernel data structures**
    -   They are protected and only accessible in **kernel mode**
    -   Allowing user applications to access them directly could compromise their integrity
    -   The OS manages them on the user's behalf through **system calls**

**Process Implimentation**

-   **Tables and Control blocks**

<img src="assets/Screenshot 2023-10-09 at 15.31.35.png" alt="Screenshot 2023-10-09 at 15.31.35" style="zoom:40%;" />

-   An operating system maintains information about the status of "resources" in **tables**

    -   **Process tables** (process control blocks)

    -   **Memory tables** (memorhy allocation, memory protection, virtual memory)

    -   **I/O tables** (availability, status, transfer info)

    -   **File tables** (location, status)

-   The **process table** holds a **process control block** for each process, allocated upon process creation
-   Tables are maintained by the **kernel** and are usually **cross referenced**

<img src="assets/Screenshot 2023-10-19 at 00.45.38.png" alt="Screenshot 2023-10-19 at 00.45.38" style="zoom:33%;" />

**Switching Processes**

1. Interruption or system calls
2. Save the context of the current process

    -   Save PC, registers into PCB
    -   Update process state to Ready or Blocked
3. Move PCB to appropriate queue
4. Run scheduler to select the next process
5. Load the context of the new process

    -   restore CPU State: load PC and register
    -   update new process state to running in new PCB
    -   update memory unit (MMU)
6. Execute the New Process

## System Calls for Process Management

**Process Creation**

**A new process is created by having an existing process execute a process creation system call.**

-   System call in UNIX: `fork`
-   System call in Win32: `CreateProcess`

<img src="assets/Screenshot 2024-01-13 at 00.01.33.png" alt="Screenshot 2024-01-13 at 00.01.33" style="zoom:50%;" />

**Process Termination**

The process would terminate due to one of the following conditions:

-   Normal exit (voluntary).
    -   `exit` in UNIX and `ExitProcess` in Win32
-   Error exit (voluntary).
    -   user tries to compile a file that does not exist
-   Fatal error (involuntary).
    -   divided by 0
-   Killed by another process (involuntary).
    -   `kill` in UNIX
    -   `TerminateProcess` in Win32

**Process Hierarchies**

-   In UNIX
    -   a process and all of its children and further descendants together form a process group
-   In Win32
    -   no concept of a process hierarchy

**Fork**

-   `fork()` creates an **exact copy** of the current process
-   `fork()` returns the **process identifier** of the child process **to the parent process**
-   `fork()` **return 0** to the child process

### Example

```C
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() {
	pid_t const pid = fork();
    if(pid < 0){
        printf("Fork failure\n");
        return -1;
	} else if(pid == 0) {
        printf("Child process\n");
        execl("/bin/ls", "ls", "-l", 0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        printf("Child %d returned %d\n", pid, status);
    }
}
```

## Quiz

1.   **Why might you run fork without running a subsequent exec?**

2.   **Do you always need to call exit to end a process?**
- No. If the main function returns
3.   **Why does a process control block contain data about register contents?** 

-   The register contents hold the state of a process's execution, including PC, stack pointer, etc.
-   **Enabling Context Switching**: When the process is resumed, the registers are restored from the PCB, allowing the process to continue from where it left off.

4.   **Why might it be useful to retain a process control block for a terminated process?**

-   To provide information about the process's exit status to the parent process.
-   For debugging purpose
