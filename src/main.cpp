#include <iostream>
#include "queue.hpp"
#include <string>
#include <cstdio>

// Test enqueue ops
void test_basic_enqueue(Queue<char*> *q) {
    printf("Starting enqueue test...\n");
    printf("Len: %d\n", q->length()); // 0
    q->enqueue("hello");
    printf("Len: %d\n", q->length()); // 1
    q->enqueue("world");
    printf("Len: %d\n", q->length()); // 2
    printf("Enqueue test done.\n\n");
}

// Test dequeue ops
void test_basic_dequeue(Queue<char*> *q) {
    printf("Dequeue test...\n");
    printf("Len: %d\n", q->length()); // 2
    q->dequeue();
    printf("Len: %d\n", q->length()); // 1
    q->dequeue();
    printf("Len: %d\n", q->length()); // 0
    printf("Empty queue dequeue: %d\n", q->dequeue()); // 0
    printf("Dequeue test done.\n\n");
}

// Interleave ops
void test_interleaved_operations(Queue<char*> *q) {
    printf("Interleaving test...\n");
    q->enqueue("first");
    printf("Len: %d\n", q->length()); // 1
    q->dequeue();
    printf("Len: %d\n", q->length()); // 0
    q->enqueue("second");
    q->enqueue("third");
    printf("Len: %d\n", q->length()); // 2
    q->dequeue();
    printf("Len: %d\n", q->length()); // 1
    q->dequeue();
    printf("Len: %d\n", q->length()); // 0
    printf("Interleave test done.\n\n");
}

// Stress
void test_stress(Queue<char*> *q) {
    printf("Stress test...\n");
    for (int i = 0; i < 100; ++i) {
        char* value = new char[10];
        snprintf(value, 10, "val%d", i); // Make strings
        q->enqueue(value);
    }
    printf("Len after 100 enqueue: %d\n", q->length()); // 100

    for (int i = 0; i < 100; ++i) {
        q->dequeue();
    }
    printf("Len after 100 dequeue: %d\n", q->length()); // 0
    printf("Stress test done.\n\n");
}

int main() {
    Queue<char*> *q = new Queue<char*>();

    test_basic_enqueue(q);
    test_basic_dequeue(q);
    test_interleaved_operations(q);
    test_stress(q);

    delete q;
    return 0;
}
