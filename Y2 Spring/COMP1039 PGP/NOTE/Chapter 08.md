## Chapter 8: Declaring Types and Classes

#### 1. Type Declarations

-   A new name for an existing type can be defined using a **type declaration**

    `type String = [Char]`

-   Type declarations can be used to make other types easier to read

```haskell
type Pos = (Int, Int)

origin :: Pos
origin = (0,0)

left :: Pos -> Pos
left (x,y) = (x-1, y)
```



-   Type declarations can also have parameters

```haskell
type Pair a = (a, a)

mult :: Pair Int -> Int
mult (m,n) = m*n

copy :: a -> Pair a
copy x = (x,x)
```



-   Type declarations can be **nested**, but **not recursive**

```haskell
type Pos = (Int, Int)
type Trans = Pos -> Pos			-- we can do that

type Tree = (Int, [Tree])		-- we CANNOT do that
```



#### 2. Data Declarations

-   A completely new type can be defined by specifying its values using a **data declaration**

    -   `data Bool = False | True`

    -   The two values False and True are called the **constructors** for the type `Bool`
    -   Type and Constructor names must begin with an **Upper-case** letter

```haskell
data Answer = Yes | No | Unknown

answers :: [Answer]
answers = [Yes, No, Unknown]

flip :: Answer -> Answer
flip Yes 	 = No
flip No 	 = Yes
flip Unknown = Unknown
```

-   The **constructors** in a data declarationg can also hava parameters

```haskell
data Shape = Circle Float | Rect Float Float

square :: Float -> Shape
square n = Rect n n

area :: Shape -> Float
area (Circle r) = pi * r^2
area (Rect x y) = x * y

-- Circle and Rect can be viewed as functions that construct values of type Shape:
-- but those lines could not be compiled by haskell
Circle :: Float -> Shape
Rect   :: Float -> Float -> Shape
```

-   **Data declarations themselves** can also have parameters

```haskell
data Maybe a = Nothing | Just a

safediv :: Int -> Int -> Maybe Int
safediv _ 0 = Nothing
safediv m n = Just (m `div` n)

safehead :: [a] -> Maybe a
safehead [] = Nothing
safehead xs = Just (head xs)
```



#### 2*. lab06 Exercises

```haskell
data Shape = Sphere Float | Cuboid Float Float Float | Cone Float Float

area :: Shape -> Float
area (Sphere r)     = 4 * pi * r^2
area (Cuboid w l d) = 2 * (w*l + w*d + l*d)
area (Cone r h)		= pi*r^2 + 1/3 * pi * r * sqrt (r^2 + h*2)

volume :: Shape -> Float
volume (Sphere r) 	  = 4/3 * pi * r^3
volume (Cuboid w l d) = w * l * d
volume (Cone r h)     = 1/3 * pi * r^2 * h
```



#### 3. Recursive Types

-   New types can be declared in terms of themselves, i.e. **recursive.**

```haskell
data Nat = Zero | Succ Nat
-- Nat  : natural number
-- Zero : 0
-- Succ : successor function 1+

nat2int :: Nat -> Int
nat2int Zero = 0
nat2int (Succ n) = 1 + nat2int n

int2nat :: Int -> Nat
int2nat 0 = Zero
int2nat n = Succ (int2nat (n-1))

-- Use conversion
add :: Nat -> Nat -> Nat
add m n = int2nat (nat2int m + nat2int n)

-- Use Recursion
add Zero	 n = n
add (Succ m) n = Succ (add m n)
```



#### 4. Arithmetic Expressions

-   Using recursion, a suitable new type to represent such expressions can be declared by:

```haskell
data Expr = Val Int
		  | Add Expr Expr
          | Mul Expr Expr
```

-   Now easy to define functions that process expressions

```haskell
-- how big is the expression
size :: Expr -> Int
size (Val n)   = 1
size (Add x y) = size x + size y
size (Mul x y) = size x + size y

-- the value of the function
eval :: Expr -> Int
eval (Val n)   = n
eval (Add x y) = eval x + eval y
eval (Mul x y) = eval x * eval y
```

-   The Three constructors have types

```haskell
Val :: Int -> Expr
Add :: Expr -> Expr -> Expr
Mul :: Expr -> Expr -> Expr

-- e of folde stands for expression
-- Actually there is no function called folde, but we will do it in exercise
size = folde 1  (+) (*)
eval = folde id (+) (*)
```



#### 5. Binary Tree

-   Using recursion, a suitable new type to represent such binary trees can be declared by:

```haskell
data Tree a = Leaf a
		 	| Node (Tree a) a (Tree a)

t :: Tree Int
t = Node (Node (Leaf 1) 3 (Leaf 4)) 5
	 	 (Node (Leaf 6) 7 (Leaf 9))
```

-   a function `occurs` that decides **if a given value occurs in a binary tree**

```haskell
occurs :: Ord a => a -> Tree a -> Bool
occurs x (Leaf y) 	  = x == y
occurs x (Node l y r) = x == y || occurs x l || occurs x r
```

-   a function `flatten` that returns the list of all the values contained in a tree

```haskell
flatten :: Tree a -> [a]
flatten (Leaf x)     = [x]
flatten (Node l x r) = flatten l ++ [x] ++ flatten r
```

-   rewrite function `occurs` for a binary tree

```haskell
occurs x (Leaf y) = x == y
occurs x (Node l y r) | x == y = True
					  | x < y  = occurs x l
                      | x > y  = occurs x r
```



#### Exercise

-   Q1: define function `multiple` with function add

```haskell
multiple :: Int -> Int -> Int
multiple x 1 = x
multiple x y = add x (multiple x y-1)

data Nat = Zero | Succ Nat deriving Show
-- Succ (Succ Zero)

add Zero n = n
add (Succ m) n = Succ (add m n)

mult Zero n = Zero
mult (Succ m) n = add n (mult m n)
-- (1+m) n = 1 + mn
```



-   Q2: define a suitable function `folde` for expressions
    -   有点太难了所以跳过




-   Q3: Define a function that decides if a binary tree is **complete.**
    -   Complete: the two sub-trees of every node are of **equal size**.

```haskell
check_complete :: Tree -> Bool


check_branch :: Char -> Tree -> Tree
check_branch _ (Leaf a) = Leaf a
check_branch l (Node l x r) = l
check_branch r (Node l x r) = r
```



















###### 
