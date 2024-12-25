#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <atomic>

template <typename T>
struct Node {
    T value;
    std::shared_ptr<Node<T>> next;

    Node(T val) : value(val), next(nullptr) {}
};

template <typename T>
class Queue {
public:
    Queue();
    ~Queue() = default;
    bool enqueue(T value);
    bool dequeue();

private:
    std::atomic<std::shared_ptr<Node<T>>> head;
    std::atomic<std::shared_ptr<Node<T>>> tail;
};

// Implementation of Queue methods
template <typename T>
Queue<T>::Queue() {
    std::shared_ptr<Node<T>> initialNode = std::make_shared<Node<T>>(T{});
    this->head = initialNode;
    this->tail.store(initialNode);
}

template <typename T>
bool Queue<T>::enqueue(T value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    newNode->next = nullptr;

    while (true) {
        auto tail = this->tail;
        auto tailNext = this->tailNext;

        if (tail == this->tail) {
            if (head == tail) {
                if (tailNext == nullptr) {
                    return false;
                } else {
                    this->tail.compare_exchange_strong(tail, std::make_shared<Node<T>>(tailNext->value, tailNext->next, tailNext->count));
                    
                }
            }
        }

    }
}

template <typename T>
bool Queue<T>::dequeue() {
    if (this->head == this->tail) {
        // Queue is empty or has only one element
        return;
    }
    this->head = this->head->next;
}

#endif // QUEUE_H
