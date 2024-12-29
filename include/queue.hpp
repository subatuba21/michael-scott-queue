#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <atomic>
#include "pointer.hpp"
#include "node.hpp"

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue() = default;
    bool enqueue(T value);
    bool dequeue();

private:
    std::atomic<Pointer<T>> head;
    std::atomic<Pointer<T>> tail;
};

// Implementation of Queue methods
template <typename T>
Queue<T>::Queue()
{
    Node<T> *initialNode = new Node<T>(T{});
    this->head = Pointer(initialNode, 0);
    this->tail = Pointer(initialNode, 0);
}

template <typename T>
bool Queue<T>::enqueue(T value)
{
    Node<T> *newNode = new Node<T>(value);
    newNode->next = Pointer<T>(nullptr, 0);

    while (true)
    {
        Pointer<T> tail = this->tail.load(std::memory_order_acquire);
        // invariant: tail always points to a valid node
        Pointer<T> tailNext = tail.ptr->next;

        if (tail == this->tail)
        {
            // this was the last node
            if (tailNext.ptr == nullptr)
            {
                // newNode pointer is nullptr
                Pointer<T> newPointer(newNode, tail.count + 1);
                if (tail.ptr->next.compare_exchange_weak(tailNext, newPointer, std::memory_order_release, std::memory_order_relaxed))
                    break;
            }
            else
            {
                // go to next pointer
                Pointer<T> newTail(tailNext.ptr, tail.count + 1);
                if (this->tail.compare_exchange_weak(tail, newTail, std::memory_order_acquire, std::memory_order_relaxed))
                    break;
            }
        }
    }

    // we're done, swing tail over
    Pointer<T> oldTail = this->tail.load();
    Pointer<T> newTail(newNode, oldTail.count + 1);
    
    while (!this->tail.compare_exchange_strong(oldTail, newTail, std::memory_order_release, std::memory_order_relaxed));
}

template <typename T>
bool Queue<T>::dequeue()
{

    while (true)
    {
        Pointer<T> head = this->head.load(std::memory_order_acquire);
        Pointer<T> headNext = head.ptr->next;
        Pointer<T> tail = this->tail.load(std::memory_order_acquire);

        // head and tail are same. the queue is empty
        if (head == this->head.load())
        {
            if (head == tail)
            {
                // queue is empty
                if (headNext.ptr == nullptr)
                {
                    return false;
                }
                else
                {
                    // tail is falling behind
                    // go to next pointer
                    Pointer<T> newTail(headNext.ptr, tail.count + 1);
                    if (this->tail.compare_exchange_weak(tail, headNext, std::memory_order_acquire, std::memory_order_relaxed))
                        break;
                }
            }
            else
            {
                Pointer<T> newHead(headNext.ptr, head.count + 1);
                if (this->head.compare_exchange_weak(head, newHead, std::memory_order_acquire, std::memory_order_relaxed))
                    break;
            }
        }
    }
}

#endif // QUEUE_H
