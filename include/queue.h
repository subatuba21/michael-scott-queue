#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

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
    void enqueue(T value);
    void dequeue();

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

// Implementation of Queue methods
template <typename T>
Queue<T>::Queue() {
    std::shared_ptr<Node<T>> initialNode = std::make_shared<Node<T>>(T{});
    this->head = initialNode;
    this->tail = initialNode;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    this->tail->next = newNode;
    this->tail = newNode;
}

template <typename T>
void Queue<T>::dequeue() {
    if (this->head == this->tail) {
        // Queue is empty or has only one element
        return;
    }
    this->head = this->head->next;
}

#endif // QUEUE_H
