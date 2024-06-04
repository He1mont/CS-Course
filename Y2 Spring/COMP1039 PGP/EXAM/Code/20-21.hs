-- Q3
-- (f)
getValues :: [(Int, String)] -> Int -> [String]
getValues (x:xs) k
    | fst x == k  = (snd x) : getValues xs k
    | otherwise   = getValues xs k 

-- (i)(j)
applyToLists :: [a] -> [b] -> (a->b->c) -> [c]
applyToLists [] _ _ = []
applyToLists _ [] _ = []
applyToLists (x:xs) (y:ys) f = (f x y) : applyToLists xs ys f 

-- Q4
-- (c)
squareList :: Int -> [Int]
squareList n 
    | n < 0     = []
    | otherwise = [x*x| x <- [0..n]]

-- (d)
d1 = (\x -> \y -> x+y) 3 4
d2 = (\x -> (True, 2)) (False, 3)
d3 = (\x -> (\y -> x (x y))) (\z -> z+2) 4

-- Before (e)
data Tree a = Leaf a
            | Node (Tree a) a (Tree a)
t :: Tree Int
t = Node (Node (Leaf 1) 3 (Leaf 4)) 5
         (Node (Leaf 6) 7 (Leaf 9))

foldt :: (b->b->b) -> (a->b) -> Tree a -> b 
foldt _ g (Leaf x) = g x
foldt f g (Node t1 x t2) = f (f (g x) (foldt f g t1)) (foldt f g t2)

occurs x = foldt (||) (==x)

-- (j)
sumTree :: Tree Int -> Int
sumTree = foldt (+) id

