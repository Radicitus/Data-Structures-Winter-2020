#include "LLQueue.hpp"
#include <iostream>

int main()
{
    auto* queue = new LLQueue<int>;

    std::cout << "Queue is:" << queue->isEmpty() << std::endl;

//    queue->dequeue();

    queue->enqueue(69);
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;
    queue->enqueue(420);
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;
    queue->enqueue(42069);
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;

    std::cout << "Queue is:" << queue->isEmpty() << std::endl;

    queue->dequeue();
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;
    queue->dequeue();
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;
    queue->dequeue();
    std::cout << queue->front() << std::endl;
    std::cout << "Queue size is:" << queue->size() << std::endl;

    std::cout << queue->front() << std::endl;

    std::cout << "Queue is:" << queue->isEmpty() << std::endl;

    return 0;
}

