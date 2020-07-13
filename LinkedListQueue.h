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
        Node* next = nullptr;
    };

    Node* m_next = nullptr;
    size_t m_size = 0;

    void delete_all() {
        while (m_next != nullptr) {
            auto to_delete = m_next;
            m_next = m_next->next;
            delete to_delete;
        }
    }
    
public:
    LinkedListQueue() { }
    
    ~LinkedListQueue() {
        delete_all();
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
        Node* prev = nullptr;
        Node* iter = m_next;
        while (iter->next != nullptr) {
            prev = iter;
            iter = iter->next;
        }
        if (prev) {
            prev->next = nullptr;
        } else {
            m_next = nullptr;
        }
        T value = std::move(iter->value);
        delete iter;
        --m_size;
        return value;
    }

    virtual const T& peek() const override {
        if (!m_next) {
            throw std::runtime_error("peek into empty queue");
        }
        Node* iter = m_next;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        return iter->value;
    }

    virtual size_t size() const override {
        return m_size;
    }
    
    virtual void clear() override {
        delete_all();
        m_next = nullptr;
        m_size = 0;
    }
};


#endif // LINKEDLISTQUEUE_H
