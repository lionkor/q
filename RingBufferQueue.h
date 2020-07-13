#ifndef RINGBUFFERQUEUE_H
#define RINGBUFFERQUEUE_H

#include "Queue.h"
#include <stdexcept>

template<class T, size_t _size>
class RingBufferQueue : public Queue<T>
{
protected:
    T* m_data = nullptr;
    T* m_write_ptr = nullptr;
    T* m_read_ptr = nullptr;
    size_t m_enqueued_count = 0;

    void increment_ptr(T*& ptr) {
        ptr += 1;
        if (ptr == m_data + _size) {
            ptr = m_data;
        }
    }

    void decrement_ptr(T*& ptr) {
        ptr -= 1;
        if (ptr <= m_data) {
            ptr = m_data + _size - 1;
        }
    }

public:
    RingBufferQueue()
        : m_data(new T[_size])
        , m_write_ptr(m_data)
        , m_read_ptr(m_data) { }

    ~RingBufferQueue() {
        delete[] m_data;
    }

    virtual void enqueue(T&& value) override {
        if (m_enqueued_count == _size) {
            throw std::runtime_error("enqueue into full queue");
        }
        *m_write_ptr = value;
        increment_ptr(m_write_ptr);
        ++m_enqueued_count;
    }
    
    virtual const T& peek() const override {
        if (m_enqueued_count == 0) {
            throw std::runtime_error("peek into empty queue");
        }
        return *m_read_ptr;
    }

    virtual T dequeue() override {
        if (m_enqueued_count == 0) {
            throw std::runtime_error("dequeue from empty queue");
        }
        T value = std::move(*m_read_ptr);
        increment_ptr(m_read_ptr);
        --m_enqueued_count;
        return value;
    }

    virtual size_t size() const override { return m_enqueued_count; }
};

#endif // RINGBUFFERQUEUE_H
