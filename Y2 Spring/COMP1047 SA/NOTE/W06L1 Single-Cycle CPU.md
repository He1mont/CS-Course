## W6L1 Single-Cycle CPU

>   ### Outline
>
>   -   Introducing the MIPS CPU design
>   -   Analyzing the instruction set
>   -   Constructing the datapath
>   -   Datapath with control unit



#### 1. Instruction execution process

1.   <u>PC</u>: instruction memory, fetch instruction
2.   <u>Register numbers</u>: register file, read registers
3.   <u>Depending on instruction types</u>
     -   Use ALU to calculate
         -   Arithmetic result
         -   Memory address for loading/storing
         -   Branch target address
     -   Access data memory for loading/storing
4.   <u>PC</u>: target address or PC + 4

<img src="assets/Screenshot 2023-03-27 at 19.24.51.png" alt="Screenshot 2023-03-27 at 19.24.51" style="zoom:40%;" />



#### 2. Logic Design Basics

<img src="assets/Screenshot 2023-03-27 at 14.22.56.png" alt="Screenshot 2023-03-27 at 14.22.56" style="zoom:40%;" />



#### 3. Sequential Elements

-   ==Register: stores data in a circuit==
    -   Uses a **clock signal** to determine when to update the stored value
    -   update when `Clk` changes from 0 to 1

<img src="assets/Screenshot 2023-03-27 at 14.26.46.png" alt="Screenshot 2023-03-27 at 14.26.46" style="zoom:40%;" />

-   ==Register with write control==
    -   Only updates on clock edge **when write control input is 1**
    -   Used when stored value is required later

<img src="assets/Screenshot 2023-03-27 at 14.27.00.png" alt="Screenshot 2023-03-27 at 14.27.00" style="zoom:40%;" />



#### 4. How to design a Processor

1.   Analyze the instruction set (datapath requirements)
     -   the meaning of each instruction is given by the *register transfers*
     -   datapath must include storage element
     -   datapath must support each register transfer
2.   Select the set of datapath components and establish clocking methodology
3.   Assemble datapath meeting the requirements
4.   Analyze the implementation of each instruction to determine the setting of control points that affect the register transfer
5.   Assemble the control logic



#### 5. Analyzing the Instruction Set

-   RTL (Register Transfer Language)
    -   gives the semantics of the instructions
    -   the chart is as follows
-   LOAD
    -   do sign extension with Imm16
    -   access Memory
-   BEQ
    -   || 00 means << 2 i.e. left shift by 2 bits
    -   imm16是CPU根据label的地址计算出来的

<img src="assets/Screenshot 2023-03-27 at 14.34.02.png" alt="Screenshot 2023-03-27 at 14.34.02" style="zoom:50%;" />



#### 6. What hardware are needed

-   Memory
    -   store instructions and data
-   Registers (32 * 32)
    -   read RS
    -   read RT
    -   Write RT or RD
-   PC
-   Extender for zero- or sign-extension
-   Calculating values in registers or extended immediate (ALU)
-   Add 4 or extended immediate to PC



#### 7. Sequential components for datapath:

1.   **Register**

<img src="assets/Screenshot 2023-03-27 at 19.57.54.png" alt="Screenshot 2023-03-27 at 19.57.54" style="zoom:40%;" />

-   Similar to the D Flip Flop except
    -   32-bit input and output
    -   Write Enable input
-   Write Enable
    -   Negated (0): **Data Out** will not change
    -   Asserted (1): **Data Out** will become **Data In**



2.   **Register file**

<img src="assets/Screenshot 2023-03-27 at 19.58.21.png" alt="Screenshot 2023-03-27 at 19.58.21" style="zoom:50%;" />

-   Consist of 32 registers
    -   two 32-bit output busses: **busA** and **busB**
    -   one 32-bit input bus: **busW**
-   Register is selected by:
    -   RA selects the register to put on busA
    -   RB selects the register to put on busB
    -   RW selects the register to be written via busW when Write Enable is 1
        -   e.g.: RW = 01010, this mean `$10 i.e. $t2` is going to be changed
-   Clock input (CLK)
    -   the CLK input is a factor ONLY during write operation
    -   during read, behaves as a combinational circuit



3.   Memory

<img src="assets/Screenshot 2023-03-27 at 20.00.09.png" alt="Screenshot 2023-03-27 at 20.00.09" style="zoom:50%;" />

-   One input bus: Data In
-   One output bus: Data Out
-   Word is selected by:
    -   **Address** selects the word to put on Data Out
    -   `Write Enable = 1`: address selects the memory word to be written via the Data In bus
-   Clock input (CLK)
    -   The CLK input is a factor during write and read operations



4.   Assembling the datapath

<img src="assets/Screenshot 2023-03-27 at 20.21.49.png" alt="Screenshot 2023-03-27 at 20.21.49" style="zoom:33%;" />

-   Instruction fetching is divided into two major steps
    -   Fetch the instruction: mem[PC]
    -   Update the program counter:
        -   Sequential code: `PC <- PC + 4`
        -   Branch and Jump: `PC <- "something else"`



<img src="assets/Screenshot 2023-03-27 at 23.18.19.png" alt="Screenshot 2023-03-27 at 23.18.19" style="zoom:40%;" />

-   **Arithmetic / logical operations**: `R[rd] <- R[rs] op R[rt] `
    -   e.g.: R-type instructions: add, sub, and, or, etc.
    -   RA, RB, RW, come from insttruction's `rs, rt, rd` fields, they are **index values**
    -   ALU and RegWrite: control logic after decoding



<img src="assets/Screenshot 2023-03-27 at 23.18.59.png" alt="Screenshot 2023-03-27 at 23.18.59" style="zoom:40%;" />

-   **load operations:** `lw rt, imm16(rs)` 
    -   `R[rt] <- MEM[R[rs] + sign_ext(imm16)]`

-   **store operations:** `sw rt, imm16(rs)`
    -   `MEM[R[rs] + sign_ext(imm16)] <- R[rt]`



<img src="assets/Screenshot 2023-03-27 at 23.23.05.png" alt="Screenshot 2023-03-27 at 23.23.05" style="zoom:50%;" />

-   **Branch operations**: `beq rs, rt, imm16`

    ```
    mem[PC]
    Equal <- R[rs] == R[rt]
    if (Equal)
    	PC <- PC + 4 + (SignExt(Imm16)*4)
    else
    	PC <- PC + 4
    ```



-   A Single-Cycle Datapath

<img src="assets/Screenshot 2023-03-27 at 23.26.52.png" alt="Screenshot 2023-03-27 at 23.26.52" style="zoom:50%;" />

