# lec05: Rules for little-oh proofs and other advanced usages

## Multiplication Rule

### Example 1

-   $a, b, c > 0, \ a < b \to ac < bc $
-   Suppose $h(n)$ is **strictly positive**, and $f(n)$ is $o(g(n))$
-   By multiplication rule, we have
    -   $\forall c>0 , \exist n_0, \ h(n) \cdot f(n) \lt c \cdot h(n) \cdot g(n), \forall n \ge n_0$
-   which is $h(n)f(n)$ is $o(h(n)g(n))$

### Example 2

-   $a,b,c,d > 0, \ a\le b \and  \ c < d \to ac < bd$
-   Suppose $f_1(n)$ is $O(g_1(n))$ and $f_2(n)$ is $O(g_2(n))$ 
-   From definition, we have
    -   $\exist c_1 >0, \exist n_1, \ f_1(n) \le c_1 \cdot g_1(n), \ \forall n \ge n_1$
    -   $\forall c_2 >0, \exist n_2, \ f_2(n) < c_2 \cdot g_2(n), \ \forall n \ge n_2$

$$
\exist c_1 > 0, \forall c_2 >0, \exist n_1, n_2, n_0 = \max(n_1, n_2)\\ f_1(n)f_2(n) < c_1 c_2 \cdot g_1(n)g_2(n), \ \forall n \ge n_0
$$

-   Hence $f_1(n) f_2(n)$ is $o(g_1(n)g_2(n))$

## Advanced Usages

$$
\{ n^{f(n)} | f(n) \ \text{is} \ O(1)  \}
$$

-   $n^{O(1)}$ includes $n, n^2,n^3, \dots$

$1-o(1)$ would mean a set of functions
$$
\{ 1-f(n) | f(n) \ \text{is} \ o(1) \and f(n) >0  \}
$$

-   Hence

$$
\forall c > 0, \exist n_0, \forall n \ge n_0, 0\le f(n) < c
$$

-   That is
    -   However small we pick `c`, then eventually $f(n)$ becomes and stays smaller than `c`
-   $o(1)$ has the same meaning as

$$
\lim_{n\to \infin} f(n) \to 0
$$







