//
// Created by semen on 19.04.19.
//

#ifndef PARALLEL_SEQUENTIAL_H
#define PARALLEL_SEQUENTIAL_H

#include <vector>
#include <complex>

namespace {
    typedef std::complex<double> base;

    void fft(std::vector<base> &a, bool invert);
}
namespace sequential {
    std::vector<int> multiply(const std::vector<int> &a, const std::vector<int> &b);
}

#endif //PARALLEL_SEQUENTIAL_H
