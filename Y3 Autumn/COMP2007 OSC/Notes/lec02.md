# lec02: Intro 2

>   **Overview**
>
>   -   Hardware
>   -   Address spaces
>
>   *Reference: MOS 1.3, 1.6, 1.7*

## Computer Hardware

<img src="assets/Screenshot 2023-10-08 at 21.50.29.png" alt="Screenshot 2023-10-08 at 21.50.29" style="zoom:40%;" />

**Instruction Evaluation**

-   A CPU's basic cycle consist of fetch, decode and execute
-   A CPU might have separate cycles, therefore use **pipeline**
-   A **superscalar CPU** provides **intruction level parallelism**
    -   multiple execution units are present, e.g., one for Integer Arithmetic, one for floating-point arithmetic

<img src="assets/Screenshot 2023-10-08 at 21.55.39.png" alt="Screenshot 2023-10-08 at 21.55.39" style="zoom:45%;" />

**Registers**

-   Registers are small fast element of memery close to CPU
-   Registers have multiple purposes:
    -   **Program Counter(PC)**: which instruction should be run next
    -   **Program Status Word(PSW)**: flags configuring the state of the CPU
    -   **General Purpose Registers**: storing operands for CPU instructions
-   The **compiler/programmer** decides what to keep in the registers

## Address Spaces

>   进程 (Process) 可以访问的内存被称为地址空间 (address space)

**An example**

```C
#include <stdio.h>

int main(){
    int x = 0;
    while (x++ < 10) {
        printf("Addr: %p; Val: %d\n", &x, x);
    }
    return 0;
}
```

**Results**:

-   The address printed are **logical addresses**, and they are the same
-   If compiled twice, the addresses printed would be the same on Win, but different on Mac
    -   due to **Address Space Layout Randomization(ASLR)**



**Compiling Process**

-   When compiling, memory addresses must be assigned to variables and instructions

-   The compiler **doesn't know** the physical addresses

-   It assumes that the code start running at **address 0**

-   Therefore the relations are below

    `physical address = logical address + offset`



**The Memory Management Unit (MMU) **

-   MMUs is responsible for address translation (to add the offset)
-   There are two different address spaces
    -   **logical address space:** seen by the program and used by the compiler
    -   **physical address space:** seen by the hardware/OS
