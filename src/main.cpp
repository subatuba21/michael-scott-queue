#include <iostream>
#include "queue.hpp"
#include <string>

int main() {
    std::cout << "Hello world!";
    Queue<char*> *q = new Queue<char*>();

    q->enqueue("hello");

    delete q;
}