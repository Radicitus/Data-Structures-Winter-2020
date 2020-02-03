#include "proj2.hpp"
#include "LLQueue.hpp"

#include <vector>


void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{
    auto* queue = new LLQueue<int>;
    bool visited[friends.size()];
    int level = 1;

    pathLengths[start] = 0;
    numShortestPaths[start] = 1;
    queue->enqueue(start);
    while (!queue->isEmpty()) {
        if (!visited[queue->front()]) {
            for (const auto i : friends[queue->front()]) {
                if (!visited[i]) {
                    queue->enqueue(i);
                    if (pathLengths[i] < level || pathLengths[i] == 0) {
                        pathLengths[i] = level;
                    }
                    numShortestPaths[i]++;
                }
            }
            visited[queue->front()] = true;
            queue->dequeue();
        } else {
            queue->dequeue();
        }
    }
    delete queue;
}
