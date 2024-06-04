# lec02: Introduction to big-Oh

## Classification of Functions

-   CS needs a way to group together **functions** by their scaling behaviour, and the classification should
    -   Remove unnecessary details
    -   Be (relatively) quick and easy
    -   Handle ‘weird’ functions that can happen for runtimes
    -   Still be mathematically well-defined
-   Big-Oh notation and family:
    -   $O$ (big-oh)
    -   $\Omega$ (big-omega)
    -   $\Theta$ (big-theta)
    -   $o$ (little-oh)
    -   $\omega$ (little-omega)

**Advanced uses of Big-Oh family**

-   Stirling's approximation:

$$
\ln(n!) = n \ln n- n+ O(\ln n)
$$

-   Polynomial functions are $n^{O(1)}$
-   The best case of algorithm X is $O(n \log n)$

## Big-Oh Notation: Motivations

**Important Comments**

-   At this point we are just talking about functions `f(n)` of a single parameter `n`
-   Big-Oh is often applied to runtimes, but this is not essential
    -   The big-oh definitions are just in terms of functions
    -   It is not only for worst case runtime
    -   But the big-oh definition should be designed to be suitable for discussion of runtime functions

**Suppose we have two functions `4n + 5`, `3n - 6`**

-   One way to motivate definitions is to look at their ratio
-   We have the following

$$
(4 n + 5) \le 1.5 * (3n-6), \quad n\ge 28
$$

-   Therefore we could say $(4n+5)$ is $O(3n-6)$
    -   with `c = 1.5` and `n0 = 28`

## Big-Oh Notation: Definitions

**Given positive functions $f(n)$ and $g(n)$, we say**
$$
f(n) \ \text{is} \ O(g(n) \ \Leftrightarrow  \  \exist\ c > 0, \exist \ n_0, \  \text{such that} \ \forall n \ge n_0, \ f(n) \le c \cdot g(n)
$$

-   Big Oh is intended to functions of **positive integers** (size), and that are **positive real values** because they often represent runtimes:
    -   $f : \mathbb{N}^{+} \to \mathbb{R}^{+}$
    -   That is to assume, $\forall n \ge 1, \ f(n)\ge 0$
    -   Or  $\forall n \ge N, \ f(n)\ge 0$ for some constant `N`
-   The definition doesn't mention **worst case of an algorithm**, and it doesn't even mention **algorithm**
-   It only mentions **functions**
-   **It means $f$ grows no faster than $g$ at large enough $n$**

## Exercise

-   Show that function $f(n) = 1$ is $O(1)$
    -   Pick `c = 1`, `n0 = 1`
    -   $\forall n \ge 1, \ 1 \le 1$
-   Show that function $f(n) = 2$ is $O(1)$
    -   Pick `c = 2`, `n0 = 1`
    -   $\forall n \ge 1, \ 2 \le 2$
-   Show that function $f(n) = k$ is $O(1)$
    -   Pick `c = max(k,1)`, `n0 = 1`
    -   $\forall n \ge 1, \ k \le max(k,1)$
-   Show that function $f(n) = 1$ is $O(n)$
    -   Pick `c = 1`, `n0 = 1`
    -   $\forall n \ge 1, \ 1 \le n$
-   Show that function $f(n) = k$ is $O(n)$ for any `k ≥ 0`
    -   Pick `c = 1`, `n0 = k`
    -   $\forall n \ge k, \ k \le n$
-   Show that function $f(n) = k\cdot n$ is $O(n)$ for any `k ≥ 0`
    -   Pick `c = k`, `n0 = 1`
    -   $\forall n \ge 1, \ k \cdot n \le k \cdot n$
-   Show that function $f(n) = n + k$ is $O(n)$ for any `k ≥ 0`
    -   Pick `c = 2`, `n0 = k`
    -   $\forall n \ge k, \ n + k \le 2 n$
-   Show that function $f(n) = n$ is **NOT**  $O(1)$
    -   Assume $P(n)$, then we could pick `c, n0` such that
    -   $n \le c, \ \forall n \ge n_0$
    -   But we could not pick `c = infinity`, hence it is false
-   Consider the function: 
    $f(n)=n$ if n is **even** , $f(n) = 1$ if n is **odd**
    -   Pick `c = 1, n0 = 1`
    -   $\forall n \ge 1, \ n \le n \ \and \ 1 \le n$
    -   **Depite two cases, the definition requires to provide one `c` and one `n0`**


### Ratios vs. big-Oh

Consider the function:  $f(n)=n$ if n is **even**, $f(n) = 1$ if n is **odd**

-   It does NOT have a limiting ratio since
    -   $f(n)/n = 1$ if n is **even**, limit is 1
    -   $f(n)/n = 1/n$ if n is **odd**, limit is 0
-   **Conclusions**
    -   $f(n)$ can be $O(g(n))$ even if the ratio $f(n)/g(n)$ **does not exist**
    -   Hence, big-Oh can be used in situations that ratios cannot, 
    -   big-Oh is more **suitable** than ratios for doing analysis of efficiency of programs

### Some Details

Consider $(3n - 6)$ is $O(n)$

-   $f(n) = 3n-6$ is not always positive, and is only negative on a finite number of values
-   **Two ways**
    -   consider $f(n) = \max (0, 3n-6)$
    -   or just require that $n_0$ is taken large enough that $f(n)$ is positive

## Big-Oh as a binary relation

-   $f$ is $O(g)$ can be regarded as a binary relation between two functions $f$ and $g$
    -   written as $O(f,g)$ 
-   Generally, binary relations R could have properties as **Reflexive**, **Symmetric**, **Transitive**

**Big-Oh is reflexive**

For any functions, $f(n)$ is $O(f(n))$

-   Take `c = 1`, for any `n`, $f(n) \le f(n)$

**Big-Oh is not symmetric**

-   Take one **counter-example**
-   1 is $O(n)$ but n is $O(1)$

**Big-Oh is transitive**

>   **By meaning**, if $f$ grows no faster than $g$ at some $n_1$, and $g$ grows no faster than $h$ at some $n_2$, then for $\max (n_1, n_2)$, $f$ grows no faster than $h$

**By definition**

-   $\exist \ c_1, c_2, n_1, n_2$ such that
    -   $\forall n \ge n_1, \  f(n) \le c_1 \cdot g(n)$
    -   $\forall n \ge n_2, \  g(n) \le c_2 \cdot h(n)$
-   Mult 2nd inequality by $c_1$,
    -   $\forall n \ge n_2, \ c_1 \cdot g(n) \le c_1 \cdot c_2 \cdot h(n)$ 
-   Therefore, we take $n_0 = \max(n_1, n_2)$, $c_0 = c_1 \cdot c_2$
    -   $\forall n \ge n_0, \ f(n) \le c_1 \cdot g(n) \le c_1 \cdot c_2 \cdot h(n) = c_0 \cdot h(n)$ 

## Big-Oh as a set

-   Big Oh as a binary relation is **reflexive** and **transitive** but not **symmetric**
    -   It behaves like $\in, \subseteq, \le$, not like $=$
-   Consider $O(n)$ as a set of functions, with each function $f$ in the set $f \in O(n)$
-   Consider the expression $n^{O(1)}$
    -   including $n, n^2, n^3$

