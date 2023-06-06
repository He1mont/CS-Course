## Chapter 6: Recursive Functions

##### 1. Recursion on Lists

```haskell
product :: Num a => [a] -> a
product [] = 1
product (n:ns) = n * product ns		-- (n:ns) is a list pattern in Chapter 4
```

```haskell
length :: [a] -> Int
length [] = 0
length (_:xs) = 1 + length xs
```

```haskell
reverse :: [a] -> [a]
reverse [] = []
reverse (x:xs) = reverse xs ++ [x]
```

```haskell
-- a fast reverse that avoid (++) for each element
-- instead, we use cons(:)
fastRev :: [a] -> [a]
fastRev xs = fastRev' xs []
	where
		fastRev' :: [a] -> [a] -> [a]
		fastRev' [] acc = acc					-- Base Case
		fastRev' (x:xs) acc = fastRev' xs x:acc -- Ind. Step
```

```haskell
Prelude> :set +s		-- turn on timing
Prelude> head $ reverse [1..10000000]
Prelude> head $ fastRev [1..10000000]
```

<img src="assets/Screenshot 2023-03-20 at 01.03.23.png" alt="Screenshot 2023-03-20 at 01.03.23" style="zoom:50%;" />

-   ==为啥我电脑跑出来fastRev要慢一点？==



##### 2. Multiple Arguments

-   Zipping the elements of two lists

```haskell
zip :: [a] -> [b] -> [(a,b)]
zip [] _ = []
zip _ [] = []
zip (x:xs) (y:ys) = (x,y) : zip xs ys
```

-   Remove the first n elements from a list:

```haskell
drop :: Int -> [a] -> [a]
drop 0 xs = xs
drop _ [] = []
drop n (_:xs) = drop (n-1) xs
```

-   Appending two lists

```haskell
(++) :: [a] -> [a] -> [a]
[] ++ ys = ys
(x:xs) ++ ys = x : (xs ++ ys)
```



##### 3. Mutual Recursion

-   Testing for even / odd

```haskell
even :: Int -> Bool
even 0 = True
even n = odd (n-1)

odd :: Int -> Bool
odd 0 = False
odd n = even (n-1)
```



##### 4. Quicksort

-   The <u>quicksort</u> algorithm for sorting a list of values can be specified by the following two rules
    -   The empty list is already sorted
    -   Non-empty lists can be sorted by sorting the tail values and the head, and then appending the result lists on either side of the head value

```haskell
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort smaller ++ [x] ++ qsort larger
			   where
			   		smaller = [a | a <- xs, a <= x]
                    smaller = [b | b <- xs, b > x]
```

-   -   probably the **simplest** implementation of quicksort in any programming language

<img src="assets/Screenshot 2023-03-29 at 23.09.46.png" alt="Screenshot 2023-03-29 at 23.09.46" style="zoom:33%;" />



### Exercises

1.   Define library functions using recursions

``` haskell
-- Decide if all logical values in a list are true
and :: [Bool] -> Bool
and [] = False
and (x:xs) = x && (and xs)

-- Concatenate a list of lists
myConcat :: [[a]] -> [a]
myConcat [] = []
myConcat (xs:xss) = xs ++ myConcat xss

-- Produce a list with n identical element
replicate :: Int -> a -> [a]
replicate 0 _ = []
replicate n x = x : replicate n-1 x

-- Select the nth element of a list:
(!!) :: [a] -> Int -> a
(!!) (x:xs) 0 = x
(!!) (x:xs) n = (!!) xs n-1

-- Decide if a value is an element of a list:
elem :: Eq a => a -> [a] -> Bool
elem a [] = False
elem a (x:xs) = (a==x) || elem a xs
```



2.   Merge function

```haskell
-- merges two sorted lists of values to give a single sorted list
merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = if x<=y then x : merge xs (y:ys)
							  else y : merge (x:xs) ys
```



3.   Merge Sort

```haskell
msort :: Ord a => [a] -> [a]

-- a function that split a list into two equal-length list
splitInHalf :: [a] -> ([a], [a])
splitInHalf xs = splitAt (length xs `div` 2) xs

msort [] = []
msort [x] = [x]
msort xs = let (left, right) = splitInHalf xs
		   in merge (msort left) (msort right)
```



















