# lec03: Rules for quick big-Oh proofs

## Multiplication Rule

-   Suppose 
    -   $f_1(n)$ is $O(g_1(n))$
    -   $f_2(n)$ is $O(g_2(n))$
-   Then by definition, $\exist \  c_1, c_2, n_1, n_2$ such that
    -   $\forall n \ge n_1, \ f_1(n) \le c_1 \cdot g_1(n)$
    -   $\forall n \ge n_2, \ f_2(n) \le c_2 \cdot g_2(n)$
-   Let $n_0 = \max (n_1, n_2)$, after multiplying we have 
    -   $\forall n \ge n_0, \ f_1(n) \cdot f_2(n) \le c_1 \cdot c_2 \cdot g_1(n) \cdot g_2(n)$
    -   Therefore $f_1(n) \cdot f_2(n)$ is $O(g_1(n)\cdot g_2(n))$

-   **Sanity checks**: unit tests for maths
-   Consider
    -   5 is $O(1)$
    -   $n$ is $O(n)$
    -   $5n$ is $O(n)$

## Drop Smaller Items

-   Consider $f(n) = 1 + h(n)$ with $\lim_{n \to \infin} h(n) \to 0$
-   Then $f(n)$ is $O(1)$

**Proof**

-   By definition of $h(n)$
    -   $\exist \ n_0, \ \forall n \ge n_0,  \ h(n) \le 1$
-   Therefore
    -   $\exist \ n_0, \ \forall n \ge n_0, \  f(n) \le 2$
    -   $f(n)$ is $O(1)$

## Exercise

-   **What is $O(n^2 + n)$**

    -   $f(n) = n^2 + n = n^2 \cdot (1 + 1/n)$

    -   $1 + 1/n$ is $O(1)$ by **drop small terms**

    -   $n^2$ is $O(n^2)$

    -   Then by **multiplication rule**, $f(n)$ is $O(n^2)$
-   What is $O(2^n + n^2)$
    -   $f(n) = 2^n \cdot (1 + n^2 / 2^n)$
    -   $n^2 / 2^n \to 0$
    -   Hence $f(n)$ is $O(2^n)$
-   What is $O(n\log n + n^2)$
    -   $f(n) = n^2 \cdot (\log n/n + 1)$
    -   $\log n / n \to 0$ so can drop it
    -   Hence $f(n)$ is $O(n^2)$

## Big-Oh Conventions

**Conventions**

-   Use the smallest reasonable class of functions
    -   Say $2n$ is $O(n)$ instead of $2n$ is $O(n^2)$
-   Use the simplest expression of the class
    -   Say $2n$ is $O(n)$ instead of $2n$ is $O(2n)$

**Usage of Big-Oh in practice**

-   For any $f(n)$ that $f(n)$ is $O(f(n))$, but it's inappropriate
-   If asked for the ‘**big-Oh**’ then want the ‘**tightest nice function**'


### Exercise

-   Consider $f(n) = 2^{n/100} + n^{200}$
-   $f(n) = 2^{n/100} * (1 + n^{200}/2^{n/100}) $ therefore $O(2^{n/100})$
-   $n^{200}/2^{n/100} \to 0$  so we can drop it

## Big-Oh as a "Set"

-   Think $O(n)$ as the set of all functions whose growth is no worse than linear for sufficiently large n
-   Hence it can be thought of as the infinite set

$$
\{ 1,2, \dots, \log n, \dots, n, 2n, \dots, n+1, n+2, \dots \}
$$

## Big-Oh: Usage for Algorithms

-   Worst case runtime, $w(n)$
-   Best case runtime, $b(n)$
-   Average case runtime, $b(n)$
-   **Quick sort**
    -   worst case: $O(n^2)$
    -   average case: $O(n \log n)$
-   **Merge sort**
    -   worst case: $O(n \log n)$

**Asymptotic Algorithm Analysis in practice**

-   **The asymptotic analysis of an algorithm determines the running time in big-Oh notation**
-   To perform the asymptotic analysis
    -   We find the (worst-case, etc.) **number of primitive operations** executed as a function of the input size
    -   We express this function with **big-Oh notation**
-   Example:
    -   We determine that algorithm `arrayMax` executes at most $8n + 3$ primitive operations
    -   We say that algorithm `arrayMax` “runs in $O(n)$ time”









