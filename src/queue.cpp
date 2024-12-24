#include "queue.h"
#include "node.h"
#include <memory>

template <typename T> Queue<T>::Queue() {
    std::shared_ptr<Node<void *>> initialNode = std::make_shared<Node<void *>>(nullptr);
    this->head = initialNode;
    this->tail = initialNode;
}

template <typename T> void Queue<T>::enqueue(T value) {
    Node initialNode = new Node<T>(value);
    while (this->tail) {

    }
}