
#ifndef THREADING_CPP_RANDOM_GEN_HPP
#define THREADING_CPP_RANDOM_GEN_HPP

#include <random>

namespace ais2203 {

    inline int rand(int min, int max) {
        thread_local std::random_device rd;
        thread_local std::mt19937 gen(rd());
        std::uniform_int_distribution distribution(min, max);

        return distribution(gen);
    }

}// namespace ais2203

#endif//THREADING_CPP_RANDOM_GEN_HPP
