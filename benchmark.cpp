//
// Created by semen on 12.04.19.
//
#include "benchmark.hpp"

namespace benchmark {
    ///https://stackoverflow.com/a/19555298/9609025
    long current_time() {
        std::chrono::microseconds mc =
                std::chrono::duration_cast<std::chrono::microseconds>(
                        std::chrono::system_clock::now().time_since_epoch()
                );
        return mc.count();
    }
}
