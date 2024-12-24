#include "node.h"
#include "stdlib.h"
#include <map>

template <typename T>

class Queue {
    public:
        Queue();
        ~Queue() = default;
        void enqueue(T value);
        // void dequeue();
    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
};