## Chapter* : Countdown



#### 1. Countdown Rules

-   Six numbers selected randomly from the list [1 . . 10, 1 . . 10, 25, 50, 75, 100].
-   Target number selected randomly in the range 100..999.
-   Use any of the six numbers and combine with operators +, -, *, / to calculate the target number.
-   Negative numbers and fractions not allowed in the calculations.



#### 2. Brute Force Strategy

1.   Generate all possible subsequences of the given source numbers

     Function `subs`

2.   Generate all possible permutations of the subsequences.

     Function `perms`

3.   Generate all possible expressions over each permutation

     Function `exprs`

4.   Check whether each expression evaluates to the target number

     Function `eval`



#### 3. Solution in Haskell

-   `solutions`

```haskell
> s1 = solutions [1,3,7,10,25,50] 765

solutions :: [Int] -> Int -> [Expr]
solutions ns target = [e | ys <- subs ns,
						   zs <- perms ys,
						   e <- exprs zs,
						   eval e == [target]]
```

-   `subs`

```haskell
subs :: [a] -> [[a]]
subs [] = [[]]
subs (x:xs) = subs xs ++ map (x:) (subs xs)
-- where (x:) is a function that add x to the head of a list
```

-   `perm`

```haskell
> perms [1,2,3]
[[1,2,3],[2,1,3],[2,3,1],[1,3,2],[3,1,2],[3,2,1]]
-- the first half，put 1 in different places with [2,3]
-- the last half， put 1 in different places with [3,2]

perms :: [a] -> [[a]]
perms [] = [[]]
perms (x:xs) = concat (map (perms2 x) (perms xs))

-- put x in different places with xs
perms2 :: a -> [a] -> [[a]]
perms2 x xs = map (\(ys,zs) -> ys ++ [x] ++ zs) (split 0 xs)

-- produce all possible splits of a list as pairs of sublists
split :: Int -> [a] -> [([a],[a])]
split n xs = zip (takeV n xs) (dropV n xs)

takeV :: Int -> [a] -> [[a]]
takeV n xs = [take i xs | i <- [n..(length xs - n)]]

dropV :: Int -> [a] -> [[a]]
dropV n xs = [drop i xs | i <- [n..(length xs - n)]]

> takeV 1 [1,2,3,4]
[[1],[1,2],[1,2,3]]
> dropV 0 [1,2,3,4]
[[1,2,3,4],[2,3,4],[3,4],[4],[]]
```



































