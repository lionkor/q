#ifndef DOUBLYLINKEDLISTQUEUE_H
#define DOUBLYLINKEDLISTQUEUE_H

#include "Queue.h"
#include <utility>
#include <stdexcept>
#include <cassert>

// circular doubly linked list queue

template<class T>
class DoublyLinkedListQueue : public Queue<T>
{
protected:
    struct Node {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* m_head = nullptr;
    size_t m_size = 0;

    void delete_all() {
        if (m_head) {
            Node* iter = m_head->next;
            while (iter != m_head) {
                auto to_delete = iter;
                iter = iter->next;
                delete to_delete;
            }
            delete m_head;
        }
    }

public:
    DoublyLinkedListQueue() { }

    ~DoublyLinkedListQueue() {
        delete_all();
    }

    virtual void enqueue(T&& value) override {
        Node* new_node = new Node { value, nullptr, nullptr };

        if (!m_head) {
            new_node->next = new_node;
            new_node->prev = new_node;
        } else {
            Node* next = m_head;
            Node* prev = m_head->prev;
            new_node->next = next;
            new_node->prev = prev;
            next->prev = new_node;
            prev->next = new_node;
        }
        m_head = new_node;
        ++m_size;
    }

    virtual T dequeue() override {
        if (!m_head) {
            throw std::runtime_error("dequeue from empty queue");
        }
        assert(m_head->prev != nullptr);
        assert(m_head->next != nullptr);
        T value = std::move(m_head->prev->value);
        if (m_head->prev != m_head) {
            Node* to_delete = m_head->prev;
            Node* next = m_head;
            Node* prev = m_head->prev->prev;
            next->prev = prev;
            prev->next = next;
            delete to_delete;
        } else {
            // it's empty, set it up so enqueue knows (set to nullptr)
            delete m_head;
            m_head = nullptr;
        }
        --m_size;
        return value;
    }

    virtual const T& peek() const override {
        if (!m_head) {
            throw std::runtime_error("peek into empty queue");
        }
        return m_head->prev->value;
    }

    virtual size_t size() const override {
        return m_size;
    }

    virtual void clear() override {
        delete_all();
        m_head = nullptr;
        m_size = 0;
    }
};

#endif // DOUBLYLINKEDLISTQUEUE_H
