## W5L1 Instruction Sets

>   ### Outline
>
>   -   ISA
>   -   R-type instructions
>   -   I-type instructions
>   -   J-type instructions



#### 1. Recap

-   RISC ISA: Reduced Instruction Set Computing
    -   As opposed to CISC (e.g. x86)
    -   Simple, elegant, easy to implement
-   **Instruction Set Architecture**
    -   ==defines the set of operations that a computer can execute==
    -   ==the contract between the hardward and software==
    -   Examples
        -   x86: Intel
        -   ARM: Apple
        -   MIPS: Sony/Toshiba



#### 2. MIPS ISA

-   **All instructions are 32 bits**
-   32 32-bit register
-   50 opcode : the first 6 bits
    -   Arithmetic / Logic operations
    -   Load / store operations
    -   Branch / jump operations
-   3 instruction formats
    -   R-type: all operands are registers
    -   I-type: one of the operands is an immediate value
    -   J-type: non-conditional, nonrelative branches

<img src="assets/Screenshot 2023-03-20 at 14.43.57.png" alt="Screenshot 2023-03-20 at 14.43.57" style="zoom: 40%;" />



#### 3. R-format instructions

<img src="assets/Screenshot 2023-03-20 at 14.44.58.png" alt="Screenshot 2023-03-20 at 14.44.58" style="zoom:50%;" />

-   **Opcode:** partially specifies what instructions it is
    -   0 for all R-format instructions
-   **funct**: combined with opcode to specify the instruction
    -   e.g.: add: op(0), funct(32);	sub: op(0), funct(34)
-   **rs** (Source Register): used to specify register containing first operand
-   **rt** (S-next Register): used to specify register containing second operand
-   **rd** (Destination Register): used to specify register which will receive result of calculation
-   **shamt** (Shift amount): contains the amount a shift instruction will shift by



#### 4. I-format instructions

<img src="assets/Screenshot 2023-03-20 at 15.01.16.png" alt="Screenshot 2023-03-20 at 15.01.16" style="zoom:38%;" />

-   **opcode**: **uniquely** specifies an I-format instruction
-   **rs**: specifies the **only** register operand
-   **rt**: specifies the register which receives the result of calculation (*target register*)
-   **immediate**: 16-bit **signed** integer, can represent up to $2^{16}$ different immediate values



#### 5. J-format instructions

<img src="assets/Screenshot 2023-03-20 at 15.11.12.png" alt="Screenshot 2023-03-20 at 15.11.12" style="zoom:38%;" />

-   **opcode**: **uniquely** specifies an J-format instruction, so far, we've learnt `j` and `jal`
-   **JTA**: 26-bit jump target address, jump relative to the current PC value, jump in words not in bytes











