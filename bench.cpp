#include <benchmark/benchmark.h>

#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include "RingBufferQueue.h"
#include "DoublyLinkedListQueue.h"

static void BM_ArrayQueue_peek(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        std::to_string(q.peek());
    }
}

static void BM_LinkedListQueue_peek(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        std::to_string(q.peek());
    }
}

static void BM_RingBufferQueue_peek(benchmark::State& state) {
    RingBufferQueue<size_t, 100> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        std::to_string(q.peek());
    }
}

static void BM_DoublyLinkedListQueue_peek(benchmark::State& state) {
    DoublyLinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        std::to_string(q.peek());
    }
}

#define BM_ARRAY_Q(name, n)                             \
    static void BM_##name##n(benchmark::State& state) { \
        for (auto _ : state) {                          \
            name<size_t> q;                             \
            for (size_t k = 0; k <= n; k += n / 10) {   \
                for (size_t i = 0; i < k; ++i) {        \
                    q.enqueue(std::move(i));            \
                }                                       \
                for (size_t i = 0; i < k; ++i) {        \
                    (void)q.dequeue();                  \
                }                                       \
            }                                           \
        }                                               \
    }                                                   \
    BENCHMARK(BM_##name##n);

#define BM_ARRAY_Q_S(name, n)                           \
    static void BM_##name##n(benchmark::State& state) { \
        for (auto _ : state) {                          \
            name<size_t, n> q;                          \
            for (size_t k = 0; k <= n; k += n / 10) {   \
                for (size_t i = 0; i < k; ++i) {        \
                    q.enqueue(std::move(i));            \
                }                                       \
                for (size_t i = 0; i < k; ++i) {        \
                    (void)q.dequeue();                  \
                }                                       \
            }                                           \
        }                                               \
    }                                                   \
    BENCHMARK(BM_##name##n);

BM_ARRAY_Q(ArrayQueue, 10)
BM_ARRAY_Q(ArrayQueue, 100)
BM_ARRAY_Q(ArrayQueue, 1000)
BM_ARRAY_Q(ArrayQueue, 10000)
BM_ARRAY_Q(ArrayQueue, 50000)

BM_ARRAY_Q(LinkedListQueue, 10)
BM_ARRAY_Q(LinkedListQueue, 100)
BM_ARRAY_Q(LinkedListQueue, 1000)
BM_ARRAY_Q(LinkedListQueue, 10000)
BM_ARRAY_Q(LinkedListQueue, 50000)

BM_ARRAY_Q_S(RingBufferQueue, 10)
BM_ARRAY_Q_S(RingBufferQueue, 100)
BM_ARRAY_Q_S(RingBufferQueue, 1000)
BM_ARRAY_Q_S(RingBufferQueue, 10000)
BM_ARRAY_Q_S(RingBufferQueue, 50000)

BM_ARRAY_Q(DoublyLinkedListQueue, 10)
BM_ARRAY_Q(DoublyLinkedListQueue, 100)
BM_ARRAY_Q(DoublyLinkedListQueue, 1000)
BM_ARRAY_Q(DoublyLinkedListQueue, 10000)
BM_ARRAY_Q(DoublyLinkedListQueue, 50000)


static void BM_ArrayQueue_all(benchmark::State& state) {
    for (auto _ : state) {
        ArrayQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 100; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 1000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 1000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 10000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        q.clear();
    }
}

static void BM_LinkedListQueue_all(benchmark::State& state) {
    for (auto _ : state) {
        LinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 100; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 1000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 1000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 10000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        q.clear();
    }
}

static void BM_RingBufferQueue_all(benchmark::State& state) {
    for (auto _ : state) {
        RingBufferQueue<size_t, 10000> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 100; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 1000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 1000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 10000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        q.clear();
    }
}

static void BM_DoublyLinkedListQueue_all(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 100; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 1000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 1000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        for (size_t i = 0; i < 10000; ++i) {
            (void)q.dequeue();
        }
        for (size_t i = 0; i < 10000; ++i) {
            q.enqueue(std::move(i));
        }
        q.clear();
    }
}

BENCHMARK(BM_ArrayQueue_all);
BENCHMARK(BM_LinkedListQueue_all);
BENCHMARK(BM_RingBufferQueue_all);
BENCHMARK(BM_DoublyLinkedListQueue_all);

BENCHMARK(BM_ArrayQueue_peek);
BENCHMARK(BM_LinkedListQueue_peek);
BENCHMARK(BM_RingBufferQueue_peek);
BENCHMARK(BM_DoublyLinkedListQueue_peek);

BENCHMARK_MAIN();
