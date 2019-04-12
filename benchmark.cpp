//
// Created by semen on 12.04.19.
//

#include <chrono>

namespace benchmark {
    ///https://stackoverflow.com/a/19555298/9609025
    long current_time() {
        std::chrono::milliseconds ms =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch()
                );
        return ms.count();
    }
}
