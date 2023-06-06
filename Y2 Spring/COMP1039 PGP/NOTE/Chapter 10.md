## Chapter 10: Interactive Programming

#### 1. Basic Actions

-   `getChar :: IO Char`
    -   read a character and returns the character as its result value
-   `putChar :: Char -> IO()`
    -   writes the character c to the screen and returns no result value
-   `return :: a -> IO a`
    -   return the value

#### 2. Sequencing

-   A sequence of actions can be combined as a single composite action using `do`

```haskell
act :: IO (Char,Char)
act = do
    x <- getChar
    getChar
    y <- getChar
    return (x,y)
```



#### 3. Derived Primitives

-   Read a string from the keyboard

```haskell
getLine :: IO String
getLine = do 
	x <- getChar
	if x == '\n' then		-- empty list
		return []
	else
		do xs <- getLine
		   return (x:xs)
```

-   Write a string to the screen

```haskell
putStr :: String -> IO()
putStr [] = return ()
putStr (x:xs) = do putChar x
				   putStr xs

putStrLn :: String -> IO()
putStrLn xs = do putStr xs
				 putChat '\n'
```

-   Example

```haskell
strlen :: IO ()
strlen = do putStr "Enter a string: "
            xs <- getLine
            putStr "The string has "
            putStr (show(length xs))
            putStrLn " characters!"
```















