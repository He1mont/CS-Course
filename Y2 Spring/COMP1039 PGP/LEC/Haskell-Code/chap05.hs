-- zip :: [a] -> [b] -> [(a,b)]

-- Using zip we can define a function returns the list of all pairs of adjacent elements 
pairs :: [a] -> [(a,a)]
pairs xs = zip xs (tail xs)

-- Using pairs we can define a function that decides if the elements in a list are sorted
sorted :: Ord a => [a] -> Bool
sorted xs = and [x <= y | (x,y) <- pairs xs]

positions :: Eq a => a -> [a] -> [Int]
positions x xs = [i | (x',i) <- zip xs [0..], x == x']
-- zip xs [0..] we have a list of pairs (x',i) 
-- where x' is the element of list and i is the index



-- ex.1
pyths :: Int -> [(Int,Int,Int)]
pyths n = [(x,y,n) | x <- [1..n-1], y <- [1..n-1], x^2 + y^2 == n^2] 

-- Python pseudo Code
-- def pyths(n):
--     l = []
--     for x in range(1, n):
--         for y in range(1, n):
--             if (x**2 + y**2 == n**2):
--                 l.append((x,y,n))
--     return l


-- ex.2
-- give a integer and return its factors
factors :: Int -> [Int]
factors n = [x | x <- [1..n-1], n `mod` x == 0]

perfects :: Int -> [Int]
perfects n = [x | x <- [1..n], x == sum (factors x)]

-- ex.3
-- 在传入参数前确保 1.两个list不为空 2.两个list长度
scalar :: [Int] -> [Int] -> Maybe Int

scalar xs ys = if null xs || null ys || length xs /= length ys then Nothing
               else Just (sum [(xs !! i)*(ys !! i) | i <- [0..length xs-1]])
-- Just函数将Int的结果装入Maybe Int的类型中
-- 一定注意if和else语句的缩进，如果是自己打的tab可能会报错