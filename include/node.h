#pragma once

#include <map>

template <typename T>

struct Node {
    T value;
    std::atomic<Pointer<T>> ptr;
    Node(T cValue) : value(cValue), ptr(Pointer<T>(nullptr, 0)) {}
    Node(T cValue, Pointer<T> ) : value(cValue), ptr(cPtr) {}
};
