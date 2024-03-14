// File: Punched.h

#ifndef PUNCHED_H
#define PUNCHED_H

#include <vector>
#include "Cell.h"

class Punched
{
  public:
    void add(int r1, int c1, int r2, int c2)
    {
        punched_walls.push_back({{r1, c1}, {r2, c2}});
        punched_walls.push_back({{r2, c2}, {r1, c1}});
    }
    void remove(int r1, int c1, int r2, int c2)
    {
        punched_walls.end() = {};
    }
    std::vector<cell<cell<int, int>, cell<int, int>>> get_walls()
    {
        return punched_walls;
    }
    bool has(int r1, int c1, int r2, int c2)
    {
        for (int i = 0; i < punched_walls.size(); ++i)
        {
            auto wall = punched_walls[i];
            if ((wall.one.one == r1 && wall.one.two == c1)
                && wall.two.one == r2 && wall.two.two == c2)
            {
                return true;
            }
        }
        return false;
    }
    
  private:
    std::vector<cell<cell<int, int>, cell<int, int>>> punched_walls;
};

#endif
