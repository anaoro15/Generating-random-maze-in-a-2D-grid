// File: Path.h

#ifndef PATH_H
#define PATH_H

#include <vector>
#include "Cell.h"

class Path
{
  public:
    void push(int r, int c)
    {
        path_.push_back({r, c});
    }
    void pop()
    {
        path_.pop_back();  // removes the last element from vector
    }
    bool empty()
    {
        return path_.empty(); // checks if the vector is empty
    }
    cell< int, int > back() const
    {
        if (path_.empty()) return {-1, -1};
        else   return path_.back();
    }
    
  private:
    std::vector <cell<int, int>> path_;
};

#endif
