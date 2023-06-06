import System.IO

main :: IO ()
main = do 
    putStr "Enter your name: "
    name <- getLine
    putStrLn ("Hello, " ++ name ++ "!")

act :: IO (Char,Char)
act = do 
    x <- getChar
    getChar
    y <- getChar
    return (x,y)

strlen :: IO ()
strlen = do 
    putStr "Enter a string: "
    xs <- getLine
    putStr "The string has "
    putStr (show(length xs))
    putStrLn " characters!"
            
hangman :: IO ()
hangman = do 
    putStrLn "Think of a word: "
    word <- sgetLine
    putStrLn "Try to guess it: "
    play word

sgetLine :: IO String
sgetLine = do 
    x <- getCh
    if x == '\n' then
        do 
            putChar x
            return []
    else
        do 
            putChar '-'
            xs <- sgetLine
            return (x:xs)

getCh :: IO Char
getCh = do
    hSetEcho stdin False
    x <- getChar
    hSetEcho stdin True
    return x 

play :: String -> IO ()
play word = do
    putStr "? "
    guess <- getLine
    if guess == word then
        putStrLn "You got it!"
    else
        do 
            putStrLn (match word guess)
            play word

match :: String -> String -> String
match xs ys = [if elem x ys then x else '-'| x <- xs]


-- Exercise: The game of nim in Haskell
-- playNim :: IO ()
-- playNim = do
--     let ml = [(1,5),(2,4),(3,3),(4,2),(5,1)]
--     putStrLn (showBoard ml)
--     let x = fst userInput
--     let y = snd userInput
--     if (x<1 && x>5) then
--         putStrLn "Invalid input! Please type again!"
--         pu
    

-- showBoard :: [(Int,Int)] -> String
-- showBoard [] = ""
-- showBoard (x:xs) = show (fst x) ++ ": " ++ showStars (snd x) ++ "\n"
--                    ++ showBoard xs
        
-- showStars :: Int -> String
-- showStars 0 = ""
-- showStars n = "*" ++ showStars (n-1)

-- userInput :: IO (Char, Char)
-- userInput = do
--     putStrLn "Please enter a number of line"
--     x <- getChar
--     putStrLn "Please enter a number of stars"
--     y <- getChar
--     return (x,y)


