#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "Queue.h"
#include <utility>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

static const double GROWTH_FACTOR = (1 + std::sqrt(5)) / 2.0;

#ifdef ARRAY_QUEUE_DEBUG
#include <cstdio>
#endif // ARRAY_QUEUE_DEBUG)

template<class T>
class ArrayQueue : public Queue<T>
{
protected:
    T* m_data = nullptr;
    size_t m_write_index = 0;
    size_t m_size = 0;

public:
    ArrayQueue() { }
    ~ArrayQueue() {
        std::free(static_cast<void*>(m_data));
    }

    virtual void enqueue(T&& value) override {
        if (!m_data) {
            m_data = static_cast<T*>(std::malloc(sizeof(T)));
            m_write_index = 0;
            m_size = 1;
        }
        if (m_write_index >= m_size) {
            // we're at the end, resize
            m_size = std::ceil(static_cast<double>(m_size) * GROWTH_FACTOR);
            T* new_data = static_cast<T*>(std::realloc(static_cast<void*>(m_data), m_size * sizeof(T)));
            if (!new_data) {
                throw std::runtime_error("failed to realloc (OOM)");
            }
            m_data = new_data;
        }
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("enqueue: data = %#x, index = %u, size = %u\n", m_data, m_write_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        m_data[m_write_index] = value;
        m_write_index += 1;
    }

    [[nodiscard]] virtual T dequeue() override {
        if (m_write_index == 0) {
            // nothing in the queue
            throw std::runtime_error("tried to dequeue from empty queue");
        }
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("dequeue: data = %#x, index = %u, size = %u\n", m_data, m_write_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        T value = std::move(m_data[0]);
        for (size_t i = 0; i < m_write_index; ++i) {
            m_data[i] = m_data[i + 1];
        }
        m_write_index -= 1;
        return value;
    }

    virtual const T& peek() const override {
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("peek: data = %#x, index = %u, size = %u\n", m_data, m_write_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        if (m_write_index == 0) {
            // nothing in the queue
            throw std::runtime_error("tried to peek into empty queue");
        }
        return m_data[0];
    }

    virtual size_t size() const override {
#ifdef ARRAY_QUEUE_DEBUG
        std::printf("size: data = %#x, index = %u, size = %u\n", m_data, m_write_index, m_size);
#endif // ARRAY_QUEUE_DEBUG)
        return m_write_index;
    }

    virtual void clear() override {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_write_index = 0;
    }
};

#endif // ARRAYQUEUE_H
