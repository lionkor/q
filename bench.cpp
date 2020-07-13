#include <benchmark/benchmark.h>

#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include "RingBufferQueue.h"
#include "DoublyLinkedListQueue.h"

static void BM_ArrayQueue_dequeue_1(benchmark::State& state) {
    ArrayQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        (void)q.dequeue();
        q.enqueue(60);
    }
}

static void BM_LinkedListQueue_dequeue_1(benchmark::State& state) {
    LinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        (void)q.dequeue();
        q.enqueue(60);
    }
}

static void BM_RingBufferQueue_dequeue_1(benchmark::State& state) {
    RingBufferQueue<size_t, 100> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        (void)q.dequeue();
        q.enqueue(60);
    }
}

static void BM_DoublyLinkedListQueue_dequeue_1(benchmark::State& state) {
    DoublyLinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        (void)q.dequeue();
        q.enqueue(60);
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

static void BM_DoublyLinkedListQueue_peek(benchmark::State& state) {
    DoublyLinkedListQueue<size_t> q;
    for (size_t i = 0; i < 100; ++i) {
        q.enqueue(std::move(i));
    }
    for (auto _ : state) {
        std::to_string(q.peek());
    }
}

static void BM_ArrayQueue_enqueue_10(benchmark::State& state) {
    for (auto _ : state) {
        ArrayQueue<size_t> q;
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_10(benchmark::State& state) {
    for (auto _ : state) {
        LinkedListQueue<size_t> q;
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_10(benchmark::State& state) {
    for (auto _ : state) {
        RingBufferQueue<size_t, 10> q;
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_DoublyLinkedListQueue_enqueue_10(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedListQueue<size_t> q;
        for (size_t i = 0; i < 10; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_ArrayQueue_enqueue_100(benchmark::State& state) {
    for (auto _ : state) {
        ArrayQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_100(benchmark::State& state) {
    for (auto _ : state) {
        LinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_100(benchmark::State& state) {
    for (auto _ : state) {
        RingBufferQueue<size_t, 100> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_DoublyLinkedListQueue_enqueue_100(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_ArrayQueue_enqueue_100000(benchmark::State& state) {
    for (auto _ : state) {
        ArrayQueue<size_t> q;
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_LinkedListQueue_enqueue_100000(benchmark::State& state) {
    for (auto _ : state) {
        LinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_RingBufferQueue_enqueue_100000(benchmark::State& state) {
    for (auto _ : state) {
        RingBufferQueue<size_t, 100000> q;
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

static void BM_DoublyLinkedListQueue_enqueue_100000(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedListQueue<size_t> q;
        for (size_t i = 0; i < 100000; ++i) {
            q.enqueue(std::move(i));
        }
    }
}

BENCHMARK(BM_ArrayQueue_dequeue_1);
BENCHMARK(BM_LinkedListQueue_dequeue_1);
BENCHMARK(BM_RingBufferQueue_dequeue_1);
BENCHMARK(BM_DoublyLinkedListQueue_dequeue_1);

BENCHMARK(BM_ArrayQueue_peek);
BENCHMARK(BM_LinkedListQueue_peek);
BENCHMARK(BM_RingBufferQueue_peek);
BENCHMARK(BM_DoublyLinkedListQueue_peek);

BENCHMARK(BM_ArrayQueue_enqueue_10);
BENCHMARK(BM_LinkedListQueue_enqueue_10);
BENCHMARK(BM_RingBufferQueue_enqueue_10);
BENCHMARK(BM_DoublyLinkedListQueue_enqueue_10);
BENCHMARK(BM_ArrayQueue_enqueue_100);
BENCHMARK(BM_LinkedListQueue_enqueue_100);
BENCHMARK(BM_RingBufferQueue_enqueue_100);
BENCHMARK(BM_DoublyLinkedListQueue_enqueue_100);
BENCHMARK(BM_ArrayQueue_enqueue_100000);
BENCHMARK(BM_LinkedListQueue_enqueue_100000);
BENCHMARK(BM_RingBufferQueue_enqueue_100000);
BENCHMARK(BM_DoublyLinkedListQueue_enqueue_100000);

BENCHMARK_MAIN();
