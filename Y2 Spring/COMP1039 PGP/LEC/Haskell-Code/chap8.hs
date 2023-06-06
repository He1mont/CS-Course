type Pos = (Int, Int)

origin :: Pos 
origin = (0,0)

left :: Pos -> Pos 
left (x,y) = (x-1,y)


-- lab06 Exercise
data Shape = Sphere Float | Cuboid Float Float Float | Cone Float Float

area :: Shape -> Float
area (Sphere r)     = 4 * pi * r^2
area (Cuboid w l d) = 2 * (w*l + w*d + l*d)
area (Cone r h)     = pi*r^2 + 1/3 * pi * r * sqrt (r^2 + h*2)

volume :: Shape -> Float
volume (Sphere r)     = 4/3 * pi * r^3
volume (Cuboid w l d) = w * l * d
volume (Cone r h)     = 1/3 * pi * r^2 * h


-- Exercise 3
data Tree a = Leaf a
            | Node (Tree a) a (Tree a)

treeSize :: Tree a -> Int
treeSize (Leaf _) = 1
treeSize (Node l _ r) = treeSize l + treeSize r + 1

isComplete :: Tree a -> Bool
isComplete (Leaf _) = True
isComplete (Node l _ r) = isComplete l && isComplete r && treeSize l == treeSize r

-- if you don't use parenthesis with Tree, the function don't treat it like a tree