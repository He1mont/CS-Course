## Blind Searches

>   ### Outline 
>
>   -   Evaluation Criteria
>   -   General Tree Search `pseudo code`
>   -   Blind Search
>   -   BFS
>   -   DFS
>   -   UCS



#### 1. Evaluation Criteria

-   **Completeness**: does it always find a solution if it exists
-   **Optimality**: does it always find a least-cost solution
-   **Time Complexity**: number of nodes expanded (i.e. leaves)
-   **Space Complexity**: max number of nodes in memory
    -   b: **maximum** branching factors of the search tree
    -   d: depth of the **least-cost solution**
    -   m: maximum depth of the state space



#### 2. Two Categories of Strategies

-   **Blind Search**: no additional info. about states
-   **Heuristic Search**: use strategies that know whether one state is promising



#### 3. General Tree Search (pseudo-code)

```python
Function General-Search(p, QUEUING-FN)
	return Solution or Failure
	
frontier = Make-Queue(Make-Node(Initial-State[p]))

Loop do
	if isEmpty(frontier) then
		return failure
	
	node = Remove-Front(frontier)
	
	if Goal-Test[p] on node succeed then 
		return node
	
    frontier = QUEUING-FN(frontier, (Expand(node, Actions[p]))
End
```



#### 4. Blind Search Implementation

-   Implementation

    -   **Operators**
    -   **Expand**: ask a node for its children
    
-   **Test**: test a node to see whether it is a goal




-   Three types of node during the tree search

    -   **frontier nodes**: have been discovered, not yet processed

    -   **visited nodes**: have been discovered and processed

    -   **undiscovered nodes**



#### 5. Breadth First Search (BFS):

-   **Method**

    1.   expand Root Node

    2. expand all nodes at level `d` before expanding nodes at level `d+1`
    3.   Queuing function: add nodes to the end of the queue (**FIFO**)
    
         `General-Search(problem, ENQUEUE-AT-END)`


​    

-   **Implementation**

```python
General-Search(problem, ENQUEUE-AT-END)

node = Remove-Front(frontier)
if Goal-Test[p] on State(node) succeeds then
	return node

frontier = QUEUING-FN(frontier, Expand(node, Action[p]))
```



#### 6. Evaluation for BFS

-   <u>Time Complexity</u>: 

    -   $O(b^d)$,  i.e. total number of nodes in the tree

-   <u>Space Complexity</u>: 

    -   $O(b^d)$, i.e. number of leaves
    -   b: the max branching factor

    -   d: the depth of the search tree



#### 7. Depth First Search (method)

1.   Expand Root Node First

2.   Explore `one branch` before exploring another branch

3.   Queuing function: add nodes to the front of the queue (**LIFO**)

     `General-Search(problem, ENQUEUE-AT-FRONT)`

     

#### 8. Evaluation for DFS

-   <u>Time complexity</u>
    -   worst case: $O(b^m)$
-   <u>Space complexity</u>
    -   store: the path from the root to the leaf node as well as the unexpanded neighbor nodes
    -   requires storage of $O(b*m)$
-   <u>Completeness</u>: **NO**
    -   an infinite branch: never terminate
-   <u>Optimality</u>: **NO**
    -   find a solution: is there a better solution at a lower level



#### 9. Uniform Cost Search

-   Method
    -   a variant of Dijkstra's algorithm
    -   a special case of BFS
    -   explore the **cheapest node** first
    -   guarantee to find the shortest path from the start node to any reachable node in the graph



#### 10. Summary

| Evaluation | BFS&UCS | DFS   |
| :--------- | :------ | ----- |
| Time       | $b^d$   | $b^m$ |
| Space      | $b^d$   | $b*m$ |
| Optimal    | YES     | NO    |
| Complete   | YES     | NO    |

-   b = average branching factor
-   d = depth of solution
-   m = maximum depth of the search tree











