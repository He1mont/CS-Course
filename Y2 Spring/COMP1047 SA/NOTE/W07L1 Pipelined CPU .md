## W7L1 Instruction Pipelining

>   ### Outline
>
>   -   An overview of pipelining
>   -   A pipelined datapath
>   -   Pipelined control
>   -   Hazards: types of hazard
>       -   Handling data hazards
>       -   Handling branch hazards



#### 1. Pipelined datapath

-   IF: Instruction Fetch
-   ID: Instruction Decode
-   EX: Calculate the memory address
-   MEM: Read the data from the Data Memory
-   WB: Write the data back to the register file



#### 2. Pipeline hazards

-   Structural hazards
    -   Attempt to use the same resource in two different ways at the same time
-   Data hazards
    -   Attempt to use the data value before available
    -   Instruction depends on result of prior instruction still in the pipeline
-   Control hazards
    -   Attempt to make decision before condition is evaluated
    -   Most often happens in ==branch instruction==



#### 3. Data Hazards

<img src="assets/Screenshot 2023-05-17 at 23.09.30.png" alt="Screenshot 2023-05-17 at 23.09.30" style="zoom:50%;" />

-   Method 1: Insert NOP
    -   This really slows the CPU down!



-   Method 2: Forwarding (for R-type instruction)
    -   Hardware solution
    -   Feed the value directly to ALU read-in ports



-   Method 3: Stalling (for load instructions)
    -   Stall pipeline by "freezing" or duplicating the control/data values
    -   Namely: inserting a ==bubble== in the pipeline































