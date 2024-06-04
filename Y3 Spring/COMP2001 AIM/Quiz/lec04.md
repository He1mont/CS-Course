# Quiz-lec04

## Q1

**Parameter tuning** techniques are used for detecting the best initial parameter settings of an optimisation algorithm in an offline manner, while **parameter control** techniques operate during the search process in an online manner.

## Q2

Is the following statement TRUE or FALSE?

The geometric cooling schedule in Simulated Annealing is used to cool the temperature parameter *T* used within the **Boltzmann probability** equation using the formula $T = \alpha \cdot T$

-   **a. TRUE**
-   b. FALSE

## Q3

All parameters of the local search metaheuristics, Simulated Annealing with Lundy Mees cooling schedule and  Iterated Local Search using Steepest Descent for hill climbing and random bit flip for perturbation are both tuned using the Taguchi method for solving the MAX-SAT problem. 

Which one of the following statements on the performance comparison of Simulated Annealing and Iterated Local Search is more likely to be correct? 

-   a. Iterated Local Search would perform better than Simulated Annealing for MAX-SAT
-   b. Both metaheuristics would perform the same for MAX-SAT
-   **c. No performance comparison can be done based on the given information.**
-   d. Simulated Annealing would perform better than Iterated Local Search for MAX-SAT

## Q4

What happens as the temperature parameter *T* used within the **Boltzmann probability** equation in Simulated Annealing **decreases**?

-   a. The probability of accepting worsening solutions becomes higher than the probability of accepting improving solutions
-   **b. The probability of accepting worsening solutions decreases**
-   c. The probability of accepting worsening solutions increases
-   d. The probability of accepting worsening solutions does not change

### Explanation

$$
T \downarrow \Rightarrow \ \frac{\triangle}{T} \uparrow (\triangle > 0)
\Rightarrow - \frac{\triangle}{T} \downarrow \Rightarrow e^{\frac{-\triangle}{T}} \downarrow
$$



## Q5

Is the following statement TRUE or FALSE?

The parameters of the Simulated Annealing metaheuristic using the Luny Mees cooling schedule include only *β* and initial temperature (*T*0).

-   a. TRUE
-   **b. FALSE**

### Explanation

3 parameters: `T0, T_final, beta` 

## Q6

A move acceptance method with no parameters is a **static** method. 

Great deluge is a **dynamic** move acceptance method. 

You have merged great deluge and extended great deluge creating a group decision-making move acceptance method that is **adaptive**. This method accepts a new solution if the great deluge **and** extended great deluge both return true (accept the new solution) at a given step, otherwise, the new solution is rejected. 

## Q7

Is the following statement TRUE or FALSE?

Simulated Annealing is a non-stochastic threshold move acceptance method.

-   a. TRUE
-   **b. FALSE**
