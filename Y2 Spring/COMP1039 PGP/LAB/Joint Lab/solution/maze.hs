-- Program: maze
-- 
-- A maze is represented as a list of Strings. 
-- Each character has the following meaning:
-- '.' = empty space;
-- '#' = wall;
-- 'A' = starting point;
-- 'B' = finish point.
--
-- Task is to find an unbroken path across empty spaces from A to B, without hitting walls or leaving the maze. Show the path as a trail of asterisks '*'.
--
-- Write programs that will do this by depth-first and breadth-first search from A to B.

-- 4 example mazes.
maze1 = ["A#.", 
        "...", 
        "#.B"]
maze2 = ["...A",
         "B#..",
		 "...."]
maze3 = ["B#A...",
         "..##..",
		 "#..#..",
		 "..###.",
		 "#....."]
maze4 = [".......###",
         ".###......",
         "...#A.#...",
         "####.##...",
         ".#....#...",
         "...####...",
         "#.##......",  
         "...#..####",
         "#....#.B..",
         "####......"]

-- Utility function to show a maze.
showMaze :: [String] -> IO()
showMaze [] = do putStrLn ""
showMaze (x:xs) = do putStrLn ("   " ++ x)
                     showMaze xs

-- Represent positions in a maze by tuples (x,y) where x is the xth row and y is the yth column, counting from 1.

-- Return the character at a certain position of a maze.
mazeAt :: [String] -> (Int,Int) ->  Char					 
mazeAt (row:m) (1,y) = row!!(y-1)
mazeAt (row:m) (x,y) = mazeAt m (x-1,y)

-- Return index of the first occurence of an element in a list, or return -1 if it is not in the list.
indexAt :: Eq a => [a] -> a -> Int
indexAt [] _ = -1
indexAt (x:xs) y | x==y = 0
                 | otherwise = if i== -1 then -1 else i+1
                                 where i = indexAt xs y

-- Add two tuples together.
addXY :: (Int,Int) -> (Int,Int) -> (Int,Int)
addXY (x1,y1) (x2,y2) = (x1+x2,y1+y2)

-- Find the position of the first occurrence of a character in a maze.
mazeFind :: [String] -> Char -> (Int,Int)
mazeFind [] _ = (-1,-1)
mazeFind (row:m) ch = if i== -1 then
                       if mF==(-1,-1) then mF else mF `addXY` (1,0)
                     else 
					   (1,i+1)
				     where 
				       i = indexAt row ch
				       mF = mazeFind m ch

-- Set the character at a position in a maze and return the updated maze.
mazeSet :: [String] -> (Int,Int) ->  Char -> [String]
mazeSet (row:m) (1,y) ch = (take (y-1) row ++ [ch] ++ drop y row):m
mazeSet (row:m) (x,y) ch = row:mazeSet m (x-1,y) ch

-- All possible movements from a position.
mazeSteps = [(-1,0),(0,-1),(1,0),(0,1)]

-- Return the first non-empty list from a list of lists;
-- otherwise return [] if no non-empty list is found.
firstNotEmpty :: [[a]] -> [a]
firstNotEmpty [] = []
firstNotEmpty ([]:xs) = firstNotEmpty xs
firstNotEmpty (x:xs) = x

-- Return true if the given position is within the bounds of a maze.
mazeInBounds :: [String] -> (Int,Int) -> Bool
mazeInBounds m1 (x,y) = 1<=x && x<=length m1 && 1<=y && y<=length (head m1)

-- Depth first search.
-- The search is performed recursively:
--  m1 = partial solution, so far;
--  pos = position to explore next.
-- Returns [] if no solution is possible from this position, or the path to B.
searchDF1 :: [String] -> (Int,Int) -> [String]
searchDF1 m1 pos 
  | not (mazeInBounds m1 pos) || ch == '#' || ch == '*' = []
  | ch == 'B' = m1
  | otherwise = firstNotEmpty 
     (map (searchDF1 (mazeSet m1 pos '*') ) 
	      (map (addXY pos) mazeSteps)  )
  where 
    ch = mazeAt m1 pos

-- Start the search in a maze from position A.
-- e.g. showMaze (searchDF maze1) 
searchDF :: [String] -> [String]
searchDF m1 = searchDF1 m1 (mazeFind m1 'A')

-- Breadth first search. 
-- The search is performed recursively with a queue of positions to explore next.
-- Each element of the queue is a tuple containing:-
--  m1 = partial solution, so far;
--  pos = position to explore next.
-- Returns [] if no solution is possible from this position, or the path to B.
searchBF1 :: [ ([String], (Int,Int) ) ] -> [String]
searchBF1 [] = []
searchBF1 ( (m1,pos):searchQ ) 
  | not (mazeInBounds m1 pos) || ch == '#' || ch == '*' = searchBF1 searchQ
  | ch == 'B' = m1
  | otherwise = searchBF1 (searchQ ++ 
      [ (mazeSet m1 pos '*', pos') | pos' <- map (addXY pos) mazeSteps] )
  where 
    ch = mazeAt m1 pos

-- Start the search in a maze from position A.
-- e.g. showMaze (searchBF maze1) 
searchBF :: [String] -> [String]
searchBF m1 = searchBF1 [(m1, mazeFind m1 'A')]
