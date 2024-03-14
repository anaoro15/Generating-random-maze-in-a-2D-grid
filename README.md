# Generating-random-maze-in-a-2D-grid
C++ practice project
PSEUDOCODE:
---------------------------------------------------------------
ALGORITHM: build_maze
INPUT: (r,c) - the starting point
let UNVISITED be the container of unvisited cells:
    initially this should be all cells except for (r,c)
let PATH be the container containing only (r,c)
let VISITED be a container of visited cells:
    initially this should contain only (r,c)
let PUNCHED be an empty container of "(r0,c0) -- (r1,c1)"
    that represents punched walls.
WARNING: If "(r0,c0) -- (r1,c1)" is in this container.
    then "(r1,c1) -- (r0,c0)" is also in the container.
while PATH is not empty:
    look at the last step stored in PATH -- call it x
    look at all the surrounding cells around x
      the available cells to go to are the
      cells to the north, south, east, west of x
      which are within the grid and not visited yet,  
      i.e., in UNVISITED.
    if there is at least one available cell:
        randomly choose one available cell -- call it y
        store y in VISITED and add that to PATH
        remove y from UNVISITED
        store x--y (the punched wall) in PUNCHED; y--x
        should be there too
    else:
      there are are no available cells
      we have to go backwards -- remove x from PATH
------------------------------------------------------------
• You need a container (let’s call it UNVISITED) that tells you the cells (i.e., row and
column positions) that you have not been to. Initially of course every (row, column) is
unvisited. Once you step into a cell (i.e., a (row, column)) you would need to record it in
UNVISITED. (Hint: You have everything you need from CISS240). You might want to
create a class for this container. One useful method is for instance UNVISITED.has(2,
4) which returns true exactly when you have not visited (2, 4). Another useful method
is UNVISITED.add(3, 5) to record down the fact that you have just visited (3, 5).
The name UNVISITED is only a suggestion. You can also call it NOT VISITED. You
choose the name you like best.
• You need a container (let’s call it PATH) to keep track of the steps going forward.
Think of it as a trail. Of course the trail is made up of a sequence of (row, column)
values. Notice that in the above algorithm, you can take a step moving forward and
you can also retrace a step by going backward. You might want to create a class
for PATH. A useful method is PATH.push(3, 7) to add (3, 7) to your path. To go
backwards, i.e., to retrace a step, you can do PATH.pop(). (Yes you have everything
you need to implement PATH.) The name PATH is only a suggestion. You can for
instance call it TRAIL if you wish.
• You also need to record down which wall is punched. For instance you can call it
PUNCHED. For instance if you are in cell (2,3) and you punch a wall on the east side,
you would see cell (2,4). Therefore you want to record ((2, 3), (2, 4)) in PUNCHED.
This means you can walk from (2,3) to (2,4). Of course you can also walk from (2,4)
to (2,3). Therefore you also need to record ((2,3),(2,4)) in PUNCHED as well. You
might want to create a class for PUNCHED.

+-+-+-+-+
| |   | |
+-+ +-+ +
| |     |
+-+-+-+ +
| | | | |
+-+ +-+-+
|   | | |
+-+-+-+-+
