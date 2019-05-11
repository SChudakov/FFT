//
// Created by semen on 10.05.19.
//

#include "Timer.hpp"

void Timer::start() {
    state = State::STARTED;
    start_time = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
}

void Timer::stop() {
    duration += std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    ) - start_time;
    state = State::STOPPED;
}

Timer::Timer() : duration(std::chrono::microseconds(0)),
                 start_time(std::chrono::microseconds(0)),
                 state(State::CREATED) {
}

std::chrono::microseconds Timer::get_duration() {
    return duration;
}
