//
// Created by semen on 12.04.19.
//

#include "sequential.hpp"


namespace {

    void fft(std::vector<base> &a, bool invert) {
        int n = (int) a.size();
        if (n == 1) return;

        std::vector<base> a0(static_cast<unsigned long>(n / 2));
        std::vector<base> a1(static_cast<unsigned long>(n / 2));
        for (int i = 0, j = 0; i < n; i += 2, ++j) {
            a0[j] = a[i];
            a1[j] = a[i + 1];
        }

        fft(a0, invert);
        fft(a1, invert);

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

namespace sequential {

    std::vector<int> multiply(const std::vector<int> &a, const std::vector<int> &b) {
        std::vector<int> result;

        std::vector<base> fa(a.begin(), a.end());
        std::vector<base> fb(b.begin(), b.end());
        size_t n = 1;
        while (n < std::max(a.size(), b.size())) {
            n <<= 1;
        }
//        n <<= 1;

        fa.resize(n), fb.resize(n);

        ::fft(fa, false);
        ::fft(fb, false);
        for (size_t i = 0; i < n; ++i) {
            fa[i] *= fb[i];
        }

        ::fft(fa, true);

        result.resize(n);
        for (size_t i = 0; i < n; ++i) {
            result[i] = int(std::lround(fa[i].real()));
        }

        return result;
    }
}
