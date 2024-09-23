
#ifndef THREADING_CPP_SEMAPHORE_H
#define THREADING_CPP_SEMAPHORE_H

#include <condition_variable>
#include <mutex>

namespace ais2203 {

    class semaphore {
    public:
        explicit semaphore(unsigned int max)
            : max_(max), count_(0) {}

        void release() {
            std::lock_guard lock(mutex_);
            count_--;
            condition_.notify_one();
        }

        void acquire() {
            std::unique_lock lock(mutex_);
            while (count_ == max_) {
                condition_.wait(lock);
            }
            count_++;
        }

        [[nodiscard]] unsigned int getCount() const {
            return count_;
        }

    private:
        const unsigned int max_;
        unsigned int count_;

        std::mutex mutex_;
        std::condition_variable condition_;
    };

}// namespace ais2203

#endif//THREADING_CPP_SEMAPHORE_H
