#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include "RingBufferQueue.h"
#include "DoublyLinkedListQueue.h"

#define QUEUE_TEST(classname)                \
    TEST_CASE(#classname) {                  \
        classname<int> q;                    \
        CHECK(q.size() == 0);                \
        for (int i = 0; i < 10; ++i) {       \
            q.enqueue(std::move(i));         \
        }                                    \
        CHECK(q.size() == 10);               \
                                             \
        SUBCASE("dequeue") {                 \
            for (int i = 0; i < 9; ++i) {    \
                CHECK(i == q.dequeue());     \
            }                                \
            CHECK(q.size() == 1);            \
            CHECK(q.dequeue() == 9);         \
            CHECK(q.size() == 0);            \
            CHECK_THROWS((void)q.dequeue()); \
        }                                    \
                                             \
        SUBCASE("peek") {                    \
            CHECK(q.peek() == 0);            \
            (void)q.dequeue();               \
            CHECK(q.peek() == 1);            \
            while (q.size() != 0) {          \
                (void)q.dequeue();           \
            }                                \
            CHECK_THROWS(q.peek());          \
        }                                    \
                                             \
        SUBCASE("clear") {                   \
            q.clear();                       \
            CHECK(q.size() == 0);            \
            CHECK_THROWS((void)q.dequeue()); \
            CHECK_THROWS((void)q.peek());    \
        }                                    \
    }

QUEUE_TEST(ArrayQueue)
QUEUE_TEST(LinkedListQueue)
QUEUE_TEST(DoublyLinkedListQueue)

TEST_CASE("RingBufferQueue") {
    RingBufferQueue<int, 10> q;
    CHECK(q.size() == 0);
    for (int i = 0; i < 10; ++i) {
        q.enqueue(std::move(i));
    }
    CHECK(q.size() == 10);
    // full, needs to throw as ring buffers are of immutable size
    CHECK_THROWS(q.enqueue(5));

    SUBCASE("peek") {
        CHECK(q.peek() == 0);
        (void)q.dequeue();
        CHECK(q.peek() == 1);
        while (q.size() != 0) {
            (void)q.dequeue();
        }
        CHECK_THROWS(q.peek());
    }

    SUBCASE("dequeue") {
        for (int i = 0; i < 9; ++i) {
            CHECK(i == q.dequeue());
        }
        CHECK(q.size() == 1);
        CHECK(q.dequeue() == 9);
        CHECK(q.size() == 0);
        CHECK_THROWS((void)q.dequeue());
    }
    
    SUBCASE("clear") {
        q.clear();
        CHECK(q.size() == 0);
        CHECK_THROWS((void)q.dequeue());
        CHECK_THROWS((void)q.peek());
    }
}
