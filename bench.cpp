#include <benchmark/benchmark.h>

#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include "RingBufferQueue.h"

static void BM_ArrayQueue_dequeue_1(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        q.enqueue(60);
        (void)q.dequeue();
    }
}

static void BM_LinkedListQueue_dequeue_1(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        q.enqueue(60);
        (void)q.dequeue();
    }
}

static void BM_RingBufferQueue_dequeue_1(benchmark::State& state) {
    RingBufferQueue<size_t, 100> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        q.enqueue(60);
        (void)q.dequeue();
    }
}

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

static void BM_ArrayQueue_enqueue_10(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_10(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_10(benchmark::State& state) {
    RingBufferQueue<size_t, 10> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_ArrayQueue_enqueue_100(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_100(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_100(benchmark::State& state) {
    RingBufferQueue<size_t, 100> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_ArrayQueue_enqueue_100000(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_100000(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_100000(benchmark::State& state) {
    RingBufferQueue<size_t, 100000> q;
    for (auto _ : state) {
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

BENCHMARK(BM_ArrayQueue_dequeue_1);
BENCHMARK(BM_LinkedListQueue_dequeue_1);
BENCHMARK(BM_RingBufferQueue_dequeue_1);

BENCHMARK(BM_ArrayQueue_peek);
BENCHMARK(BM_LinkedListQueue_peek);
BENCHMARK(BM_RingBufferQueue_peek);

BENCHMARK(BM_ArrayQueue_enqueue_10);
BENCHMARK(BM_LinkedListQueue_enqueue_10);
BENCHMARK(BM_RingBufferQueue_enqueue_10);
BENCHMARK(BM_ArrayQueue_enqueue_100);
BENCHMARK(BM_LinkedListQueue_enqueue_100);
BENCHMARK(BM_RingBufferQueue_enqueue_100);
BENCHMARK(BM_ArrayQueue_enqueue_100000);
BENCHMARK(BM_LinkedListQueue_enqueue_100000);
BENCHMARK(BM_RingBufferQueue_enqueue_100000);
BENCHMARK_MAIN();
