#pragma once

#include <map>

template <typename T>

struct Node {
    T value;
    std::shared_ptr<Node<T>> next;
    Node(T cValue) : value(cValue), next(nullptr) {}
};