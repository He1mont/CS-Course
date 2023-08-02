## Chapter 3: Types and Classes

##### 1. Types in Haskell

-   A **type** is a name for a collection of related values
-   Applying a function to arguments of the wrong time is called a **type error**
-   an expression e would produce a value of type t, written as:
    -   `e :: t`



##### 2. Int type and Integer Type

-   `int` : fixed precision integers, **faster**

-   `Integer`: **arbitrary-precision** integers



##### 3. Different types

-   List types
    -   a sequence of values **of the same type**
    -   [t] is the type of lists with elements of type t
    -   the type of components is unrestricted
-   Tuple types
    -   a sequence of values **of different types**
    -   the type of components is unrestricted
-   Function types
    -   a mapping from values of one type to values of another type



##### 4. Curried functions

-   add

    ```haskell
    add' :: Int -> (Int -> Int)
    add' x y = x+y
    ```

    -   add' takes an integer x and returns a function add' x
    -   In turn, this function takes an integer y and returns the result x+y

-   multiply

    ```haskell
    mult :: Int -> (Int -> (Int -> Int))
    mult x y z = x*y*z
    ```

    -   mult takes an integer x and returns a function mult x
    -   which in turn takes an integer y and returns a function mult x y
    -   which finally takes an integer z and returns the result x *y *z

-   Why is Curring Useful?

    -   **more flexible than functions on tuples**
    -   useful functions can often be made by <u>partially applying</u> a curried function

-   The arrow -> associates to the right

    -   `Int -> Int -> Int -> Int` means `Int -> (Int -> (Int -> Int))`

-   Function application associates to the left

    -   mult x y z



##### 5. Polymorphic Functions

-   A function is called **<u>polymorphic</u>** if its type contains one or more type variables

    -   `length :: [a] -> int`

-   some defined polymorphic functions

    ```haskell
    fst :: (a,b) -> a
    head :: [a] -> a
    take :: Int -> [a] -> [a]
    zip :: [a] -> [b] -> [(a,b)]
    id :: a -> a
    ```



##### 6. Overloaded Functions

-   A polymorphic function is called **<u>overloaded</u>** if its type contains one or more class constraints
    -   `(+) :: Num a => a -> a -> a`
    -   For any numeric type a, (+) takes two values of type a and returns a value of type a
    -   =>: type constraint, `Num a =>`means arguments should be of type class Num



##### 7. Type classes

-   `Num` : Numeric types
    -   `(+) :: Num a => a -> a -> a`
-   `Eq`: Equality types
    -   `(==) :: Eq a => a -> a -> Bool `
-   `Ord`: Ordered types
    -   `(<) :: Ord a => a -> a -> Bool `



##### 8. Hints and Tips

-   Begin by writing down its type when defining new functions
-   State the type of every new function defined within a script
-   Take care to include necessary class constraints when stating types of polymorphic functions



#### Exercises

1.   Types of the follwing values

```haskell
['a','b','c'] :: [Char]
('a','b','c') :: (Char, Char, Char)
[(False, '0'), (True, '1')] :: [(Bool, Char)]
([False, True], ['0', '1']) :: ([Bool], [Char])
[tail, init, reverse] :: [[a] -> [a]
```

-   line 5: tail, init, reverse都是内置函数



2.   Types of the following functions

```haskell
second xs = head (tail xs)
swap (x,y) = (y,x)
pair x y = (x,y)
double x = x*2
palindrome xs = reverse xs == xs
twice f x = f (f x)
```

```haskell
second :: [a] -> a
swap :: (a,b) -> (b,a)
pair :: a -> b -> (a,b)
double :: Num a => a -> a
palindrome :: Eq => a -> [a] -> Bool
twice :: (a -> a) -> a -> a
```

-   line 4: function `double` must return a value of class `Num`, so there's a class constraint
-   line 5: function `palindrome` must return a value of class `Eq`
-   line 6: function `twice` firstly takes an argument of function `(a->a)`, and then takes an argument of value `a`. Finally, it returns a value `a`.



















