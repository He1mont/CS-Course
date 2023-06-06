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


