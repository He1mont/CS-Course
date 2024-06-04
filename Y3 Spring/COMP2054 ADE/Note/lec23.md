# lec23: Shortest Path: Floyd-Warshall (FW)

[toc]

## All-Pairs Shortest Paths

Suppose that wanted to find the SP between all pairs of start and end nodes

-   Dijkstra’s algorithm finds all shortest path costs from one given starting node
    -   The complexity of Dijkstra is $O( |V| * (|V| * log(|V|) +|E|))$
-   We could run Dijkstra from every node
    -   Would then be a factor of $O( |V| )$ 
    -   worse than Dijkstra, e.g. $O( |V| * (|V| * log(|V|) +|E|))$
-   But may be better to run a specific algorithm
-   We will do the **“Floyd-Warshall” (FW) algorithm**

## FW All-Pairs SPs

-   The basic method has similarities to the methods for “change giving” in an earlier lecture
    -   “Build best answers for a set of coins, and then add the effects of coins one at a time”
-   “Build the optimal answers using a subset of the nodes. Then add the effects of other nodes one at a time”

### Data structure

-   `d(i,j,k)` = shortest distance between nodes i and j,
    -   but using only the nodes {1,…,k} as potential allowed intermediary points
-   E.g. `d(2,5,3)` = "shortest distance from n2 to n5 using only {n1,n2,n3} as potential intermediate points’."
    -   Usage of all or any of these intermediate points is not forced, but other points, such as n4 …, cannot be used

**Initialisation**

-   `d(i,j,0)` = best distance between nodes i and j, but not using any intermediate nodes,
-   `d(i,j,0)` = `w(i,j)`, if there is an edge i to j
                    = Infinity,  otherwise

**Algorithms**

-   Now suppose that we add the node ‘n1’ to the set of nodes that can be intermediates, i.e. consider k = 1
-   Best path is now the best of “either direct, or via n1.”

<img src="assets/Screenshot 2024-05-12 at 17.28.33.png" alt="Screenshot 2024-05-12 at 17.28.33" style="zoom:50%;" />

-   Now suppose that we add the new node “(k+1)” to the set of “via nodes” that can be intermediates, but have already considered k of them
-   Best path is now either direct using only the k ‘via nodes’ already accounted for, or else also via node ‘k+1’ (and using the previous k via’s)

<img src="assets/Screenshot 2024-05-12 at 17.29.45.png" alt="Screenshot 2024-05-12 at 17.29.45" style="zoom:50%;" />

<img src="assets/Screenshot 2024-05-12 at 17.31.16.png" alt="Screenshot 2024-05-12 at 17.31.16" style="zoom:50%;" />

**Self-edges**

`d(i, i) = 0` for all i

### Example

<img src="assets/Screenshot 2024-05-12 at 17.33.12.png" alt="Screenshot 2024-05-12 at 17.33.12" style="zoom:50%;" />

`d(i, j, 0)`

| `d(i, j, 0)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | inf  |
| n2           | 8    | 0    | inf  | 1    |
| n3           | 2    | inf  | 0    | 3    |
| n4           | inf  | 1    | 3    | 0    |

`d(i, j, 1)`: Set of intermediates = `{n1}`

| `d(i, j, 1)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | inf  |
| n2           | 8    | 0    | 10   | 1    |
| n3           | 2    | 10   | 0    | 3    |
| n4           | inf  | 1    | 3    | 0    |

`d(i, j, 2)`: Set of intermediates = `{n1, n2}`

| `d(i, j, 2)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    |      |      |      |
| n2           | 8    | 0    |      |      |
| n3           | 2    | 10   | 0    |      |
| n4           | 9    | 1    | 3    | 0    |

`d(i, j, 3)`: Set of intermediates = `{n1, n2, n3}`

| `d(i, j, 3)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    |      |      |      |
| n2           | 8    | 0    |      |      |
| n3           | 2    | 10   | 0    |      |
| n4           | 5    | 1    | 3    | 0    |

`d(i, j, 4)`: Set of intermediates = `{n1, n2, n3, n4}`

| `d(i, j, 4)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    |      |      |      |
| n2           | 6    | 0    |      |      |
| n3           | 2    | 4    | 0    |      |
| n4           | 5    | 1    | 3    | 0    |

### FW Code and Complexity

**The main loop after initialisation**

<img src="assets/Screenshot 2024-05-12 at 17.37.20.png" alt="Screenshot 2024-05-12 at 17.37.20" style="zoom:50%;" />

Note that is it is vital that ‘k’ is the outer loop.

Hence is $O( {|V|}^3 )$

## FW on digraphs

<img src="assets/Screenshot 2024-05-12 at 17.39.05.png" alt="Screenshot 2024-05-12 at 17.39.05" style="zoom:50%;" />

`d(i, j, 0)`

| `d(i, j, 0)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | inf  |
| n2           | 8    | 0    | inf  | 1    |
| n3           | 2    | inf  | 0    | inf  |
| n4           | inf  | 1    | 3    | 0    |

`d(i, j, 1)`: Set of intermediates = `{n1}`

| `d(i, j, 1)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | inf  |
| n2           | 8    | 0    | 10   | 1    |
| n3           | 2    | 10   | 0    | inf  |
| n4           | inf  | 1    | 3    | 0    |

`d(i, j, 2)`: Set of intermediates = `{n1, n2}`

| `d(i, j, 2)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | 9    |
| n2           | 8    | 0    | 10   | 1    |
| n3           | 2    | 10   | 0    | 11   |
| n4           | 9    | 1    | 3    | 0    |

`d(i, j, 3)`: Set of intermediates = `{n1, n2, n3}`

| `d(i, j, 3)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | 9    |
| n2           | 8    | 0    | 10   | 1    |
| n3           | 2    | 10   | 0    | 11   |
| n4           | 5    | 1    | 3    | 0    |

`d(i, j, 4)`: Set of intermediates = `{n1, n2, n3, n4}`

| `d(i, j, 4)` | n1   | n2   | n3   | n4   |
| ------------ | ---- | ---- | ---- | ---- |
| n1           | 0    | 8    | 2    | 9    |
| n2           | 6    | 0    | 4    | 1    |
| n3           | 2    | 10   | 0    | 11   |
| n4           | 5    | 1    | 3    | 0    |

## FW with negative edges

FW even works if some (directed) edge weights are negative

-   BUT it is essential that there are **no cycles of total negative weight**
-   Otherwise simply repeatedly following around the negative cycle may reduce lengths to be as negative as desired, so there is no shortest path







