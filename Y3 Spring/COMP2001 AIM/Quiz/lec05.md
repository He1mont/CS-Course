# Quiz-lec05

## Q1

Which of the following evolutionary algorithms is used for evolving computer programs? 

-   a. Evolutionary Programming
-   b. Evolution Strategies
-   **c. Genetic Programming**
-   d. Genetic Algorithms

##  Q2

Is the following statement TRUE or FALSE?

Memetic Algorithms are iterative single-point based search methods.

-   a. TRUE
-   **b. FALSE**

## Q3

Choose the benchmark functions below for which **delta/incremental evaluation** can be utilised.

-   a. $f(x) = f(x_1, \dots, x_n) = \sum_{i=1}^{n} ix_i^2$​
-   b. $f(x) = f(x_1, \dots, x_n) = 1 + \sum_{i=1}^{n} \frac{x_i^2}{4000} - \Pi^{n}_{i=1}\cos(\frac{x_i}{\sqrt{i}})$
-   c. $f(x) = f(x_1, \dots, x_n) = \frac{1}{2} \sum_{i=1}^{n}(x_i^4-16x_i^2 + 5x_i)$
-   d. $f(x) = f(x_1, \dots, x_n) = 10n+\sum_{i=1}^{n} (x_i^2-10\cos(2\pi x_i))$

**Ans: all of the above**

## Q4

Is the following statement TRUE or FALSE?

**Hill climbing/local search** cannot be applied to parents and offpring, before crossover and after mutation, respectively, in a memetic algorithm.

-   a. TRUE
-   **b. FALSE**

## Q5

Which one of the following is a reason why benchmark functions are used for performance comparison of search/optimisation algorithms?

-   a. The benchmark functions always allow delta/incremental evaluation
-   b. The benchmark functions are difficult to implement
-   c. The benchmark functions have similar characteristics
-   **d. The global optimum is usually known for the benchmark functions**

## Q6

A generic memetic algorithm is applied to an instance of the MAX-SAT problem. What is likely to happen at the end of the search process if all individuals in the population of size 20 get replaced with the newly produced 20 offspring at every generation?

-   **a. The best solution might be lost.**
-   b. The worst solution when achieved persists until to the end.
-   c. The best solution when achieved persists until to the end.
-   d. The optimal/perfect solution can be found much faster.

## Q7

A generic trans-generational memetic algorithm is applied to an instance of the MAX-SAT problem. Assume that binary encoding for the representation, generic one-point crossover, mutation, Davis's bit hill-climbing, elitist replacement and **tournament parent selection** methods are utilised while the **population size** is fixed as `5`. The tournament selection operator **allows the same individual** to be selected as parents that will undergo crossover.

What would happen if the tour size for the parent selection is set to `5`?

Choose from the following answers which apply.

-   **a. The best individual in the population will always be selected for crossover**
-   b. The second best individual in the population never has a chance to be selected for crossover
-   c. No new solutions will be introduced as the search progresses from one generation to another
-   **d. The newly generated two solutions (children) produced after crossover will be the same**

## Q8

Genetic Algorithms simulate natural evolution based on the concept of **survival of the fittest** via processes of selection, **mutation**, and reproduction. In GA, a collection of individuals currently “alive”, called **population** is evolved from one **generation** to another depending on the fitness of individuals in a given environment.

## Q9

Is the following statement TRUE or FALSE?

A memetic algorithm extends a genetic algorithm using hill climbing/local search.

-   **a. TRUE**
-   b. FALSE