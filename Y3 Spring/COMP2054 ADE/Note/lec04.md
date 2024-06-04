# lec04: The Big-Oh family

## Relatives of Big-Oh

-   $O$ (big-oh)
-   $\Omega$ (big-omega)
-   $\Theta$ (big-theta)
-   $o$ (little-oh)
-   $\omega$ (little-omega)

## Big-Omega

### Definitions

Given functions $f(n)$ and $g(n)$, we say
$$
f(n) \ \text{is} \ \Omega(g(n) \ \Leftrightarrow  \  \exist\ c > 0, \exist \ n_0, \  \text{such that} \ \forall n \ge n_0, \ f(n) \ge c \cdot g(n)
$$

>   It says that $f(n)$ grows at least as fast as $g(n)$ at large n

### Exercises

-   Show $n$ is $\Omega (n)$
    -   need to prove $n \ge c \cdot n, \ \forall n\ge n_0$
    -   Take $c = 1$then $n \ge n, \ \forall n\ge 1$
    -   Take $n_0 = 1$
-   Show $n^2$ is $\Omega (n)$
    -   need to prove $n^2 \ge c \cdot n, \ \forall n\ge n_0$
    -   Take $c = 1$ then $n \ge 1, \ \forall n \ge n_0$
    -   Take $n_0 = 1$
-   Show $n^3 - n$ is $\Omega (n^3)$
    -   need to prove $n^3 - n \ge c \cdot n^3, \ \forall n\ge n_0$
    -   Take $c = 0.5$ then $n^2 \ge 2, \ \forall n \ge n_0$
    -   Take $n_0 = 2$ 
-   Disprove $1$ is $\Omega (n)$
    -   need to prove $1 \ge c \cdot n, \ \forall n\ge n_0$
    -   $1/c \ge n, \ \forall n \ge n_0$
    -   It fails sinc eventually $n > 1/c$

### Big-Omega properties

-   Reflextive
-   NOT Symmetric
-   Transitive

### Big-Oh vs. Big-Omega

-   Given $f$ is $O(g)$, we have
    -   $\forall n\ge n_0, \ f(n) \le c \cdot g(n) \Rightarrow g(n) \ge (1/c)\cdot f(n) $
    -   Hence $g$ is $\Omega (f)$
-   $f \in O(g) \to g \in \Omega(f)$
-   $f \in \Omega(g) \to g \in O(f)$
-   Similar to: $x \le y \to y \ge x$

### Usage of Big-Omega

-   Same rules apply
    -   **Multiplication rule**
    -   **Drop smaller iterms** (might be counter-intuitive)
-   A standard usage might be to capture a limitation on the best one can hope for

## Big-Theta

### Definition

Given functions $f(n)$ and $g(n)$, we say
$$
f(n) \ \text{is} \ \Theta(g(n) \ \Leftrightarrow  \  \exist\ c' > 0, \exist c'' \gt 0,  \exist \ n_0, \  \text{such that}\\ \ \forall n \ge n_0, \ f(n) \le c' \cdot g(n) \ \and \ f(n) \ge c'' \cdot g(n)
$$

-   $f$ is $\Theta(g)$ **iff** $f$ is $O(g)$ and $f$ is $\Omega (g)$
-   $\Theta$ expresses **grows exactly as fast as**

### Properties

-   Reflexive
-   Symmetric
-   Transitive
-   **An equivalence relation** (like an equality)
    -   $\Theta(g(n))$ is the equivalence class of all functions whose large `n` behaviour is bounded above and below by constants times $g(n)$

## Litlle-Oh

### Definition

Given functions $f(n)$ and $g(n)$, we say

$$
f(n) \ \text{is} \ o(g(n) \ \Leftrightarrow  \  \forall c > 0, \exist  n_0, \  \text{such that} \ \forall n \ge n_0, \ f(n) \lt c \cdot g(n)
$$

-   Asymptotically **strictly less than**
-   If $f(n)$ is $o(g(n))$ then $f(n) \ \text{is} \ O(g(n))$

### Usage of rules

-   **Mutiplication**
-   **Drop smaller terms**

## Little-Omega

-   **NOT Required**
-   Asymptotically **strictly greater**
-   Rarely used in CS

## Other definitions of Big-Oh

Here we define $O_\le$ and $O_<$ as
$$
f(n) \ \text{is} \ O_<(g(n) \ \Leftrightarrow  \  \exist c > 0, \exist  n_0, \  \text{such that} \ \forall n \ge n_0, \ f(n) \lt c \cdot g(n)
$$

$$
f(n) \ \text{is} \ O_\le(g(n) \ \Leftrightarrow  \  \exist c > 0, \exist  n_0, \  \text{such that} \ \forall n \ge n_0, \ f(n) \le c \cdot g(n)
$$

When $g(n) > 0$, we can prove
$$
f(n) \ \text{is} \ O_<(g(n)) \Leftrightarrow f(n) \ \text{is} \ O_\le(g(n))
$$

-   **除非 $g(n)>0$，不然 < 和 ≤ 没区别**

Similarly, when $g(n) > 0$, we can prove

$$
f(n) \ \text{is} \ o_<(g(n)) \Leftrightarrow f(n) \ \text{is} \ o_\le(g(n))
$$





