> import Geography
> import MyMaze

======================================================================

Draw a maze.

***************************************
*              Question 2             *
* Complete the definition of drawMaze *
***************************************

> drawMaze :: Maze -> IO()
> drawMaze maze = putStr ( unlines ( [ ( draw_N maze x (fst(sizeOf maze)) ) ++ "\n" ++ (draw_E maze x (fst(sizeOf maze)) ) | x <- [snd(sizeOf maze)-1, (snd(sizeOf maze)-2)..(-1)] ] ) )

> draw_N :: Maze -> Int -> Int -> String
> draw_N maze y (-1) = ""
> draw_N maze y x  = draw_N maze y (x-1) ++ if ( hasWall maze (x,y) N ) then "+--" else "+  "

> draw_E :: Maze -> Int -> Int -> String
> draw_E maze y (-2) = ""
> draw_E maze y x  = draw_E maze y (x-1) ++ if ( hasWall maze (x,y) E ) then "|  " else "   "


======================================================================

Solve the maze, giving a result of type:

> type Path = [Direction]

***************************************
*            Questions 3--4           *
*     Complete the definition of      *
*              solveMaze              *
***************************************

> solveMaze :: Maze -> Place -> Place -> Path
> solveMaze maze start target = solveMazeIter maze target [(start,[])]

> solveMazeIter :: Maze -> Place -> [(Place, Path)] -> Path
> solveMazeIter maze target (x:xs)
>     | fst x == target = snd x
>     | otherwise       = solveMazeIter maze target (xs++curr)
>   where curr = (if hasWall maze (fst x) N == True then [] else [(move N (fst x),snd x ++ [N])]) ++
>                (if hasWall maze (fst x) S == True then [] else [(move S (fst x),snd x ++ [S])]) ++
>                (if hasWall maze (fst x) E == True then [] else [(move E (fst x),snd x ++ [E])]) ++
>                (if hasWall maze (fst x) W == True then [] else [(move W (fst x),snd x ++ [W])])

> fastSolveMaze :: Maze -> Place -> Place -> Path
> fastSolveMaze maze start target = fastSolveMazeIter maze target [] [(start,[])]

> fastSolveMazeIter :: Maze -> Place -> [Place] -> [(Place,Path)] -> Path -- maze, target, visited, queue, answer
> fastSolveMazeIter maze target visited [] = error "Impossible maze"
> fastSolveMazeIter maze target visited (x:xs)
>     | fst x == target = snd x
>     | otherwise       = fastSolveMazeIter maze target (visited ++ [fst x]) (xs ++ curr)
>   where curr = (if hasWall maze (fst x) N == True || ((move N (fst x)) `elem` visited) then [] else [(move N (fst x),snd x ++ [N])]) ++
>                (if hasWall maze (fst x) S == True || ((move S (fst x)) `elem` visited) then [] else [(move S (fst x),snd x ++ [S])]) ++
>                (if hasWall maze (fst x) E == True || ((move E (fst x)) `elem` visited) then [] else [(move E (fst x),snd x ++ [E])]) ++
>                (if hasWall maze (fst x) W == True || ((move W (fst x)) `elem` visited) then [] else [(move W (fst x),snd x ++ [W])])

*Main> length(fastSolveMaze largeMaze  (0,0) (22,21)  )
271
(0.10 secs, 10,819,632 bytes)
*Main> length(fastSolveMaze smallMaze   (0,0) (3,2)  )
7
(0.01 secs, 113,968 bytes)


With the new type of maze (i e MyMaze)
--------------------------------------

*Main> length(fastSolveMaze largeMaze  (0,0) (22,21)  )
271
(0.04 secs, 11,785,624 bytes)

*Main> fastSolveMaze impossibleMaze   (0,0) (2,2)
*** Exception: Impossible maze
CallStack (from HasCallStack):
  error, called at Main.lhs:53:46 in main:Main


======================================================================

Some test mazes.  In both cases, the task is to find a path from the bottom
left corner to the top right.

First a small one

> smallMaze :: Maze
> smallMaze =
>   let walls = [((0,0), N), ((2,2), E), ((2,1),E), ((1,0),E),
>                ((1,2), E), ((1,1), N)]
>   in makeMaze (4,3) walls

Now a large one.  Define a function to produce a run of walls:

> run (x,y) n E = [((x,y+i),E) | i <- [0..n-1]]
> run (x,y) n N = [((x+i,y),N) | i <- [0..n-1]]

And here is the maze.

> emptyMaze :: Maze
> emptyMaze = makeMaze (10,10) []

+--+--+--+--+--+--+--+--+--+--+
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+  +  +  +  +  +  +  +  +  +  +
|                             |
+--+--+--+--+--+--+--+--+--+--+

fastSolveMaze verylargeEmptyMaze (0,0) (7,7)
[N,N,N,N,N,N,N,E,E,E,E,E,E,E]
(6.35 secs, 8,016,786,544 bytes)

> singlePathMaze :: Maze
> singlePathMaze = makeMaze (50,50) walls
>   where walls = concat [run (i,0) 49 E | i <- [0,2..49]] ++ concat [run (i,1) 49 E | i <- [1,3..49]]

*Main> length(fastSolveMaze singlePathMaze (0,0) (49,49))
2450
(0.47 secs, 407,766,920 bytes)

> quiteHardMaze :: Maze
> quiteHardMaze = makeMaze (25,25) walls
>   where walls = concat [run (i,0) 24 E | i <- [0,2..24]]

*Main> fastSolveMaze quiteHardMaze (0,0) (24,24)
[N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E]
(0.12 secs, 55,782,640 bytes)
*Main> drawMaze quiteHardMaze
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|                                                                          |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +
|  |     |     |     |     |     |     |     |     |     |     |     |     |
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+


> hardMaze :: Maze
> hardMaze = makeMaze (10,10) walls
>   where walls = concat [run (i,0) 9 E | i <- [0,3..9]] ++ concat [run (i,1) 9 E | i <- [1,4..9]]

*Main> drawMaze hardMaze
+--+--+--+--+--+--+--+--+--+--+
|     |        |        |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |  |     |  |     |  |     |
+  +  +  +  +  +  +  +  +  +  +
|  |        |        |        |
+--+--+--+--+--+--+--+--+--+--+

(0.02 secs, 1,177,120 bytes)
*Main> fastSolveMaze hardMaze (0,0) (9,9)
[N,N,N,N,N,N,N,N,N,E,S,S,S,S,S,S,S,S,S,E,N,N,N,N,N,N,N,N,N,E,E,S,S,S,S,S,S,S,S,S,E,N,N,N,N,N,N,N,N,N,E,E,S,S,S,S,S,S,S,S,S,E,N,N,N,N,N,N,N,N,N,E]
(2.65 secs, 1,471,014,544 bytes)

> largeHardMaze :: Maze
> largeHardMaze = makeMaze (16,16) walls
>   where walls = concat [run (i,0) 15 E | i <- [0,3..15]] ++ concat [run (i,1) 15 E | i <- [1,4..15]]



> largeMaze :: Maze
> largeMaze =
>   let walls =
>         run (0,0) 3 E ++ run (1,1) 3 E ++ [((1,3),N)] ++ run (0,4) 5 E ++
>         run (2,0) 5 E ++ [((2,4),N)] ++ run (1,5) 3 E ++
>         run (1,8) 3 N ++ run (2,6) 3 E ++
>         run (3,1) 7 E ++ run (4,0) 4 N ++ run (4,1) 5 E ++ run (5,2) 3 N ++
>         run (4,6) 2 N ++ run (5,4) 3 E ++ run (6,3) 5 N ++ run (8,0) 4 E ++
>         run (6,1) 3 N ++ run (0,9) 3 N ++ run (1,10) 3 N ++ run (0,11) 3 N ++
>         run (1,12) 6 N ++ run (3,9) 4 E ++ run (4,11) 2 N ++
>         run (5,9) 3 E ++ run (4,8) 3 E ++ run (5,7) 5 N ++ run (6,4) 9 E ++
>         run (7,5) 3 N ++ run (8,4) 4 N ++ run (8,6) 3 N ++ run (10,5) 7 E ++
>         run (9,8) 3 E ++ run (8,9) 3 E ++ run (7,8) 3 E ++ run (8,11) 3 N ++
>         run (0,13) 5 N ++ run (4,14) 2 E ++ run (0,15) 2 E ++
>         run (1,14) 3 N ++ run (3,15) 2 E ++ run (0,17) 2 N ++
>         run (1,16) 2 E ++ run (2,15) 1 N ++ run (3,16) 3 N ++
>         run (2,17) 2 E ++ run (1,18) 6 N ++ run (4,17) 3 N ++
>         run (6,14) 7 E ++ run (5,13) 4 E ++ run (7,12) 2 E ++
>         run (8,13) 3 N ++ run (7,14) 3 N ++ run (10,14) 2 E ++
>         run (8,15) 5 N ++ run (7,16) 5 N ++ run (9,1) 2 E ++
>         run (10,0) 12 N ++ run (21,1) 1 E ++ run (10,2) 2 E ++
>         run (11,1) 7 N ++ run (17,1) 1 E ++ run (11,3) 3 E ++
>         run (12,2) 7 N ++ run (18,2) 2 E ++ run (19,1) 2 N ++
>         run (15,3) 3 N ++ run (14,4) 3 E ++ run (13,3) 3 E ++
>         run (12,4) 3 E ++ run (12,6) 3 N ++ run (11,7) 8 E ++
>         run (9,12) 3 N ++ run (12,14) 1 N ++ run (12,8) 10 E ++
>         run (0,19) 6 N ++ run (1,20) 6 N ++ run (7,18) 8 E ++
>         run (8,17) 1 N ++ run (8,18) 3 E ++ run (9,17) 4 E ++
>         run (10,18) 2 E ++ run (11,17) 2 E ++ run (10,20) 3 N ++
>         run (11,19) 3 N ++ run (12,18) 2 N ++ run (13,17) 2 N ++
>         run (13,13) 4 E ++ run (14,12) 7 N ++ run (13,11) 2 N ++
>         run (14,10) 2 E ++ run (13,9)2 E ++ run (14,8) 3 N ++
>         run (13,7) 3 N ++ run (15,5) 3 E ++ run (16,6) 3 E ++
>         run (18,5) 4 N ++ run (16,4) 2 N ++ run (13,20) 2 E ++
>         run (14,18) 4 E ++ run (20,2) 3 N ++ run (19,3) 2 E ++
>         run (18,4) 2 E ++ run (23,4) 1 E ++ run (22,4) 1 N ++
>         run (21,3) 1 N ++ run (20,4) 2 E ++ run (17,6) 4 N ++
>         run (20,7) 2 E ++ run (21,7) 2 N ++ run (21,6) 1 E ++
>         run (15,9) 1 E ++ run (17,8) 2 E ++ run (18,7) 2 E ++
>         run (19,8) 2 E ++ run (21,9) 1 E ++ run (16,9) 6 N ++
>         run (16,10) 7 N ++ run (15,11) 2 E ++ run (17,11) 5 N ++
>         run (14,14) 3 E ++ run (15,15) 6 E ++ run (17,14) 4 E ++
>         run (16,18) 4 E ++ run (15,17) 1 N ++ run (17,17) 3 N ++
>         run (15,13) 7 N ++ run (21,12) 2 E ++ run (16,16) 1 N ++
>         run (16,14) 1 N ++ run (17,15) 3 N ++ run (19,14) 4 N ++
>         run (20,15) 5 E ++ run (19,16) 2 N ++ run (21,16) 5 E ++
>         run (17,19) 2 E ++ run (18,20) 2 E ++ run (19,19) 2 E ++
>         run (18,18) 2 N ++ run (20,20) 3 N
>   in makeMaze (23,22) walls

And now an impossible maze

> impossibleMaze :: Maze
> impossibleMaze =
>   let walls = [((0,1), E), ((1,0),N), ((1,2), E), ((2,1), N)]
>   in makeMaze (3,3) walls
