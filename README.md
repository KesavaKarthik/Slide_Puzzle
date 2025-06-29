15-Puzzle Solver using A* Search

This project implements a solver for the classic 15-Puzzle (sliding puzzle) using the A* Search Algorithm with the Manhattan distance heuristic. 
The puzzle consists of a 4x4 grid with 15 numbered tiles and one blank space, and the goal is to arrange the tiles in ascending order with the 
blank tile at the bottom-right corner. The solution involves calculating the most optimal sequence of moves from any valid initial configuration to the goal state.
Steps Followed to Build and Solve the 15-Puzzle Problem -
1) Took 4x4 puzzle input from the user
2) Checked solvability using inversion count and blank row position
3) Calculated Manhattan distance as the heuristic function
4) Implemented A* search using a min-heap priority queue
5) Stored puzzle states using a custom Puzzle class
6) Generated valid moves by sliding the blank tile
7) Tracked visited states to avoid revisiting
8) Stopped the search when the goal state was reached
