## Computer Performance

#### *. Instruction Set Architecture

-   Defines the set of instructions that a computer/processor can execute
-   The contract between the hardware and software
-   examples:
    -   x86
    -   ARM
    -   MIPS



#### 1. Timing Performance

<img src="assets/image-20230314235757296.png" alt="image-20230314235757296" style="zoom:75%;" />

<img src="assets/image-20230314235802134.png" alt="image-20230314235802134" style="zoom:67%;" />



##### 2. CPU Clocking

-   one clock cycle: the unit of the CPU clock
-   clock period: time per clock cycle
-   clock frequency (clock rate): clock cycle per second

![image-20230315000238920](assets/image-20230315000238920.png)



##### 3. CPU Time

<img src="assets/image-20230315000322434.png" alt="image-20230315000322434" style="zoom:80%;" />



##### 4. Clock cycles per instructions (CPI)

the average number of clock cycles each instruction takes to execute

<img src="assets/image-20230315000525700.png" alt="image-20230315000525700" style="zoom:75%;" />

-   CPI is determined by how you design the CPU

-   Instruction Count is determined by program, ISA and compiler

    

##### 5. The Classic CPU Performance Equation

<img src="assets/image-20230315000710953.png" alt="image-20230315000710953" style="zoom:67%;" />



##### 6. Average CPI (weighted average)

<img src="assets/image-20230315000751841.png" alt="image-20230315000751841" style="zoom: 80%;" />

<img src="assets/image-20230315000808807.png" alt="image-20230315000808807" style="zoom:90%;" />

-   IC~i~ is weighted SUM of instructions
-   IC is just the SUM of instructions



##### 7. Power and Energy

<img src="assets/image-20230315000915863.png" alt="image-20230315000915863" style="zoom:80%;" />