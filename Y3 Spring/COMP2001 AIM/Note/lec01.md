# lec01: Introduction

[toc]

## Part 1: Preliminaries

**Definition: Decision Support Systems**

-   **Degree of dependence** of systems on the environment
    -   Closed systems are totally independent
    -   Open systems dependent on their environment
-   Evaluation of systems
    -   System effectiveness: the degree to which goals are achieved, i.e. result, output
    -   System efficiency: a measure of the use of inputs to achieve output, e.g. speed

-   **Search for paths to goals**
    -   efficiently finding a set of actions that will move from a given initial state to a given goal 

    -   central to many AI problems (e.g., game playing, path finding) 

    -   typical algorithms are the DFS, BFS, UCS, A*, branch and bound

-   **Search for solutions (optimisation)** 
    -   more general class than searching for paths to goals. 
    -   efficiently finding a solution to a problem in a large space of candidate solutions
    -   **subsumes the first type**, since a path through a search tree can be encoded as a candidate solution

**Soving a Single Objective Optimisation Problem**

-   Solving a mathematical optimisation problem:
-   First choose a quantity to be maximised or minimised, which might be subject to one or more constraints
-   Next choose a mathematical or search method to solve the optimisation problem
    -   $z = f(X), \{g_{i}(X) \le b_{i} \} (=|\ge)$
    -   where X is vector of variables $<x_1, x_2, \dots, x_n>$

**Global vs Local Optimum**

-   **Global Optimum**: better than all other solutions (best)
-   **Local Optimum**: better than all solutions in a certain neighbourhood, N

<img src="assets/Screenshot 2024-01-30 at 09.51.56.png" alt="Screenshot 2024-01-30 at 09.51.56" style="zoom:50%;" />

**Search in Continuous vs. Discrete Space**

<img src="assets/Screenshot 2024-03-05 at 01.18.51.png" alt="Screenshot 2024-03-05 at 01.18.51" style="zoom:50%;" />

**Problem and Problem Instance**

-   **Problem** refers to **the high level question** or **optimisation issue** to be solved.
-   **An instance of this problem is the concrete expression**, which represents the input for a decision or optimisation problem.
-   Example: Optimal assignment of groups to busses (minimising the number of busses) is an **optimisation (minimisation) problem** 
    -   Optimal assignment of 3 groups of 10, 15, 43 to busses, each with 45 seats and company having 10 busses at max is an instance of this problem
    -   Optimal assignment of 5 groups of 19, 25, 30, 30, 45 to busses, each with 60 seats and company having 10 busses at max is another instance of this problem

**Problem Classes**

>   **NP**是“非确定性多项式时间”的缩写（Non-deterministic Polynomial-time）。如果一个问题是NP问题，那么一旦给出一个解，我们就能在多项式时间内（相对于输入大小）验证这个解是否正确。
>
>   **NP完全问题**是指那些**既属于NP类**，又能被所有其他NP问题多项式时间归约到它的问题，它们被认为是最难解决的NP问题。

<img src="assets/Screenshot 2024-03-05 at 01.22.48.png" alt="Screenshot 2024-03-05 at 01.22.48" style="zoom:50%;" />

**Combinatorial Optimisation Problems**

-   Require finding an optimal object from a finite set of objects 

**Optimisation/Search Methods**

-   Exact/Exhaustive/Systematic Methods

    -   Examples
        -   Dynamic Programming
        -   Branch&Bound
        -   Constraint Satisfaction
        -   Math Programming: ILP, MILP

    -   **Limitations:**
        -   Only work if the problem is structured – in many cases for small problem instances
        -   Quite often used to solve sub-problems

-   Inexact/Approximate/Local Search Methods
    -   Heuristics, metaheuristics, hyper-heuristics

**Search Paradigms**

-   **Single point** based search vs. **Multi-point** based search
-   **Perturbative**: complete solutions
-   **Constructive**: partial solutions

-   Single point-based search
    -   Mutational Search
    -   Local Search (HC, SA, Tabu Search, ...)

<img src="assets/Screenshot 2024-03-05 at 01.38.29.png" alt="Screenshot 2024-03-05 at 01.38.29" style="zoom:50%;" />

## Part 2: Heuristic Search/Optimisation

>   A **heuristic** is a rule of thumb method derived from human intuition.

-   A heuristic is a **problem dependent search method** which seeks good, i.e. near-optimal solutions, at a reasonable cost (e.g. speed) without being able to guarantee optimality
-   Good for solving **ill-structured problems**, or complex well-structured problems (large-scale combinatorial problems that have many potential solutions to explore)

### Example 1: Bin Packing Problem

<img src="assets/Screenshot 2024-02-28 at 22.55.37.png" alt="Screenshot 2024-02-28 at 22.55.37" style="zoom:50%;" />

-   **Largest item first fit** (A Deterministic Greedy Constructive Heuristic Algorithm)
    -   Sort the items by its size in decreasing order
    -   place each item into the **first bin** that will accommodate that objec

### Example 2: Traveling Salesman Problem (TSP)

-   Given a list of cities and the distances between each pair of cities, what is the **shortest possible route** that visits each city and returns to the origin city
-   Heuristics for TSP
    -   **The nearest neighbour algorithm (NN)**: Constructive
    -   **Pairwise exchange (2-opt)**: Perturbative
-   **NN heuristic** 
    -   Select a starting city randomly
    -   choose the nearest unvisited city as the next move
    -   After the choice of the last city, algorithm terminates
    
-   **NN algorithm**
    -   Choose a random city
    -   Apply nearest neighbour to construct a complete solution 
    -   Compare the new solution to the best found so far and update the best solution as appropriate
    -   Go-to Step 1 and repeat while the maximum number of iterations is not exceeded (parameter)
    -   Return the best solution
-   **Pairwise exchange** (perturbative stochastic local search algorithm)
    -   Create a **random current solution** (build a permutation array and shuffle its content) 
    -   Apply 2-opt: **swap two randomly** chosen cities forming a new solution 
    -   Compare the new solution to the current solution and if there is improvement make the new solution current solution, otherwise continue 
    -   Go-to Step 2 and repeat while the maximum number of iterations is not exceeded (parameter) 
    -   Return the current solution

**Drawbacks of Heuristic Search**

-   **no guarantee for the optimality** of the obtained solutions.
    -   may give a poor solution
-   usually can be used only for the specific situation for which they are designed.
-   heuristics have some parameters

## Part 3: Pseudo-random numbers

**Deterministic vs. Stochastic Heuristic Search**（确定性/随机性启发式搜索）

-   **Deterministic heuristic search algorithms** provide **the same solution** when run on the given problem instance **regardless of how many times**
-   **Stochastic algorithms** contain a random component and may return **a different solution at each time** they are run on the same instance
    -   **Multiple trials**/runs should be performed for the experiments/simulations
    -   Being able to repeat/replicate those multiple trials/runs in the experiments/simulations is crucial in science, and
    -   This also enables average performance comparison of different stochastic heuristic search algorithms applying **statistical tests**

**Pseudo-random numbers**

-   A **long sequence of numbers** that is produced using a **deterministic process** but which appear to be random
-   Note that most computers and programming languages have support to produce **pseudo-random numbers**, and often with seeding
    -   E.g, assume a pseudo-random number generator producing values with lower limit: `0.00`, upper limit: `1.00`
    -   `seed(12345): <0.19, 0.03, 0.87, 0.54, …> `
    -   `seed(4927): <0.48, 0.91, 0.02, 0.26, …>`

**Some problems with pseudo-random numbers**

-   Shorter than expected periods for **some seed states**; such seed states may be called **'weak'** in this context


<img src="assets/Screenshot 2024-02-28 at 23.35.12.png" alt="Screenshot 2024-02-28 at 23.35.12" style="zoom:50%;" />

-   **Lack of uniformity of distribution**. 
    -   E.g., 0.17 appears 100 times in 10000 successive numbers while 0.29 appears 5 times more 
-   Correlation of successive values
-   The distances between where certain values occur are distributed differently from those in a random sequence distribution

### Example: Middle Square Method

-   An early random number generator by John Von Neumann
-   To generate a sequence of n-digit pseudo random numbers
-   **Steps**
    -   Start with an initial value (seed) `2156`
    -   Take its square `2156^2 = 4648336`
    -   Middle digits are used as a random number `6483`
    -   Then repeat this process
-   **Problem**: all sequence eventually repeat themselves



**Note the difference - Exercise 1**

-   Always the **same value** for “num” is printed out for each trial

```java
for (int trial = 0; trial < 5; trial++) {
    long seed = 123456789;
    Random generator = new Random(seed);
    double num = generator.nextDouble();
    System.out.print(num + " ");
}
// 0.664 0.664 0.664 0.664 0.664 
```



**Note the difference - Exercise 2**

-   The value for “num” changes at each trial/run (iteration).
-   **Experiments cannot be replicated**: different results (print-outs) at each time

```java
for (int trial = 0; trial < 5; trial++) {
    long seed = System.currentTimeMillis();
    Random generator = new Random(seed);
    double num = generator.nextDouble();
    System.out.print(num + ' ');
}
```



**Note the difference - Exercise 3**

-   The value for “num” changes at each trial/run (iteration).
-   **Experiment can be replicated: same results (print-outs) at each time**

```java
long seed = 123456789;
Random generator = new Random(seed);
for (int trial = 0; trial < 5; trial++) {
    double num = generator.nextDouble();
    System.out.print(num + ' ');
}
```



**Note the difference - Exercise 4**

-   The value for “num” changes at each trial/run (iteration).
-   Experiment can be replicated: same results (print-outs) at each time

```java
long[] seed = {123456, 789000, 323241, 5523525, 2432342};
Random generator = new Random(seed);
for (int trial = 0; trial < 5; trial++) {
    double num = generator.nextDouble(seed[i]);
    System.out.print(num + ' ');
}
```

