#pragma once

#include <map>

template <typename T>

struct Node {
    T value;
    std::atomic<Pointer> ptr;
    Node(T cValue) : value(cValue), next(nullptr), count(0) {}
    Node(T cValue, std::shared_ptr<Node<T>> cNext, int cCount) : value(cValue), next(nullptr), count(0) {}
};
