#include "proj2.hpp"
#include "LLQueue.hpp"

#include <vector>


void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{
    auto* queue = new LLQueue<int>;
    std::vector<bool> visited(friends.size(), false);

    pathLengths[start] = 0;
    numShortestPaths[start] = 1;
    queue->enqueue(start);

    visited[start] = true;

    while (!queue->isEmpty()) {
        for (const auto i : friends[queue->front()]) {
            if (!visited[i]) {
                pathLengths[i] = pathLengths[queue->front()] + 1;
                numShortestPaths[i] = numShortestPaths[queue->front()];
                queue->enqueue(i);
                visited[i] = true;
            } else {
                if (pathLengths[i] == pathLengths[queue->front()] + 1) {
                    numShortestPaths[i]++;
                }
            }
        }
        queue->dequeue();
    }
    delete queue;
}
