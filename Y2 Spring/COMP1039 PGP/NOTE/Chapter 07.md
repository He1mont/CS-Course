## Chapter 7: Higher-Order Functions

##### 1. Introduction

-   A function is called **higher-order** if ==it takes a function as an argument== or returns a function as a result

```haskell
twice :: (a -> a) -> a -> a
twice f x = f (f x)
```



##### 2. The Map Function

-   The higher-order library function called **map** applies a function to every element of a list

```haskell
map :: (a -> b) -> [a] -> [b]

> map (+1) [1,3,5,7]
[2,4,6,8]

-- def.1 by list comprehension
map f xs = [f x| x <- xs]

-- def.2 by recursion
map f [] = []
map f (x:xs) = f x : map f xs
```



##### 3. The Filter Function

-   The higher-order library function **filter** selects every element from a list that satisfies a predicate, where the predicate is `(a -> Bool)`

```haskell
filter :: (a -> Bool) -> [a] -> [a]

> filter even [1..10]
[2,4,6,8,10]

-- def.1 by list comprehension
filter p xs = [x | x <- xs, p x]

-- def.2 by recursion
filter p [] = []
filter p (x:xs)
	| p x		= x : filter p xs
	| otherwise = filter p xs
```



##### 4. The Foler Function

<img src="assets/Screenshot 2023-04-06 at 17.31.48.png" alt="Screenshot 2023-04-06 at 17.31.48" style="zoom:25%;" />

-   Base Case
    -   f maps the empty list to some value v
-   Inductive Step
    -   f maps any non-empty list to some function that applied to its head and f of its tail
-   The higher-order library function **foldr** (fold right)

```haskell
sum [] = 0
sum (x:xs) = x + sum xs

product [] = 1
product (x:xs) = x * product xs

and [] = True
and (x:xs) = x && and xs

sum 	= foldr (+) 0
product = foldr (*) 1
and 	= foldr (&&) True
or 		= foldr (||) False
```

-   foldr itself can be defined using recursion

```haskell
foldr :: (a -> b -> b) -> b -> [a] -> b
foldr f v [] = v
foldr f v (x:xs) = f x (foldr f v xs)	

-- f takes two argument, one is x, the other is (foldr f v xs)
-- and f returns the type like (foldr f v xs)
-- so f :: (a -> b -> b)
```

-   However, it is best to think of foldr non-recursively
    -   replace each (:) in a list y a given function
    -   replace [] by a given value

```haskell
  sum [1,2,3]
= foldr (+) 0 [1,2,3]
= foldr (+) 0 (1:(2:(3:[])))
```



##### 5. Other Foldr Examples

-   Recall the length function:

```haskell
length :: [a] -> Int
length [] = 0
length (_:xs) = 1 + length xs	-- 用'_'代表我不关心list的head

  length [1,2,3] 
= length (1:(2:(3:[])))			-- replace each (:) by \_ n -> n + 1
= 1+(1+(1+0))
= 3

length = foldr (\_ n -> 1+n) 0	

length (_:xs) = 1 + length xs 
			  = 1 + (foldr f 0 xs)
	          = f _ (foldr f 0 xs)	-- let f = (\_ n -> 1+n)
```

-   Recall the reverse function

```haskell
reverse [] = []
reverse (x:xs) = reverse xs ++ [x]

  reverse [1,2,3]
= reverse (1:(2:(3:[])))			-- replace each (:) by \x xs -> xs ++ [x]
= (([]++[3])++[2]) ++ [1]
= [3,2,1]

reverse = foldr (\x xs = xs ++ [x]) []

reverse (x:xs) = xs ++ [x]
			   = (foldr f [] xs) ++ [x]
			   = f x (foldr f [] xs)	-- f = \x xs -> xs ++ [x]
```

-   用foldr来完成递归的结构
-   用lambda函数来完成递归的函数



##### 6. Other Library Functions

-   `.` composition of two functions

```haskell
(.) :: (b -> c) -> (a -> b) -> (a -> c)
f . g = \x -> f (g x)

-- for example
odd :: Int -> Bool
odd = not . even
```

-   `all` decides if every element of a list satisfies a given predicate

```haskell
all :: (a -> Bool) -> [a] -> Bool
all p xs = and [p x | x <- xs]

> all even [2, 4, 6, 8, 10]
True
```

-   `any` decides if at least one element of a list satisfies a predicate

```haskell
any :: (a -> bool) -> [a] -> Bool
any p xs = or [p x | x <- xs]

> any (== ' ') "abc def"
True
```

-   `takeWhile` selects elements from a list while a predicate holds of all the elements

```haskell
takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile p [] = []
takeWhile p (x:xs)
	| p x 		= x : takeWhile p xs
	| otherwise = []					-- 在第一个不满足p的element中断
										-- 只返回从头开始的连续的element
> takeWhile (/= ' ') "abc def"
"abc"
```

-   `dropWhile` removes elements while a predicate holds of all the elements

```haskell
dropWhile :: (a -> Bool) -> [a] -> [a]
dropWhile p [] = []
dropWhile p (x:xs)
	| p x 		= dropWhile p xs
	| otherwise = x:xs
	
> dropWhile (== ' ') "     abc"
"abc"
```

-   `curry` takes an uncurried function and constructs a curried version of this function

```haskell
curry :: ((a,b) -> c) -> (a -> b -> c)
curry f = \x y -> f (x,y)

addUncurried :: (Int, Int) -> Int
addUncurried (x,y) = x + y

> addUncurried (1,2)
3
> curry addUncurried 1 2
3
:type curry addUncurried :: Int -> Int -> Int
```

-   `uncurry` takes a curried function and constructs an uncurried version of this function

```haskell
uncurry :: (a -> b -> c) -> ((a,b) -> c)
uncurry f = \(x,y) -> f x y

addCurried :: Int -> Int -> Int
addCurried x y = x + y

> addCurried 1 2
3
> uncurry addCurried (1,2)
3
>:type uncurry addCurried: (Int, Int) -> Int
```



### Exercises

Q2

-   Express the comprehension `[f x | x <- xs, p x]` using the functions map and filter.

```haskell
[f x | x <- xs, p x]

map f xs 	= [f x| x <- xs]
filter p xs = [x  | x <- xs, p x]
map f (filter p xs) = [f x| x <- xs, p x]	-- 先过滤，在apply function
```

Q3	

-   Redefine `map f` and `filter p` using `foldr`.

```haskell
-- an example from reverse
reverse (x:xs) = reverse xs ++ [x]
			   = (foldr f [] xs) ++ [x]		-- function f takes x, xs and return this line
			   = f x (foldr f [] xs)		-- f = \x xs -> xs ++ [x]

reverse = foldr (\x xs -> xs ++ [x]) []
```

```haskell
map :: (a -> b) -> [a] -> [b]
map f [] = []
map f (x:xs) = f x : map f xs

map f :: [a] -> [b]
-- map f is a function that takes a list and return a list
-- from now on we call it (mymap f)

(mymap f) (x:xs) = f x : (mymap f) xs
			     = f x : (foldr g [] xs)	-- function g takes x, xs and return this line
			     = g x (foldr g [] xs) 		-- g = \x xs -> f x : xs
			   
mymap f = foldr (\x xs -> f x : xs) []
```

```haskell
filter :: (a -> Bool) -> [a] -> [a]
filter p (x:xs)	| p x  		= x : filter p xs
				| otherwise = filter p xs
				
filter p :: [a] -> [a]
-- map f is a function that takes a list and return a list
-- from now on we call it (myfilter p)

(myfilter p) (x:xs) = if p x then x : (myfilter p) xs else (myfilter p) xs
					= if p x then x : (foldr f [] xs) else (foldr f [] xs)
					= f x (foldr f [] xs)   -- where f = \x xs -> x:xs if p x else xs

myfilter p = foldr (\x xs -> if p x then x:xs else xs) []
```



















