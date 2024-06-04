# lec09: Advanced Topics

[toc]

## Policy Matrix Evolution for Generation of Heuristics

### Bin Packing

**1D Offline Bin Packing**

-   Pack a set of items of sizes $s_i$ for i =1,…, n
    -   Sizes are integer values and $s_i \in [1,C]$ 
    -   C is the fixed capacity of each bin
-   In such a way that
    -   Never exceed bin capacity 
    -   Minimise number of bins used

**1D Online Bin Packing**

-   Pack a stream of items of sizes $s_i$ for i =1,…
    -   Sizes are integer values and $s_i \in [1,C]$
    -   C is the fixed capacity of each bin upon their arrival (one item at a time)
-   in such a way that
    -   Never exceed bin capacity 
    -   Minimise number of bins used (Maximise the average binfullness) at the end

>   **1D Offline Bin Packing**
>
>   假设有以下物品：4, 8, 1, 4, 2, 1。箱子容量 C=10*C*=10。
>
>   1.  先将所有物品排序（可以根据算法选择，比如降序）：8, 4, 4, 2, 1, 1。
>   2.  开始放置物品：
>       -   第一个箱子：放8。
>       -   第二个箱子：放4，再放4（剩余2）。
>       -   第三个箱子：放2，再放1，再放1。
>
>   **1D Online Bin Packing**
>
>   假设有以下物品按顺序到达：4, 8, 1, 4, 2, 1。箱子容量 C=10*C*=10。
>
>   1.  处理第一个物品4，放入第一个箱子。
>   2.  处理第二个物品8，放入第二个箱子。
>   3.  处理第三个物品1，放入第一个箱子（剩余5）。
>   4.  处理第四个物品4，放入第一个箱子（剩余1）。
>   5.  处理第五个物品2，放入第三个箱子。
>   6.  处理第六个物品1，放入第一个箱子（已满）。
>
>   -   **Offline Bin Packing** 可以利用所有物品的全局信息进行优化，通常能得到更好的结果。
>   -   **Online Bin Packing** 必须在每个物品到达时立即做出决策，策略的选择对最终结果影响很大。

**Standard Heuristic: First-fit and Best-fit**

-   **First Fit Heuristic (BP-FF).**
    -   总是选择第一个能放下物品的箱子。
-   **Best Fit Heuristic (BP-BF)**. 
    -   总是选择放置物品后剩余空间最少的箱子。

### **Index policy**

-   “index policy”: each choice option is given a score, or “index value” independently of the other options
    -   The option with the highest index value is taken
    -   Also need a rule to break ties
-   Although index policies are a special case, in some situations, they can be optimal, or at least very good

### Index policy for 1D Online Bin Packing

-   Given
    -   r : remaining capacity of bin (residual space) 
    -   s : item size
-   score of bin is f(r,s) for some function f
-   Given a new item of size then place into bin with largest value of f(r,s) 
-   We will break any ties using FF:
    -   place item in earliest bin with the best available score

<img src="assets/Screenshot 2024-05-19 at 23.05.17.png" alt="Screenshot 2024-05-19 at 23.05.17" style="zoom:50%;" />

**1D Online Bin Packing**

-   A new empty bin is always available (**open**)
-   A bin is **closed** if it can take no more items
    -   e.g. if residual space is smaller than size of any item
-   We need a good “policy”, i.e. a method to assign a new item upon its arrival to one of the open bins

**Potential General Method for 1D Online Bin Packing**

-   On arrival of new item of size $s_i$
    -   Inspect the current set of open bins
    -   Simultaneously use the entire set of residual spaces in the open bins to pick where to place the new item
-   This is difficult and expensive (in general)

### Generating Heuristics

-   Within search methods, often have score functions, “index functions” to help make some choice
    -   difficult to invent successful ones; want to automate this
-   GP approach: evolve arithmetic score functions
    -   Use Genetic Programming to learn f(r,s) 
    -   f(r,s) is represented as arithmetic function tree 
    -   **Automatically creates functions that at least match FF, BF**

<img src="assets/Screenshot 2024-05-19 at 23.13.51.png" alt="Screenshot 2024-05-19 at 23.13.51" style="zoom:50%;" />

**Chanllenges of using GP**

-   Space of functions, as used in GP,
    -   is hard to understand 
    -   potentially biased because of the choice of representation 
    -   some perfectly good functions might have “bloated” representations

### Matrix View of Policies/Heuristics

-   Since all item sizes (s) and residual capacities (r) are integer, then f(r,s) is simply a large (CxC) matrix M(r,s) of parameter values

<img src="assets/Screenshot 2024-05-19 at 23.16.10.png" alt="Screenshot 2024-05-19 at 23.16.10" style="zoom:50%;" />

<img src="assets/Screenshot 2024-05-19 at 23.16.24.png" alt="Screenshot 2024-05-19 at 23.16.24" style="zoom:50%;" />

### Uniform Instances

-   We empirically studied matrix policies on **Uniform Bin Packing** problems
    -   UBP(C, s_min , s_max , N) (problem generator)
-   Bin capacity C 
-   N items are generated with integer sizes independently taken uniformly at random from the range [ smin , s max ]
    -   N is usually taken to be large: 100k

**Example: UBP(6, 2, 3)**

-   (Bin capacity 6, items are size 2 or 3 only.)
-   The only perfect packings are
    -   2+2+2 
    -   3+3
-   Hence the ‘obvious’ policy is “never mix even and odd sizes”
-   Index policy as a matrix:
    -   rows: residual capacity of the bin 
    -   columns: item size
-   **Ties are broken using First-Fit (FF)** 
-   Grey entries “.” are never usable

<img src="assets/Screenshot 2024-05-19 at 23.20.18.png" alt="Screenshot 2024-05-19 at 23.20.18" style="zoom:50%;" />

### Creating Heuristics viA Many Parameters - CHAMP

-   Basic idea:
    -   Take values in matrix M(r,s) to be integers 
    -   Do (meta-)heuristic search to find good choices for M(r,s): Evaluation is by simulation
-   Our Original Expectation:
    -   the matrix will tweak the functions from GP and might slightly improve performance
-   Potential expected disadvantages:
    -   matrices can be much more verbose than functions
    -   they fail to take into account of the good structure captured by functions

<img src="assets/Screenshot 2024-05-19 at 23.22.13.png" alt="Screenshot 2024-05-19 at 23.22.13" style="zoom:50%;" />

**Implementation Details**

-   Apply a standard GA for training
    -   Trans-generational (with weak elitism, population size:C/2), tournament selection (tour size:2), Uniform Crossover, standard mutation (with probability 1/L), termination after 200 iterations, number of trials: 1.
-   Only the active members of the matrix are stored as integer/binary values (GA Original /GA Binary ) in the chromosome (GAFFinit : GA Original where initial population contains -seeded with- an individual representing FF)
-   Evaluation:
    -   write matrix to a file
    -   use matrix as input for a program that packs many items

### Conclusions

Can use standard metaheuristics to create policies expressed in matrix representation

-   Policies exist that out-perform standard heuristics 

-   Finding the policies is easier than expected 

-   There are many different policies with similar performance 

-   The policies are “weirder” than expected

    -   The good policies could have “random” structures

    - Not necessarily easy to capture with an algebraic function of GP

-   The results can be “analysed” (inspected) to produce simple policies that out-perform standard ones

    - and that then scale to larger problems

## Data Science Improved Hyper-heuristic Optimisation

**Single Objective Hyper2 -heuristic: A Data Science Improved Hyper-heuristic**

-   Many real-world data are multidimensional
    -   Very high-dimensional (big) with a large amount of redundancy
-   Multi-dimensional arrays representing such data describe a tensor







