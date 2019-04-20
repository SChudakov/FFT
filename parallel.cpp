//
// Created by semen on 12.04.19.
//
#include "parallel.hpp"
#include <iostream>
#include <thread>


namespace {
    void fft(std::vector<base> &a, bool invert) {
        unsigned long long n = a.size();
        if (n == 1) {
            return;
        }
//        std::cout << "par" << " " << n << " " << THRESHOLD << std::endl;
//        std::cout << std::this_thread::get_id() << std::endl;

        std::vector<base> a0(static_cast<unsigned long>(n / 2));
        std::vector<base> a1(static_cast<unsigned long>(n / 2));

        for (int i = 0, j = 0; i < n; i += 2, ++j) {
            a0[j] = a[i];
            a1[j] = a[i + 1];
        }

#pragma omp task shared(a0, invert) if (n>=THRESHOLD)
        {
            fft(a0, invert);
        };

        fft(a1, invert);

#pragma omp taskwait

        double ang = 2 * M_PI / n * (invert ? -1 : 1);
        base w(1);
        base wn(cos(ang), sin(ang));

        for (int i = 0; i < n / 2; ++i) {
            a[i] = a0[i] + w * a1[i];
            a[i + n / 2] = a0[i] - w * a1[i];
            if (invert) {
                a[i] /= 2, a[i + n / 2] /= 2;
            }
            w *= wn;
        }
    }
}

namespace parallel {

    std::vector<int> multiply(const std::vector<int> &a, const std::vector<int> &b) {
        std::vector<int> result;

        std::vector<base> fa(a.begin(), a.end());
        std::vector<base> fb(b.begin(), b.end());
        long long n = 1;
        while (n < std::max(a.size(), b.size())) {
            n <<= 1;
        }
//        std::cout << n << std::endl;
//        n <<= 1;

        fa.resize(static_cast<unsigned long>(n));
        fb.resize(static_cast<unsigned long>(n));

#pragma omp parallel shared(fa, fb)
        {
#pragma omp single
            {
                ::fft(fa, false);
                ::fft(fb, false);
            };

#pragma omp for
            for (long long i = 0; i < n; ++i) {
                fa[i] *= fb[i];
            }

#pragma omp single
            {
                ::fft(fa, true);

                result.resize(static_cast<unsigned long>(n));
            };

#pragma omp for
            for (long long i = 0; i < n; ++i) {
                result[i] = int(std::lround(fa[i].real()));
            }

        };

        return result;
    }
}