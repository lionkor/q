#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "ArrayQueue.h"

#define QUEUE_TEST(classname)                \
    TEST_CASE(#classname) {                \
        classname<int> q;                   \
        CHECK(q.size() == 0);                \
        for (int i = 0; i < 10; ++i) {       \
            q.enqueue(std::move(i));         \
        }                                    \
        CHECK(q.size() == 10);               \
                                             \
        SUBCASE("dequeue") {                 \
            for (int i = 0; i < 9; ++i) {    \
                CHECK(9 - i == q.dequeue()); \
            }                                \
            CHECK(q.size() == 1);            \
            CHECK(q.dequeue() == 0);         \
            CHECK(q.size() == 0);            \
            CHECK_THROWS((void)q.dequeue()); \
        }                                    \
                                             \
        SUBCASE("peek") {                    \
            CHECK(q.peek() == 9);            \
            (void)q.dequeue();               \
            CHECK(q.peek() == 8);            \
            while (q.size() != 0) {          \
                (void)q.dequeue();           \
            }                                \
            CHECK_THROWS(q.peek());          \
        }                                    \
    }

QUEUE_TEST(ArrayQueue)
