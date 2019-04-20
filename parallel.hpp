//
// Created by semen on 19.04.19.
//

#ifndef PARALLEL_PARALLEL_HPP
#define PARALLEL_PARALLEL_HPP

#include <vector>
#include <math.h>
#include <chrono>
#include <complex>

namespace {
    const int THRESHOLD = 20000;

    typedef std::complex<double> base;

    void fft(std::vector<base> &a, bool invert);
}

namespace parallel {
    std::vector<int> multiply(const std::vector<int> &a, const std::vector<int> &b);
}

#endif //PARALLEL_PARALLEL_HPP
