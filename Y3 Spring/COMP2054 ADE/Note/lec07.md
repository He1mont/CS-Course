# lec07: Simple Sorting Algorithms

>   **Overview**
>
>   -   Bubble sort
>   -   Selection sort
>   -   Insertion sort

## Bubble Sort

>   ### 稳定性 Stability
>
>   一个算法被称为是**稳定的（stable）**，指的是这个算法在排序具有相等关键字的元素时，能够保持这些元素原有的相对顺序不变。换句话说，如果有两个元素A和B（A不是B），在排序前，如果A在B前面，并且A和B的关键字相等（即它们是比较时认为的“相等”的），那么一个稳定的排序算法会保证在排序后A仍然在B的前面。
>
>   -   **选排和快排不是稳定的**
>   -   剩下的都是稳定的

-   Bubble sort is **stable**
-   Complexity: 
    -   `t(n-1 + n-2 + ... + 1) + k + t1(n-1)` is $O(n^2)$
    -   `t`: time require for one comparison, one swap and check the inner loop condition and increment `j`
    -   `k`: time required to declare `i, j, temp`
    -   `t1(n-1)`: outer loop

```java
void bubbleSort(int arr[]) {
    n = arr.length
	for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
```

## Selection Sort

-   **Fewer swaps** compared to bubble sort
-   Also $O(n^2)$
-   **NOT Stable**
    -   consider `3a, 2, 3b, 1`


```java
void selectionSort(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = arr[i];
        }
    }

```

## Insertion Sort

-   This sort was **stable**
-   Worst case complexity: $O(n^2)$
-   Best case complexity: $O(n)$

```java
void insertionSort(int arr[]) {
    for (int i = 1; i < arr.length; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

## Adaptive Sort

-   Ask what happens to the complexity when the lists are already **nearly sorted**

