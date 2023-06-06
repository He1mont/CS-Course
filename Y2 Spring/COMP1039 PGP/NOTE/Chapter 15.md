## Chapter 15: Lazy Evaluation



#### 1. Reduction Strategies

-   Innermost reduction
    -   an innermost reduction is always reduced
-   Outermost reduction
    -   an outermost reduction is always reduced

-   Termination
    -   Outermost reduction always terminate with results

```haskell
loop = tail loop

-- 1. Innermost Reduction
fst (1, loop)
= fst (1, tail loop)
= fst (1, tail (tail loop))
= -- does not terminate!

-- 2. Outermost reduction
fst (1, loop) = 1
```



#### 2. Lazy Evaluations

`Lazy Evaluation = Outmost reduction + Sharing`

-   Benefits
    -   Outmost reduction may require more steps than innermost reduction
    -   Lazy Evaluation combines outmost reduction with `Sharing`, therefore improves efficiency
    -   Allow us to program with infinite lists
    -   Make programs more modular by separating `control` from `data`

<img src="assets/Screenshot 2023-05-20 at 23.26.20.png" alt="Screenshot 2023-05-20 at 23.26.20" style="zoom:40%;" />













