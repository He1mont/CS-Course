data Shape = Circle Float | Rect Float Float deriving Show

square :: Float -> Shape
square n = Rect n n

area :: Shape -> Float
area (Circle r) = pi * r^2
area (Rect x y) = x * y

-- -- Circle and Rect can be viewed as functions that construct values of type Shape:
-- Circle :: Float -> Shape
-- Rect   :: Float -> Float -> Shape

mymap f = foldr (\x xs -> f x : xs) []
myfilter p = foldr (\x xs -> if p x then x:xs else xs) []
