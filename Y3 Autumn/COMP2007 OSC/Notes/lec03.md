# lec03: Intro 3

>   **Overview**
>
>   -   Kernel and user space
>   -   Interrupts
>       -   Interrupt mechanism
>    -   Challenges
>   -   System calls
>   -   The C programming language
>   
>*Reference: MOS Chapter 1.6, [Youtube](https://www.youtube.com/watch?v=lhToWeuWWfw&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=9)*

## Kernel and user space

>   The code running in kernel mode is often referred to as the **kernel**.

<img src="assets/Screenshot 2023-10-05 at 16.07.27.png" alt="Screenshot 2023-10-05 at 16.07.27" style="zoom:33%;" />

**Two modes**

Most CPUs, have two modes. On most embedded systems, a small piece runs in *kernel mode*, with the rest running in *user mode*

-   **kernel mode**
    -   where CPU can execute every instruction in its instruction set
    -   and use *every feature of the hardware*
-   **user mode**
    -   where *user programs* always run
    -   only a subset of the instructions to be executed
    -   only a subset of the features to be accessed
    -   all instructions involving I/O and memory protection are disallowed in user mode.

**Why we need kernel mode**

-   **Security**: User applications cannot directly perform operations that could harm the system.
-   **Resource Management**: The kernel can manage hardware and software resources efficiently, ensuring that all processes and tasks are handled correctly.

## Interrupts

**An interrupt is a mechanism for changing the normal flow of execution**

-   can happpen asynchronously, called **interrupt**
    -   triggered by unpredictable factors **external** to the CPU like **user input**
-   can also happen synchronously, called **exception**
    -   triggered **directly by the CPU** executing a instruction
    -   like divided by 0, segmentation fault, ...

**Interrupt mechanism**

-   The CPU is doing some work
-   An interrupt is signalled by a hardware device
    -   e.g.: to indicate some IO data is available

-   The CPU records aspects of its current state, **switches to kernel mode** and runs code in a handler to service the interrupt
-   Once completed, the CPU is returned to processing other tasks

**Challenges**

-   Interrupts can come at any time
    -   Handlers may split work into **top** component(dealt with immediately) and a **bottom** component(dealt with later)

-   Interrupts may be interrupted - may be **nested**
-   Some critical code cannot be interrupted and must be temporarily disabled

>   **Blocking IO**
>
>   Naive IO which wastes CPU cylces waiting for slow devices to respond

<img src="assets/Screenshot 2023-10-08 at 22.37.02.png" alt="Screenshot 2023-10-08 at 22.37.02" style="zoom:33%;" />

>   **Interrupts**
>
>   Better CPU usage supported by interrupts "calling back" when there is work to do

<img src="assets/Screenshot 2023-10-08 at 22.39.30.png" alt="Screenshot 2023-10-08 at 22.39.30" style="zoom:33%;" />

## System calls

>   **System calls** are how programs request services from the OS

Some examples

-   Requesting memory
-   **Accessing files**
-   Running programs
-   Accessing concurrency features



**System calls and API**

-   ==An API is **a programming interface**==
    -   a library of functions that run in user space like pthreads
-   An API may need to **make system calls** to access the required functionality
-   The relationship is not one-to-one 
    -   single API function may invoke 0, 1, or many system calls




**System call mechanisms**

-   Some user code is running
-   A system call is required - each has a *unique system call number*
-   The system call **number** is stored in a designated register
-   The system call **parameters** are stored in designated registers
-   A synchronous interrupt(exception) is triggered by an instruction referred to as a **trap**
-   The interrupt is **handled by kernel mode code**, which calls a **system call service routine** that delivers the required functionality
-   The operating system continues running the calling code

>   ### Example from *MOS Chapter 1.6*
>
>   One example from C: `count = read(fd, buffer, nbytes);`
>
>   There are 3 params:
>
>   -   `fd` to specify the file
>   -   `buffer` to point to the buffer
>   -   `nbytes` to give the number of bytes to read
>
>   <img src="assets/Screenshot 2023-10-16 at 00.21.00.png" alt="Screenshot 2023-10-16 at 00.21.00" style="zoom:50%;" />
>
>   
>
>   **HOWEVER**
>
>   -   The system call service routine may not actually service the request immediately
>   -   The operating system may not continue running the original caller
>   -   System calls are the kernel's big chance to get work done for the benefit of everything running on the system
>

## The C Programming Language

>   Why we choose C for OS implementaiton?

**Performance**

An OS must be fast enough for as many users as possible

-   A slow OS slows every program that it runs
-   Mobile hardware must also consider energy efficiency
-   Bias toward performance over simplicity, elegance and maintainability
-   Cannot sacrifice correctness

**Portability**

As OS development is difficult, reuse is desirable

-   Must run directly on the hardware
-   Ideally must be able to compile for many different hardware platforms

**Predictability**

The behaviour of an OS must be predictable for user programs

-   Example - games cannot tolerate unpredictable delays slowing frame rates and responsiveness
-   Unpredictable behaviour such as garbage collection is inappropriate
