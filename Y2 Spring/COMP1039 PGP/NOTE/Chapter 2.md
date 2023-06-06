## Chapter 2: First Steps

##### 1. Functions on lists

-   Select the first element
    -   `> head [1,2,3,4,5]`
-   Remove the first element
    -   `> tail [1,2,3,4,5]`
-   Remove the last element
    -   `> init [1,2,3,4,5]`
-   Select the nth element
    -   `> [1,2,3,4,5] !! 2`
-   Select the first n elements
    -   `> take 3 [1,2,3,4,5]`
-   Remove the first n elements
    -   `> drop 3 [1,2,3,4,5]`

-   Length
    -   `> length [1,2,3,4,5]`
-   Sum
    -   `> sum [1,2,3,4,5]`
-   Product
    -   `> product [1,2,3,4,5]`
-   Append
    -   `> [1,2,3] ++ [4,5]`
-   Reverse
    -   `> reverse [1,2,3,4,5]`



##### 2. Function Application

-   In Haskell, function application is denoted using space, and multiplication is denoted using *
-   Function application is assumed to have higher priority

-   Here are some basic functions and commands

    | function | command                               |
    | -------- | ------------------------------------- |
    | add      | `+`                                   |
    | subtract | `-`                                   |
    | multiply | `*`                                   |
    | divide   | `/`                                   |
    | modulo   | `mod a b` or `a mod b (mod with ``)`  |
    | 整除     | `div a b` or  `a div b (mod with ``)` |



##### 3. Useful GHCi Commands

<img src="assets/Screenshot 2023-03-19 at 17.16.14.png" alt="Screenshot 2023-03-19 at 17.16.14" style="zoom: 40%;" />



##### 4. Naming Requirements

-   Function and argument names must begin with **a lower-case letter**
-   By convention, list arguments usually have an **suffix** on their name
    -   e.g.: `xs, ns, nss`



##### 5. The Layour Rule

-   In a sequence of definitions, each definition must begin in precisely the same column:

<img src="assets/Screenshot 2023-03-19 at 17.22.51.png" alt="Screenshot 2023-03-19 at 17.22.51" style="zoom: 33%;" />

##### 6. Grouping

-   implicit grouping

    ```haskell
    a = b + c
    	where
    		b = 1
    		c = 2
    d = a * 2
    ```

-   explicit grouping

    ```haskell
    a = b + c
    	where {
    		b = 1;
    		c = 2
    	}
    d = a * 2
    ```

    









