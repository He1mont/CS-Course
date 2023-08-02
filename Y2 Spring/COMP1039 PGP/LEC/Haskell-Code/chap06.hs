-- reverse :: [a] -> [a]
-- reverse [] = []
-- reverse (x:xs) = reverse xs ++ [x]

-- a fast reverse that avoid (++) for each element
-- instead, we use cons(:)
fastRev :: [a] -> [a]
fastRev xs = fastRev' xs []
    where
        fastRev' :: [a] -> [a] -> [a]
        fastRev' [] acc = acc                       -- Base Case
        fastRev' (x:xs) acc = fastRev' xs (x:acc)   -- Ind. Step

-- merges two sorted lists of values to give a single sorted list
merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = if x<=y then x : merge xs (y:ys)
                              else y : merge (x:xs) ys