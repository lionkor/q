#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

// abstract
template<class T>
class Queue
{
private:
public:
    Queue() { }

    virtual void enqueue(T&&) = 0;
    [[nodiscard]] virtual T dequeue() = 0;
    virtual const T& peek() const = 0;
    virtual size_t size() const = 0;
};

#endif // QUEUE_H
