## Problem Forlumation & Search Tree

>   ### Outline
>
>   -   Problem formulation
>   -   Tree-Terminology
>   -   Problem representation
>



#### 1. Problem formulation:

-   the process of deciding what `actions` and `states` to consider given a `goal`



#### 2. Problem Components

*   <u>Initial State:</u> the starting state of the problem
*   <u>Actions (Operator):</u> move the problem from one state to another
    *   actions can be recognized as the <u>successor function</u>
    *   <u>neighborhood:</u> the set of all possible states reachable from a given state by applying all legal action
*   <u>Goal Test</u>: a test applied to a state which returns true if we solves the problem
*   <u>Path Cost</u>: how much it costs to take a particular sequence of actions

-   <u>State Space:</u> the set of all states reachable from the initial state
-   <u>Complexity</u>: the size of the state space



#### 3. Trees - Terminology

-   Nodes
    -   Root node
    -   Children/Parent nodes
    -   Leaves
-   Branches
-   Average branching factor
    -   average number of branches of the nodes in the tree

<img src="assets/Screenshot 2023-03-15 at 17.30.10.png" alt="Screenshot 2023-03-15 at 17.30.10" style="zoom: 25%;" />



#### 4. Problem representation

-   <u>State</u>: node
-   <u>Initial State</u>: root node
-   <u>State Space</u>: all nodes in the tree
-   <u>Successors</u>: Neighborhood
    -   the set of all possible states reachable from a given state
-   <u>Branching factor</u>: number of neighborhoods
-   <u>Operators</u>: branches









