# Quiz-lec02

## Q1

Assume that the implementation of Davis's Bit Hill Climbing for MAX-SAT internally uses an accept-only-improving-moves strategy within. How might this strategy be changed (without accepting the worsening moves) to potentially improve the performance of Davis's Bit Hill Climbing?

-   a. Accept all bit flips
-   **b. Accept bit flips resulting in improving or equal solution costs**
-   c. Accept bit flips resulting in a better solution cost
-   d. Accept only bit flips resulting with a FALSE truth assignment for the related literal

## Q2

Assume that Davis's Bit Hill Climbing and Steepest Descent Hill Climbing algorithms are run for 10 minutes to solve a MAX-SAT problem instance resulting in the average objective values of 12.4 and 3.8, respectively, over 30 runs/trials.

Which algorithm would perform the best for solving MAX-SAT problems assuming a minimisation problem formulation?

-   a. Davis's Bit Hill Climbing
-   b. Steepest Descent Hill Climbing
-   c. Both algorithms would perform the same
-   **d. It is not possible to determine**

## Q3

Assume that Davis's Bit Hill Climbing, First Improvement Hill Climbing and Steepest Descent Hill Climbing algorithms are applied to a MAX-SAT problem instance resulting in average objective values of 12.4, 34.3 and 25.7, respectively, over 30 runs.

Which algorithm performs the best based on the average objective value on this problem instance?

-   a. Davis's Bit Hill Climbing
-   b. First Improvement Hill Climbing
-   c. Assuming that the problem is formulated as a minimisation problem, then Steepest Descent Hill Climbing
-   **d. Assuming that the problem is formulated as a maximisation problem, then First Improvement Hill Climbing**

## Q4

The **First Improvement Hill Climbing** algorithm may get trapped at a local optimum regardless of the problem dealt with.

-   **True** 
-   False

## Q5

One of the strengths of hill-climbing methods in search and optimisation is that they are generally **easy to implement algorithms**. 

-   **True** 
-   False

## Q6

A **hill-climbing heuristic** processes a given candidate solution and generates an improved solution or returns the same solution, while a **mutational heuristic** processes a given candidate solution and generates a solution that is not guaranteed to be better than the input. All such heuristics are **perturbative**

## Q7

Applying the bit-flip operator randomly **for once** to the candidate solution of "0101010", which of the following new candidate solutions could be produced?

-   a. 1111010
-   **b. 1101010**
-   **c. 0101000**
-   d. 0100000

## Q8

After applying the **adjacent pairwise** interchange operator **three times** at random to the candidate solution of "1-3-2-5-4-7-6", which of the following new candidate solutions could be produced?

-   **a. 1-3-2-5-7-4-6**
-   **b. 1-3-2-5-4-7-6**
-   c. 6-7-4-5-2-3-1
-   d. 1-7-4-5-2-3-6

