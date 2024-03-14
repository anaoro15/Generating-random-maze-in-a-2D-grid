// File: Unvisited.h

#ifndef UNVISITED_H
#define UNVISITED_H

#include <vector>

class Unvisited
{
  public:
    Unvisited(int n)
    {
        unvisited.resize(n, std::vector< bool >(n, true));
    }
    const std::vector<std::vector< bool >> & vector() const
    {
        return unvisited;
    }
    bool has(int r, int c) const
    {
        if (r < 0 || r >= unvisited.size() || c < 0 || c >= unvisited[0].size())
        {
            return false;
        }
        return unvisited[r][c];
    };
    void visited(int r, int c)
    {
        if (r >= 0 && r < unvisited.size() && c >= 0 && c < unvisited[0].size())
        {
            unvisited[r][c] = false;
        }
    }
  private:
    std::vector<std::vector< bool >> unvisited;
};

#endif
