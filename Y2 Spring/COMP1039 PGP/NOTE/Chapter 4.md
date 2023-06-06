## Chapter 4: Defining functions

##### 1. Conditional expressions and Guarded equations

-   conditional expressions can be nested

    ```haskell
    signum :: Int -> Int
    signum n = if n < 0 then -1 else
    			if n == 0 then 0 else 1
    ```

    -   In Haskell, conditional expressions must always have an else branch

-   **Guarded Equations**

    ```haskell
    abs n | n >= 0 		= n
    	  | otherwise	= -n
    ```

    -   Guarded equations could be used to make definitions involving multiple conditions



##### 2. Pattern Matching

-   definition of `not`

    ```haskell
    not :: Bool -> Bool
    not False = True
    not True = False
    ```

    -   not maps False to True, and True to False

-   definition of `&&`

    1.   Truth table

    ```haskell
    (&&) :: Bool -> Bool -> Bool
    True  && True  = True
    True  && False = False
    False && True  = False
    False && False = False
    ```

    2.   Or can be defined more compactly by

    ```haskell
    True && True = True
    _    && _    = False
    ```

    3.   The following definition avoids evaluating the second argument

    ```haskell
    True  && b = b
    False && _ = False
    ```

-   **The underscore symbol _ is a wildcard pattern that matches any argument value**

-   Patterns are matched in order. The following definition always returns False.

    ```haskell
    _    && _    = False
    True && True = True
    ```

-   Patterns may not repeat variables. The following definition gives an error

    ```haskell
    b && b = b
    _ && _ = False
    ```



##### 3. List patterns

-   Internally, every non-empty list is constructed by repeated use of **an operator (:) called "cons"** that adds an element to the start of a list.

-   Functions on lists can be defined using `x:xs` patterns

    ```haskell
    head :: [a] -> a
    head (x:_) = x
    
    tail :: [a] -> [a]
    tail (_:xs) = xs
    ```

-   `x:xs` patterns only match **non-empty lists**

-   `x:xs` patterns must be **parenthesised**



##### 4. Lambda Expressions

-   Functions can be constructed without naming the functions by using **lambda expressions**

    `\x -> x + x`

-   used to give a **formal meaning** to functions defined using **currying**.

    ```haskell
    add x y = x + y		-- it means
    add = \x -> (\y -> x + y)
    ```

-   useful when defining functions that **returns functions as results**

    ```haskell
    const :: a -> b -> a
    const x _ = x
    
    -- more naturally defined by
    const :: a -> (b -> a)
    const x = \_ -> x
    ```
    
-   used to avoid naming functions that are only **referenced once**

    ```haskell
    odds n = map f [0..n-1]
    		 where
    		 	f x = x*2 + 1
    -- it can be simplified to
    odds n = map (\x -> x*2 + 1)[0..n-1]
    ```

##### 5. Operator sections

-   An operator written between its two arguments can be converted into a curried function written before its two arguments by using parentheses

    ```haskell
    > 1+2
    3
    > (+) 1 2
    3
    ```

-   Also allows one of the arguments of the operator to be included in the parentheses

    ```haskell
    > (1+) 2
    3
    > (+2) 1
    3
    ```

    -   `(+), (x+), (+y)` are called **sections**

-   Useful functions can be constructed using sections

    ```haskell
    (1+)	-- successor function
    (1/)	-- reciprocation function
    (*2)	-- doubling function
    (/2)	-- halving function
    ```




#### Exercises

1.   define a safetail

```haskell
-- ex1.a conditional expression
safetail1 :: [a] -> [a]
safetail1 xs = if (length xs) <= 1 then [] else tail xs

-- ex1.b guarded equation
safetail2 :: [a] -> [a]
safetail2 xs | (length xs) <= 1 = []
             | otherwise        = tail xs

-- ex1.c list patterns
safetail3 :: [a] -> [a]
safetail3 (_:xs) = xs 
safetail3 ([]) = []
```



2.   define an or function

```haskell
-- ex2
(&&) :: Bool -> Bool -> Bool
True  && True  = True
True  && False = False
False && True  = False
False && False = False

-- method 1
or1 :: Bool -> Bool -> Bool   -- or is a defined function, you cannot name a function 'or'
or1 True  True  = True        -- or1是个函数，照理来说不能当作operator一样放在两个变量当中使用
or1 True  False = True
or1 False True  = True
or1 False False = False

-- method 2
or2 :: Bool -> Bool -> Bool
or2 False False = False
or2 _ _ = True

-- method 3
or3 :: Bool -> Bool -> Bool
or3 True _ = True
or3 False b = b
```



3.   redefine `&&` without patterns

```haskell
-- ex.3
&& :: Bool -> Bool -> Bool
(&&) a b = if a == True then if b == True then True else False else False
```

```haskell
-- ex.4
&& :: Bool -> Bool -> Bool
(&&) a b = if a == False then False else b
```

