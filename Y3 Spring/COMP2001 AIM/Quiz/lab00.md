# Quiz-lab00

## Q1

What does SAT stand for (in the context of Lab#0)?

-   a. Static Air Problem
-   b. Scholastic Assessment Problem
-   c. Science and Technology Problem
-   **d. Satisfiability Problem**

## Q2

Performing multiple trials using the same seed leads to the objective value of the best solution found for each trial to be the same.

-   **True** 
-   False

## Q3

Choose from the following observations that are/is **incorrect**, assuming that a user performs multiple trials using different seeds in an experiment using the code in Lab#0. 

-   a. Different seeds means that a different sequence of numbers/Booleans are produced by the pseudo-random number generator while creating new solutions in the code.
-   b. Different seeds implies there is a high chance that the initial solutions generated randomly are different.
-   c. Objective value of the best solution found for each trial can be different.
-   **d. Objective value of the best solution found for each trial are different.**

## Q4

The experimental seeds are of no importance for the reproducibility of the experiments.

-   True
-   **False** 

## Q5

```java
long seed = 123456; 
Random generator = new Random(seed); 
double num;
for (int trial=0; trial<4; trial++) {
	num = generator.nextDouble() ; 
}
System.out.print(num);
```

Given the code above and assuming that the seed 123456 produces the following sequence of double values in the given order

`<0.3, 0.489, 0.2, 0.123, 0.234, 0.005, 0.01, ....>`

which value would be printed out at line number 7?

-   a. 0.3
-   **b. 0.123**
-   c. 92.2
-   d. 0.234

