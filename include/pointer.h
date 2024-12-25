#pragma once

#include <map>

struct Pointer {
    std::shared_ptr<Pointer> next;
    int count;
    Pointer(std::shared_ptr<Pointer> cNext, int cCount) : next(cNext), count(cCount) {}
};
