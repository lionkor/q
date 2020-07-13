#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "Queue.h"
#include <utility>
#include <stdexcept>

#ifdef ARRAY_QUEUE_DEBUG
#include <cstdio>
#endif // ARRAY_QUEUE_DEBUG)

template<class T>
class ArrayQueue : public Queue<T>
{
protected:
    T* m_data = nullptr;
    size_t m_index = 0;
    size_t m_size = 0;

public:
    ArrayQueue() { }
    ~ArrayQueue() {
        delete[] m_data;
    }

    virtual void enqueue(T&& value) override {
        if (!m_data) {
            m_data = new T[1];
            m_index = 0;
            m_size = 1;
        }
        if (m_index >= m_size) {
            // we're at the end, resize
            auto new_data = new T[m_size *= 2];
            for (size_t i = 0; i < m_size / 2; ++i) {
                new_data[i] = std::move(m_data[i]);
            }
            delete[] m_data;
            m_data = new_data;
        }
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("enqueue: data = %#x, index = %u, size = %u\n", m_data, m_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        m_data[m_index] = value;
        m_index += 1;
    }
    
    [[nodiscard]] virtual T dequeue() override {
        if (m_index == 0)  {
            // nothing in the queue
            throw std::runtime_error("tried to dequeue from empty queue");
        }
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("dequeue: data = %#x, index = %u, size = %u\n", m_data, m_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        T value = std::move(m_data[0]);
        for (size_t i = 0; i < m_index; ++i) {
            m_data[i] = m_data[i + 1];
        }
        m_index -= 1;
        return value;
    }
    
    virtual const T& peek() const override {
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("peek: data = %#x, index = %u, size = %u\n", m_data, m_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        if (m_index == 0)  {
            // nothing in the queue
            throw std::runtime_error("tried to peek into empty queue");
        }
        return m_data[0];
    }
    
    virtual size_t size() const override {
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("size: data = %#x, index = %u, size = %u\n", m_data, m_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        return m_index;
    }
};

#endif // ARRAYQUEUE_H
