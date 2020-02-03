#include "LLQueue.hpp"
#include "proj2.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector< std::vector<unsigned> > g1 = {
            {1,2}, {0,3}, {0,3}, {1,2}
    };
    std::vector<unsigned> pathLengths(4);
    std::vector<unsigned> numShortestPaths(4);

    countPaths(g1, 0, pathLengths, numShortestPaths);
    return 0;
}

