#include <iostream>
#include "queue.h"
#include <string>

int main() {
    std::cout << "Hello world!";
    Queue<char*> *q = new Queue<char*>();
    delete q;
}