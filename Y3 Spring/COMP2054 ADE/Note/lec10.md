# lec10: Recurrence Relations

## Recurrence Relations

-   A recurrence relation is a **recursively-defined** function

    -   But, generally, applied to the case when the function is some measure of resources …
    -   and we might only **want the big-Oh family properties** of the solution
-   Suppose that the **runtime** of a program is `T(n)`, then a recurrence relation will express `T(n)` in terms of its values at other (smaller) values of `n`.

## Example: Merge Sort

- Suppose the runtime of merge-sort of an array of `n` integers is `T(n)`, then

$$
T(n) = 2 T(n/2) + b + a \cdot n
$$

- `2 T(n/2)`: sort the two sub-arrays each of size `n/2`
- `b`: the cost of doing the split
- `a n`: the cost of doing the merge
- $T(1) = 1$​
- $T(9) = T(4) + T(5)$

### Example 1

-   $\Theta (n)$

$$
T(n) = 2 \cdot T(n/2), T(1) = 1, \ \text{show that:} \ \forall k \in N, T(2^k) = 2^k
$$

<img src="assets/Screenshot 2024-02-28 at 17.36.19.png" alt="Screenshot 2024-02-28 at 17.36.19" style="zoom: 33%;" />

### Example 2

-   $\Theta(n)$

$$
T(n) = 2 \cdot T(n/2) + b, T(1) = 1, \ \text{show that:} \ \forall k \in N, T(2^k) = 2^k + (2^k -1)\cdot b
$$

<img src="assets/Screenshot 2024-02-28 at 17.38.02.png" alt="Screenshot 2024-02-28 at 17.38.02" style="zoom: 33%;" />

### Example 3

-   $\Theta(n \log n)$

$$
T(n) = 2 \cdot T(n/2) + a\cdot n, T(1) = 1, \ \text{show that:} \ \forall k \in N, T(2^k) = 2^k \cdot ( 1+ k \cdot a)
$$

<img src="assets/Screenshot 2024-02-28 at 17.39.12.png" alt="Screenshot 2024-02-28 at 17.39.12" style="zoom:33%;" />

### Example 4

-   $\Theta(n^2)$

$$
T(n) = 4 \cdot T(n/2), T(1) = 1, \ \text{show that:} \ \forall k \in N, T(2^k) = (2^k)^2
$$

<img src="assets/Screenshot 2024-02-28 at 17.42.11.png" alt="Screenshot 2024-02-28 at 17.42.11" style="zoom: 33%;" />

### Example 5

-   $\Theta(n^2)$

$$
T(n) = 4 \cdot T(n/2) + d \cdot n, T(1) = 1, \ \text{show that:} \ T(n) = n^2 + n \cdot (n-1) \cdot d
$$

### Example 6

-   $\Theta(\log n)$​
-   Binary search of a sorted array

$$
T(n) = T(n/2) + d, \ T(1) = 1 \ \text{show that:} \ T(n) = 1 + d \cdot \log_2(n)
$$

### Example 7

-   $\Theta(n^2)$

$$
T(n) = T(n/2) + d, \ T(1) = 1 \ \text{show that:} \ T(n) = 1 + (n(n+1)/2-1)\cdot d
$$

## Solving Recurrence

**General pattern**

-   Starting from the base case, use the recurrence to work out many cases, by directly substituting and working upwards in values of n
-   Inspect the results, look for a pattern and make a hypothesis for the general results
-   Attemp to prove the hypothesis - typically using some form of induction











