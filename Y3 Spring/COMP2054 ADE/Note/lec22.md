# lec22: BST Balance and Rotations

[toc]

## BST Imbalance Problem

<img src="assets/Screenshot 2024-05-12 at 16.54.44.png" alt="Screenshot 2024-05-12 at 16.54.44" style="zoom:50%;" />

A tree is said to be “balanced” if the heights of left and right subtrees of any node are (close to) equal, and so the height is $O(\log n)$

**Issues in Self-balancing**

-   Suppose you have a very imbalanced search tree, there are always corresponding balanced search trees
-   Could make trees balanced using a **“total rebuild”**
    -   But would require $O(n)$, and so very inefficient compared to the desired $O(\log  n)$
-   Re-balancing needs to be $O(\log n)$ or $O( height )$
-   Suggests re-balancing needs to just look at the path to some recently changed node, not the entire tree
-   A priori, it is not at all obvious that this is possible!

## Example of a Rotation

<img src="assets/Screenshot 2024-05-12 at 17.02.58.png" alt="Screenshot 2024-05-12 at 17.02.58" style="zoom:50%;" />

-   Where subtrees T1, T2, T3 are BSTs themselves
-   `h(T) = max(1 + h(T1), 2 + h(T2), 2 + h(T3))`
-   Both trees have **in-order traversal**: In(T1), a, In(T2), b, In(T3)
-   Called a (single) “rotation” as **the edge a-b rotated**

<img src="assets/Screenshot 2024-05-12 at 17.10.45.png" alt="Screenshot 2024-05-12 at 17.10.45" style="zoom:50%;" />

-   The tree can also be a sub-tree of a BST
-   Once we have decided to rotate a specific edge then we only need to look at a fixed number of nodes and edges.
-   Hence, a single rotation only has $O(1)$ in cost.

**Simple Example**

<img src="assets/Screenshot 2024-05-12 at 17.13.51.png" alt="Screenshot 2024-05-12 at 17.13.51" style="zoom:50%;" />

**Harder Example**

<img src="assets/Screenshot 2024-05-12 at 17.14.09.png" alt="Screenshot 2024-05-12 at 17.14.09" style="zoom:50%;" />

**Double work**

<img src="assets/Screenshot 2024-05-12 at 17.14.31.png" alt="Screenshot 2024-05-12 at 17.14.31" style="zoom:50%;" />

-   The goal is then to control the usage of rotations to reduce the overall height of the tree
    -   Single rotations sometimes help
    -   Sometimes need “double rotations” – a “coordinated pair of single rotations”
-   In small examples, we can do this “by inspection”
-   In general, need to be able to select rotations **algorithmically**



