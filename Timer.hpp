//
// Created by semen on 10.05.19.
//

#ifndef PARALLEL_TIMER_H
#define PARALLEL_TIMER_H

#include <chrono>

class Timer {
    enum State {
        CREATED, STARTED, STOPPED
    };
    std::chrono::microseconds duration;
    std::chrono::microseconds start_time;
    State state;

public:
    Timer();

    void start();

    void stop();

    std::chrono::microseconds get_duration();
};


#endif //PARALLEL_TIMER_H
