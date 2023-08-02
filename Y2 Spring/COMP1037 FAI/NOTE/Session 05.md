## Session 5: Game Playing

>   ### Outline
>
>   -   Minimax alg.
>   -   Alpha-beta pruning of search trees



#### 1. Game Playing - Minimax

-   An **opponent** tries to prevent your win at every move
    -   a search method (**Minimax**)
    -   ==maximise== your position whilst ==minimising== your opponent's
-   **Utility** is an abstract measuring the amount of satisfaction you receive from sth
    -   `utility function` used to measure how good a position is
    -   initially this will be a **value** that describes our position exactly



-   In discussion of minimax
    -   two players "MAX" and "MIN"
    -   **utility function** (minimax value) of a node: the utility of being in the corresponding state (larger values are better for "MAX", vice versa)
    -   MAX: take the <u>best</u> move for MAX （挑utility function最大的）
    -   MIN: take the <u>worst</u> move for MAX （挑utility function最小的）



#### 2. ZERO-SUM Games

-   Fully ==observable environments== (<u>perfect information</u>) in which two agents act attend
-   Utility values at the end are always ==equal or opposite==
    -   (0+1, 1+0, or 1/2+1/2, total payoff is the same)
    -   e.g.: if one player wins a game, the other loses
-   This **opposition** between the agents' utility functions makes the situation **adversarial**



#### 3. Components of Game Search

-   **initial state**: board position, indication of whose move it is
-   **a set of operators**: define the legal moves
-   **terminal test**: determines when the game is over
-   **utility (payoff) function**: gives a <u>numeric value for the outcome</u> (terminal state) of a game 



#### 4. Alpha-Beta Pruning ==(Only for DFS, not for BFS)==

-   **Pruning** allow us to ignore portions of the search tree that make no difference to the final choice
    -   the number of  nodes grow exponentially
    -   possible to compute the correct minimax decision without looking at every node in the game tree
    -   the idea of **pruning** to **eliminate** large parts of the tree from consideration
-   In the best case, Alpha-Beta search can effectively double the depth of search tree in a given time
    -   effectively reduces the <u>branching factor</u>



-   Two Parameters
    -   alpha $\alpha$: values stored with each MAX node
        
        the highest value at any choice point along the path
    -   beta $\beta$ : values stored with each MIN node
        
        the lowest value at any choice point along the path



-   To maximise pruning: first expand the best children
    -   use **heuristics** for the `"best-first" ordering`









