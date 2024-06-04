# lec09: Merge Sort

## Divide and Conquer

-   **Divide and conquer** is a general **algorithm design paradigm**:
    -   **Divide**: divide the input data `S` in two disjoint subsets `S1` and `S2`
    -   **Recur**: solve the subproblems associated with `S1` and `S2` 
    -   **Conquer**: combine the solutions for `S1` and `S2`  into a solution for `S`
-   The base case for the recursion are subproblems of **size 0 or 1** (or “small enough to be done directly”)
-   **Merge-sort** is a sorting algorithm based on the **divide and conquer paradigm**

## Merge-Sort

-   Merge-sort on an input sequence (array/list) S with n elements consists of three steps:
    -   **Divide**: partition `S` into two sequences `S1`and `S2` of about `n/2` elements each
    -   **Recur**: recursively sort `S1` and `S2` 
    -   **Conquer**: merge `S1` and `S2` into a unique sorted sequence

-   **Implementation**

```java
public static void recMergeSort(int[] arr, int[] workSpace, int l, int r) {
    // initially l = 0, r = arr.length-1
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    recMergeSort(arr, workSpace, l, m);
    recMergeSort(arr, workSpace, m+1, r);
    merge(arr, workSpace, l, m+1, r);
}
```

<img src="assets/Screenshot 2024-02-28 at 17.28.30.png" alt="Screenshot 2024-02-28 at 17.28.30" style="zoom:50%;" />

## Analysis of Merge-Sort

-   The height `h` of the merge-sort tree is $O(\log n)$
    -   at each mprecursive call we **divide in half** the sequence,
-   The overall amount of work done at all the nodes at depth `i` is $O(n)$
    -   we partition and merge `2^i` sequences of size `n/2^i` 
    -   we make `2^(i+1)` recursive calls
    -   the numbers all occur and are all “used” at each depth
    -   So, each depth uses O(n) work
-   Thus, the total running time of merge-sort is $O(n \log n)$

**Using Merge Sort**

-   Fast sorting method for arrays
-   Good for sorting data in **external memory**
    -   It accesses data in a sequential manner
-   Not so good with lists: relies on **constant time** access to the middle of the sequence


