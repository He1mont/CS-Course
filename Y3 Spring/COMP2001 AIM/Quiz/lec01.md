# Quiz-lec01

## Q1

**Open decision support systems** are dependent on their environment, while **Close decision support systems** are entirely independent of their environment. 

A decision support system that can solve a given problem instance to optimality can be considered **Effective**. If the optimal solution is achieved fast by that decision support system, then it can also be considered **Efficient**.

## Q2

A search algorithm based on the **nearest neighbor constructive heuristic/operator** can always find a better solution than a search algorithm based on the **pairwise exchange** perturbative heuristic/operator for solving a given instance of the Travelling Salesman Problem.

-   True 
-   **False**

## Q3

The solutions obtained from a **stochastic search method** applied to a problem instance could vary at each run of that algorithm whereas a **deterministic search method** will always give the same solution given the same problem instance.

A **perturbative search algorithm** processes and returns a **complete solution** at all times, while a **constructive search algorithm** can process a partial solution returning a new **partial** or complete solution.

## Q4

In **continuous optimisation**, the variables used in the objective function are required to be chosen from a set of real values between which there are no gaps (values from intervals of the real line)

-   **True**
-   False 

## Q5

```java
long seed = 12345;
Random generator = new Random(seed);
double num;
for (int trial = 0; trial < 3; trial++) {
    num = generator.nextDouble();
}
System.out.println(num);
```

Given the code above and assuming that the seed `12345` produces the following sequence of double values in the given order

`<12.3, 75.489, 92.2, 6.8123, 1.234, 54.005, 72.01, ....>`

which value would be printed out at line number 8?

**Answer**: 92.2

## Q6

Which one of the following algorithms is an **exact method**?

-   a. Simulated Annealing
-   **b. Branch and Bound**
-   c. Genetic Algorithm
-   d. Tabu Search

## Q7

Choose the statement or statements that can be considered as a **drawback** of using heuristic search methods for optimisation in problem-solving. 

-   **a. There is no guarantee for the optimality of the obtained solutions.**
-   **b. Usually, they can be used only for solving the problem for which they are designed.**
-   **c. Many heuristic search methods have parameters and their performance can be sensitive to the settings of those parameters.**
-   d. They may result with a near-optimal solution.
-   **e. They may result with a poor solution.**

## Q8

A seed value will correspond to a specific sequence of generated values for a given random number generator.

-   **True**
-   False 
