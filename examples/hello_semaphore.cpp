
#include "ais2203/semaphore.hpp"

#include <iostream>
#include <thread>
#include <vector>

int main() {

    std::mutex m;
    ais2203::semaphore semaphore(5);

    constexpr int numThreads = 50;
    std::vector<std::jthread> threads(numThreads);
    for (auto i = 0; i < numThreads; i++) {
        threads[i] = std::jthread([&m, &semaphore, i] {
            semaphore.acquire();

            std::this_thread::sleep_for(std::chrono::milliseconds(50));

            std::unique_lock lock(m);
            std::cout << "hello from thread " << i << ", count=" << semaphore.getCount() << std::endl;
            lock.unlock();

            semaphore.release();
        });
    }

    return 0;
}