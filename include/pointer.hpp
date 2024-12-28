#pragma once

#include <map>

template <typename T>
struct Node;


// Queue manages pointer
template <typename T> struct Pointer {
    Node<T> *ptr;
    int count;
    Pointer(Node<T> *cPtr, int cCount) : ptr(cPtr), count(cCount) {}
    Pointer() : ptr(nullptr), count(0) {}
    
    Pointer(const Pointer&) = default;
    Pointer& operator=(const Pointer&) = default;

    bool operator==(const Pointer& c) const {
        return c.count == count && c.ptr == ptr;
    }
};
