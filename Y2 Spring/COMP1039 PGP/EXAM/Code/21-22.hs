-- Q3
-- (c)
areUnique :: Eq a => [a] -> Bool 
areUnique [] = True
areUnique (x:xs)
    | null xs   = True
    | otherwise = not(elem x xs) && areUnique xs

-- Q4
-- (a)
data Matrix = Row [Float] Matrix | Null
m1 :: Matrix
m1 = Row [2.3, 4.5, 1.2] (Row [-0.4, 3.2, 3.4] Null)

m2 :: Matrix
m2 = Row [1.2, -1] (Row [4.5, -0.9] (Row [2.3, 1.8] Null))

m3 :: Matrix
m3 = transposeMatrix m2

-- (b)
legitMatrix :: Matrix -> Bool 
legitMatrix Null = True
legitMatrix (Row _ Null) = True 
legitMatrix (Row up1 (Row up2 down)) = (length up1 == length up2) && legitMatrix (Row up2 down)

-- (c)
sizeMatrix :: Matrix -> (Int, Int)
sizeMatrix m = (sizeRow m, sizeCol m)

sizeRow :: Matrix -> Int 
sizeRow Null = 0
sizeRow (Row r m) = 1 + sizeRow m 

sizeCol :: Matrix -> Int 
sizeCol Null = 0
sizeCol (Row r m) = length r 

-- (d)
insertColumn :: Matrix -> [Float] -> Matrix
insertColumn m [] = m
insertColumn Null _ = Null 
insertColumn (Row r m) (x:xs) = Row (x:r) (insertColumn m xs) 

-- (e)
emptyMatrix :: Int -> Matrix
emptyMatrix 0 = Null 
emptyMatrix n = Row [] (emptyMatrix (n-1))

-- (f)
transposeMatrix :: Matrix -> Matrix 
transposeMatrix Null = Null
transposeMatrix (Row r m) = transHelper (Row r m) t 
    where 
        t = emptyMatrix (length r)

transHelper :: Matrix -> Matrix -> Matrix 
transHelper Null t = t 
transHelper (Row r m) t = insertColumn t' r 
    where
        t' = transHelper m t 

-- (g)
addRows :: [Float] -> [Float] -> [Float]
addRows l1 l2 = [x+y | (x,y) <- zip l1 l2]

-- (h)
(+#+) :: Matrix -> Matrix -> Matrix
m +#+ Null = m
(Row r1 m1)+#+(Row r2 m2) = Row (addRows r1 r2) (m1 +#+ m2)

-- (i)
(+##+) :: Matrix -> Matrix -> Maybe Matrix
m1 +##+ m2 
    | legitMatrix m1 && legitMatrix m2 &&
      sizeMatrix m1 == sizeMatrix m2 = Just (m1 +#+ m2)
    | otherwise                      = Nothing

-- (j)
showMatrix :: Matrix -> IO()
showMatrix Null = putStrLn ""
showMatrix (Row r m) = do 
    putStr "["
    putStr(showRow r)
    putStr "]\n"
    showMatrix m 

showRow :: [Float] -> String
showRow [] = ""
showRow xs 
    | length xs == 1  = show (head xs)
    | otherwise       = show (head xs) ++ "\t" ++ showRow (tail xs) 

