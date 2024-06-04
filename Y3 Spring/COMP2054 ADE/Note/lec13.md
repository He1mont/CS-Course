# lec13: Comparison Based Sorting

## Comparison sorting

-   A sorting algorithm is a comparison sorting algorithm if it **uses comparisons between elements in the sequence** to determine in which order to place them
-   Examples
    -   bubble sort, selection sort, insertion sort, heap sort, merge sort, quick sort
-   Not a comparison based:
    -   bucket sort

**Lower bound for comparison sort**

-   We can model sorting which depends on comparisons between elements as a binary decision tree.
-   At each node, a comparison between two elements is made; there are two possible outcomes and we find out a bit more about the correct order of items in the array.
-   Finally arrive at full information about the correct order of the items in the array.

<img src="assets/Screenshot 2024-03-11 at 22.16.23.png" alt="Screenshot 2024-03-11 at 22.16.23" style="zoom:50%;" />

**How many comparisons**

-   If a binary tree has $n!$ leaves, than the minimal number of **levels** (assuming the tree is perfect) is $\log_2{n!} + 1$​
    -   uses Stirling's approximation
-   This shows that $O(n\log n )$ sorting algorithms are essentailly optimal
-   **Comparison-based sorting cannot do better than $O(n \log n)$**

