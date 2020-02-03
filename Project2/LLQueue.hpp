#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"

//Exception handling
class QueueEmptyException : public RuntimeException 
{
public:
	explicit QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};

//Node struct
template <typename Object>
struct LLQNode {
    Object nodeElement; //Node value
    LLQNode<Object>* next; //Next node in the queue
};

//Queue
template <typename Object>
class LLQueue {
private:
    LLQNode<Object>* head;
    int queueSize = 0;
public:
	LLQueue();
	~LLQueue();
	size_t size() const noexcept;
	bool isEmpty() const noexcept;
	Object & front() noexcept(false);
	const Object & front() const noexcept(false);
	void enqueue(const Object & elem);
	void dequeue() noexcept(false);
};

template<typename Object>
LLQueue<Object>::LLQueue()
    : head(NULL){ }

template<typename Object>
LLQueue<Object>::~LLQueue() {
    while (!isEmpty()) dequeue();
}

template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept {
    return head == NULL;
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object &elem) {
    auto* newNode = new LLQNode<Object>;
    newNode->nodeElement = elem;

    if (isEmpty()) {
        head = newNode;
        newNode->next = NULL;
    } else {
        auto tempNode = head;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = newNode;
        newNode->next = NULL;
        head = tempNode;
    }

    queueSize++;
}

template<typename Object>
void LLQueue<Object>::dequeue() noexcept(false) {
    if (isEmpty()) {
        throw QueueEmptyException("Cannot dequeue an empty queue.");
    }
    LLQNode<Object>* nodeToDelete = head;
    head = nodeToDelete->next;
    delete nodeToDelete;
    queueSize--;
}

template<typename Object>
size_t LLQueue<Object>::size() const noexcept {
    return queueSize;
}

template<typename Object>
Object &LLQueue<Object>::front() noexcept(false) {
    if (isEmpty()) {
        throw QueueEmptyException("Cannot return a value from an empty queue.");
    }
    return head->nodeElement;
}

template<typename Object>
const Object &LLQueue<Object>::front() const noexcept(false) {
    if (isEmpty()) {
        throw QueueEmptyException("Cannot return a value from an empty queue.");
    }
    return head->nodeElement;
}

#endif

