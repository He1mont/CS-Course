# lec01: Analysis of Algorithms

## **Experimental Studies**

**General Pattern:**

-   Write a program implementing the algorithm
-   Run the program with inputs of “varying size and composition”
-   Use a system method to get an (in)accurate measure of the actual running time
-   Plot the results
-   Interpret & analyse

**Limitation of Experiments**

-   Necessary to implement the algorithm, which may be time-consuming
-   We may miss the real worst case
-   To compare two algorithms, the same hardware and software experiments should be used

**Limitation of Theory**

-   It is necessary to implement the theory, which may be difficult or time-consuming
-   Results may not be indicative of the typical running time on inputs encountered in real world.

## **Theoretical Analysis**

-   Uses a **“high-level” description** of the algorithm instead of an implementation
    -   Takes into account **all possible inputs**
    -   Allows us to evaluate the speed of an algorithm **independently** of the hardware/software/language environment

**Pseudocode Example**

```pseudocode
Algorithm arrayMax(A, n)
Input array A of n integers
Output maximum element of A

currentMax = A[0]
for i = 1 to n - 1 do
    if A[i] > currentMax then
        currentMax = A[i]
return currentMax
```

==**Primitive Operations**==

-   Assigning a value to a variable
-   Indexing into an array
-   Comparing two numbers
-   Adding/subtracting/ multiplying/dividing two numbers
-   Calling a method
-   Returning from a method

**The Random Access Machine (RAM) Model**

-   A CPU
-   A potentially-unbounded bank of memory cells, each of which can hold **an arbitrary number** or character
-   Memory cells are numbered and accessing any cell in memory takes **unit time** (some **fixed time**).
-   Ignore the **size of numbers** in arithmetic operations

## **Counting Primitive Operations**

<img src="assets/Screenshot 2024-01-31 at 09.30.36.png" alt="Screenshot 2024-01-31 at 09.30.36" style="zoom:50%;" />

**Underspecified Counting**

-   Consider `c = A[i]` then ‘full’ process can be
    -   get A = pointer to start of array A, and store into a register
    -   get i, and store into a register
    -   compute A+i = pointer to location of A[i], and store back into a register
    -   get value of “*(A+i)” (from RAM) and store value it into a register
    -   copy the value into the location of c in the RAM
-   Here we just count
    -   ‘plus’ of “A+i”
    -   the assignment

**Correctness vs. Efficiency**

-   Primitive operation counting is relevant to **efficiency**, but not for **correctness**
-   We did not prove the algorithm correct

**Estimating Running Time**

-   Algorithm **arrayMax** executes `8n - 4 ` primitive operations in the worst case
    -   `a` = time takend by the fastest primitive operation
    -   `b` = time takend by the slowest primitive operation
-   Let `T(n)` be the worst case time of **arrayMax**, then
    -   $a(8n-4) \le T(n) \le b(8n-4)$
-   Usually said as **arrayMax runs in linear time**

### **Another Example**

```pseudocode
Algorithm: alg-lec1
Input: positive integer n, which is a power of 2
Output: integer m such that 2^m = n

m = 0				// 1
while (n >= 2) {	// 3 per pass
	n = n / 2		// ? per pass
	m++				// 3 per pass
}
return m			// 1
```

**Consider `n = n / 2`**

-   Case 1: **4 steps needed**

    1.   read `n` from RAM and store it in a register `r1`

    2.   read `2` from memory and store it in a register `r2`
    3.   send the register `r1, r2` through arithmetic division and store result in a register `r3`
    4.   write `r3` back to `n`

-   Case 2: **3 steps needed**

    1.   read `n` from RAM and store it in a register `r1`
    2.   send `r1` through a ***right shift*** of the bits and store result in a register `r3`
    3.   write `r3` back to `n`

**Consider the number of passes  through loop**

-   for `n = 2^m`, we need `log(n)` passes through loop

## Exercise

```pseudocode
m = 0
while (n >= 2) 
	n = sqrt(n)
	m++
return m
```

