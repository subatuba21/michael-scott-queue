# An implementation of Michael-Scott queue in C++

## Lock-free queue

Queues are important in a variety of applications in computer science. Some of these include:
- process scheduling
- load balancing
- message queues

In some applications, non-blocking queues are useful. In operating systems, if there's an interrupt while a process is being added to the queue during scheduling, this could result in performance loss as other processors wait for the lock to be released. This is where a lock-free queue can be useful.

I implemented the queue based on the [original paper](https://www.cs.rochester.edu/~scott/papers/1996_PODC_queues.pdf).

Critical technologies/concepts:
- C++
- atomic variables
- memory models