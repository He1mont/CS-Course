## W5L2 Digital Blocks and ALU Design

##### 1. Digital Building Blocks

-   Basic 

<img src="assets/Screenshot 2023-03-27 at 23.44.18.png" alt="Screenshot 2023-03-27 at 23.44.18" style="zoom:33%;" />

-   1-bit adders

<img src="assets/Screenshot 2023-03-27 at 23.47.48.png" alt="Screenshot 2023-03-27 at 23.47.48" style="zoom:33%;" />

-   Multi-bit adders

<img src="assets/Screenshot 2023-03-27 at 23.48.16.png" alt="Screenshot 2023-03-27 at 23.48.16" style="zoom:33%;" />

-   Subtractor

    -   `-B = B' + 1`

    -   `A - B = A + B' + 1 `

    -   Bit-wise inverse of B is B'

<img src="assets/Screenshot 2023-03-27 at 23.48.47.png" alt="Screenshot 2023-03-27 at 23.48.47" style="zoom:33%;" />

-   Comparator: Equality

<img src="assets/Screenshot 2023-03-27 at 23.50.37.png" alt="Screenshot 2023-03-27 at 23.50.37" style="zoom:40%;" />

-   Comparator: Less than
    -   Calculate A - B. If A < B, then result is negative
    -   for 2's complement numbers, (n-1)th bit is 1

<img src="assets/Screenshot 2023-03-27 at 23.52.04.png" alt="Screenshot 2023-03-27 at 23.52.04" style="zoom:25%;" />

-   Multiplexer
    -   Selects between one of N inputs to connect to the output
    -   $\log_{2}{N}$-bit input selection

<img src="assets/Screenshot 2023-03-28 at 00.02.48.png" alt="Screenshot 2023-03-28 at 00.02.48" style="zoom:25%;" />

-   Register
    -   store data in a circuit
    -   use a clock signal to determine when to update the stored value
    -   edge-triggered: update when `Clk` changes from 0 to 1

<img src="assets/Screenshot 2023-04-22 at 22.03.26.png" alt="Screenshot 2023-04-22 at 22.03.26" style="zoom:40%;" />



##### 2. ALU design

<img src="assets/Screenshot 2023-04-22 at 22.04.32.png" alt="Screenshot 2023-04-22 at 22.04.32" style="zoom:50%;" />

















