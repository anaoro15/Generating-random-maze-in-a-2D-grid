// Name: aoro
// File: main.cpp

#include <iostream>
#include <string>
#include "Unvisited.h"
#include "Path.h"
#include "Punched.h"
#include "Cell.h"
#include <ctime>
#include <cstdlib>

struct PunchedWall
{
    cell< int, int > cell1;
    cell< int, int > cell2;
};

std::vector< PunchedWall > build_maze(int n, int r, int c);
void print_maze(int n, const std::vector< PunchedWall > & walls);
int main()
{
    srand((unsigned int) time(NULL));
   
    int n, r, c;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter r and c: ";
    std::cin >> r >> c;

    std::vector< PunchedWall > punched_walls = build_maze(n, r, c);

    std::cout << "Random maze: " << '\n';
    print_maze(n, punched_walls);
    
    return 0;
}


std::vector< PunchedWall > build_maze(int n, int r, int c)
{
    Unvisited unvisited(n); // set the side of maze fields
    unvisited.visited(r, c); // set all cells to false except (r,c)

    Path path;
    path.push(r, c);  // create path that only has field[r][c] at initialization
    Punched punched; // initially no punched walls

    while (!path.empty())  // while the path is not empty
    {
        cell< int, int> x = path.back(); // last field in the path
        int row = x.one;
        int col = x.two;

        std::vector<cell <int, int>> available_cells;
        if (row >= 0 && row < n && col >= 0 && col < n)   // check the surrounding cells 
        {
            // if the cells are in the grid and in unvisited, add to available_cells
            if (unvisited.has(row, col - 1))  available_cells.push_back({row, col - 1}); // west
            if (unvisited.has(row, col + 1))  available_cells.push_back({row, col + 1}); // east
            if (unvisited.has(row - 1, col))  available_cells.push_back({row - 1, col}); // north
            if (unvisited.has(row + 1, col))  available_cells.push_back({row + 1, col}); // south
        }
            
        if (!available_cells.empty()) 
        {
            int rand_choose = rand() % available_cells.size();  // randomly choose available cell to move            
            cell< int, int> y = available_cells[rand_choose];
            path.push(y.one, y.two);  // add new cell to path
            unvisited.visited(y.one, y.two);   // remove that cell from unvisited
            punched.add(x.one, x.two, y.one, y.two);  // record new punched wall
        }
        else // if there is no available steps moving forward
        {
            path.pop(); // delete the last step from the path
        }
    }
       
    std::vector<cell<cell<int, int>, cell<int, int>>> walls = punched.get_walls(); // create walls - all punched walls in the maze
    std::vector< PunchedWall > maze_walls;
    for (int i = 0; i < walls.size(); i++)
    {
        int row1 = walls[i].one.one;
        int col1 = walls[i].one.two;
        int row2 = walls[i].two.one;
        int col2 = walls[i].two.two;
        
        cell< int, int > cell0;
        cell< int, int > cell1;
        cell0.one = row1;
        cell0.two = col1;
        cell1.one = row2;
        cell1.two = col2;
        
        PunchedWall punched_wall;
        punched_wall.cell1 = cell0;
        punched_wall.cell2 = cell1;

        maze_walls.push_back(punched_wall); // add the punched wall to maze_walls
    }

    return maze_walls;   
}

void print_maze(int n, const std::vector< PunchedWall > & walls)
{
    std::cout << "+";
    for (int i = 1; i <= n; ++i)
    {
        std::cout << "-+";
    }
    std::cout << '\n';

    for (int row = 0; row < n; ++row)
    {
        std::cout << "|";
        for (int col = 0; col < n - 1; ++col)
        {
            bool wall_is_there = true;
            for (const auto & wall : walls)
            {
                if ((wall.cell1.one == row && wall.cell1.two == col && wall.cell2.one == row && wall.cell2.two == col + 1) ||
                    (wall.cell1.one == row && wall.cell1.two == col + 1 && wall.cell2.one == row && wall.cell2.two == col))
                {
                    wall_is_there = false;
                    break;
                }
            }

            std::cout << " " << (wall_is_there ? "|" : " "); // if the wall is punched then " "
        }
        std::cout << " |" << '\n';

        std::cout << "+";
        for (int col = 0; col < n; ++col)
        {
            bool wall_is_there = true;
            for (const auto & wall : walls)
            {
                if ((wall.cell1.one == row && wall.cell1.two == col && wall.cell2.one == row + 1 && wall.cell2.two == col) ||
                    (wall.cell1.one == row + 1 && wall.cell1.two  == col && wall.cell2.one == row && wall.cell2.two == col))
                {
                    wall_is_there = false;
                    break;
                }
            }
            std::cout << (wall_is_there ? "-" : " ") << "+"; // if the wall is punched then " "
        }
        std::cout << '\n';
    }
}

