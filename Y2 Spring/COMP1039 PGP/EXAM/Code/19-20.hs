-- Q3 c
s :: Int -> Float
s i | even i    = -1
    | otherwise = 1

piSub :: Int -> [Float]
piSub k = piSubHelper k 0

piSubHelper :: Int -> Int -> [Float]
piSubHelper k num = sth : piSubHelper k (num+1)
    where
        tmp = 2*(k+num)-1
        sth = s (k+num) / fromIntegral tmp

getPi :: Int -> Float
getPi n = sum (take n (piSub 1)) * 4

-- Q4 

-- (a)
type Emp = (Int, String, Int, Int, String)

-- (d)
empType :: Emp -> Int
empType (_, _, _, a, _) = a 

empInc :: Emp -> Int
empInc (_, _, a, _, _) = a 

-- (e)
empByType :: [Emp] -> Int -> [Emp]
empByType [] _ = []
empByType (x:xs) n
    | n == empType x  = x : empByType xs n
    | otherwise         = empByType xs n

-- (h)
taxCalcs :: [Emp -> Int]
taxCalcs = [\x -> max (div (empInc x - 10000) 10) 0,
            \x -> max (div (empInc x - 15000) 8) 0,
            \x -> max (div (empInc x - 5000) 12) 0]

empsTax :: [Emp] -> [Int]
empsTax [] = []
empsTax (x:xs) = (taxCalcs !! (t-1)) x : empsTax xs
    where
        t = empInc x

-- (i)
incTaxByType :: [Emp] -> Int -> (Int, Int, Int)
incTaxByType es t = (t, sum(map empInc ets), sum(empsTax ets))
    where  
        ets = empByType es t

-- (k)
incTaxTotals :: [Emp] -> [(Int, Int, Int)]
incTaxTotals es = map (incTaxByType es) [1,2,3]

ml :: [(Int, Int, Int)]
ml = [(1,12,13),(2,22,23),(3,32,33)]

es :: [Emp]
es = [(1,"",1,1,""), (2,"",2,2,""), (3,"",3,3,"")]

-- (l)
showIncTaxTotals :: [Emp] -> IO()
showIncTaxTotals es = do
    let ml = incTaxTotals es
    let len = length ml
    putStrLn "Total income and tax by employee type: "
    putStr "Type\tIncome\tTax\n"
    whileLoop ml len
    putStrLn "End of report"


whileLoop :: [(Int,Int,Int)] -> Int -> IO()
whileLoop es 0 = return()
whileLoop ((t, i, tax):xs) len = do
    putStrLn ""
    putStr(show t)
    putStr "\t"
    putStr(show i)
    putStr "\t"
    putStr(show tax)
    putStrLn ""
    whileLoop xs (len-1)
