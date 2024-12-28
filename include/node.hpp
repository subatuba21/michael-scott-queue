#pragma once

#include <map>
#include "pointer.hpp"

template <typename T>

struct Node {
    T value;
    std::atomic<Pointer<T>> next;
    Node(T cValue) : value(cValue), next(Pointer<T>(nullptr, 0)) {}
    Node(T cValue, Pointer<T> cPtr) : value(cValue), next(cPtr) {}
    bool operator==(const Node& c) {
        return c.value == value && next.load() == c.next.load();
    }
};
