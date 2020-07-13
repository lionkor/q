#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include "Queue.h"
#include <utility>
#include <stdexcept>

template<class T>
class LinkedListQueue : public Queue<T>
{
protected:
    struct Node {
        T value;
        Node* next;
    };

    Node* m_next = nullptr;
    size_t m_size = 0;

public:
    LinkedListQueue() { }
    
    ~LinkedListQueue() {
        while (m_next != nullptr) {
            auto to_delete = m_next;
            m_next = m_next->next;
            delete to_delete;
        }
    }

    virtual void enqueue(T&& value) override {
        Node* new_node = new Node { value, m_next };
        m_next = new_node;
        ++m_size;
    }

    virtual T dequeue() override {
        if (!m_next) {
            throw std::runtime_error("dequeue from empty queue");
        }
        --m_size;
    }

    virtual const T& peek() const override {
        if (!m_next) {
            throw std::runtime_error("peek into empty queue");
        }
        return m_next->value;
    }

    virtual size_t size() const override {
        return m_size;
    }
};


#endif // LINKEDLISTQUEUE_H