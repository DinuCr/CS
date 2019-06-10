> module MyMaze where

> import Geography

> data Maze = Maze Size [Place] [Place] [Place] [Place]

> sizeOf :: Maze -> Size
> sizeOf (Maze size _ _ _ _) = size

> hasWall :: Maze -> Place -> Direction -> Bool
> hasWall (Maze size n s e w) place d
>   | d == N = elem place n
>   | d == S = elem place s
>   | d == E = elem place e
>   | d == W = elem place w

> reflect :: Wall -> Wall
> reflect ((i,j), d) = (move d (i,j), opposite d)

> makeMaze :: Size -> [Wall] -> Maze
> makeMaze (x,y) walls =
>   let boundaries = -- the four boundaries
>         [((0,j),   W) | j <- [0..y-1]] ++ -- westerly boundary
>         [((x-1,j), E) | j <- [0..y-1]] ++ -- easterly boundary
>         [((i,0),   S) | i <- [0..x-1]] ++ -- southerly boundary
>         [((i,y-1), N) | i <- [0..x-1]]    -- northerly boundary
>       allWalls = walls ++ boundaries ++ map reflect (walls ++ boundaries)
>       boundary_N = [ x | (x,d) <- allWalls, d == N]
>       boundary_S = [ x | (x,d) <- allWalls, d == S]
>       boundary_E = [ x | (x,d) <- allWalls, d == E]
>       boundary_W = [ x | (x,d) <- allWalls, d == W]
>  in Maze (x,y) boundary_N boundary_S boundary_E boundary_W
