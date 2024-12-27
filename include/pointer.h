#pragma once

#include <map>
#include "node.h"

template <typename T> struct Pointer {
    std::weak_ptr<Node<T>> next;
    int count;
    Pointer(std::weak_ptr<Pointer> cNext, int cCount) : next(cNext), count(cCount) {}
};
