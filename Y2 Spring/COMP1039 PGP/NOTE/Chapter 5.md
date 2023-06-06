## Chapter 5: List Comprehension

##### 1. Set Comprehension

-   In mathematics: 

    -   $\{x^2 | x \in \{1,2,3,4,5 \}\}$

-   In Haskell:

    -    `[x^2 | x <- [1..5]]`

    -   `x <- [1..5]` is called a **generator**

-   Comprehensions can have multiple generators, separated in commas

    ```haskell
    > [(x,y) | x <- [1,2,3], y <- [4,5]]	
    -- Cartesian product of x and y
    [(1,4), (1,5), (2,4), (2,5), (3,4), (3,5)]
    ```



##### 2. Dependant Generators

-   depend on variables that are introduced by earlier generators

    -   `[(x,y) | x <- [1..3], y <- [x..3]]`

    ```python
    # same functionality in python
    l = []
    for x in range(1,4):
        for y in range(x,4):
            l.append((x,y))
    ```

-   using a dependant generator, we can define the library function that concatenates a list of lists:

    ```haskell
    concat :: [[a]] -> [a]
    concat xss = [x | xs <- xss, x <- xs]
    
    -- for example
    > concat [[1,2,3],[4,5],[6]]
    [1,2,3,4,5,6]
    ```

    ```python
    # same functionality in python
    def concat(l):
        mylist = []
        for x in l:			# xs <- xss in Haskell
            for y in x:		# x <- xs   in Haskell
                mylist.append(y)
    	return mylist
    ```

    

##### 3. Guards

-   List comprehensions can use guards to restrict the values produced by earlier generators

    ```haskell
    -- give a integer and return its factors
    factors :: Int -> [Int]
    factors n = [x | x <- [1..n], n `mod` x == 0]
    > factor 15
    [1,3,5,15]
    ```

    ````haskell
    -- check whether an integer is prime
    prime :: Int -> Bool
    prime n = factors n == [1,n]
    > prime 15
    False
    > prime 7
    True
    ````

    ```haskell
    -- a list of prime not exceeding n
    primes :: Int -> [Int]
    primes n = [x | x <- [2..n], prime x]
    > 10
    [2,3,5,7]
    ```



##### 4. The Zip Function and its Extending functions

-   maps two lists ot a list of pairs of their corresponding elements

    ```haskell
    zip :: [a] -> [b] -> [(a,b)]
    > zip ['a', 'b', 'c'] [1,2,3,4]
    [('a',1), ('b',2), ('c',3)]
    ```

-   Using zip we can define a function returns the list of all pairs of adjacent elements 

    ```haskell
    pairs :: [a] -> [(a,a)]
    pairs xs = zip xs (tail xs)
    > pairs [1,2,3,4]
    [(1,2), (2,3), (3,4)]
    ```

-   Using pairs we can define a function that decides if the elements in a list are sorted

    ```haskell
    -- check sorted list
    sorted :: Ord a => [a] -> Bool
    sorted xs = and [x <= y | (x,y) <- pairs xs]
    ```
    
    -   the function `and` takes a list of Bool values and returns a Bool value
    -   the Constraints `Ord` ensures that every element in the list is a Bool value obtained by `<=`
    
-   Using zip we can define a function that returns the list of all positions of a value in a list

    ```haskell
    positions :: Eq a => a -> [a] -> [Int]
    positions x xs = [i | (x',i) <- zip xs [0..], x == x']
    -- zip xs [0..] we have a list of pairs (x',i) 
    -- where x' is the element of list and i is the index
    -- Constraints Eq 表示positions函数接受的x值必须满足相等性检查，
    -- 即属于Equality class
    
    > positions 0 [1,0,0,1,0,1,1,0]
    [1,2,4,7]
    ```
    



##### 5. String Comprehensions

-   A string is a sequence of characters enclosed in **double quotes.**

    ```haskell
    "abc" :: String		-- which means
    ['a','b','c'] :: [Char]
    ```

-   Any polymorphic function operating on lists can be applied to strings

-   List comprehensions can also be used to define functions on strings

    ```haskell
    count :: Char -> String -> Int
    count x xs = length [x' | x' <- xs, x == x']
    > count 's' "Mississippi"
    ```



#### Exercises

1.   pythagorean

```python
# python pseudo code
def pyths(n):
    l = []
    for x in range(1, n):
        for y in range(1, n):
            if (x**2 + y**2 == n**2):
                l.append((x,y,n))
    return l
```

```haskell
-- ex.1
pyths :: Int -> [(Int,Int,Int)]
pyths n = [(x,y,n) | x <- [1..n-1], y <- [1..n-1], x^2 + y^2 == n^2] 
```



2.   perfect number

```python
# python pseudo code
def factor(n):
    l = []
    for i in range(1,n+1):
        if n%i == 0:
            l.append(i)
	return l

def perfect(n):
    l = []
    for i in range(1,n+1):
        if i == sum(factor(n)):
            l.append(i)
	return l
```

```haskell
factors :: Int -> [Int]
factors n = [x | x <- [1..n-1], n `mod` x == 0]

perfects :: Int -> [Int]
perfects n = [x | x <- [1..n], x == sum (factors x)]
```



3.   scalar product

```python
# python pseudo code
def scalar(l1, l2):
	if len(l1)==0 or len(l2)==0 or len(l1)!=len(l2):
        return "Cannot Operate!"
    sum = 0
    for i in range(len(l1)):
        sum += l1[i] * l2[i]
	return sum
```

```haskell
-- 在传入参数前确保 1.两个list不为空 2.两个list长度
scalar :: [Int] -> [Int] -> Maybe Int
scalar xs ys = if null xs || null ys || length xs /= length ys then Nothing
               else Just (sum [(xs !! i)*(ys !! i) | i <- [0..length xs-1]])
-- Just函数将Int的结果装入Maybe Int的类型中
-- 一定注意if和else语句的缩进，如果是自己打的tab可能会报错
```























